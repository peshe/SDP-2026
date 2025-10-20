#pragma once

template<class It, class ItOut>
ItOut copy(It first, It last, ItOut out)
{
	for(; first != last; ++out, ++first)
		*out = *first;
	return out;
}

template<class It1, class It2, class ItOut, class Cmp>
ItOut merge(It1 first1, It1 last1, It2 first2, It2 last2, ItOut out, Cmp cmp)
{
	for(; first1 != last1 && first2 != last2; ++out)
		if(cmp(*first2, *first1)) // *first2 < *first1
			*out = *first2++;
		else
			*out = *first1++;
	out = copy(first1, last1, out);
	out = copy(first2, last2, out);
	return out;
}
