#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+10;

void findSubsequencesSum(int ind, int sum, vector<int> arr, vector<int> &answer, int n)
{
    if(ind == n)
    {
        answer.push_back(sum);
        return;
    }
    
    findSubsequencesSum(ind+1, sum + arr[ind], arr, answer, n);
    
    findSubsequencesSum(ind+1, sum, arr, answer, n);
}
 
vector<int> printSubsequencesSum(vector<int> arr, int n)
{
    vector<int> answer;
    findSubsequencesSum(0, 0, arr, answer, n);
    return answer;
}

int main()
{
    vector<int> arr = {2,3};
    int n = arr.size();
    vector<int> ans = printSubsequencesSum(arr, n);
    
    for(int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << " ";
    }
    
    cout << endl;
    
    return 0;
}