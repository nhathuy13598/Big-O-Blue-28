#include <iostream>
#include <vector>
#include <limits>
using namespace std;
vector<int> dist;
int n, m;
struct Edge {
	int source;
	int target;
	int weight;
};
vector<Edge> graph;
const int INF = 1e9;
bool BellmanFord(int s)
{
	int u, v, w;
	dist[s] = 0;
	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = 0; j < m; j++)
		{
			u = graph[j].source;
			v = graph[j].target;
			w = graph[j].weight;
			if (dist[u] != INF && dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		u = graph[i].source;
		v = graph[i].target;
		w = graph[i].weight;
		if (dist[u] != INF && dist[u] + w < dist[v])
		{
			return true;
		}
	}
	return false;
}
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> m;
		int u, v, w;
		dist.resize(n, INF);
		graph.erase(graph.begin(), graph.end());
		for (int j = 0; j < m; j++)
		{
			cin >> u >> v >> w;
			graph.push_back(Edge{ u,v,w });
		}
		for (int s = 0; s < n; s++)
		{
			if (BellmanFord(s))
			{
				cout << "possible" << endl;
				break;
			}
			if (s == n - 1)
			{
				cout << "not possible" << endl;
			}
		}
	}
	return 0;
}
