#include <iostream>
#include <string>
using namespace std;

int find(string s, int n)
{
	int x, b[n];
	b[0] = 1;
	for(int i=1; i<n; i++)
	{
		if(int(s[i])==48)
		{
			if(int(s[i-1]<=50) && int(s[i-1]>=49))
			{
				if(i==1)
					b[i] = 1;
				else
					b[i] = b[i-2];
			}
			else	
				return 0;
		}
		else
		{
			if((int(s[i-1]<50)&&int(s[i-1])>=49) || (int(s[i-1])==50 && int(s[i])<=54))
			{
				if(i==1)
					b[i] = 2;
				else
					b[i] = b[i-1] + b[i-2];
			}		
			else
				b[i] = b[i-1];	
		}
	}
	return b[n-1];
}

int main()
{
	string s;
	cin >> s;
	while(s!="0")
	{
		int n = s.length();
		cout << find(s, n) << endl;
		cin >> s;
	}
	return 0;
}
