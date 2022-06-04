/*
First line of the input contains an integer N denoting the number of integers.
Second line contains N space-separated integers. 
Third line contains an integer X denoting the index(0-based) of the N integers which needs to be deleted.

Your task is to print the N-1 integers in sorted order (ascending). Each integer in a new line.

Constraints

1 <= N <= 105  
0 <= X < N
Sample Input

5
10 5 2 3 10
2
Sample Output

3
5
10
10
**/

#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()  {
    // YOUR CODE GOES HERE
    // Please take input and print output to standard input/output (stdin/stdout)
    // E.g. 'cin' for input & 'cout' for output

    int N;
    cin >> N;
    vector <int> v (N);
    for (int i = 0; i < N; i++)
    {
        // int a;
        cin >> v[i];
        // v.push_back(a);
    }
    int del;
    cin >> del;
    v.erase(v.begin() + del);
    sort(v.begin(), v.end());

    for (int i = 0; i < N - 1; i++)
    {
        cout << v[i] << endl;
    }

    return 0;
}
