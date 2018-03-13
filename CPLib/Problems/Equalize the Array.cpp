#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>
#include <climits>
using namespace std;

int main() 
{
    int n, k;
    cin >> n;
    map<int , int> m;
    map<int , int> :: iterator it, i;
    for(int i=0; i<n; i++)
    {
        cin >> k;
        if(m.find(k)==m.end() || m.empty())
            m.insert(pair<int, int> (k, 1));
        else
        {
            it = m.find(k);
            it->second += 1;
        }
    }
    int max = INT_MIN, key;
    for(it=m.begin(); it!=m.end(); it++)
    {
        if(it->second > max)
        {
            max = it->second;
            key = it->first;
        }
    }
    it = m.find(key);
    int count = 0;
    for(i=m.begin(); i!=m.end(); i++)
    {
        if(i!=it)
        {
            count += i->second;
        }
    }
    cout << count;
    return 0;
}
