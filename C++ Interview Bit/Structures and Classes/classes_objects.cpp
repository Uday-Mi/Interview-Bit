/*
We have a class defined for Student. Create a function set_variable which takes three parameters name(string), age(int), rollno(int) and assign values to the member variables. Also, create a function print_variable which prints name, age, rollno each in new line.
**/

/*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
*/

class Student{
    string name;
    int age;
    int rollno;
public:
    // Create funtions here with the name given
    void set_variable (string new_name, int new_age, int new_rollno);
    void print_variable();
};

void Student::set_variable (string new_name, int new_age, int new_rollno)
{
    name = new_name;
    age = new_age;
    rollno = new_rollno;
}

void Student::print_variable()
{
    cout << name << endl << age << endl << rollno << endl;
}

/*
int main()  {
    Student obj1;
    obj1.set_variable("Robin", 15, 10);
    Student obj2;
    obj2.set_variable("Rahul", 20, 14);
    obj1.print_variable();
    obj2.print_variable();
    return 0;
}
*/
