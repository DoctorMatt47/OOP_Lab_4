#include "pch.h"

#include "Tests/ArrayList.Tests.h"
#include "Tests/LinkedList.Tests.h"
#include "Tests/ListSorter.Tests.h"
#include "Tests/Sorts.Tests.h"
#include "Tests/VectorList.Tests.h"

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}