#include <iostream>
#include <vector>
using namespace std;
#define INF 1e9
struct Point
{
	int u, v, weight;
};
vector<int> dist;
vector<int> path;
vector<bool> multipath;
vector<Point> graph;
int n, m, q, s, dest;
void BellmanFord(int start)
{
	int u, v, w;
	dist[start] = 0;
	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = 0; j < m; j++)
		{
			u = graph[j].u;
			v = graph[j].v;
			w = graph[j].weight;
			if (dist[u] != INF && dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
				if (path[v] != -1 && u != start)
				{
					multipath[v] = true;
				}
				path[v] = u;
			}
		}
	}
}
int main()
{
	cin >> n;
	while (n != 0)
	{
		cin >> m >> q >> s;
		graph.clear();
		dist.clear();
		dist.resize(size_t(n), INF);
		path.clear();
		path.resize(size_t(n), -1);
		multipath.clear();
		multipath.resize(size_t(n), false);
		for (int i = 0; i < m; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			graph.push_back(Point{ u,v,w });
		}
		BellmanFord(s);
		for (int i = 0; i < q; i++)
		{
			cin >> dest;
			if (multipath[dest])
			{
				cout << "-Infinity" << endl;
			}
			else
			{
				if (dest >= n || dist[dest] == INF)
				{
					cout << "Impossible" << endl;
				}
				else
				{
					cout << dist[dest] << endl;
				}
			}
		}
		cout << "\n";
		cin >> n;
	}
	return 0;
}