#include <bits/stdc++.h>
using namespace std;
float power(int x, int y)
{
	if(y == 0)
		return 1;
	float temp = power(x, y/2);
	if(y%2==0)
		return temp*temp;
	else
	{
		if(y>0)
		{
			return x*temp*temp;
		}
		else
		{
			return (temp*temp)/float(x);
		}
	}
}
int main()
{
	int x, y;
	cout << "Enter x and y for x^y: ";
	cin >> x >> y;
	cout << power(x, y);
}
