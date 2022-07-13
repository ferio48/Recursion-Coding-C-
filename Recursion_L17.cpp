#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+10;

bool isPalindrome(string s, int start, int end)
{
	while(start <= end)
	{
		if(s[start++] != s[end--]) 
			return false;
	}
	return true;
}

void func(int ind, vector<vector<string>> &res, vector<string> &path, string s)
{
	if(ind == s.size())
	{
		res.push_back(path);
		return;
	}
	
	for(int i = ind; i < s.size(); ++i)
	{
		if(isPalindrome(s, ind, i))
		{
			path.push_back(s.substr(ind, i - ind + 1));
			func(i+1, res, path, s);
			path.pop_back();
		}
	}
}

vector<vector<string>> part(string s)
{
	vector<vector<string>> res;
	vector<string> path;
	
	func(0, res, path, s);
	return res;
}


int main()
{
	string s = "aabb";
	vector<vector<string>> ans;
	
	ans = part(s);
	
	for (auto i: ans) {
    cout << "[ ";
    for (auto j: i) {
      cout << j << " ";
    }
    cout << "] "<< endl;
  }

	return 0;
}