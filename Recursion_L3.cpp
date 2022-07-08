#include<bits/stdc++.h>
using namespace std;
#define ll long long

// Paramerterized Recursion
int fun(int i, int sum)
{
	if(i < 1) 
	{
		cout << sum << endl;
		return 0;
	}
	 
	fun(i-1, sum + i);
}

// Functional Recursion
int fun1(int i)
{
	if(i == 0)
		return 0;
	
	return i + fun1(i-1); 
}

// Factorial Function
int fact(int i)
{
	if(i == 1) return 1;
	
	return i * fact(i-1);
}

int main()
{
	int n, sum = 0;
	cin >> n;
	
	// fun(n, sum);
	int r = fact(n);
	cout << r << endl;
	return 0;
}

// Time and space complexity
// (auxilliary space complexity) will be O(n);
