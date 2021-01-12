#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX_VERTICE 1000
int DFS(int src, bool visited[], std::vector<int> vertice[], std::vector<int>& girls)
{
	int max = UINT32_MAX;
	visited[src] = true;
	std::stack<int> st;
	st.push(src);
	while (!st.empty())
	{
		int u = st.top();
		st.pop();
		for (int i = 0; i < vertice[u].size(); i++)
		{
			int v = vertice[u][i];
			if (!visited[v])
			{
				visited[v] = true;
				if (v < max)
				{
					st.push(v);
				}
				if (std::find(girls.begin(), girls.end(), v) != girls.end())
				{
					max = std::max(v, max);
				}
				
			}
		}
	}
	return max;
}
int main()
{
	int N, u, v, Q;
	std::cin >> N;
	std::vector<int> vertice[MAX_VERTICE];
	bool visited[MAX_VERTICE] = { false };
	for (int i = 0; i < N - 1; i++)
	{
		std::cin >> u >> v;
		vertice[u].push_back(v);
		vertice[v].push_back(u);
	}
	std::cin >> Q;
	std::vector<int> girls(Q);
	for (int i = 0; i < Q; i++)
	{
		std::cin >> girls[i];
	}
	
	std::cout << DFS(1, visited, vertice, girls) << std::endl;
	return 0;
}