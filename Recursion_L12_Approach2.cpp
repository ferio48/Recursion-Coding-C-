/*
=>Permutation (leetcode)
=> Given an array find all the possible permutations.
=> Time complexity - O(n! * n) --> n! is the recursive calls and n is the loop time complexity
=> Space complexity - O(n) --> only auxiliary space is being used in this code.
SPACE COMPLEXITY IS LESS IN THIS CODE.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+10;

void findPerm(int ind, vector<int> &nums, vector<vector<int>> &ans)
{
	if(ind == nums.size())
	{
		ans.push_back(nums);
		return;
	}
	
	for(int i = ind; i < nums.size(); ++i)
	{
		swap(nums[ind], nums[i]);
		findPerm(ind+1, nums, ans);
		swap(nums[ind], nums[i]);
	} 
}


vector<vector<int>> findPermutations(vector<int> &nums)
{
	vector<vector<int>> ans;
	
	findPerm(0, nums, ans);
	
	return ans;
}


int main()
{
	vector<int> nums = {1,2,3};
	
	vector<vector<int>> answer;
	
	answer = findPermutations(nums);
	
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
