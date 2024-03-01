#include "Student.h"

Student::Student() : Student("Studenchenko", "Student", "Studentovich", "Studencheskaya 38", "0630300033") { count++; }

Student::Student(string surname, string name, string middlname, string adress, string phonenumber)
{
    count++;
    SetSurname(surname);
    SetName(name);
    SetMiddlName(middlname);
    SetAdress(adress);
    SetPhone(phonenumber);

}

Student::Student(string surname, string name, string middlname, string adress) :Student(surname, name, middlename, adress, "0687680685") { count++;  }

Student::~Student()
{
    count--;
}

void Student::PrintStudent() 
{
    cout << "Surname:    " << surname << "\n";
    cout << "Name:       " << name << "\n";
    cout << "Midlname:   " << middlename << "\n";
    cout << "Adress:     " << adress << "\n";
    cout << "Phonnumber: " << phonenumber << "\n";
    PrintExam();
    PrintHomeWork();
    PrintPractic();

}
unsigned int Student::GetCount()
{
    return count;
}
void Student::AddPractic(int new_practic)
{
    grade_of_practic.push_back(new_practic);
}

void Student::PrintPractic() const
{
    cout << "Practic: ";
    for (int i = 0; i < grade_of_practic.size(); i++)
    {
        cout << grade_of_practic[i] << ", ";
    }
    cout << "\n";
}

int Student::GePracticRatesCount(unsigned int index) const
{
    return grade_of_practic.at(index);
}

void Student::AddHomeWork(int new_home_work)
{
    grade_of_homework.push_back(new_home_work);
}

void Student::PrintHomeWork() const
{
    cout << "HomeWork: ";
    for (int i = 0; i < grade_of_homework.size(); i++)
    {
        cout << grade_of_homework[i] << ", ";
    }
    cout << "\n";
}

int Student::GetHomeWorkRatesCount(unsigned int index) const
{
    return grade_of_homework.at(index);
}

void Student::AddExam(int new_exam)
{
    grade_of_exam.push_back(new_exam);
}

void  Student::AverageGrade()
{

    for (int i = 0; i < grade_of_exam.size(); i++)
    {
        average_grade += grade_of_exam[i] / grade_of_exam.size();
    }
    cout << average_grade << "\n";
}

void Student::PrintExam() const
{
    cout << "Exam: ";
    for (int i = 0; i < grade_of_exam.size(); i++)
    {
        cout << grade_of_exam[i] << ", ";
    }
    cout << "\n";
}

int Student::GetExamRatesCount(unsigned int index) const
{
    return grade_of_exam.at(index);
}

void Student::SetSurname(string surname)
{
    this->surname = surname;
}

string Student::GetSurname() const
{
    return surname;
}

void Student::SetName(string name)
{
    this->name = name;
}

string Student::GetName() const
{
    return name;
}

void Student::SetMiddlName(string middlname)
{
    this->middlename = middlname;
}

string Student::GetMiddlName() const
{
    return middlename;
}

void Student::SetAdress(string adress)
{
    this->adress = adress;
}

string Student::GetAdress() const
{
    return adress;
}

void Student::SetPhone(string phonenumber)
{
    this->phonenumber = phonenumber;
}

string Student::GetPhone() const
{
    return phonenumber;
}
void Student::SetAverageGrade(int average_grade)
{
    this->average_grade = average_grade;
}
int Student::GetAverageGrade() const
{
    return average_grade;
}

unsigned int Student::count;