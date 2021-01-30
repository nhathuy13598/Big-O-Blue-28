#include <iostream>
#include <vector>
using namespace std;
struct Point {
	int source, target;
};
vector<int> dist;
vector<Point> graph;
vector<int> cost_energy;
#define INF 1e9
int vertices;
int edges = 0;
int start_energy = 100;
bool BellmanFord(int start)
{
	int source, target;
	dist[start] = 0;
	for (int i = 1; i <= vertices - 1; i++)
	{
		for (int j = 0; j < edges; j++)
		{
			source = graph[j].source;
			target = graph[j].target;
			if (dist[source] != INF && dist[source] + cost_energy[target] < dist[target])
			{
				dist[target] = dist[source] + cost_energy[target];
				if (target == vertices)
				{
					return false;
				}
			}
		}
	}
	for (int j = 0; j < edges; j++)
	{
		source = graph[j].source;
		target = graph[j].target;
		if (dist[source] != INF && dist[source] + cost_energy[target] > dist[target])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	cin >> vertices;
	cost_energy.resize(size_t(vertices) + 1, 0);
	dist.resize(size_t(vertices) + 1, INF);
	while (vertices != -1)
	{
		graph.clear();
		cost_energy.assign(cost_energy.size(), 0);
		dist.assign(dist.size(), INF);

		for (int i = 0; i < vertices; i++)
		{
			int energy, doorways;
			cin >> energy >> doorways;
			cost_energy[size_t(i) + 1] = energy;
			edges += doorways;
			for (int j = 0; j < doorways; j++)
			{
				int roomID;
				cin >> roomID;
				graph.push_back(Point{ i + 1,roomID });
			}
		}
		
		bool isCycle = BellmanFord(1);
		if (isCycle || dist[size_t(vertices)] <= -start_energy || dist[size_t(vertices)] == INF)
		{
			cout << "hopeless" << endl;
		}
		else
		{
			cout << "winnable" << endl;
		}
		cin >> vertices;
		edges = 0;
	}
	return 0;
}