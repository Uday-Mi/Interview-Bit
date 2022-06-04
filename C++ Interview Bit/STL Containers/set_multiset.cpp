/*
You will be given Q queries. Each query is one of the following three types:

1 x : Add an element x to the set.
2 x : Delete an element x from the set. (If the number x is not present in the set, then do nothing).
3 x : If the number x is present in the set, then print "Yes"(without quotes) else print "No"(without quotes).
Alfter processing all queries, if the size of set is greater than 0, print each element (sorted order) in the new line.

Input Format:

First line of the input contains an integer Q denoting the number of queries.
 Next Q lines consists of two integers y and x where y is the type of the query and x is an integer.

Constraints

1 <= Q <= 105    
1 <= y <= 3
1 <= x <= 109
Sample Input

7  
1 5
1 4
1 6
1 5
3 4
2 4
3 4
Sample Output

Yes
No
5
6
**/

#include<iostream>
#include<set>
#include<iterator>
using namespace std;
#include <vector>

int main()  {
    // YOUR CODE GOES HERE
    // Please take input and print output to standard input/output (stdin/stdout)
    // E.g. 'cin' for input & 'cout' for output

    int Q;
    cin >> Q;

    int y;
    set <int> s;
    int x;
    for (int i = 0; i < Q; i++)
    {
        cin >> y;
        cin >> x;
        if (y == 1)
            s.insert(x);
        if (y == 2)
            s.erase(x);
        if (y == 3)
        {
            set<int> :: iterator itr = s.find(x);
            if (itr == s.end())
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
    }

    int l = s.size();
    // s.sort();
    vector <int> v(l);
    if (l > 0)
    {
        set<int> :: iterator itr = s.begin();
        int i = 0;
        for (; itr != s.end(); itr++)
        {
            v[i] = *itr;
            i++;
        }
        for (i = 0; i < l; i++)
        {
            cout << v[i] << endl;
        }
    }

    
    return 0;
}
