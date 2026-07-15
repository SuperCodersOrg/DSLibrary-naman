#include <gtest/gtest.h>
#include <string>
#include "linkedList.h"

class Student
{
public:
    int rollNo;
    std::string name;

    Student()
    {
        rollNo = 0;
        name = "";
    }

    Student(int rollNo, const std::string& name)
    {
        this->rollNo = rollNo;
        this->name = name;
    }

    bool operator==(const Student& other) const
    {
        return rollNo == other.rollNo &&
               name == other.name;
    }
};

TEST(LinkedListUserDefinedTest, InsertBackStoresObjects)
{
    LinkedList<Student> list;

    list.insertBack(Student(1, "Alice"));
    list.insertBack(Student(2, "Bob"));

    EXPECT_EQ(list.size(), 2);

    EXPECT_EQ(list.getHead()->value.rollNo, 1);
    EXPECT_EQ(list.getHead()->value.name, "Alice");

    EXPECT_EQ(list.getTail()->value.rollNo, 2);
    EXPECT_EQ(list.getTail()->value.name, "Bob");
}

TEST(LinkedListUserDefinedTest, InsertFrontStoresObjects)
{
    LinkedList<Student> list;

    list.insertFront(Student(1, "Alice"));
    list.insertFront(Student(2, "Bob"));

    EXPECT_EQ(list.size(), 2);

    EXPECT_EQ(list.getHead()->value.rollNo, 2);
    EXPECT_EQ(list.getTail()->value.rollNo, 1);
}

TEST(LinkedListUserDefinedTest, SearchFindsExistingObject)
{
    LinkedList<Student> list;

    list.insertBack(Student(1, "Alice"));
    list.insertBack(Student(2, "Bob"));

    EXPECT_TRUE(list.search(Student(2, "Bob")));
}

TEST(LinkedListUserDefinedTest, SearchReturnsFalseForMissingObject)
{
    LinkedList<Student> list;

    list.insertBack(Student(1, "Alice"));

    EXPECT_FALSE(list.search(Student(5, "Charlie")));
}

TEST(LinkedListUserDefinedTest, RemoveDeletesCorrectObject)
{
    LinkedList<Student> list;

    list.insertBack(Student(1, "Alice"));
    list.insertBack(Student(2, "Bob"));

    list.remove(Student(1, "Alice"));

    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.getHead()->value.rollNo, 2);
}

TEST(LinkedListUserDefinedTest, CopyConstructorCopiesObjects)
{
    LinkedList<Student> original;

    original.insertBack(Student(1, "Alice"));
    original.insertBack(Student(2, "Bob"));

    LinkedList<Student> copy(original);

    EXPECT_EQ(copy.size(), original.size());

    EXPECT_EQ(copy.getHead()->value.rollNo, 1);
    EXPECT_EQ(copy.getTail()->value.rollNo, 2);
}

TEST(LinkedListUserDefinedTest, CopyConstructorPerformsDeepCopy)
{
    LinkedList<Student> original;

    original.insertBack(Student(1, "Alice"));

    LinkedList<Student> copy(original);

    copy.getHead()->value.name = "Charlie";

    EXPECT_EQ(original.getHead()->value.name, "Alice");
    EXPECT_EQ(copy.getHead()->value.name, "Charlie");
}

TEST(LinkedListUserDefinedTest, AssignmentOperatorCopiesObjects)
{
    LinkedList<Student> original;

    original.insertBack(Student(10, "Rahul"));
    original.insertBack(Student(20, "Aman"));

    LinkedList<Student> copy;

    copy = original;

    EXPECT_EQ(copy.size(), original.size());

    EXPECT_EQ(copy.getHead()->value.rollNo, 10);
    EXPECT_EQ(copy.getTail()->value.rollNo, 20);
}

TEST(LinkedListUserDefinedTest, AssignmentOperatorPerformsDeepCopy)
{
    LinkedList<Student> original;

    original.insertBack(Student(1, "Alice"));

    LinkedList<Student> copy;

    copy = original;

    copy.getHead()->value.name = "Bob";

    EXPECT_EQ(original.getHead()->value.name, "Alice");
    EXPECT_EQ(copy.getHead()->value.name, "Bob");
}

TEST(LinkedListUserDefinedTest, SelfAssignment)
{
    LinkedList<Student> list;

    list.insertBack(Student(1, "Alice"));
    list.insertBack(Student(2, "Bob"));

    list = list;

    EXPECT_EQ(list.size(), 2);

    EXPECT_EQ(list.getHead()->value.rollNo, 1);
    EXPECT_EQ(list.getTail()->value.rollNo, 2);
}

TEST(LinkedListUserDefinedTest, CopyAndOriginalRemainIndependent)
{
    LinkedList<Student> original;

    original.insertBack(Student(1, "Alice"));

    LinkedList<Student> copy(original);

    copy.insertBack(Student(2, "Bob"));

    EXPECT_EQ(original.size(), 1);
    EXPECT_EQ(copy.size(), 2);
}

TEST(LinkedListUserDefinedTest, RemoveLastObject)
{
    LinkedList<Student> list;

    list.insertBack(Student(1, "Alice"));

    list.remove(Student(1, "Alice"));

    EXPECT_EQ(list.size(), 0);
    EXPECT_EQ(list.getHead(), nullptr);
    EXPECT_EQ(list.getTail(), nullptr);
}