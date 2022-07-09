#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+10;

bool isSubsetSum(vector<int> arr, int sum, int n)
{
    bool dp[n+1][sum+1];
    
    memset(dp, 0, sizeof(dp));
    
	for(int i = 0; i <= n; ++i)
	{
		for(int j = 0; j <= sum; ++j)
		{
			if(i == 0 && j == 0)
			{
				dp[i][j] = true;
			}
			else if(i == 0)
			{
				dp[i][j] = false;
			}
			else if(j == 0)
			{
				dp[i][j] = true;
			}
			else
			{
				if(dp[i-1][j] == true)
				{
					dp[i][j] = true;
				}
				else
				{
					int val = arr[i-1];
					if(j >= val)
					{
						if(dp[i-1][j - val] == true)
						{
							dp[i][j] = true;
						}
					}
				}
			}
		}
	}
	
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < sum; ++j)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	
	return dp[n][sum];
}

int main()
{
	vector<int> arr = {3, 34, 4, 12, 5, 2};
    int n = arr.size();
    //cout << "n: " << n << endl;
    int sum = 30;
    
    bool ans = isSubsetSum(arr, sum, n);
    
    cout << ans << endl;
    
    return 0;
}