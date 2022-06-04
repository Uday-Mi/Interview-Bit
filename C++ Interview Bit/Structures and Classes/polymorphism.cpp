/*
Your task is to create two functions with same name “compute” and return type int. One will take two integer parameters and return absolute difference between them. Other will take one integer parameter and return the square of that number.
**/

/*
#include<iostream>
using namespace std;
*/

#include<cmath>

// YOUR CODE GOES HERE

int compute (int x, int y)
{
    return abs(x - y);
}

int compute (int x)
{
    return x * x;
}

/*
int main()  {
    int x,y;
    cin>>x>>y;
    cout<<compute(x,y)<<endl;
    int z;
    cin>>z;
    cout<<compute(z)<<endl;
    return 0;
}
*/
