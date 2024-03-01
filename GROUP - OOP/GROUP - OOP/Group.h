#pragma once
#include "Student.h"
#include <set>

class Group {
private:
    unsigned short countstudent = 0;
    set<Student> classmates;
    string group_name;
    string specification;
    unsigned short number_of_course;
public:
    Group();

    void Print();
    void AddStudent(const Student& new_student);
    void WeanStudent(const Student& delete_student);
    void Expel();
    void SetCountOfStudent(int countstudent);
    int GetCountOfStudent()const;
    void SetGroupName(string group_name);
    string GetGroupName() const;
    void SetSpecification(string specification);
    string GetSpecification() const;
    void SetNumberOfCourse(int number_of_course);
    int GetNumberOfCourse() const;

    Group& operator += (const Student& s)
    {
        AddStudent(s);
        return *this;
    }

    operator string()
    {
        return group_name + "\n" + specification + "\n" + to_string(number_of_course) + "\n" + to_string(countstudent);
    }
};