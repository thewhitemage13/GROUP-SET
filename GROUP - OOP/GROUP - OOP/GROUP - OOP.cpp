using namespace std;
#include "Student.h"
#include "Date.h"
#include "Group.h"
#include "Fraction.h"

int operator - (const Date& date_now, const Date& other_date)
{
    int thisDays = date_now.GetDay() + 31 * (date_now.GetMonth() - 1);
    int otherDays = other_date.GetDay() + 31 * (other_date.GetMonth() - 1);

    thisDays += (date_now.GetYear() % 4 == 0 && date_now.GetMonth() > 2);
    otherDays += (other_date.GetYear() % 4 == 0 && other_date.GetMonth() > 2);

    thisDays += (date_now.GetMonth() > 1);
    otherDays += (other_date.GetMonth() > 1);

    thisDays += date_now.GetMonth() / 2 + ((date_now.GetMonth() % 2 == 0 && date_now.GetMonth() > 7));
    otherDays += other_date.GetMonth() / 2 + ((other_date.GetMonth() % 2 == 0 && other_date.GetMonth() > 7));

    thisDays += 365 * (date_now.GetYear() - 1);
    otherDays += 365 * (other_date.GetYear() - 1);

    return thisDays - otherDays;
}
//Student
bool operator > (const Student& a, const Student& b)
{
    return a.GetAverageGrade() > b.GetAverageGrade();
}

bool operator<(const Student& left, const Student& right)
{
    return left.GetAverageGrade() < right.GetAverageGrade();
}

bool operator >= (const Student& a, const Student& b)
{
    return a.GetAverageGrade() > b.GetAverageGrade();
}

bool operator <= (const Student& a, const Student& b)
{
    return a.GetAverageGrade() <= b.GetAverageGrade();
}

bool operator == (const Student& a, const Student& b)
{
    return a.GetAverageGrade() == b.GetAverageGrade();
}

bool operator != (const Student& a, const Student& b)
{
    return a.GetAverageGrade() != b.GetAverageGrade();
}
//Group: 
bool operator > (const Group& a, const  Group& b)
{
    return a.GetCountOfStudent() > b.GetCountOfStudent();
}

bool operator < (const Group& left, const Group& right) 
{
    return left.GetCountOfStudent() < right.GetCountOfStudent();
}

bool operator >= (const Group& a, const  Group& b)
{
    return a.GetCountOfStudent() >= b.GetCountOfStudent();
}

bool operator <= (const Group& a, const  Group& b)
{
    return a.GetCountOfStudent() <= b.GetCountOfStudent();
}

bool operator == (const Group& a, const Group& b)
{
    return a.GetCountOfStudent() == b.GetCountOfStudent();
}

bool operator != (const Group& a, const Group& b)
{
    return a.GetCountOfStudent() != b.GetCountOfStudent();
}
//Student
istream& operator >> (const istream& i, Student& d)
{
    cout << "surname: ";
    string answear;
    cin >> answear;
    d.SetSurname(answear);
    
    cout << "name: ";
    cin >> answear;
    d.SetName(answear);
    
    cout << "middle name: ";
    cin >> answear;
    d.SetMiddlName(answear);
    
    cout << "adress: ";
    cin >> answear;
    d.SetAdress(answear);
    
    cout << "phonnumber: ";
    cin >> answear;
    d.SetPhone(answear);
    
    cout << "adress: ";
    cin >> answear;
    d.SetAdress(answear);
    
    return cin;  
}

ostream& operator << ( ostream& i, Student& d)
{
    d.PrintStudent();
    d.PrintExam();
    d.PrintPractic();
    d.PrintHomeWork();
    return cout;
}

istream& operator >> (istream& i, Group& g)
{
    cout << "Group Name: ";
    string answear;
    cin >> answear;
    g.SetGroupName(answear);

    cout << "Group Specification: ";
    cin >> answear;
    g.SetSpecification(answear);

    cout << "Course: ";
    unsigned short amswear2;
    cin >> amswear2;
    g.SetNumberOfCourse(amswear2);

    return cin;
}

ostream& operator << (ostream& i, Group& d)
{
    d.Print();
    return cout;
}

istream& operator >> (istream& i, Fraction& f)
{
    cout << "numerator: ";
    int answear;
    cin >> answear;
    f.SetNumerator(answear);

    cout << "denominator: ";
    cin >> answear;
    f.SetDenominator(answear);

    return cin;
}

ostream& operator << (ostream& i, Fraction& f)
{
    f.Print();
    return cout;
}

int main()
{
    Student one("Pyatochkin", "Petya", "Petrovich", "Mira 102","12121212");
    one.AddExam(12);
    one.AddExam(12);
    Student two;
    two.AddExam(2);
    two.AddExam(9);
    Group p;
    p.AddStudent(one);
    p.AddStudent(two);
    //p.Expel();
    p.Print();
    p.WeanStudent(two);
    p.Print();
}