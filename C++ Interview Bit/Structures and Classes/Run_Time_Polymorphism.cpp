/*
You will first build three classes:

Animal (parent class)
Dog (derived class)
Cat (derived class)
Dog and Cat class will inherit from Animal.

In the editor below you have to implement the following:

Animal class:
Has one protected variable for age of the mammal.
A constructor that takes the age of animal as input and sets it.
The function Eat() that displays "Animal eats food".
Function get_Age() which returns the age of the animal.
Dog class:
Inherits all the members from Animal class.
Implement all member functions of Animal class for Dog class.
Eat() should display "Dog eats meat".
get_Age() should return Dog’s age.
Cat class:
Inherits all the members from Animal class.
Implement all member functions of Animal class for Cat class.
Eat() should display "Cat eats meat".
get_Age() should return Cat’s age.
You are given main function displaying all the class functions and objects called and created.

Following should be the output after running the program:

Dog eats meat
Dog's age is: 8
Cat eats meat
Cat's age is 3
Hint: Think along the direction of virtual functions and their use to implement the same function for different classes separately.
**/

/*
#include<iostream>
using namespace std;
*/

// Your code goes here

class Animal 
{
    public :
    Animal (int new_age) 
    {
        age = new_age;
    }
    virtual void Eat ()
    {
        cout << "Animal eats food" << endl;
    }
    virtual int get_Age ()
    {
        return age;
    }
    protected :
        int age;
};

class Dog : public Animal 
{
    public :
        Dog (int new_age) : Animal (new_age) 
        {

        }
        void Eat ()
        {
            cout << "Dog eats meat" << endl;
        }
        int get_Age ()
        {
            return age;
        }
};

class Cat : public Animal 
{
    public :
        Cat (int new_age) : Animal (new_age) 
        {

        }
        void Eat ()
        {
            cout << "Cat eats meat" << endl;
        }
        int get_Age ()
        {
            return age;
        }
};


/*
int main()  {
   Animal *a;
   Dog dg(8); //making object of child class Dog
   Cat ct(3); //making object of child class Cat
   
   a = &dg;
   a->Eat();
   cout << "Dog's age is: "<<a->get_Age()<<endl;
   a= &ct;
   a->Eat();
   cout << "Cat's age is: "<<a->get_Age()<<endl;
   return 0;
}
*/
