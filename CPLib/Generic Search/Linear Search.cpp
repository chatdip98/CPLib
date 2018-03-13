#include <iostream>
using namespace std;
#define MAX 1000
int linear_search(int arr[MAX], int n, int key);
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
	if(linear_search(arr, n, x) == -1)
	{
		cout << "Element not found.";
	}
	else
	{
		cout << "Element found at position " << linear_search(arr, n, x) << ".";
	}
	delete []arr;
	fflush(stdin);
	getchar();
	return 0;
}
int linear_search(int arr[MAX], int n, int key)
{
	int i;
	for(i=0; i<n; i++)
	{
		if(arr[i] == key)
			return i;
	}
	return -1;
}
