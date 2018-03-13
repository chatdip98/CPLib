#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long int lld;
unordered_map<lld, lld> m;

lld max(lld x, lld y){
	return x>y?x:y;
}

lld ans(int n)
{
	if(n==0)
		return 0;
	lld x = n/2, y = n/3, z = n/4;
	if(m.find(n)==m.end())
	{
		m.insert(pair<lld, lld> (n, max(n, max(x, ans(x)) + max(y, ans(y)) + max(z, ans(z)))));
	}	
	return m.find(n)->second;
}

int main()
{
	int n;
	while(cin>>n)
	{
		cout << ans(n) << endl;
	}	
	return 0;
}
