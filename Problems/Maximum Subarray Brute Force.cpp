#include <iostream>
#include <climits>
#define MAX 100
using namespace std;
int maxsum(int arr[MAX], int n);
int main()
{
	int i, *arr, n;
	cout << "Enter the number of elements of the array: ";
	cin >> n;
	arr = new int[n];
	cout << "Enter the array elements:" << endl;
	for(i=0; i<n; i++)
	{
		cout << "Enter element" << "[" << i+1 << "]: ";
		cin >> arr[i];
	}
	cout << "The value of maximum sum subarray is: " << maxsum(arr, n) << endl;
	fflush(stdin);
	getchar();
	return 0;
}
int maxsum(int arr[MAX], int n)
{
	int i, j, sum, max = INT_MIN;
	for(i=0; i<n; i++)
	{
		sum = 0;
		for(j=i; j<n ;j++)
		{
			sum += arr[j];
			if(sum > max)
				max = sum;	
		}
	}
	return max;
}
