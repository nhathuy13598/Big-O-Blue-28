#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;
#define MAX 1e9
vector<vector<bool>> graph;
vector<vector<int>> dist;
void FloydWarshall()
{
	int v = graph[0].size();
	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < v; j++)
		{
			if (graph[i][j] && i != j)
			{
				dist[i][j] = 1;
			}
			else if (i == j)
			{
				dist[i][j] = 0;
			}
			else
			{
				dist[i][j] = MAX;
			}
			
		}
	}
	for (int k = 0; k < v; k++)
	{
		for (int i = 0; i < v; i++)
		{
			for (int j = 0; j < v; j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}
int main()
{
	int T;
	cin >> T;
	int size = 0;
	for (int i = 0; i < T; i++)
	{
		graph.clear();
		string input;
		cin >> input;
		graph = vector<vector<bool>>(input.size(), vector<bool>(input.size()));
		dist = vector<vector<int>>(input.size(), vector<int>(input.size()));
		for (int j = 0; j < input.size(); j++)
		{
			if (input[j] == 'Y')
			{
				graph[0][j] = true;
			}
		}
		for (int j = 1; j < input.size(); j++)
		{
			cin >> input;
			for (int k = 0; k < input.size(); k++)
			{
				if (input[k] == 'Y')
				{
					graph[j][k] = true;
				}
			}
		}
		FloydWarshall();
		int max_id = MAX;
		int max_friend = -1;
		for (int j = 0; j < graph[0].size(); j++)
		{
			int count = 0;
			for (int k = 0; k < graph[0].size(); k++)
			{
				if (dist[j][k] == 2)
				{
					count += 1;
				}
			}
			if (count > max_friend)
			{
				max_friend = count;
				max_id = j;
			}
		}
		cout << max_id << " " << max_friend << endl;
	}
	return 0;
}