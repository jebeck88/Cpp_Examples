
#include "pch.h"

#include "ListTestHelper.h"

void ListTestHelper::assertLength(const List& l, int length)
{
    EXPECT_EQ(l.size(), length);

    if (length > 0)
    {
        EXPECT_FALSE(l.isEmpty());
    }
    else
    {
        EXPECT_TRUE(l.isEmpty());
    }
}

void ListTestHelper::assertEmpty(const List& l)
{
    ListTestHelper::assertLength(l, 0);
}

void ListTestHelper::assertElement(const List& l, int index, const std::string& expectedValue)
{
    const auto& value = l.get(index);

    EXPECT_EQ(value, expectedValue);
}

void ListTestHelper::testList(List& l)
{
    // Make sure it's empty
    ListTestHelper::assertEmpty(l);

    // Test addFront
    ListTestHelper::testAddFront(l, "c");
    ListTestHelper::testAddFront(l, "b");
    ListTestHelper::testAddFront(l, "a");
    ListTestHelper::testAddFront(l, "aa");

    // Test addBack
    ListTestHelper::testAddBack(l, "x");
    ListTestHelper::testAddBack(l, "y");
    ListTestHelper::testAddBack(l, "z");
    ListTestHelper::testAddBack(l, "zz");

    // Test add at front, back and middle
    ListTestHelper::testAdd(l, 0, "front");
    ListTestHelper::testAdd(l, l.size(), "back");
    ListTestHelper::testAdd(l, 2, "index-2");

    // Test removeFront
    ListTestHelper::testRemoveFront(l);
    ListTestHelper::testRemoveFront(l);

    // Test removeBack
    ListTestHelper::testRemoveBack(l);
    ListTestHelper::testRemoveBack(l);

    // Test remove at front back and middle
    ListTestHelper::testRemove(l, 0);
    ListTestHelper::testRemove(l, 1);
    ListTestHelper::testRemove(l, l.size() - 1);

    // Test get at front, back, middle and outside range
    ListTestHelper::testGet(l, 0, "a");
    ListTestHelper::testGet(l, l.size() - 1, "y");
    ListTestHelper::testGet(l, 1000);
    ListTestHelper::testGet(l, -1);

}

void ListTestHelper::testAdd(List& list, int index, const std::string value)
{
    int initialSize = list.size();

    list.add(index, value);

    ListTestHelper::assertLength(list, initialSize + 1);
    ListTestHelper::assertElement(list, index, value);
}

void ListTestHelper::testAddFront(List& list, const std::string value)
{
    int initialSize = list.size();

    list.addFront(value);

    ListTestHelper::assertLength(list, initialSize + 1);
    ListTestHelper::assertElement(list, 0, value);
}

void ListTestHelper::testAddBack(List& list, const std::string value)
{
    int initialSize = list.size();

    list.addBack(value);

    ListTestHelper::assertLength(list, initialSize + 1);
    ListTestHelper::assertElement(list, list.size()-1, value);
}

void ListTestHelper::testRemove(List& list, int index)
{
    int initialSize = list.size();

    const bool hasNextValue = index < list.size() - 1;

    const std::string value = list.get(index);
    const std::string nextValue = (hasNextValue) ? list.get(index + 1) : "";

    list.remove(index);

    ListTestHelper::assertLength(list, initialSize - 1);

    if (hasNextValue)
    {
        ListTestHelper::assertElement(list, index, nextValue);
    }
}

void ListTestHelper::testRemoveFront(List& list)
{
    int initialSize = list.size();

    const bool hasNext = initialSize > 1;
    const std::string nextValue = hasNext ? list.get(1) : "";

    list.removeFront();

    ListTestHelper::assertLength(list, initialSize - 1);

    if (hasNext)
    {
        EXPECT_EQ(list.get(0), nextValue);
    }
}

void ListTestHelper::testRemoveBack(List& list)
{
    int initialSize = list.size();

    const bool hasPrev = initialSize > 1;
    const std::string prevValue = hasPrev ? list.get(initialSize-2) : "";

    list.removeBack();

    ListTestHelper::assertLength(list, initialSize - 1);

    if (hasPrev)
    {
        EXPECT_EQ(list.get(list.size()-1), prevValue);
    }
}

void ListTestHelper::testGet(const List& list, int index, const std::string expectedValue)
{
    if (index < 0 || index > list.size() - 1)
    {
        EXPECT_ANY_THROW(list.get(index));
    }

    else
    {
        EXPECT_EQ(list.get(index), expectedValue);
    }
}

void ListTestHelper::testClear(List& list)
{
    list.clear();

    ListTestHelper::assertEmpty(list);
}
