/*--------DibyadipChaterjee--------*/
/*------------dichat98-------------*/
#include <bits/stdc++.h>
#define ini(arr, val) memset(arr, val, sizeof(arr))
#define print(arr, n) for(i=0; i<n; i++) cout << arr[i] << " "; cout << endl;
#define sum(arr, n) accumulate(arr, arr+n, 0, plus<int>())
using namespace std;

int n;

void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);	
	adj[v].push_back(u);	
}

vector<int> bfs_level(vector<int> adj[], int s)
{	
	vector<int> level(n, -1), flag(n, 0);
	int v, u;
	queue<int> q;
	flag[s]=1;
	level[s] = 0;
	q.push(s);
	while(!q.empty())
	{
		u = q.front();
		q.pop();
		//cout << u << endl;		
		int i = 0;
		while(i<adj[u].size())
		{
			v = adj[u][i];
			if(flag[v]==0)
			{
				flag[v]=1;
				level[v]=level[u]+1;
				q.push(v);	
			}
			i++;
		}
		flag[u] = 2;
	}
	return level;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	int i, k, t, u, v, s, m;
	scanf("%d", &t);
	for(int a0=0; a0<t; a0++)
	{
		scanf("%d %d", &n ,&m);
		vector<int> adj[n];
		for(i=0; i<m; i++)
		{
			scanf("%d %d", &u ,&v);
			addEdge(adj, u-1, v-1);
		}
		scanf("%d", &s);	s--;
		vector<int> level = bfs_level(adj, s);		
		for(i=0; i<n; i++)
		{
			if(i!=s)
			{
				if(level[i]==-1)
					printf("-1 ");
				else
					printf("%d ", 6*level[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
