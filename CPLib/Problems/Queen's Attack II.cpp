#include <iostream>
#define space 0
#define obstacle 1
#define queen 2
#define MAX 100000
using namespace std;

void print(int **board, int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
}

int horizontal(int **board, int n, int r, int c)
{
	int i, j, count = 0;
	for(i=c+1; i<n; i++)
	{
		if(board[r][i] == obstacle)
			break;
		count++;
	}
	for(i=c-1; i>=0; i--)
	{
		if(board[r][i] == obstacle)
			break;
		count++;
	}
	//cout << count << endl;
	return count;
}

int vertical(int **board, int n, int r, int c)
{
	int i, j, count = 0;
	for(i=r+1; i<n; i++)
	{
		if(board[i][c] == obstacle)
			break;
		count++;
	}
	for(i=r-1; i>=0; i--)
	{
		if(board[i][c] == obstacle)
			break;
		count++;
	}
	//cout << count << endl;
	return count;
}

int diagonal(int **board, int n, int r, int c)
{
	int i, j, count = 0;
	i=r+1;	j=c-1;
	while(1)
	{
		if(i==n || j<0)
			break;
		if(board[i][j] == obstacle)
			break;
		count++;
		i++;	j--;
	}
	i = r-1;	j = c+1;
	while(1)
	{
		if(i<0 || j==n)
			break;
		if(board[i][j] == obstacle)
			break;
		count++;
		i--; j++;
	}
	i = r-1;	j = c-1;
	while(1)
	{
		if(i<0 || j<0)
			break;
		if(board[i][j] == obstacle)
			break;
		count++;
		i--; j--;
	}
	i = r+1;	j = c+1;
	while(1)
	{
		if(i==n || j==n)
			break;
		if(board[i][j] == obstacle)
			break;
		count++;
		i++; j++;
	}
	return count;
}

int main()
{
	int i, j, n, k, r, c, qr, qc, **board;
	cin >> n >> k;
	board = new int*[n];
	for(i=0; i<n; i++)
		board[i] = new int[n];
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			board[i][j] = space;
	}
	cin >> r >> c;
	r = n-r;	c-=1;	qr = r;	qc = c;
	board[r][c] = queen;
	for(i=0; i<k; i++)
	{
		cin >> r >> c;
		r = n-r;	c-=1;
		board[r][c] = obstacle;
	}
	//print(board, n);
	int count = horizontal(board, n, qr, qc) + vertical(board, n, qr, qc) + diagonal(board, n, qr, qc);
	cout << count;
	return 0;
}
