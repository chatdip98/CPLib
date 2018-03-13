#include <iostream>
using namespace std;

int express(int n)
{
	int D[n];
	D[0] = D[1] = D[2] = 1;		
	D[3] = 2;	D[4] = 4;
	for(int i=4; i<=n; i++)
	{
		D[n] = D[n-1] + D[n-3] + D[n-4];
	}
	return D[n];
}

int main()
{
	int n;
	cout << "Enter the number: ";
	cin >> n;
	cout << "The number of ways you can express it as a sum of 1, 3 and 4 is: " << express(n);
}
