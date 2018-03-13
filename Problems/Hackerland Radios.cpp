#include <bits/stdc++.h>
#include <set>
using namespace std;

int place_i(int i, int arr[])
{
    while(arr[i]==0)
    {
        i++;
    }
    return i;
}    
    
int place_j(int i, int arr[])
{
    while(arr[i]==0)
    {
        i--;
    }
    return i;
}    

int main()
{
    int n, x, k;
    cin >> n >> k;
    unordered_set<int> s;
    for(int x_i = 0;x_i < n;x_i++)
	{
       cin >> x;
	   if(s.find(x)==s.end())
    	{    		
			s.insert(x);
		}
    }
    int m = *max_element(s.begin(), s.end());
    cout << m << endl;
    int arr[m];
    for(int i=0; i<m; i++)
    {
    	if(s.find(i+1)!=s.end())
		{
			arr[i] = 1;	
		}	
	}
    int i=0,  j=m-1;
    i = place_i(i+2, arr);
    j = place_j(j-2, arr);
    int count=2;
    while(i<=j)
    {
        i = place_i(i+2, arr);
        j = place_j(j-2, arr);
        count+=2;
    }
    
    count -= int((i-j)/k);
    cout << count;
    return 0;
}
