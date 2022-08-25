/*
You are given an array of logs. Each log is a space-delimited string of words, where the first word is the identifier.

There are two types of logs:

Letter-logs: All words (except the identifier) consist of lowercase English letters.
Digit-logs: All words (except the identifier) consist of digits.

Reorder these logs so that:

The letter-logs come before all digit-logs.
The letter-logs are sorted lexicographically by their contents. If their contents are the same, then sort them lexicographically by their identifiers.
The digit-logs maintain their relative ordering.

Return the final order of the logs.


Problem Constraints
1 <= logs.length <= 1000
3 <= logs[i].length <= 1000
All the tokens of logs[i] are separated by a single space.
logs[i] is guaranteed to have an identifier and at least one word after the identifier.


Input Format
The first argument is a string array A where each element is a log.


Output Format
Return the string array A after making the changes.


Example Input
Input 1:
A = ["dig1-8-1-5-1", "let1-art-can", "dig2-3-6", "let2-own-kit-dig", "let3-art-zero"]
Input 2:

A = ["a1-9-2-3-1","g1-act-car","zo4-4-7","ab1-off-key-dog","a8-act-zoo"]


Example Output
Output 1:
["let1-art-can","let3-art-zero","let2-own-kit-dig","dig1-8-1-5-1","dig2-3-6"]
Output 2:

["g1-act-car", "a8-act-zoo", "ab1-off-key-dog", "a1-9-2-3-1", "zo4-4-7"]


Example Explanation
Explanation 1:
The letter-log contents are all different, so their ordering is "art-can", "art-zero", "own-kit-dig".
The digit-logs have a relative order of "dig1-8-1-5-1", "dig2-3-6".
Explanation 2:

The array has been sorted restricted to the conditions given.
**/

bool sortbysec (const pair <string, string> &a, const pair <string, string> &b)
{
    return (a.second < b.second);
}

vector<string> Solution::reorderLogs(vector<string> &A) {
    
    int n = A.size();
    
    vector <string> letter;
    vector <string> digit;
    
    vector <pair <string, string>> s;
    
    for (int i = 0; i < n; i++)
    {
        int x = A[i].find("-");
        
        if (isdigit(A[i][x + 1]))
        digit.push_back(A[i]);
        
        else
        {
            s.push_back({A[i].substr(0, x), A[i].substr(x + 1)});
        }
    }
    
    int m = s.size();
    
    sort(s.begin(), s.end(), sortbysec);
    
    for (int i = 0; i < m - 1; i++)
    {
        if (s[i].second == s[i + 1].second)
        {
            if (s[i].first < s[i + 1].first)
            {
                swap(s[i], s[i + 1]);
            }
        }
        string str = s[i].first + "-" + s[i].second;
        letter.push_back(str);
    }
    
    string str = s[m - 1].first + "-" + s[m - 1].second;
    letter.push_back(str);
    
    vector <string> ans = letter;
    
    for (int i = 0; i < digit.size(); i++)
    {
        ans.push_back(digit[i]);
    }
    
    return ans;
    
}
