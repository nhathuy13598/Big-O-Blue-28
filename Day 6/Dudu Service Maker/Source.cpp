#include <iostream>
#include <stack>
#include <vector>
bool DFS(int i, std::vector<std::vector<int>>& arr, std::vector<bool>& visited)
{
	std::stack<int> st;
	st.push(i);
	visited[i] = true;
	while (!st.empty())
	{
		int u = st.top();
		st.pop();
		for (int i = 0; i < arr[u].size(); i++)
		{
			int v = arr[u][i];
			if (visited[v] == true)
			{
				return true;
			}
			else
			{
				st.push(v);
				visited[v] = true;
			}
		}
	}
	return false;
}
int main()
{
	int T, N, M;
	std::cin >> T;
	for (int i = 0; i < T; i++)
	{
		std::cin >> N >> M;
		std::vector<std::vector<int>> arr(size_t(N) + 1);
		std::vector<bool> visited(size_t(N) + 1, false);
		for (int j = 0; j < M; j++)
		{
			int a, b;
			std::cin >> a >> b;
			arr[a].push_back(b);
		}

		for (int i = 1; i <= N; i++)
		{
			if (visited[i] == false)
			{
				if (DFS(i, arr, visited))
				{
					std::cout << "YES" << std::endl;
					break;
				}
			}
			if (i == N - 1)
			{
				std::cout << "NO" << std::endl;
			}
		}
	}
	return 0;
}