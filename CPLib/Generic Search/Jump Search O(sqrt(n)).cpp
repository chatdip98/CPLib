#include <iostream>
#include <cmath>
using namespace std;
#define MAX 1000
int jump_search(int arr[MAX], int n, int key);
int main()
{
	int n, *arr, i, j, x;
	cout << "///Binary Search///\n\nEnter the number of array elements: ";
	cin >> n;
	arr = new int[n];
	cout << "Enter the sorted array elements: ";
	for(i=0; i<n; i++)
	{
		cin >> arr[i];
	}
	cout << "Enter the key element: ";
	cin >> x;
	if(jump_search(arr, n, x) == -1)
	{
		cout << "Element not found.";
	}
	else
	{
		cout << "Element found at position " << jump_search(arr, n, x) << ".";
	}
	delete []arr;
	fflush(stdin);
	getchar();
	return 0;
}
int jump_search(int arr[MAX], int n, int key)
{
	int i, c = -1, m = (int)sqrt(n);
	for(i=0; i<n; i+=m)
	{
		if(arr[i] > key)
		{
			c = i-m;
			break;
		}
	}
	if(c == -1)
		return c;
	else
	{
		for(i=c; i<=c+m; i++)
		{
			if(arr[i] == key)
				return i;
		}
	}
}
