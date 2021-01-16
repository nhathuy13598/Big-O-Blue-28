#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

void DFS(int src, std::vector<bool>& visited, std::vector<std::vector<int>> vertice, std::vector<int>& girls, std::vector<int>& ans)
{
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
				st.push(v);
				ans[v] = ans[u] + 1;
			}
		}
	}
}
int main()
{
	int N, u, v, Q;
	std::cin >> N;
	std::vector<std::vector<int>> vertice(N + 1);
	std::vector<bool> visited(N + 1, false);
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
	std::vector<int> ans(N + 1, 0);
	DFS(1, visited, vertice, girls, ans);
	int min = 1001, index = 1001;
	for (int i = 0; i < Q; i++)
	{
		if (ans[girls[i]] < min)
		{
			min = ans[girls[i]];
			index = girls[i];
		}
		else if (ans[girls[i]] == min)
		{
			index = std::min(girls[i], index);
		}
	}
	std::cout << index << std::endl;
	return 0;
}