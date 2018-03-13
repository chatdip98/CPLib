#include <iostream>
using namespace std;
//Sieve of Eratosthenes
int main()
{
	int n, num[1000], i, k, flag = 0;
	cout << "Enter the upper bound: ";
	cin >> n;
	for(i=0; i<n; i++)
	{
		num[i] = i+1;
	}
	for(k=2;k<=n;k++)
	{
		flag = 0;
		for(i=(2*k)-1; i<n; i=i+k)
		{
			if(num[i] != 0)
			{
				num[i] = 0;
				flag = 1;
			}
		}
		if(flag == 0)
		{
			break;
		}
	}
	for(i=0; i<n; i++)
	{
		if(num[i] != 0 && num[i] != 1)
		cout << num[i] << " ";
	}
	return 0;
}
