#include <gtest/gtest.h>
#include <string>
#include "dynamicArray.h"

class Student
{
public:
    int id;
    std::string name;

    Student()
    {
        id = 0;
        name = "";
    }

    Student(int id, const std::string& name)
    {
        this->id = id;
        this->name = name;
    }

    bool operator==(const Student& other) const
    {
        return id == other.id && name == other.name;
    }
};

TEST(DynamicArrayUserDefinedTypeTest, AppendUserDefinedObjects)
{
    DynamicArray<Student> students;

    students.append(Student(1, "Alice"));
    students.append(Student(2, "Bob"));

    EXPECT_EQ(students.getSize(), 2);

    EXPECT_EQ(students[0].id, 1);
    EXPECT_EQ(students[0].name, "Alice");

    EXPECT_EQ(students[1].id, 2);
    EXPECT_EQ(students[1].name, "Bob");
}

TEST(DynamicArrayUserDefinedTypeTest, CopyConstructorCopiesObjects)
{
    DynamicArray<Student> original;

    original.append(Student(1, "Alice"));
    original.append(Student(2, "Bob"));

    DynamicArray<Student> copy(original);

    EXPECT_EQ(copy.getSize(), original.getSize());

    EXPECT_EQ(copy[0], Student(1, "Alice"));
    EXPECT_EQ(copy[1], Student(2, "Bob"));
}

TEST(DynamicArrayUserDefinedTypeTest, CopyConstructorPerformsDeepCopy)
{
    DynamicArray<Student> original;

    original.append(Student(1, "Alice"));

    DynamicArray<Student> copy(original);

    copy[0].name = "Charlie";

    EXPECT_EQ(original[0].name, "Alice");
    EXPECT_EQ(copy[0].name, "Charlie");
}

TEST(DynamicArrayUserDefinedTypeTest, AssignmentOperatorCopiesObjects)
{
    DynamicArray<Student> original;

    original.append(Student(10, "Rahul"));
    original.append(Student(20, "Aman"));

    DynamicArray<Student> copy;

    copy = original;

    EXPECT_EQ(copy.getSize(), original.getSize());

    EXPECT_EQ(copy[0], Student(10, "Rahul"));
    EXPECT_EQ(copy[1], Student(20, "Aman"));
}

TEST(DynamicArrayUserDefinedTypeTest, AssignmentOperatorPerformsDeepCopy)
{
    DynamicArray<Student> original;

    original.append(Student(1, "Alice"));

    DynamicArray<Student> copy;

    copy = original;

    copy[0].name = "Bob";

    EXPECT_EQ(original[0].name, "Alice");
    EXPECT_EQ(copy[0].name, "Bob");
}

TEST(DynamicArrayUserDefinedTypeTest, SelfAssignment)
{
    DynamicArray<Student> students;

    students.append(Student(1, "Alice"));
    students.append(Student(2, "Bob"));

    students = students;

    EXPECT_EQ(students.getSize(), 2);

    EXPECT_EQ(students[0], Student(1, "Alice"));
    EXPECT_EQ(students[1], Student(2, "Bob"));
}

TEST(DynamicArrayUserDefinedTypeTest, ResizePreservesObjects)
{
    DynamicArray<Student> students;

    for (int i = 0; i < 100; i++)
    {
        students.append(Student(i, "Student"));
    }

    EXPECT_EQ(students.getSize(), 100);

    for (int i = 0; i < 100; i++)
    {
        EXPECT_EQ(students[i].id, i);
        EXPECT_EQ(students[i].name, "Student");
    }
}

TEST(DynamicArrayUserDefinedTypeTest, CopyAndOriginalRemainIndependent)
{
    DynamicArray<Student> original;

    original.append(Student(1, "Alice"));
    original.append(Student(2, "Bob"));

    DynamicArray<Student> copy(original);

    copy.append(Student(3, "Charlie"));

    EXPECT_EQ(original.getSize(), 2);
    EXPECT_EQ(copy.getSize(), 3);

    EXPECT_EQ(copy[2], Student(3, "Charlie"));
}

TEST(DynamicArrayUserDefinedTypeTest, EmptyArrayCopyConstructor)
{
    DynamicArray<Student> original;

    DynamicArray<Student> copy(original);

    EXPECT_EQ(copy.getSize(), 0);
    EXPECT_EQ(copy.getCapacity(), original.getCapacity());
}

TEST(DynamicArrayUserDefinedTypeTest, EmptyArrayAssignmentOperator)
{
    DynamicArray<Student> original;

    DynamicArray<Student> copy;

    copy = original;

    EXPECT_EQ(copy.getSize(), 0);
    EXPECT_EQ(copy.getCapacity(), original.getCapacity());
}