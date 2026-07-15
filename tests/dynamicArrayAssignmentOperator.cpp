#include <gtest/gtest.h>
#include "dynamicArray.h"

TEST(DynamicArrayTest, AssignmentOperatorCopiesSize)
{
    DynamicArray<int> original;

    original.append(10);
    original.append(20);
    original.append(30);

    DynamicArray<int> copy;
    copy = original;

    EXPECT_EQ(copy.getSize(), original.getSize());
}

TEST(DynamicArrayTest, AssignmentOperatorCopiesCapacity)
{
    DynamicArray<int> original;

    for (int i = 0; i < 10; i++)
    {
        original.append(i);
    }

    DynamicArray<int> copy;
    copy = original;

    EXPECT_EQ(copy.getCapacity(), original.getCapacity());
}

TEST(DynamicArrayTest, AssignmentOperatorCopiesElements)
{
    DynamicArray<int> original;

    original.append(5);
    original.append(15);
    original.append(25);

    DynamicArray<int> copy;
    copy = original;

    EXPECT_EQ(copy[0], 5);
    EXPECT_EQ(copy[1], 15);
    EXPECT_EQ(copy[2], 25);
}

TEST(DynamicArrayTest, AssignmentOperatorPerformsDeepCopy)
{
    DynamicArray<int> original;

    original.append(1);
    original.append(2);
    original.append(3);

    DynamicArray<int> copy;
    copy = original;

    copy[0] = 100;

    EXPECT_EQ(original[0], 1);
    EXPECT_EQ(copy[0], 100);
}

TEST(DynamicArrayTest, AssignmentOperatorHandlesEmptyArray)
{
    DynamicArray<int> original;

    DynamicArray<int> copy;
    copy = original;

    EXPECT_EQ(copy.getSize(), 0);
    EXPECT_EQ(copy.getCapacity(), original.getCapacity());
}

TEST(DynamicArrayTest, AssignmentOperatorCreatesIndependentObject)
{
    DynamicArray<int> original;

    original.append(10);
    original.append(20);

    DynamicArray<int> copy;
    copy = original;

    copy.append(30);

    EXPECT_EQ(original.getSize(), 2);
    EXPECT_EQ(copy.getSize(), 3);

    EXPECT_EQ(original[0], 10);
    EXPECT_EQ(original[1], 20);

    EXPECT_EQ(copy[2], 30);
}

TEST(DynamicArrayTest, AssignmentOperatorHandlesSelfAssignment)
{
    DynamicArray<int> array;

    array.append(10);
    array.append(20);
    array.append(30);

    array = array;

    EXPECT_EQ(array.getSize(), 3);
    EXPECT_EQ(array[0], 10);
    EXPECT_EQ(array[1], 20);
    EXPECT_EQ(array[2], 30);
}