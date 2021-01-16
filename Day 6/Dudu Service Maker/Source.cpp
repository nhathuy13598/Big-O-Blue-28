#include <iostream>
#include <stack>
#include <vector>
bool DFS(int i, std::vector<std::vector<int>>& arr, std::vector<int>& visited)
{
	visited[i] = 1;
	for (int j = 0; j < arr[i].size(); j++)
	{

	}
}
int main()
{
	int T, N, M;
	std::cin >> T;
	for (int i = 0; i < T; i++)
	{
		std::cin >> N >> M;
		std::vector<std::vector<int>> arr(size_t(N) + 1);
		std::vector<int> visited(size_t(N) + 1, false);
		for (int j = 0; j < M; j++)
		{
			int a, b;
			std::cin >> a >> b;
			arr[a].push_back(b);
		}

		for (int i = 1; i <= N; i++)
		{
			if (DFS(i, arr, visited))
			{
				std::cout << "YES" << std::endl;
			}
			else
			{
				std::cout << "NO" << std::endl;
			}
		}
	}
	return 0;
}