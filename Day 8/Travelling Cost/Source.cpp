#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> node;
void Dijkstra(int start, vector<vector<node>>& graph, vector<int>& dist)
{
	priority_queue<node> pq;
	pq.push(make_pair(start, 0));
	dist[start] = 0;
	while (!pq.empty())
	{
		auto top = pq.top();
		pq.pop();
		int u = top.first;
		int w = top.second;
		for (int i = 0; i < graph[u].size(); i++)
		{
			auto neighbor = graph[u][i];
			if (w + neighbor.second < dist[neighbor.first])
			{
				dist[neighbor.first] = w + neighbor.second;
				pq.push(make_pair(neighbor.first, dist[neighbor.first]));
			}
		}

	}
}
int main()
{
	int N;
	cin >> N;
	vector<vector<node>> graph(N + 1);
	vector<int> dist(N + 1, INFINITY);
	for (int i = 0; i < N; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
	}
	int u;
	cin >> u;
	Dijkstra(u, graph, dist);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int v;
		cin >> v;
		if (dist[v] == INFINITY)
		{
			cout << "NO PATH" << std::endl;
		}
		else
		{
			cout << dist[v] << std::endl;
		}
	}
	return 0;
}