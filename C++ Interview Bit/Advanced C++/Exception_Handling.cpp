/*
You are given a function named division which throw an exception if the value of divisor is 0 as shown below. Your task is to complete the main function and use try and catch blocks. In try block call and print the value return by division function, else if an exception is thrown print the exception in catch.
**/

/*
#include<iostream>
using namespace std;

int division(int a, int b) {
   if( b == 0 ) {
      throw "Division by zero condition!";
   }
   return (a/b);
}
*/

int main()  {
    int a, b;
    cin>>a>>b;
    
    // call function division(a, b)
    // print the result in try else exception in catch
    // Your code goes here

    string str;

    try {
        int c = division (a, b);
        cout << c << endl;
    }
    catch (...)
    {
        cout << "Division by zero condition!";
    }

    return 0;
}
