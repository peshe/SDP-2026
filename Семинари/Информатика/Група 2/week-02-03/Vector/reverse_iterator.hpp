#pragma once

template<class It>
class Reverse_iterator
{
	It current;

public:
	Reverse_iterator(It current): current(current) {}

	decltype(auto) operator*() const
	{
		It tmp = current;
		return *--tmp;
	}

	Reverse_iterator& operator++()
	{
		--current;
		return *this;
	}
	Reverse_iterator operator++(int)
	{
		Reverse_iterator old = *this;
		++*this;
		return old;
	}

	Reverse_iterator& operator--()
	{
		++current;
		return *this;
	}
	Reverse_iterator operator--(int)
	{
		Reverse_iterator old = *this;
		--*this;
		return old;
	}

	bool operator==(const Reverse_iterator& rhs) const noexcept = default;
};
