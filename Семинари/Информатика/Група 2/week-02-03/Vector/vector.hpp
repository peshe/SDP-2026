#pragma once

#include <cstddef>
#include <algorithm>
#include <utility>

#include "reverse_iterator.hpp"

template<class T>
class Vector
{
	T* buf;
	std::size_t sz, cap;

	static constexpr std::size_t initial_capacity = 16;

public:
	using value_type = T;
	using iterator = T*;
	using const_iterator = const T*;
	using reverse_iterator = Reverse_iterator<iterator>;
	using const_reverse_iterator = Reverse_iterator<const_iterator>;

	Vector(): buf(new T[initial_capacity]{}), sz(0), cap(initial_capacity) {}

	Vector(const Vector& other): buf(new T[other.cap]{}), sz(other.sz), cap(other.cap)
	{
		try
		{
			for(std::size_t i = 0; i < sz; i++)
				buf[i] = other.buf[i];
		}
		catch(...)
		{
			delete[] buf;
			throw;
		}
	}
	Vector(Vector&& other) noexcept: buf(other.buf), sz(other.sz), cap(other.cap)
	{
		other.buf = nullptr;
		other.sz = other.cap = 0;
	}
	~Vector()
	{
		delete[] buf;
	}

	// copy and swap
	/*Vector& operator=(Vector other)
	{
		std::swap(buf, other.buf);
		std::swap(sz, other.sz);
		std::swap(cap, other.cap);
		return *this;
	}*/

	Vector& operator=(const Vector& other)
	{
		if(this != &other)
		{
			if(cap < other.sz)
			{
				delete[] buf;
				buf = nullptr;
				sz = 0;
				buf = new T[other.sz];
				cap = other.sz;
			}
			for(std::size_t i = 0; i < sz; i++)
				buf[i] = other.buf[i];
			sz = other.sz;
		}
		return *this;
	}

	Vector& operator=(Vector&& other) noexcept
	{
		if(this != &other)
		{
			delete[] buf;
			buf = other.buf;
			sz = other.sz;
			cap = other.cap;
			other.buf = nullptr;
			other.sz = other.capacity = 0;
		}
		return *this;
	}

	void push_back(const T& value)
	{
		if(sz == cap)
			reserve(std::max(initial_capacity, 2 * cap));
		buf[sz] = value;
		sz++;
	}

	void push_back(T&& value)
	{
		if(sz == cap)
			reserve(std::max(initial_capacity, 2 * cap));
		buf[sz] = std::move(value);
		sz++;
	}

	void reserve(std::size_t new_cap)
	{
		if(new_cap <= cap) return;
		T* tmp = new T[new_cap]{};

		try
		{
			for(std::size_t i = 0; i < sz; i++)
				tmp[i] = std::move_if_noexcept(buf[i]);
		}
		catch(...)
		{
			delete[] tmp;
			throw;
		}

		delete[] buf;
		buf = tmp;
		cap = new_cap;
	}

	void resize(std::size_t new_sz)
	{
		reserve(new_sz);
		sz = new_sz;
	}

	std::size_t capacity() const noexcept
	{
		return cap;
	}
	std::size_t size() const noexcept
	{
		return sz;
	}

	void clear()
	{
		sz = 0;
	}

	T& operator[](std::size_t ind)
	{
		return buf[ind];
	}
	const T& operator[](std::size_t ind) const
	{
		return buf[ind];
	}

	T& at(std::size_t ind)
	{
		if(ind >= size())
			throw std::out_of_range("vector::at called with invalid index");
		return buf[ind];
	}
	const T& at(std::size_t ind) const
	{
		if(ind >= size())
			throw std::out_of_range("vector::at called with invalid index");
		return buf[ind];
	}

	iterator begin() noexcept
	{
		return buf;
	}
	const_iterator begin() const noexcept
	{
		return buf;
	}
	iterator end() noexcept
	{
		return buf + size();
	}
	const_iterator end() const noexcept
	{
		return buf + size();
	}

	reverse_iterator rbegin() noexcept
	{
		return reverse_iterator(end());
	}
	const reverse_iterator rbegin() const noexcept
	{
		return reverse_iterator(end());
	}
	reverse_iterator rend() noexcept
	{
		return reverse_iterator(begin());
	}
	const reverse_iterator rend() const noexcept
	{
		return reverse_iterator(begin());
	}
};
