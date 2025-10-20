#pragma once

#include <utility>

template<class Container>
class Back_insert_iterator
{
	Container* c;

public:
	Back_insert_iterator(Container& c): c(&c) {}

	Back_insert_iterator& operator++() noexcept
	{
		return *this;
	}
	Back_insert_iterator operator++(int) noexcept
	{
		return *this;
	}

	Back_insert_iterator& operator*() noexcept
	{
		return *this;
	}

	Back_insert_iterator& operator=(const Container::value_type& value)
	{
		c->push_back(value);
		return *this;
	}
	Back_insert_iterator& operator=(Container::value_type&& value)
	{
		c->push_back(std::move(value));
		return *this;
	}
};
