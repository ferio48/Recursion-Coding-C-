#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+10;

int dp[101][10001];

bool findSubsequence(int n, vector<int> arr, int sum)
{
    if(sum == 0) return true;
    
    if(n == 0) return false;
    
    if(dp[n][sum] != -1) return dp[n][sum];
    
    if(arr[n-1] <= sum)
    {
        return dp[n][sum] = findSubsequence(n-1, arr, sum - arr[n-1]) || findSubsequence(n-1, arr, sum);
    }
    
    else return dp[n][sum] = findSubsequence(n-1, arr, sum);
    
    return dp[n][sum];
}

bool isSubsetSum(vector<int>arr, int sum){
    int n = arr.size();
    memset(dp, -1, sizeof(dp));
    return findSubsequence(n, arr, sum);
}

int main()
{
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    
    bool ans = isSubsetSum(arr, sum);
    
    cout << ans << endl;
    
    return 0;
}