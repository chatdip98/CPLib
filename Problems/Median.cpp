#include <iostream>
using namespace std;
#define MAX 1000
int median_merge(int arr1[MAX], int l1, int u1, int arr2[MAX], int l2, int u2);
int max(int x, int y);
int min(int x, int y);
int main()
{
	int arr1[] = {1, 2, 3, 6}, arr2[] = {4, 6, 8, 10};
	cout << "The median of the merged array is: " << median_merge(arr1, 0, 3, arr2, 0, 3);
	return 0;
}
int max(int x, int y)
{
	if(x>y)
		return x;
	else
		return y;
}
int min(int x, int y)
{
	if(x<y)
		return x;
	else
		return y;
}
int median_merge(int arr1[MAX], int l1, int u1, int arr2[MAX], int l2, int u2)
{
	int med1, med2;
	med1 = (u1+l1)/2;
	med2 = (u2+l2)/2;
	if((u1-l1) <= 2 || (u2-l2) <= 2)
	{
		return (max(arr1[l1], arr2[l2]) + min(arr1[u1], arr2[u2]))/2;
	}
	else
	{
		if(arr1[med1] == arr2[med2])
			return arr1[med1];
		else
		{
			if(arr1[med1]>arr2[med2])
			{
				return median_merge(arr1, l1, med1, arr2, med2, u2);
			}
			else
			{
				return median_merge(arr1, med1, u1, arr2, l2, med2);
			}
		}	
	}
}
