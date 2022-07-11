/*
N-Queens problem:
N = no. of queens.
Conditions:
1. Every row should have 1 queen.
2. Every column should have 1 queen.
3. None of the queens should attack each other.(One queen can attack the other if one is in same row, same column or diagonally aligned).
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+10;

/*bool isSafe(int row, int col, vector<string> board, int n)
{
	int duprow = row;
	int dupcol = col;
	
	while(row >= 0 && col >= 0)
	{
		if(board[row][col] = 'Q') return false;
		row--;
		col--;
	}
	
	row = duprow;
	col = dupcol;
	
	while(col >= 0)
	{
		if(board[row][col] = 'Q') return false;
		col--;
	}
	
	row = duprow;
	col = dupcol;
	
	while(row < n && col >= 0)
	{
		if(board[row][col] = 'Q') return false;
		row++;
		col--;
	}
	
	return true;
}*/

//Optimized function bu using hashing.
void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal ,int n)
{
	if(col == n)
	{
		ans.push_back(board);
		return;
	}
	
	for(int row = 0; row < n; ++row)
	{
		if(leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && 
			upperDiagonal[n-1 + col-row] == 0)
		{
			board[row][col] = 'Q';
			leftRow[row] = 1;
			lowerDiagonal[row + col] = 1; 
			upperDiagonal[n-1 + col-row] = 1;
			
			solve(col+1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
			
			board[row][col] = '.';
			leftRow[row] = 0;
			lowerDiagonal[row + col] = 0; 
			upperDiagonal[n-1 + col-row] = 0;
		} 
	}
}

vector<vector<string>> SolveQueens(int n)
{
	vector<vector<string>> ans;
	vector<string> board(n);
	string s(n, '.'); 
	for(int i = 0; i < n; ++i)
	{
		board[i] = s;
	}
	
	vector<int> leftRow(n, 0), upperDiagonal(2*n-1, 0), lowerDiagonal(2*n-1, 0);
	
	
	solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
	
	return ans;
	
}

int main()
{
	int n = 4;
	
	vector<vector<string>> answer;
	
	answer = SolveQueens(n);
	
	for(int i = 0; i < answer.size(); ++i)
	{
		for(int j = 0; j < answer[i].size(); ++j)
		{
			cout << answer[i][j] << " "<< endl;
		}
		cout << endl;
	}
	
	return 0;
}