#include <iostream>
using namespace std;
#define MAX 1000
int binary_search(int arr[MAX], int n, int key);
int search_rec(int arr[MAX], int l, int u, int key);
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
int search_rec(int arr[MAX], int l, int u, int key)
{
	int m = (l+u)/2;
	if(l>u)
		return -1;
	else
	{
		if(arr[m] == key)
		{	
			return m;
		}
		else
		{
			if(arr[m] < key)
			{
				return search_rec(arr, m+1, u, key);
			}
			else
			{
				return search_rec(arr, 0, m, key);
			}
		}		
	}
}
int binary_search(int arr[MAX], int n, int key)
{
	return search_rec(arr, 0, n-1, key);
}
