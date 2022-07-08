/*
Print the subsequence of the array whose sum is 
equal to the given sum. 
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+10;

void printSumSubsequences(int ind, vector<int> &ds/*Passed this parameter by reference because we will make changes in this parameter*/,int s, int arr[], int sum, int n)
{
	if(ind == n)
	{
		if(s == sum)
		{
			for(auto it: ds) cout << it << " ";
		    cout << endl;
	    }
		return; 
	} 
	 
	// Take or pick the index element into the subsequence
	ds.push_back(arr[ind]);
	s += arr[ind];
	
	printSumSubsequences(ind+1, ds, s, arr, sum, n);
	
	ds.pop_back();
	s -= arr[ind];
	// Not take the index element into the subsequence.
	printSumSubsequences(ind+1, ds, s, arr, sum, n);
}

bool print1SumSubsequences(int ind, vector<int> &ds/*Passed this parameter by reference because we will make changes in this parameter*/,int s, int arr[], int sum, int n)
{
	if(ind == n)
	{
		if(s == sum)
		{
			for(auto it: ds) cout << it << " ";
		    cout << endl;
		    return true; // If this is true then the next codes won't be implemented.
	    }
		return false;
	} 
	 
	// Take or pick the index element into the subsequence
	ds.push_back(arr[ind]);
	s += arr[ind];
	
	if(print1SumSubsequences(ind+1, ds, s, arr, sum, n) == true) return true;
	
	ds.pop_back();
	s -= arr[ind];
	// Not take the index element into the subsequence.
	if(print1SumSubsequences(ind+1, ds, s, arr, sum, n) == true) return true;
	
	return false;
}

// count no of times the sum of subsequences is equal to the given sum
int printCountSubsequences(int ind, int s, int sum, int arr[], int n)
{
	if(ind == n)
	{
		if(s == sum) return 1;
		else return 0;
	}
	
	s += arr[ind];
	int l = printCountSubsequences(ind+1, s, sum, arr, n);
	
	s -= arr[ind];
	int r = printCountSubsequences(ind+1, s, sum, arr, n);
	
	return l+r;
}
int main()
{
	int arr[] = {1,1,2};
	int n = 3;
	int sum = 2;
	
	vector<int> ds;
	
	//printSumSubsequences(0, ds, 0, arr, sum, n);
	
	int count = printCountSubsequences(0, 0, sum, arr, n);
	cout << "count: " << count;
	
	return 0;
}