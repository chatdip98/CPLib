#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t, i, j, k, n;
    cin >> t;
    for(int a0=0; a0<t; a0++)
    {
        cin >> n;
        int b[n];
        for(i=0; i<n; i++)
        {
            cin >> b[i];
        }
        vector<vector<int>> dp;
		vector<int> v(2, 0);
        dp.push_back(v);
        for(i=1; i<n; i++)
        {            
            v[0] = int(abs(b[i-1]-1)) + dp[i-1][1];
            v[1] = max(int(abs(1-b[i])) + dp[i-1][0], int(abs(b[i-1]-b[i])) + dp[i-1][1]);
            dp.push_back(v);
        }
        cout << *max_element(dp[n-1].begin(), dp[n-1].end()) << endl; 
    }
    return 0;
}
