#include <iostream>
#include <climits>
#define MAX 100
using namespace std;
int max(int x, int y, int z);
int maxsum(int arr[MAX], int l, int u);
int cross_sum(int arr[MAX], int l, int u, int m);
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
	cout << "The value of maximum sum subarray is: " << maxsum(arr, 0, n-1) << endl;
	fflush(stdin);
	getchar();
	return 0;
}
int max(int x, int y, int z)
{
	if(x>y)
	{
		if(z>x)
			return z;
		else
			return x;
	}
	else
	{
		if(z>y)
			return z;
		else
			return y;
	}
}
int maxsum(int arr[MAX], int l, int u)
{
	int m = (l+u)/2;
	if(l==u)
		return arr[l];
	else if(l<u)
	{
		return max(maxsum(arr, l, m), maxsum(arr, m+1, u), cross_sum(arr, l, u, m));
	}
}
int cross_sum(int arr[MAX], int l, int u, int m)
{
	int i, sum = 0, max1 = INT_MIN, max2 = INT_MIN;
	for(i=m; i>=l; i--)
	{
		sum+=arr[i];
		if(sum>max1)
			max1 = sum;
	}
	sum = 0;
	for(i=m+1; i<=u; i++)
	{
		sum+=arr[i];
		if(sum>max2)
			max2 = sum;
	}
	return (max1+max2);
}
