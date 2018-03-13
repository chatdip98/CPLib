#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>
#define MAX 10000
using namespace std;

struct vertex
{
	int data;
	vertex *next;
};

struct DFS_data
{
	int n, time;
	int flag[MAX], start[MAX], end[MAX];
};

unordered_map<int, vertex*> create_graph(string s)
{
	unordered_map<int, vertex*> adj;
	int i, m, x;
	int n = s.length();
	vertex *temp, *head, *tail;
	head = tail = NULL;
	cout << "Give the number of neighbours and in the next line give the corresponding neighbour indices in order:" << endl;
	for(i=0; i<n; i++)
	{
		cin >> m;
		for(int j=0; j<m; j++)
		{
			cin >> x;
			temp = new vertex;
			temp->data = x;	
			temp->next = NULL;
			if(head==NULL)
			{
				head = tail = temp;
			}
			else
			{
				tail->next = temp;
				tail = temp;
			}
		}
		adj.insert(pair<int, vertex*> (i, head));
		head = tail = NULL;
	}
	return adj;
}

void BFS(string s, unordered_map<int, vertex*> adj)
{
	int n = s.length();
	int v, u, flag[n]={0}, level[n]={0};
	vertex *temp;
	queue<int> q;
	cout << "Which vertex do you want to consider as the root of your BFS: ";
	cin >> v;
	flag[v]=1;
	q.push(v);
	while(!q.empty())
	{
		u = q.front();
		q.pop();
		cout << s[u];
		auto it = adj.find(u);
		temp = it->second;
		while(temp!=NULL)
		{
			v = temp->data;
			if(flag[v]==0)
			{
				flag[v]=1;
				level[v]=level[u]+1;
				q.push(v);	
			}
			temp = temp->next;
		}
		flag[u] = 2;
	}
}

DFS_data DFS_visit(string s, int u, unordered_map<int, vertex*> adj, DFS_data d)
{
	d.time++;	d.start[u]=d.time;	d.flag[u]=1;
	auto it=adj.find(u);
	cout << s[u];
	vertex *temp=it->second;
	while(temp!=NULL)
	{
		int v = temp->data;
		if(d.flag[v]==0)
		{
			d = DFS_visit(s, v, adj, d);
		}	
		temp = temp->next;
	}
	d.time++;	d.end[u]=d.time;	d.flag[u]=2;
	return d;
}

void DFS(string s, unordered_map<int, vertex*> adj)
{
	DFS_data d;
	d.n=s.length();
	d.time=0;
	memset(d.flag, 0, sizeof(d.flag[0]));
	for(int i=0; i<d.n ;i++)
	{
		if(d.flag[i]==0)
			d = DFS_visit(s, i, adj, d);
	}
}

int main()
{
	unordered_map<int, vertex*> adj;
	string s;
	int i;
	cout << "Enter vertices in the form of a space terminated string: ";
	cin >> s;
	adj = create_graph(s);
	//uncomment BFS() or DFS() to perform Breadth-First-Search or Depth-First-Search
	//BFS(s, adj);
	//DFS(s, adj);
	return 0;
}
