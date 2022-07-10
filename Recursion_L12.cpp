/*
=>Permutation (leetcode):
=>Fron a given array, outptut all the possible permutations.
=>Time complexity - O(n! * n) --> n! is the time of all recursive calls 
and n is the time complexity of looping from 0 to in map.
=>Space complexity - O(n) + O(n) --> O(n) for our data structure
and O(n) for our map array.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+10;

// This function doesn't work when the array contains 0 as multiplying it with -1 doesn't show any effect. 
// To solve this we will use mapping. 
void findPerm(int ind, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds, int freq[])
{
	if(ds.size() == nums.size())
	{
		ans.push_back(ds);
		return;
	}
	
	for(int i = 0; i < nums.size(); ++i)
	{
		if(freq[i] != 1)
		{
			ds.push_back(nums[i]);
			freq[i] = 1;
			findPerm(i+1, nums, ans, ds, freq);
			
			ds.pop_back();
			freq[i] = 0;
		}
	} 
}


vector<vector<int>> findPermutations(vector<int> &nums)
{
	vector<int> ds;
	vector<vector<int>> ans;
	int freq[nums.size()] = {0};
	
	findPerm(0, nums, ans, ds, freq);
	
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