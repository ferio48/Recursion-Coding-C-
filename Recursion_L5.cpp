#include<bits/stdc++.h>
using namespace std;
#define ll long long

// Time complexity is O(2^n) exponential.

int fibonacci(int n)
{
	if(n <= 1) return n;
	
	return fibonacci(n-2) + fibonacci(n-1);
}

int main()
{
	int n;
	
	cin >> n;
	
	int fib = fibonacci(n);
	
	cout << fib << endl;
	
	return 0;
}