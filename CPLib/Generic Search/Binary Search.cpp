#include <iostream>
using namespace std;
#define MAX 1000
int binary_search(int arr[MAX], int n, int key);
int main()
{
	int n, *arr, i, j, x;
	cout << "///Binary Search///\n\nEnter the number of array elements: ";
	cin >> n;
	arr = new int[n];
	cout << "Enter the array elements: ";
	for(i=0; i<n; i++)
	{
		cin >> arr[i];
	}
	cout << "Enter the key element: ";
	cin >> x;
	if(binary_search(arr, n, x) == -1)
	{
		cout << "Element not found.";
	}
	else
	{
		cout << "Element found at position " << binary_search(arr, n, x) << ".";
	}
	delete []arr;
	fflush(stdin);
	getchar();
	return 0;
}
int binary_search(int arr[MAX], int n, int key)
{
	int l = 0, u = n-1, m, flag = 0;
	while(flag == 0)
	{
		m = l + ((u-l)/2);
		if(l == m)
			flag = 1;
		if(arr[m] == key)	
		{
			return m;
		}
		if(arr[m] < key)
		{
			l = m+1;
		}
		else
		{
			u = m;
		}
	}
	return -1;
}
