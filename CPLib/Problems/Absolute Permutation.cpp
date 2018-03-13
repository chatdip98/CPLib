#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> generate(int n)
{
    vector<int> v;
    for(int i=1; i<=n; i++)
    {
        v.push_back(i);
    }
    return v;
}

void print(vector<int> v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int i, n, k, t;
    cin >> t;
    for(int a0=0; a0<t; a0++)
    {
        cin >> n >> k;
        vector<int> v = generate(n), cache(n, 0);
        if(k==0)
        {
            print(v);
        }
        else 
        {
            if(n%2!=0)
                cout << "-1" << endl;
            else
			{
				int flag=0, count = 0;
	            for(i=0; i<n && flag==0; i++)
	            {
	                if(cache[i]==0)
	                {
	                    if(i+k==n-1)
	                        flag = 1;
	                    else if(i+k>n-1)
	                    {
	                        flag=2;
	                        break;
	                    }
	                    v[i]^=v[i+k];
	                    v[i+k]^=v[i];
	                    v[i]^=v[i+k];
	                    cache[i] = cache[i+k] = 1;
	                    count+=2;
	                }
	                //print(cache);
	            }
	            //cout << flag << endl;
	            if(flag==1 && count==n)
	                print(v);
	            else
	                cout << "-1" << endl;
	        }
        }
    }
    return 0;
}

