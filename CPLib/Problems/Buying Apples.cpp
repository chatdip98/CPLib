#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> memo;

int min_money(int k, unordered_map<int, int> m)
{
	if(k==0)	return 0;
	int min = INT_MAX;
	for(auto it=m.begin(); it!=m.end(); it++)
	{
		int x, y = k-(it->first);
		if(y>=0)
		{
			if(memo.find(y)==memo.end())
			{
				x = min_money(y, m);
				memo.insert(pair<int, int> (y, x));		
			}	
			else
				x = (memo.find(y))->second;
			x+=it->second;
			if(x<min)	min = x;
		}
	}
	return min;
}

int main()
{
	int i, n, x, k, t;
	cin >>t;
	for(int a0=0; a0<t; a0++)
	{
		cin >> n >> k;
		unordered_map<int, int> m;
		for(i=0; i<k; i++)
		{
			cin >> x;
			if(x!=-1)
			{
				m.insert(pair<int, int> (i+1, x));
			}
		}
		x = min_money(k, m);		
		if(x<=-(int)pow(10,8))
			cout << "-1" << endl;
		else
			cout << x << endl;
		memo.clear();
		m.clear();
	}
}
