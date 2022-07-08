/*
Combination Sum - Given an array print elements whose sum is equal to the 
given sum, also the elements can be taken more than one time. 

Time complexity - O(2^t * k)
Space complexity - O(k * n) - cannot predict, totally depend on the number of combinations
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+10;

void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds) 
{
	if(ind == arr.size())
	{
		if(target == 0)
		{
			ans.push_back(ds);
		}
		return;
	}
	
	//pick up the element
	if(arr[ind] <= target)
	{
		ds.push_back(arr[ind]);
		findCombination(ind, target - arr[ind], arr, ans, ds);
		ds.pop_back();
	}
	
	findCombination(ind+1, target, arr, ans, ds);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
	vector<vector<int>> ans;
	vector<int> ds;
	findCombination(0, target, candidates, ans, ds);
	return ans;
}

int main()
{
	vector<int> candidates = {2,3,6,7};
	int target = 7;
	
	vector<vector<int>> answer = combinationSum(candidates, target);
	
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