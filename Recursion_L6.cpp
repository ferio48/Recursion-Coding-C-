/*
Print all subsequences
Sequences -> a contigous/non-contnigous sequence
which follows the order.

Time complexity - O(2^n(for every element there's two options take or not take) * n(for loop))
Space complexity - O(n) - as max depth of the recursion tree is 3 in array of 3 elements so 
space complexity comes out to be oreder of n
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+10;

void printSubsequences(int ind, vector<int> &ds/*Passed this parameter by reference because we will make changes in this parameter*/, int arr[], int n)
{
	if(ind == n)
	{
		for(auto it: ds) 
		{
			cout << it << " ";
		}    
		if(ds.size() == 0)
		{
			cout << "{}";
		}
		cout << endl;
		return;
	} 
	
	/* printSubsequences(ind+1, ds, arr, n); If this conditions 
	is take before the push operation then not take condition 
	will take place before take condition.
	*/
	
	// Take or pick the index element into the subsequence
	ds.push_back(arr[ind]);
	printSubsequences(ind+1, ds, arr, n);
	
	ds.pop_back();
	// Not take the index element into the subsequence.
	printSubsequences(ind+1, ds, arr, n);
}

int main()
{
	int arr[] = {3,1,2};
	int n = 3;
	
	vector<int> ds;
	
	printSubsequences(0, ds, arr, n);
	
	return 0;
}