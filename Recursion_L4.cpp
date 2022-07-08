#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*Time complexity is O(n/2) as we are going 
till the half odf array or string and 
Space complexity will be O(n) this is 
auxilliary space complexity*/

// using two pointers reverse an array.
int RecursiveReverseArray(int a[], int i, int j)
{
	if(i == j) return 0;
	
	swap(a[i], a[j]);
	RecursiveReverseArray(a, i+1, j-1);
}

/*void swap(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
}*/

// using single pointer reverse an array.
void RecursiveReverseArray2(int a[], int i, int n)
{
	if(i >= n/2) return;
	
	swap(a[i], a[n-i-1]);
	RecursiveReverseArray2(a, i+1, n);
}

// Recursuve function to check for a string is Palindrome or not
bool Palindrome(string s, int i, int n)
{
	if(s[i] != s[n-i-1]) return false;
	
	if(i <= n/2) return true;
	
	if(s[i] == s[n-i-1]) Palindrome(s, i+1, n);
}

int Palindrome2(string &s, int i)
{
	if(i >= s.size()) return 1;
	if(s[i] != s[s.size() - i - 1]) return 0;
	
	return Palindrome2(s, i+1);
}

int main()
{
	/*int n;
	cin >> n;
	
	int a[n];
	
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	
	RecursiveReverseArray2(a, 0 , n);
	
	for(int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	
	cout << endl;
	*/
	
	string s;
	cin >> s;
	
	/*int len = s.length();
	// cout << len;
	
	// instead of using len we can directle pass size() function into the function as paramneter
	bool con = Palindrome(s, 0, len);
	if(con) cout << "Yes the string is Palindrome\n";
	else
		cout << "No the string is not Palindrome\n";
	*/
	
	cout << Palindrome2(s, 0);
	return 0;
}