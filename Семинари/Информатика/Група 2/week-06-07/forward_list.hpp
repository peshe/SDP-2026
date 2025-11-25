#pragma once

#include <iterator>
#include <memory>
#include <utility>
#include <initializer_list>

struct flist_node_base
{
	flist_node_base* next;
	flist_node_base(flist_node_base* next = nullptr): next(next) {}
};

template<class T>
struct flist_node: flist_node_base
{
	T value;
	flist_node(const T& value, flist_node_base* next):
		flist_node_base(next), value(value) {}
};

template<class T, bool IsConst = false>
class flist_iterator
{
	template<class U>
	friend class forward_list;

	using node_type = flist_node<T>;
	using const_iterator = flist_iterator<T, true>;

	flist_node_base* node;
public:
	using iterator_category = std::forward_iterator_tag;
	using value_type = std::conditional_t<IsConst, const T, T>;
	using reference = value_type&;
	using pointer = value_type*;
	using difference_type = std::ptrdiff_t;

	flist_iterator(flist_node_base* node): node(node) {}
	operator const_iterator() const noexcept
	{
		return {node};
	}

	flist_iterator& operator++() noexcept
	{
		node = node->next;
		return *this;
	}
	flist_iterator operator++(int) noexcept
	{
		flist_iterator tmp(*this);
		++*this;
		return tmp;
	}
	reference operator*() const noexcept
	{
		return static_cast<node_type*>(node)->value;
	}
	pointer operator->() const noexcept
	{
		return std::addressof(static_cast<node_type*>(node)->value);
	}

	bool operator==(flist_iterator rhs) const noexcept
	{
		return node == rhs.node;
	}
	bool operator!=(flist_iterator rhs) const noexcept
	{
		return !(*this == rhs);
	}
};

template<class T>
class forward_list
{
	flist_node_base sentinel;
	std::size_t sz = 0;
public:
	using value_type = T;
	using iterator = flist_iterator<T>;
	using const_iterator = iterator::const_iterator;

private:
	using node_base = flist_node_base;
	using node_type = flist_node<T>;

	static node_type* cast_node(node_base* node)
	{
		return static_cast<node_type*>(node);
	}

	iterator attach_after(const_iterator pos, node_type* node) noexcept
	{
		node->next = pos.node->next;
		pos.node->next = node;
		sz++;
		return {node};
	}
	node_type* detach_after(const_iterator pos) noexcept
	{
		node_type* detached = cast_node(pos.node->next);
		pos.node->next = detached->next;
		detached->next = nullptr;
		sz--;
		return detached;
	}
	node_base* find_last() noexcept
	{
		node_base* last = &sentinel;
		while(last->next)
			last = last->next;
		return last;
	}
public:

	forward_list() = default;
	template<class It>
	forward_list(It first, It last)
	{
		try {
			for(auto it = before_begin(); first != last; ++first)
				it = insert_after(it, *first);
		}
		catch(...)
		{
			clear();
			throw;
		}
	}
	forward_list(std::initializer_list<T> list):
		forward_list(list.begin(), list.end()) {}
	forward_list(const forward_list& other): forward_list(other.begin(), other.end()) {}
	forward_list(forward_list&& other) noexcept
	{
		sentinel = other.sentinel;
		sz = other.sz;
		other.sentinel = {};
		other.sz = 0;
	}
	~forward_list()
	{
		clear();
	}
	void clear() noexcept
	{
		while(!empty())
			erase_after(before_begin());
	}

	forward_list& operator=(const forward_list& other)
	{
		if(this != &other)
		{
			auto curr = begin(), other_curr = other.begin();
			auto prev = before_begin();
			for(; curr != end() && other_curr != other.end(); ++curr, ++other_curr, ++prev)
				*curr = *other_curr;

			if(curr == end())
				insert_after(prev, other_curr, other.end());
			else
				erase_after(prev, end());
		}
		return *this;
	}
	forward_list& operator=(forward_list&& other) noexcept
	{
		clear();
		sentinel = other.sentinel;
		sz = other.sz;
		other.sentinel = {};
		other.sz = 0;
		return *this;
	}


	iterator insert_after(const_iterator pos, const value_type& value)
	{
		return attach_after(pos, new node_type{value, pos.node->next});
	}
	iterator insert_after(const_iterator pos, value_type&& value)
	{
		return attach_after(pos, new node_type{std::move(value), pos.node->next});
	}
	template<class It>
	iterator insert_after(const_iterator pos, It first, It last)
	{
		for(; first != last; ++first)
			pos = insert_after(pos, *first);
		return {pos.node};
	}
	iterator erase_after(const_iterator pos)
	{
		delete detach_after(pos);
		return {pos.node->next};
	}
	iterator erase_after(const_iterator first, const_iterator last)
	{
		if(first != last)
			while(std::next(first) != last)
				erase_after(first);
		return {last.node};
	}

	void splice_after(const_iterator pos, forward_list& other, const_iterator it) noexcept
	{
		if(pos == it || pos == std::next(it)) return;
		attach_after(pos, other.detach_after(it));
	}
	void splice_after(const_iterator pos, forward_list& other) noexcept
	{
		if(this == &other) return;
		other.find_last()->next = pos.node->next;
		pos.node->next = other.sentinel.next;
		sz += other.size();

		// set other to empty
		other.sentinel.next = nullptr;
		other.sz = 0;
	}
	void splice_after(const_iterator pos, forward_list& other,
					  const_iterator first, const_iterator last) noexcept
	{
		if(first == last) return;
		for(; std::next(first) != last; ++pos)
			splice_after(pos, other, first);
	}

	void reverse() noexcept
	{
		if(size() < 2) return;

		node_base *prev = nullptr, *curr = sentinel.next;
		while(curr)
		{
			node_base* next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}

		sentinel.next = prev;
	}

	std::size_t unique()
	{
		std::size_t erased_cnt = 0;
		for(iterator it = begin(), next; it != end() && (next = std::next(it)) != end();)
			if(*it == *next)
			{
				erase_after(it);
				erased_cnt++;
			}
			else
				++it;
		return erased_cnt;
	}

	template<class Compare>
	void merge(forward_list& other, Compare comp)
	{
		if(this == &other) return;
		for(auto this_prev = before_begin(), this_curr = begin(); !other.empty(); ++this_prev)
			if(this_curr == end() || comp(other.front(), *this_curr))
				attach_after(this_prev.node, other.detach_after(other.before_begin().node));
			else
				++this_curr;
	}

	iterator before_begin() noexcept
	{
		return {&sentinel};
	}
	const_iterator before_begin() const noexcept
	{
		return {&sentinel};
	}
	iterator begin() noexcept
	{
		return {sentinel.next};
	}
	const_iterator begin() const noexcept
	{
		return {sentinel.next};
	}
	iterator end() noexcept
	{
		return {nullptr};
	}
	const_iterator end() const noexcept
	{
		return {nullptr};
	}
	bool empty() const noexcept
	{
		return size() == 0;
	}
	std::size_t size() const noexcept
	{
		return sz;
	}

	T& front() noexcept
	{
		return *begin();
	}
	const T& front() const noexcept
	{
		return *begin();
	}
};
