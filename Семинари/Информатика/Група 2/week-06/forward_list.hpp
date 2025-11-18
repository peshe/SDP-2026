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

template<class T>
class flist_iterator
{
    template<class U>
    friend class forward_list;

    using node_type = flist_node<T>;
    using const_iterator = flist_iterator<const T>;

    flist_node_base* node;
public:
    using iterator_category = std::forward_iterator_tag;

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
    T& operator*() const noexcept
    {
        return static_cast<node_type*>(node)->value;
    }
    T* operator->() const noexcept
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
    std::size_t sz;

    using node_base = flist_node_base;
    using node_type = flist_node<T>;

    static node_type* cast_node(node_base* node)
    {
        return static_cast<node_type*>(node);
    } 
public:
    using value_type = T;
    using iterator = flist_iterator<T>;
    using const_iterator = iterator::const_iterator;

    forward_list(): sz{0} {}
    forward_list(std::initializer_list<T> list): sz{0}
    {
        for(auto it = std::rbegin(list); it != std::rend(list); ++it)
            insert_after(before_begin(), *it);
    }
    ~forward_list()
    {
        while(!empty())
            erase_after(before_begin());
    }


    void insert_after(const_iterator pos, const value_type& value)
    {
        pos.node->next = new node_type{value, pos.node->next};
        sz++;
    }
    void insert_after(const_iterator pos, value_type&& value)
    {
        pos.node->next = new node_type{std::move(value), pos.node->next};
        sz++;
    }
    void erase_after(const_iterator pos)
    {
        node_type* to_delete = cast_node(pos.node->next);
        pos.node->next = to_delete->next;
        delete to_delete;
        sz--;
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
};
