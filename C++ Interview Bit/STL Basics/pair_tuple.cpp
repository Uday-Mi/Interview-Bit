/*
You are given two functions findMaxMin and compute. Return the values as described in the comments in the editor below.
**/

/*
#include <iostream>
#include <vector>
#include<tuple>
using namespace std;
*/
#include<algorithm>

pair<int, int> findMaxMin(vector<int> &A){
    // First value of pair will be Maximum of array A and second will be Minimum of array A
    int l = A.size();
    std::sort(A.begin(), A.end());
    return make_pair(A[l - 1], A[0]);
}

tuple<int, int, int> compute(vector<int> &A){
    // First value of tuple will be sum of array A
    // Second value of tuple will be sum of even values in array A 
    // Third value of tuple will be sum of odd values in array A
    int l = A.size();
    int sum = 0;
    int odd = 0; 
    int even = 0;
    for (int i = 0; i < l; i++)
    {
        sum  = sum + A[i];
        if (A[i] % 2 == 0)
            even = even + A[i];
        else
            odd = odd + A[i];
    }
    return make_tuple(sum, even, odd);
}

/*
int main()  {
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i = 0; i < n; i++){
        cin>>A[i];
    }
    
    pair<int, int> max_min = findMaxMin(A);
    cout<<max_min.first<<" "<<max_min.second<<endl;
    
    tuple<int, int, int> tuple_values = compute(A);
    cout<< get<0>(tuple_values) << " " << get<1>(tuple_values) << " " << get<2>(tuple_values) << endl;
    
    return 0;
}
*/
