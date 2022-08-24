/*
Given an array A with non negative numbers, divide the array into two parts such that the average of both the parts is equal.

Return both parts (If exist). If there is no solution. return an empty list.

NOTE:

If a solution exists, you should return a list of exactly 2 lists of integers A and B which follow the following condition :
numElements in A <= numElements in B
If numElements in A = numElements in B, then A is lexicographically smaller than B ( https://en.wikipedia.org/wiki/Lexicographical_order )
If multiple solutions exist, return the solution where length(A) is minimum. If there is still a tie, return the one where A is lexicographically smallest.

Array will contain only non negative numbers.



**Input Format**
First andonly argument is an integer array A.



**Output Format**
Return 2D array consisting of two rows where each row denoted a partition.



**Example Input**
Input 1:

 A = [1 7 15 29 11 9]


Example Output
Output 1:

 [9 15] [1 7 11 29]


Example Explanation
Explanation 1:

 The average of part is (15+9)/2 = 12, average of second part elements is (1 + 7 + 11 + 29) / 4 = 12
 **/

bool ischeck(int ind,int sum,int element,vector<int>&A,vector<vector<vector<bool>>>&t,vector<int>&res)
{
    if(element==0)
    return (sum==0);
    
    if(ind>=A.size())
    return false;
    
    if(t[ind][sum][element]==false)
    return false;

    if(A[ind]<=sum)
    {
        res.push_back(A[ind]);
        
        if(ischeck(ind+1,sum-A[ind],element-1,A,t,res)==true)
        return t[ind][sum][element]=true;
        
        res.pop_back();
    }
    
    if(ischeck(ind+1,sum,element,A,t,res))
    return t[ind][sum][element]=true;

    return t[ind][sum][element]=false;
}

vector<vector<int> > Solution::avgset(vector<int> &A) 
{
    sort(A.begin(),A.end());
    
    int sum=0;
    int n=A.size();
    
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
    }
    
    vector<vector<vector<bool>>>t(n,vector<vector<bool>>(sum+1,vector<bool>(n,true)));
    
    vector<vector<int>>ans;
    
    for(int i=1;i<n;i++)
    {
        if((sum*i)%n==0)
        {
            int s1=sum*i;
            s1=s1/n;
            
            vector<int>res;
            
            if(ischeck(0,s1,i,A,t,res))
            {
                sort(res.begin(),res.end());
                
                ans.push_back(res);
                
                vector<int>res2;
                
                for(int j=0;j<res.size();j++)
                {
                    auto it=find(A.begin(),A.end(),res[j]);
                    
                    if(it!=A.end())
                    A.erase(it);
                }
                sort(A.begin(),A.end());
                ans.push_back(A);
                break;
            }
        }
    }
    
    return ans;

}
