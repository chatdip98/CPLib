#include <iostream>
#include <string>
#include <algorithm>
#define max(a, b) (a>b?a:b)
using namespace std;

int LCS(string s1, string s2, int m, int n)
{
	int lcs[m+1][n+1];
	//string s="";
	
	/*if(s1[m-1]==s2[n-1])
		return 1 + lcs(s1, s2, m-1, n-1);
	else
		return max(lcs(s1, s2, m-1, n), lcs(s1, s2, m, n-1));*/
	for(int i=0; i<=m; i++)
	{
		for(int j=0; j<=n; j++)
		{
			if(i==0 || j==0)
		 		lcs[i][j] = 0;
			else if(s1[i-1]==s2[j-1])
				{
					lcs[i][j] = 1 + lcs[i-1][j-1];
					//s+=s1[i-1];
				}
			else
				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
		}
	}
	return lcs[m][n];
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	cout << LCS(s1, s2, s1.length(), s2.length());
	return 0;
}
