#include "pch.h"

TEST(CreationTests, CreateEmptyList) 
{
	// Create a list
	LinkedList l;

	// Better not be empty
	EXPECT_TRUE(l.isEmpty());
}