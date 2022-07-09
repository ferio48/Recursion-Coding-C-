/*
Subset Sum 2 (leetcode):
Print all subset of an array avoiding all duplicate subsets.
Time complexity - O(2^n * n) -> 2^n for recursion and n for copying that element to our data structure.
Space complexity - O(2^n *k) -> 2^n number of sibsets with an average length of k.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+10;

void findSubset(int ind, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds)
{
    ans.push_back(ds);
    
    for(int i = ind; i < nums.size(); i++)
    {
        if(i != ind && nums[i] == nums[i-1]) continue;
        
        ds.push_back(nums[i]);
        findSubset(i+1, nums, ans, ds);
        
        ds.pop_back();
    }
}
 
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<int> ds;
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    findSubset(0, nums, ans, ds);
    return ans;
}

int main()
{
	vector<int> nums = {1,2,2};
	vector<vector<int>> answer = subsetsWithDup(nums);
	
	for(int i = 0; i < answer.size(); ++i)
	{
		for(int j = 0; j < answer[i].size(); ++j)
		{
			cout << answer[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}