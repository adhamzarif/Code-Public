#include <bits/stdc++.h>
using namespace std;

struct Student
{
    string name;
    int id;
    double cgpa;
};

Student maxCgpaStudent(vector<Student> &students, int l, int r)
{
    if (l == r)
    {
        return students[l];
    }

    int mid = (l + r) / 2;

    Student leftMax = maxCgpaStudent(students, l, mid);
    Student rightMax = maxCgpaStudent(students, mid + 1, r);

    return (leftMax.cgpa >= rightMax.cgpa) ? leftMax : rightMax;
}

int main()
{
    vector<Student> students = {
        {"A", 101, 3.5},
        {"B", 102, 3.8},
        {"C", 103, 3.2},
        {"D", 104, 3.9},
        {"E", 105, 3.7}};

    Student topStudent = maxCgpaStudent(students, 0, students.size() - 1);

    cout << "Student with highest CGPA:\n";
    cout << "Name: " << topStudent.name << ", ID: " << topStudent.id
         << ", CGPA: " << topStudent.cgpa << "\n";

    return 0;
}
