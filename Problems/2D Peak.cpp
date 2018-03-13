#include <iostream>
using namespace std;
#define MAX 1000
int max(int arr[][MAX], int n, int m)
{
	int max = 0, index;
	for(int i=0; i<n; i++)
	{
		if(arr[i][m] > max)
		{
			max = arr[i][m];
			index = i;
		}
	}
	return index;
}
int find_peak(int arr[][MAX], int l, int u, int n)
{
	int max_index, m = ((l+u)/2);
	max_index = max(arr, n, m);
	if(arr[max_index][m] < arr[max_index][m-1])
	{
		return find_peak(arr, 0, m, n);
	}
	else
	{
		if(arr[max_index][m] < arr[max_index][m+1])
		{
			return find_peak(arr, m+1, l, n);
		}
		else
		{
			return arr[max_index][m];
		}
	}	
}
int peak(int arr[][MAX], int n, int m)
{
	return find_peak(arr, 0, m-1, n);
}
int main()
{
	int n = 4, m = 4, arr[][MAX] = {{ 10, 8, 10, 10 }, { 14, 13, 12, 11 }, { 15, 9, 11, 21 }, { 16, 17, 19, 20 } };
	//{{0, 10, 0, 0}, {14, 13, 12, 0}, {15, 9, 11, 17}, {16, 17, 19, 20}};
	cout << "The peak element is: " << peak(arr, n, m);
}
