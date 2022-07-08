// Print name n times.

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int fun(int i, int n)
{
	if(i == n) return 0;
	
	cout << "Pranav " << i << " " << n << endl;
	// i++; one way to increment i
	
	fun(i+1, n); // another way of incrementing i by 1. 
}

int main()
{
	int n;
	cin >> n;

	// fun(1, n); upper condition changes to
	// if(i > n) return 0;
	
	fun(0, n);
	
	return 0;
}

/*
               Recursion tree
              
                fun(0, 5)
                   /
                  /
             fun(1,5);
                /
               /             
           fun(2, 5)   Time complexity - O(n)
             /         Space complexity - O(n)
            /
        fun(3,5);
          /
         /
       fun(4,5);
       
*/