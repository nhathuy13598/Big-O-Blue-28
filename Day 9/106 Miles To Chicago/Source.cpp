#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
#define INF -1
struct Point {
	int source;
	int target;
	double weight;
};
vector<double> prob;
vector<Point> graph;
int n, m;
void BellmanFord(int start)
{
	int u, v;
	double p;
	prob[start] = 1;
	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = 0; j < m * 2; j++)
		{
			u = graph[j].source;
			v = graph[j].target;
			p = graph[j].weight;
			if (prob[size_t(u) - 1] != INF && prob[size_t(u) - 1] * p > prob[size_t(v) - 1])
			{
				prob[size_t(v) - 1] = prob[size_t(u) - 1] * p;
			}
		}
	}
}
int main()
{
	cin >> n;
	while (n != 0)
	{
		cin >> m;
		prob.clear();
		graph.clear();
		prob.resize(size_t(n), INF);
		for (int i = 0; i < m; i++)
		{
			int u, v, p;
			cin >> u >> v >> p;
			graph.push_back(Point{ u,v,p / 100.0 });
			graph.push_back(Point{ v,u,p / 100.0 });
		}
		BellmanFord(0);
		cout << setprecision(6) << fixed << prob[size_t(n) - 1] * 100 << " percent" << endl;
		cin >> n;
	}
	return 0;
}