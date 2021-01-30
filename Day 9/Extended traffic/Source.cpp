#include <iostream>
#include <vector>
#include <limits>
using namespace std;
const int INF = 1e9;
struct Edge {
	int source;
	int target;
	int weight;
};
vector<Edge> graph;
vector<int> dist;
vector<int> busyness;
int n, m;
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
		auto res = getchar();
		cin >> n;
		busyness.resize(size_t(n) + 1);
		for (int j = 1; j <= n; j++)
		{
			int tmp;
			cin >> tmp;
			busyness[j] = tmp;
		}
		cin >> m;
		graph.erase(graph.begin(), graph.end());
		for (int j = 0; j < m; j++)
		{
			int u, v;
			cin >> u >> v;
			int w = busyness[size_t(v)] - busyness[size_t(u)];
			w = w * w * w;
			graph.push_back(Edge{ u, v, w });
		}

		dist.resize(size_t(n) + 1, INF);
		bool loop = BellmanFord(1);
		int q;
		cin >> q;
		vector<size_t> queries;
		for (int j = 0; j < q; j++)
		{
			size_t temp;
			cin >> temp;
			queries.push_back(temp);
		}
		cout << "Case " << i + 1 << ":" << endl;
		for (int j = 0; j < q; j++)
		{
			if (dist[queries[j]] == INF || dist[queries[j]] < 3 || loop)
			{
				cout << "?" << endl;
			}
			else
			{
				cout << dist[queries[j]] << endl;
			}
		}
	}
	return 0;
}
