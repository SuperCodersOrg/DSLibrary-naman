#include <gtest/gtest.h>
#include "linkedList.h"

TEST(LinkedListConstructorTest, ArrayConstructorCreatesCorrectList)
{
    int arr[] = {10, 20, 30, 40};

    LinkedList<int> list(arr, 4);

    EXPECT_EQ(list.size(), 4);
    EXPECT_EQ(list.getHead()->value, 10);
    EXPECT_EQ(list.getTail()->value, 40);
}

TEST(LinkedListConstructorTest, ArrayConstructorHandlesSingleElement)
{
    int arr[] = {100};

    LinkedList<int> list(arr, 1);

    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.getHead()->value, 100);
    EXPECT_EQ(list.getTail()->value, 100);
}

TEST(LinkedListConstructorTest, ArrayConstructorHandlesEmptyArray)
{
    int arr[1];

    LinkedList<int> list(arr, 0);

    EXPECT_EQ(list.size(), 0);
    EXPECT_EQ(list.getHead(), nullptr);
    EXPECT_EQ(list.getTail(), nullptr);
}

TEST(LinkedListConstructorTest, ArrayConstructorPreservesOrder)
{
    int arr[] = {5, 15, 25, 35, 45};

    LinkedList<int> list(arr, 5);

    Node<int>* temp = list.getHead();

    EXPECT_EQ(temp->value, 5);
    temp = temp->next;

    EXPECT_EQ(temp->value, 15);
    temp = temp->next;

    EXPECT_EQ(temp->value, 25);
    temp = temp->next;

    EXPECT_EQ(temp->value, 35);
    temp = temp->next;

    EXPECT_EQ(temp->value, 45);
}

TEST(LinkedListConstructorTest, CopyConstructorCopiesSize)
{
    LinkedList<int> original;

    original.insertBack(10);
    original.insertBack(20);
    original.insertBack(30);

    LinkedList<int> copy(original);

    EXPECT_EQ(copy.size(), original.size());
}

TEST(LinkedListConstructorTest, CopyConstructorCopiesElements)
{
    LinkedList<int> original;

    original.insertBack(1);
    original.insertBack(2);
    original.insertBack(3);

    LinkedList<int> copy(original);

    Node<int>* a = original.getHead();
    Node<int>* b = copy.getHead();

    while (a != nullptr)
    {
        EXPECT_EQ(a->value, b->value);

        a = a->next;
        b = b->next;
    }
}

TEST(LinkedListConstructorTest, CopyConstructorCreatesDeepCopy)
{
    LinkedList<int> original;

    original.insertBack(10);
    original.insertBack(20);

    LinkedList<int> copy(original);

    copy.getHead()->value = 100;

    EXPECT_EQ(original.getHead()->value, 10);
    EXPECT_EQ(copy.getHead()->value, 100);
}

TEST(LinkedListConstructorTest, CopyConstructorCreatesIndependentNodes)
{
    LinkedList<int> original;

    original.insertBack(1);
    original.insertBack(2);

    LinkedList<int> copy(original);

    EXPECT_NE(original.getHead(), copy.getHead());
    EXPECT_NE(original.getTail(), copy.getTail());
}

TEST(LinkedListConstructorTest, CopyConstructorHandlesEmptyList)
{
    LinkedList<int> original;

    LinkedList<int> copy(original);

    EXPECT_EQ(copy.size(), 0);
    EXPECT_EQ(copy.getHead(), nullptr);
    EXPECT_EQ(copy.getTail(), nullptr);
}

TEST(LinkedListConstructorTest, CopyConstructorIndependentInsertion)
{
    LinkedList<int> original;

    original.insertBack(10);
    original.insertBack(20);

    LinkedList<int> copy(original);

    copy.insertBack(30);

    EXPECT_EQ(original.size(), 2);
    EXPECT_EQ(copy.size(), 3);

    EXPECT_EQ(original.getTail()->value, 20);
    EXPECT_EQ(copy.getTail()->value, 30);
}