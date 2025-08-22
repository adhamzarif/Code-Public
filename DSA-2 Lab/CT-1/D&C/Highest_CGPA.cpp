#include <bits/stdc++.h>
using namespace std;

struct Student
{
    string name;
    int id;
    double cgpa;
};

Student findTopper(vector<Student> &students)
{
    Student topper = students[0];

    for (int i = 1; i < students.size(); i++)
    {
        if (students[i].cgpa > topper.cgpa)
        {
            topper = students[i];
        }
    }
    return topper;
}

int main()
{
    vector<Student> students = {
        {"Alice", 101, 3.6},
        {"Bob", 102, 3.9},
        {"Charlie", 103, 3.7},
        {"David", 104, 3.8}};

    Student topper = findTopper(students);

    cout << "Topper Details:\n";
    cout << "Name: " << topper.name << "\n";
    cout << "ID: " << topper.id << "\n";
    cout << "CGPA: " << topper.cgpa << endl;

    return 0;
}
