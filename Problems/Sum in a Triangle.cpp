#include <iostream>
#define max(x, y) x>y?x:y
using namespace std;

int main()
{
	int i, j, t, n;
	cin >> t;
	for(int a0=0; a0<t; a0++)
	{
		cin >> n;
		int **arr;
		arr = new int*[n];
		for(i=0; i<n; i++)
			arr[i] = new int[n];
		for(i=0; i<n; i++)
		{
			for(j=0; j<i+1; j++)
			{
				cin >> arr[i][j];	
			}
		}
		for(i=n-2; i>=0; i--)
		{
			for(j=0; j<i+1; j++)
			{
				arr[i][j] += max(arr[i+1][j], arr[i+1][j+1]);
			}
		}
		cout << arr[0][0] << endl;
	}
	return 0;
}
