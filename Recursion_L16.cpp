/*
-->M-Coloring Problem:
-->Given a set of  colors m = {1,2,3}: First contain 1 color, Second contain 2 colors and set contain 3 colors.
We have to give true or false for every position, true if the position is able to colro the graph
and false if the position isn't able to color the graph.

-->Time complexity - O(m^N) - N is the no of nodes and M is the no of color in the set of colors
, as we are trying every color for every node.

-->Space complexity - O(N) + O(N), O(N) for the color array and other O(N) for the auxiliary space for the recursion calls.
*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+10;

bool isSafe(int node, int color[], bool graph[101][101], int N, int colo)
{
	for(int k = 0; k < N; ++k)
	{
		if(k != node && graph[k][node] == 1 && color[k] == colo)
			return false;
	}
	return true;
}

bool solve(int node, int color[], bool graph[101][101], int m, int N)
{
	if(node == N)
	{
		return true;
	}
	
	for(int i = 1; i <= m; ++i)
	{
		if(isSafe(node, color, graph, N, i))
		{
			color[node] = i;
			if(solve(node+1, color, graph, N, m)) return true;
			color[node] = 0;
		}
	}
	return false;
}

bool graphColoring(bool graph[101][101], int m, int N)
{
	int color[N];
	if(solve(0, color, graph, m, N)) return true;
	return false;
}

int main()
{
	int N = 4;
	int m = 2;
	
	bool graph[101][101] = {
		(0,1),
		(1,2),
		(0,2)
	};
	
	cout << graphColoring(graph, m, N);
	
	return 0;
}