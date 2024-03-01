#include "Group.h"
#include <set>
#include <algorithm>

    Group::Group()
    {
        SetGroupName("P26");
        SetNumberOfCourse(2);
        SetSpecification("Software Development");
    }

    void Group::Print() 
    {
        cout << group_name << "\n";

        for ( auto current : classmates)
        {
            current.PrintStudent();
            current.AverageGrade();
        }
    }

    void Group::AddStudent(const Student& new_student)
    {
        countstudent++;
        classmates.insert(new_student);
        
    }

    void Group::WeanStudent(const Student& delete_student)
    {
        countstudent--;
        classmates.erase(delete_student);
    }

    void Group::Expel()
    {
        if (countstudent == 0) {
            cout << "The group is empty.\n\n";
            return;
        }
        auto minGradeStudent = classmates.begin();

        for (const auto& current : classmates)
        {
            if (current.GetAverageGrade() < minGradeStudent->GetAverageGrade())
            {
                minGradeStudent = classmates.find(current);
            }
        }
        WeanStudent(*minGradeStudent);
        cout << "The student with the lowest grade point average is expelled from the group.\n\n";
    }

    void Group::SetCountOfStudent(int countstudent)
    {
        this->countstudent = countstudent;
    }

    int Group::GetCountOfStudent() const
    {
        return countstudent;
    }

    void Group::SetGroupName(string group_name)
    {
        this->group_name = group_name;
    }

    string Group::GetGroupName() const
    {
        return group_name;
    }

    void Group::SetSpecification(string specification)
    {
        this->specification = specification;
    }

    string Group::GetSpecification() const
    {
        return specification;
    }

    void Group::SetNumberOfCourse(int number_of_course)
    {
        this->number_of_course = number_of_course;
    }

    int Group::GetNumberOfCourse() const
    {
        return number_of_course;
    }