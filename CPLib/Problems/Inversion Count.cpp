#include <iostream>
using namespace std;
 
void copy(int arr[], int a, int n, int temp[])
{
	int j = 0;
	for(int i=a; i<n ;i++)
	{
		temp[i] = arr[i];
		j++;
	}
}

int merge(int arr[], int temp[], int left, int mid, int right)
{
  int i, j, k;
  int inv_count = 0;
 
  i = left;
  j = mid; 
  k = left;
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];
      inv_count = inv_count + (mid - i);
    }
  }
  while (i <= mid - 1)
    temp[k++] = arr[i++];
  while (j <= right)
    temp[k++] = arr[j++];

  for (i=left; i <= right; i++)
    arr[i] = temp[i];
 
  return inv_count;
}

int _mergeSort(int arr[], int temp[], int left, int right)
{
  int mid, inv_count = 0;
  if (right > left)
  {
    mid = (right + left)/2;
    inv_count  = _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid+1, right);
    inv_count += merge(arr, temp, left, mid+1, right);
  }
  return inv_count;
}

int mergeSort(int arr[], int i, int array_size)
{
    int *temp;
	temp = new int[array_size];
    return _mergeSort(arr, temp, i, i+array_size - 1);
}

int main()
{
  int count = 0, n, m, *arr, *temp;
  cin >> n >> m;
  arr = new int[n];
  temp = new int[m];
  for(int i=0; i<n; i++)
  {
  	cin >> arr[i];
  }
  for(int i=0; i<n-m+1; i++)
  {
  	copy(arr, i, i+m, temp);
  	count += mergeSort(temp, i, m);
  }
  cout << count;
  delete []arr;
  delete []temp;
  return 0;
}
