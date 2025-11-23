// !!! MOST OF CODE IN THIS FILE IS AI GENERATED !!!
// compile with: g++ -Wall -pedantic-errors -O3 -std=c++20 forward_list_test.cpp -lgtest -lgtest_main -pthread

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "forward_list.hpp"

#include <vector>
#include <algorithm>
#include <iterator>

namespace
{
	using namespace testing;

	TEST(ForwardList, DefaultConstructor)
	{
		forward_list<int> fl;
		EXPECT_TRUE(fl.empty());
		EXPECT_EQ(fl.size(), 0u);
		EXPECT_EQ(fl.begin(), fl.end());
	}

	TEST(ForwardList, InitializerListConstructor)
	{
		forward_list<int> fl{1,2,3};
		EXPECT_FALSE(fl.empty());
		EXPECT_EQ(fl.size(), 3u);
		EXPECT_THAT(fl, ElementsAreArray({1, 2, 3}));
	}

	TEST(ForwardList, InsertAfterSingle)
	{
		forward_list<int> fl;
		auto it = fl.before_begin();
		fl.insert_after(it, 10);
		fl.insert_after(it, 5);  // becomes 5,10

		ASSERT_EQ(fl.size(), 2u);
		EXPECT_THAT(fl, ElementsAreArray({5, 10}));
	}

	TEST(ForwardList, InsertAfterRange)
	{
		forward_list<int> fl;
		std::vector<int> v = {1,2,3,4};

		fl.insert_after(fl.before_begin(), v.begin(), v.end());

		EXPECT_EQ(fl.size(), 4u);
		EXPECT_THAT(fl, ElementsAreArray({1,2,3,4}));
	}

	TEST(ForwardList, EraseAfterSingle)
	{
		forward_list<int> fl{1,2,3};
		auto it = fl.begin(); // points to 1
		fl.erase_after(it);   // remove 2 → list is 1,3

		EXPECT_EQ(fl.size(), 2u);
		EXPECT_THAT(fl, ElementsAreArray({1,3}));
	}

	TEST(ForwardList, EraseAfterRange)
	{
		forward_list<int> fl{1,2,3,4,5};
		auto first = fl.begin();          // 1
		auto last = std::next(first, 4); // iterator to 5
		fl.erase_after(first, last);      // remove {2,3,4}

		EXPECT_EQ(fl.size(), 2u);
		EXPECT_THAT(fl, ElementsAreArray({1,5}));
	}

	TEST(ForwardList, Clear)
	{
		forward_list<int> fl{1,2,3};
		fl.clear();
		EXPECT_TRUE(fl.empty());
		EXPECT_EQ(fl.size(), 0u);
		EXPECT_EQ(fl.begin(), fl.end());
	}

	TEST(ForwardList, CopyConstructor)
	{
		forward_list<int> fl1{1,2,3};
		forward_list<int> fl2 = fl1;

		fl1.front() = 10;
		fl2.front() = 20;

		EXPECT_THAT(fl1, ElementsAreArray({10,2,3}));
		EXPECT_EQ(fl2.size(), 3u);
		EXPECT_THAT(fl2, ElementsAreArray({20,2,3}));
	}

	TEST(ForwardList, CopyAssignment)
	{
		forward_list<int> fl1{1,2,3};
		forward_list<int> fl2{10,20};
		fl2 = fl1;

		fl1.front() = 10;
		fl2.front() = 20;

		EXPECT_THAT(fl1, ElementsAreArray({10,2,3}));
		EXPECT_EQ(fl2.size(), 3u);
		EXPECT_THAT(fl2, ElementsAreArray({20,2,3}));
	}

	TEST(ForwardList, MoveConstructor)
	{
		forward_list<int> fl1{1,2,3};
		forward_list<int> fl2(std::move(fl1));

		EXPECT_EQ(fl2.size(), 3u);
		EXPECT_EQ(fl1.size(), 0u); // moved-from empty
		EXPECT_THAT(fl2, ElementsAreArray({1,2,3}));
	}

	TEST(ForwardList, MoveAssignment)
	{
		forward_list<int> fl1{1,2,3};
		forward_list<int> fl2{10,20};
		fl2 = std::move(fl1);

		EXPECT_EQ(fl2.size(), 3u);
		EXPECT_EQ(fl1.size(), 0u);
		EXPECT_THAT(fl2, ElementsAreArray({1,2,3}));
	}

	TEST(ForwardList, SpliceWholeList)
	{
		forward_list<int> a{1,2,3};
		forward_list<int> b{4,5};

		a.splice_after(a.before_begin(), b);

		EXPECT_EQ(a.size(), 5u);
		EXPECT_TRUE(b.empty());
		EXPECT_THAT(a, ElementsAreArray({4,5,1,2,3}));
	}

	TEST(ForwardList, SpliceSingleElement)
	{
		forward_list<int> a{10,20,30};
		forward_list<int> b{1,2,3};

		auto pos = a.begin();             // after 10
		auto it = b.begin();             // b.begin() (1)

		a.splice_after(pos, b, it);       // move 2 after 10

		EXPECT_EQ(a.size(), 4u);
		EXPECT_EQ(b.size(), 2u);

		EXPECT_THAT(a, ElementsAreArray({10,2,20,30}));
		EXPECT_THAT(b, ElementsAreArray({1,3}));
	}

	TEST(ForwardList, Reverse)
	{
		forward_list<int> fl{1,2,3,4};
		fl.reverse();
		EXPECT_THAT(fl, ElementsAreArray({4,3,2,1}));
	}

	TEST(ForwardList, Unique)
	{
		forward_list<int> fl{1,1,2,3,3,3,3,3,4,3,3};
		std::size_t removed = fl.unique();

		EXPECT_EQ(removed, 6u);
		EXPECT_THAT(fl, ElementsAreArray({1,2,3,4,3}));
	}

	TEST(ForwardList, Merge)
	{
		forward_list<int> a{1,1,3,5,10};
		forward_list<int> b{2,4,6,20,30};

		a.merge(b, std::less<int>{});

		EXPECT_TRUE(b.empty());
		EXPECT_EQ(a.size(), 10u);
		EXPECT_THAT(a, ElementsAreArray({1,1,2,3,4,5,6,10,20,30}));
	}

	TEST(ForwardList, IteratorsWork)
	{
		forward_list<int> fl{1,2,3};

		int sum = 0;
		for(auto it = fl.begin(); it != fl.end(); ++it)
			sum += *it;

		EXPECT_EQ(sum, 6);

		// const_iterator test
		const auto& cfl = fl;
		int prod = 1;
		for(auto it = cfl.begin(); it != cfl.end(); ++it)
			prod *= *it;

		EXPECT_EQ(prod, 6);
	}

	TEST(ForwardList, Front)
	{
		forward_list<int> fl{10,20,30};
		EXPECT_EQ(fl.front(), 10);

		fl.front() = 99;
		EXPECT_EQ(*fl.begin(), 99);
	}
}
