/*
Combination Sum 2 - more advanced form of combination sum
conditions:
1 - No element can be taken twice.
2 - No same pattern can be considered more than once.

Time complexity - O(2^n * k)
Space complexity - O(k * n)
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+10;

void findCombination(int ind, int target, vector<int> &candidates, vector<vector<int>> &ans, vector<int> &ds)
{
	if(target == 0)
	{
		ans.push_back(ds);
		return;
	}
	
	for(int i = ind; i < candidates.size(); i++)
	{
		if(i > ind && candidates[i] == candidates[i-1])
		{
			cout << "i: " << i << " " << "ind: " << ind << endl;
			continue;	
		} 
		
		if(candidates[i] > target) break;
		
		ds.push_back(candidates[i]);
		
		findCombination(i+1, target - candidates[i], candidates, ans, ds);
		
		ds.pop_back();
	}
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
	sort(candidates.begin(), candidates.end());
	vector<vector<int>> ans;
	vector<int> ds;
	
	findCombination(0, target, candidates, ans, ds);
	return ans;
}

int main()
{
	vector<int> candidates = {1,1,1,2,2};
	int target = 4;
	
	vector<vector<int>> answer = combinationSum2(candidates, target);
	
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