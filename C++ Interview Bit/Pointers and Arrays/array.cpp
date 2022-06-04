/*
Complete the given function named ‘reverseArray’ containing an integer array ‘arr’ and length of arr N. Reverse the array ‘arr’.
**/

/*
#include<iostream>
#include <cmath>
using namespace std;
*/
#include <cmath>
void reverseArray(int arr[], int N){
    // Your code goes here
    // int len = sizeof(arr) / sizeof(arr[0]);
    int f = floor(N / 2);
    for (int i = 0, j = (N - 1); i < f, j >= f; i++, j--)
    {
        if (i != j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}


/*
int main()  {
    int N;
    cin>>N;
    int arr[N];
    for(int i = 0; i < N; i++){
        cin>>arr[i];
    }
    reverseArray(arr, N);
    for(int i = 0; i < N; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
*/
