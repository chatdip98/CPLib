#include <iostream>
using namespace std;

int check_prime(int x);
int main()
{
	int n, i, flag;
	cout << "Enter an integer: ";
	cin >> n;
	cout << "The prime factors of " << n << " are:" << endl;
	for(i = 2; i < n; i++)
	{
		flag = check_prime(i);
		if(flag == 1 && n%i ==0)
		{
			cout << i << " ";
		}
	}
	fflush(stdin);
	getchar();
	return 0;
}
int check_prime(int x)
{
	int z;
	for(z = 2; z < x; z++)
	{
		if(x%z == 0)
		{
			return 0;
		}
	}
	return 1;
}
