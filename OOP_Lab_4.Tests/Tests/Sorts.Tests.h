#pragma once

#include "../pch.h"

#include "../../OOP_Lab_4/Lists Files/ListSorter.h"
#include "../../OOP_Lab_4/Lists Files/ArrayList.h"
#include "../../OOP_Lab_4/Lists Files/Sorts/ArraySort/ArrayBubbleSort.h"
#include "../../OOP_Lab_4/Lists Files/Sorts/ArraySort/ArrayBucketSort.h"
#include "../../OOP_Lab_4/Lists Files/Sorts/ArraySort/ArrayCountingSort.h"
#include "../../OOP_Lab_4/Lists Files/Sorts/ArraySort/ArrayGnomeSort.h"
#include "../../OOP_Lab_4/Lists Files/Sorts/ArraySort/ArrayMergeSort.h"
#include "../../OOP_Lab_4/Lists Files/Sorts/ArraySort/ArrayQuickSort.h"
#include "../../OOP_Lab_4/Lists Files/Sorts/ArraySort/ArraySelectionSort.h"
#include "../../OOP_Lab_4/Lists Files/Sorts/NodeSort/NodeBubbleSort.h"
#include "../../OOP_Lab_4/Lists Files/Sorts/NodeSort/NodeBucketSort.h"
#include "../../OOP_Lab_4/Lists Files/Sorts/NodeSort/NodeCountingSort.h"
#include "../../OOP_Lab_4/Lists Files/Sorts/NodeSort/NodeGnomeSort.h"
#include "../../OOP_Lab_4/Lists Files/Sorts/NodeSort/NodeQuickSort.h"
#include "../../OOP_Lab_4/Lists Files/Sorts/NodeSort/NodeSelectionSort.h"

using std::shared_ptr;
using std::make_shared;
using std::pair;

TEST(Sort, TestNodeGnomeSort)
{
	shared_ptr<LinkedList<pair<int, char>>> list1(new LinkedList<pair<int, char>>());
	list1->PushBack(pair<int, char>(4, 'f'));
	list1->PushBack(pair<int, char>(5, 'a'));
	list1->PushBack(pair<int, char>(3, 'g'));
	list1->PushBack(pair<int, char>(7, 'e'));
	list1->PushBack(pair<int, char>(1, 'g'));
	list1->PushBack(pair<int, char>(0, 'c'));
	list1->PushBack(pair<int, char>(8, 'h'));
	list1->PushBack(pair<int, char>(10, 'b'));
	list1->PushBack(pair<int, char>(2, 'd'));

	shared_ptr<NodeGnomeSort<pair<int, char>>> ptr1(new NodeGnomeSort<pair<int, char>>(
		[](std::pair<int, char> p1,
		std::pair<int, char> p2)
		{
			return p1.first >= p2.first;
		}));
	list1->SetSort(ptr1);
	list1->Sort();
	
	EXPECT_EQ(list1->Get(0).first, 0);
	EXPECT_EQ(list1->Get(8).first, 10);

	shared_ptr<NodeGnomeSort<pair<int, char>>> ptr2(new NodeGnomeSort<pair<int, char>>(
		[](std::pair<int, char> p1,
		std::pair<int, char> p2)
		{
			return p1.second >= p2.second;
		}));
	list1->SetSort(ptr2);
	list1->Sort();

	EXPECT_EQ(list1->Get(0).second, 'a');
	EXPECT_EQ(list1->Get(8).second, 'h');
}

TEST(Sort, TestsNodeBubbleSort)
{
	shared_ptr<LinkedList<pair<int, char>>> list1(new LinkedList<pair<int, char>>());
	list1->PushBack(pair<int, char>(4, 'f'));
	list1->PushBack(pair<int, char>(5, 'a'));
	list1->PushBack(pair<int, char>(3, 'g'));
	list1->PushBack(pair<int, char>(7, 'e'));
	list1->PushBack(pair<int, char>(1, 'g'));
	list1->PushBack(pair<int, char>(0, 'c'));
	list1->PushBack(pair<int, char>(8, 'h'));
	list1->PushBack(pair<int, char>(10, 'b'));
	list1->PushBack(pair<int, char>(2, 'd'));

	shared_ptr<NodeBubbleSort<pair<int, char>>> ptr1(new NodeBubbleSort<pair<int, char>>(
		[](std::pair<int, char> p1,
			std::pair<int, char> p2)
		{
			return p1.first >= p2.first;
		}));
	list1->SetSort(ptr1);
	list1->Sort();

	EXPECT_EQ(list1->Get(0).first, 0);
	EXPECT_EQ(list1->Get(8).first, 10);

	shared_ptr<NodeBubbleSort<pair<int, char>>> ptr2(new NodeBubbleSort<pair<int, char>>(
		[](std::pair<int, char> p1,
			std::pair<int, char> p2)
		{
			return p1.second >= p2.second;
		}));
	list1->SetSort(ptr2);
	list1->Sort();

	EXPECT_EQ(list1->Get(0).second, 'a');
	EXPECT_EQ(list1->Get(8).second, 'h');
}

TEST(Sort, TestNodeSelectionSort)
{
	shared_ptr<LinkedList<pair<int, char>>> list1(new LinkedList<pair<int, char>>());
	list1->PushBack(pair<int, char>(4, 'f'));
	list1->PushBack(pair<int, char>(5, 'a'));
	list1->PushBack(pair<int, char>(3, 'g'));
	list1->PushBack(pair<int, char>(7, 'e'));
	list1->PushBack(pair<int, char>(1, 'g'));
	list1->PushBack(pair<int, char>(0, 'c'));
	list1->PushBack(pair<int, char>(8, 'h'));
	list1->PushBack(pair<int, char>(10, 'b'));
	list1->PushBack(pair<int, char>(2, 'd'));

	shared_ptr<NodeSelectionSort<pair<int, char>>> ptr1(new NodeSelectionSort<pair<int, char>>(
		[](std::pair<int, char> p1,
			std::pair<int, char> p2)
		{
			return p1.first >= p2.first;
		}));
	list1->SetSort(ptr1);
	list1->Sort();

	EXPECT_EQ(list1->Get(0).first, 0);
	EXPECT_EQ(list1->Get(8).first, 10);

	shared_ptr<NodeSelectionSort<pair<int, char>>> ptr2(new NodeSelectionSort<pair<int, char>>(
		[](std::pair<int, char> p1,
			std::pair<int, char> p2)
		{
			return p1.second >= p2.second;
		}));
	list1->SetSort(ptr2);
	list1->Sort();

	EXPECT_EQ(list1->Get(0).second, 'a');
	EXPECT_EQ(list1->Get(8).second, 'h');
}

TEST(Sort, TestNodeQuickSort)
{
	shared_ptr<LinkedList<pair<int, char>>> list1(new LinkedList<pair<int, char>>());
	list1->PushBack(pair<int, char>(4, 'f'));
	list1->PushBack(pair<int, char>(5, 'a'));
	list1->PushBack(pair<int, char>(3, 'g'));
	list1->PushBack(pair<int, char>(7, 'e'));
	list1->PushBack(pair<int, char>(1, 'g'));
	list1->PushBack(pair<int, char>(0, 'c'));
	list1->PushBack(pair<int, char>(8, 'h'));
	list1->PushBack(pair<int, char>(10, 'b'));
	list1->PushBack(pair<int, char>(2, 'd'));

	shared_ptr<NodeQuickSort<pair<int, char>>> ptr1(new NodeQuickSort<pair<int, char>>(
		[](std::pair<int, char> p1,
			std::pair<int, char> p2)
		{
			return p1.first >= p2.first;
		}));
	list1->SetSort(ptr1);
	list1->Sort();

	EXPECT_EQ(list1->Get(0).first, 0);
	EXPECT_EQ(list1->Get(8).first, 10);

	shared_ptr<NodeQuickSort<pair<int, char>>> ptr2(new NodeQuickSort<pair<int, char>>(
		[](std::pair<int, char> p1,
			std::pair<int, char> p2)
		{
			return p1.second >= p2.second;
		}));
	list1->SetSort(ptr2);
	list1->Sort();

	EXPECT_EQ(list1->Get(0).second, 'a');
	EXPECT_EQ(list1->Get(8).second, 'h');
}

TEST(Sort, TestNodeCountingSort)
{
	shared_ptr<LinkedList<pair<int, char>>> list1(new LinkedList<pair<int, char>>());
	list1->PushBack(pair<int, char>(4, 'f'));
	list1->PushBack(pair<int, char>(5, 'a'));
	list1->PushBack(pair<int, char>(3, 'g'));
	list1->PushBack(pair<int, char>(7, 'e'));
	list1->PushBack(pair<int, char>(1, 'g'));
	list1->PushBack(pair<int, char>(0, 'c'));
	list1->PushBack(pair<int, char>(8, 'h'));
	list1->PushBack(pair<int, char>(10, 'b'));
	list1->PushBack(pair<int, char>(2, 'd'));

	shared_ptr<NodeCountingSort<pair<int, char>>> ptr1(new NodeCountingSort<pair<int, char>>(
		[](std::pair<int, char> p1)
		{
			return p1.first;
		}));
	list1->SetSort(ptr1);
	list1->Sort();

	EXPECT_EQ(list1->Get(0).first, 0);
	EXPECT_EQ(list1->Get(8).first, 10);
}

TEST(Sort, TestNodeBucketSort)
{
	shared_ptr<LinkedList<pair<float, char>>> list1(new LinkedList<pair<float, char>>());
	list1->PushBack(pair<float, char>(0.4, 'f'));
	list1->PushBack(pair<float, char>(0.5, 'a'));
	list1->PushBack(pair<float, char>(0.3, 'g'));
	list1->PushBack(pair<float, char>(0.7, 'e'));
	list1->PushBack(pair<float, char>(0.1, 'g'));
	list1->PushBack(pair<float, char>(0.0, 'c'));
	list1->PushBack(pair<float, char>(0.8, 'h'));
	list1->PushBack(pair<float, char>(0.1, 'b'));
	list1->PushBack(pair<float, char>(0.2, 'd'));

	shared_ptr<NodeBucketSort<pair<float, char>>> ptr1(new NodeBucketSort<pair<float, char>>(
		[](std::pair<float, char> p1)
		{
			return p1.first;
		}));
	list1->SetSort(ptr1);
	list1->Sort();

	EXPECT_FLOAT_EQ(list1->Get(0).first, 0.0);
	EXPECT_FLOAT_EQ(list1->Get(8).first, 0.8);
}

TEST(Sort, TestArrayGnomeSort)
{
	shared_ptr<ArrayList<pair<int, char>>> list1(new ArrayList<pair<int, char>>());
	list1->PushBack(std::pair<int, char>(4, 'f'));
	list1->PushBack(std::pair<int, char>(5, 'a'));
	list1->PushBack(std::pair<int, char>(3, 'g'));
	list1->PushBack(std::pair<int, char>(7, 'e'));
	list1->PushBack(std::pair<int, char>(1, 'g'));
	list1->PushBack(std::pair<int, char>(0, 'c'));
	list1->PushBack(std::pair<int, char>(8, 'h'));
	list1->PushBack(std::pair<int, char>(10, 'b'));
	list1->PushBack(std::pair<int, char>(2, 'd'));

	shared_ptr<ArrayGnomeSort<pair<int, char>>> ptr1(new ArrayGnomeSort<pair<int, char>>(
		[](std::pair<int, char> p1,
			std::pair<int, char> p2)
		{
			return p1.first >= p2.first;
		}));
	list1->SetSort(ptr1);
	list1->Sort();
	
	EXPECT_EQ(list1->Get(0).first, 0);
	EXPECT_EQ(list1->Get(8).first, 10);

	shared_ptr<ArrayGnomeSort<pair<int, char>>> ptr2(new ArrayGnomeSort<pair<int, char>>(
		[](std::pair<int, char> p1,
			std::pair<int, char> p2)
		{
			return p1.second >= p2.second;
		}));
	list1->SetSort(ptr2);
	list1->Sort();

	EXPECT_EQ(list1->Get(0).second, 'a');
	EXPECT_EQ(list1->Get(8).second, 'h');
}

TEST(Sort, TestArrayBubbleSort)
{
	shared_ptr<ArrayList<pair<int, char>>> list1(new ArrayList<pair<int, char>>());
	list1->PushBack(std::pair<int, char>(4, 'f'));
	list1->PushBack(std::pair<int, char>(5, 'a'));
	list1->PushBack(std::pair<int, char>(3, 'g'));
	list1->PushBack(std::pair<int, char>(7, 'e'));
	list1->PushBack(std::pair<int, char>(1, 'g'));
	list1->PushBack(std::pair<int, char>(0, 'c'));
	list1->PushBack(std::pair<int, char>(8, 'h'));
	list1->PushBack(std::pair<int, char>(10, 'b'));
	list1->PushBack(std::pair<int, char>(2, 'd'));

	shared_ptr<ArrayBubbleSort<pair<int, char>>> ptr1(new ArrayBubbleSort<pair<int, char>>(
		[](std::pair<int, char> p1,
			std::pair<int, char> p2)
		{
			return p1.first >= p2.first;
		}));
	list1->SetSort(ptr1);
	list1->Sort();

	EXPECT_EQ(list1->Get(0).first, 0);
	EXPECT_EQ(list1->Get(8).first, 10);

	shared_ptr<ArrayBubbleSort<pair<int, char>>> ptr2(new ArrayBubbleSort<pair<int, char>>(
		[](std::pair<int, char> p1,
			std::pair<int, char> p2)
		{
			return p1.second >= p2.second;
		}));
	list1->SetSort(ptr2);
	list1->Sort();

	EXPECT_EQ(list1->Get(0).second, 'a');
	EXPECT_EQ(list1->Get(8).second, 'h');
}

TEST(Sort, TestArraySelectionSort)
{
	shared_ptr<ArrayList<pair<int, char>>> list1(new ArrayList<pair<int, char>>());
	list1->PushBack(std::pair<int, char>(4, 'f'));
	list1->PushBack(std::pair<int, char>(5, 'a'));
	list1->PushBack(std::pair<int, char>(3, 'g'));
	list1->PushBack(std::pair<int, char>(7, 'e'));
	list1->PushBack(std::pair<int, char>(1, 'g'));
	list1->PushBack(std::pair<int, char>(0, 'c'));
	list1->PushBack(std::pair<int, char>(8, 'h'));
	list1->PushBack(std::pair<int, char>(10, 'b'));
	list1->PushBack(std::pair<int, char>(2, 'd'));

	shared_ptr<ArraySelectionSort<pair<int, char>>> ptr1(new ArraySelectionSort<pair<int, char>>(
		[](std::pair<int, char> p1,
			std::pair<int, char> p2)
		{
			return p1.first >= p2.first;
		}));
	list1->SetSort(ptr1);
	list1->Sort();

	EXPECT_EQ(list1->Get(0).first, 0);
	EXPECT_EQ(list1->Get(8).first, 10);

	shared_ptr<ArraySelectionSort<pair<int, char>>> ptr2(new ArraySelectionSort<pair<int, char>>(
		[](std::pair<int, char> p1,
			std::pair<int, char> p2)
		{
			return p1.second >= p2.second;
		}));
	list1->SetSort(ptr2);
	list1->Sort();

	EXPECT_EQ(list1->Get(0).second, 'a');
	EXPECT_EQ(list1->Get(8).second, 'h');
}

TEST(Sort, TestArrayQuickSort)
{
	shared_ptr<ArrayList<pair<int, char>>> list1(new ArrayList<pair<int, char>>());
	list1->PushBack(std::pair<int, char>(4, 'f'));
	list1->PushBack(std::pair<int, char>(5, 'a'));
	list1->PushBack(std::pair<int, char>(3, 'g'));
	list1->PushBack(std::pair<int, char>(7, 'e'));
	list1->PushBack(std::pair<int, char>(1, 'g'));
	list1->PushBack(std::pair<int, char>(0, 'c'));
	list1->PushBack(std::pair<int, char>(8, 'h'));
	list1->PushBack(std::pair<int, char>(10, 'b'));
	list1->PushBack(std::pair<int, char>(2, 'd'));

	shared_ptr<ArrayQuickSort<pair<int, char>>> ptr1(new ArrayQuickSort<pair<int, char>>(
		[](std::pair<int, char> p1,
			std::pair<int, char> p2)
		{
			return p1.first >= p2.first;
		}));
	list1->SetSort(ptr1);
	list1->Sort();

	EXPECT_EQ(list1->Get(0).first, 0);
	EXPECT_EQ(list1->Get(8).first, 10);

	shared_ptr<ArrayQuickSort<pair<int, char>>> ptr2(new ArrayQuickSort<pair<int, char>>(
		[](std::pair<int, char> p1,
			std::pair<int, char> p2)
		{
			return p1.second >= p2.second;
		}));
	list1->SetSort(ptr2);
	list1->Sort();

	EXPECT_EQ(list1->Get(0).second, 'a');
	EXPECT_EQ(list1->Get(8).second, 'h');
}

TEST(Sort, TestArrayMergeSort)
{
	shared_ptr<ArrayList<pair<int, char>>> list1(new ArrayList<pair<int, char>>());
	list1->PushBack(std::pair<int, char>(4, 'f'));
	list1->PushBack(std::pair<int, char>(5, 'a'));
	list1->PushBack(std::pair<int, char>(3, 'g'));
	list1->PushBack(std::pair<int, char>(7, 'e'));
	list1->PushBack(std::pair<int, char>(1, 'g'));
	list1->PushBack(std::pair<int, char>(0, 'c'));
	list1->PushBack(std::pair<int, char>(8, 'h'));
	list1->PushBack(std::pair<int, char>(10, 'b'));
	list1->PushBack(std::pair<int, char>(2, 'd'));

	shared_ptr<ArrayMergeSort<pair<int, char>>> ptr1(new ArrayMergeSort<pair<int, char>>(
		[](std::pair<int, char> p1,
			std::pair<int, char> p2)
		{
			return p1.first >= p2.first;
		}));
	list1->SetSort(ptr1);
	list1->Sort();

	EXPECT_EQ(list1->Get(0).first, 0);
	EXPECT_EQ(list1->Get(8).first, 10);

	shared_ptr<ArrayMergeSort<pair<int, char>>> ptr2(new ArrayMergeSort<pair<int, char>>(
		[](std::pair<int, char> p1,
			std::pair<int, char> p2)
		{
			return p1.second >= p2.second;
		}));
	list1->SetSort(ptr2);
	list1->Sort();

	EXPECT_EQ(list1->Get(0).second, 'a');
	EXPECT_EQ(list1->Get(8).second, 'h');
}

TEST(Sort, TestArrayCountingSort)
{
	shared_ptr<ArrayList<pair<int, char>>> list1(new ArrayList<pair<int, char>>());
	list1->PushBack(std::pair<int, char>(4, 'f'));
	list1->PushBack(std::pair<int, char>(5, 'a'));
	list1->PushBack(std::pair<int, char>(3, 'g'));
	list1->PushBack(std::pair<int, char>(7, 'e'));
	list1->PushBack(std::pair<int, char>(1, 'g'));
	list1->PushBack(std::pair<int, char>(0, 'c'));
	list1->PushBack(std::pair<int, char>(8, 'h'));
	list1->PushBack(std::pair<int, char>(10, 'b'));
	list1->PushBack(std::pair<int, char>(2, 'd'));

	shared_ptr<ArrayCountingSort<pair<int, char>>> ptr1(new ArrayCountingSort<pair<int, char>>(
		[](std::pair<float, char> p1)
		{
			return p1.first;
		}));
	list1->SetSort(ptr1);
	list1->Sort();

	EXPECT_EQ(list1->Get(0).first, 0);
	EXPECT_EQ(list1->Get(8).first, 10);
}

TEST(Sort, TestArrayBucketSort)
{
	shared_ptr<ArrayList<pair<float, char>>> list1(new ArrayList<pair<float, char>>());
	list1->PushBack(pair<float, char>(0.4, 'f'));
	list1->PushBack(pair<float, char>(0.5, 'a'));
	list1->PushBack(pair<float, char>(0.3, 'g'));
	list1->PushBack(pair<float, char>(0.7, 'e'));
	list1->PushBack(pair<float, char>(0.1, 'g'));
	list1->PushBack(pair<float, char>(0.0, 'c'));
	list1->PushBack(pair<float, char>(0.8, 'h'));
	list1->PushBack(pair<float, char>(0.1, 'b'));
	list1->PushBack(pair<float, char>(0.2, 'd'));

	shared_ptr<ArrayBucketSort<pair<float, char>>> ptr1(new ArrayBucketSort<pair<float, char>>(
		[](std::pair<float, char> p1)
		{
			return p1.first;
		}));
	list1->SetSort(ptr1);
	list1->Sort();

	EXPECT_FLOAT_EQ(list1->Get(0).first, 0.0);
	EXPECT_FLOAT_EQ(list1->Get(8).first, 0.8);
}