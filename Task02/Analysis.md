# Task 2 – University People Management

## Task 2.1 – Identify the Relationships

### 1. Person and Student
Student inherits from Person because every student is a person. This is an **is-a relationship** and uses single inheritance.

### 2. Person and Staff
Staff inherits from Person because every staff member is a person. This is an **is-a relationship** and uses single inheritance.

### 3. Student and Staff
TeachingAssistant inherits from both Student and Staff because a teaching assistant is both a student and a staff member. This is an **is-a relationship** and uses multiple inheritance.

### 4. Student and ResearchScholar
ResearchScholar inherits from Student because every research scholar is a student with additional fellowship information. This is an **is-a relationship** and uses single inheritance. Together with the Person-to-Student relationship, it forms multilevel inheritance.

### Overall Inheritance Type

The complete design uses **hybrid inheritance** because it combines hierarchical, multiple and multilevel inheritance.

### Relationship Summary

| Classes | Relationship | Inheritance type |
|---|---|---|
| Person → Student | Is-a | Single |
| Person → Staff | Is-a | Single |
| Student and Staff → TeachingAssistant | Is-a | Multiple |
| Student → ResearchScholar | Is-a | Single / Multilevel chain |

## Conclusion

The university people management system uses inheritance to represent common and specialised information. The hierarchy reduces repeated data and supports different categories of university members.
## Task 2.2 – Resolve the Diamond Problem

### Diamond Problem

The diamond problem occurs when a class inherits from two classes that share the same base class.

In this system:
- Student inherits from Person.
- Staff inherits from Person.
- TeachingAssistant inherits from both Student and Staff.

Without virtual inheritance, TeachingAssistant receives two separate copies of Person. This creates ambiguity when accessing common members such as name, ID and phone number.

### Solution – Virtual Base Class

We can solve this problem by using the `virtual` keyword while inheriting Person.

```cpp
class Person
{
public:
    string name;
    int id;
    string phone;
};

class Student : virtual public Person
{
public:
    string programme;
    double cgpa;
};

class Staff : virtual public Person
{
public:
    string department;
    double salary;
};

class TeachingAssistant : public Student, public Staff
{
};
```

### Advantages of Virtual Inheritance

1. Only one shared Person subobject is created in TeachingAssistant.
2. Duplicate copies of common data are avoided.
3. Ambiguity when accessing Person members is resolved.
4. Memory duplication is reduced.

### Conclusion

Virtual inheritance solves the diamond problem by ensuring that Student and Staff share a single Person base-class subobject inside TeachingAssistant.
