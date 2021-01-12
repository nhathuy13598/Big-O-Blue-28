#include <iostream>
#include <vector>
#include <queue>
void expandNode(std::vector<char>& arr, int col, std::queue<int>& q, const int& start)
{
	int offset[] = { 1,-1,col,-col };
	for (int i = 0; i < 4; i++)
	{
		if (start + offset[i] >= 0 && start + offset[i] < arr.size() && arr[start + offset[i]] == '.')
		{
			q.push(start + offset[i]);
		}
	}
}
int main()
{
	int N, M;
	std::cin >> N >> M;
	std::vector<char> arr(N * M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cin >> arr[i * M + j];
		}
	}
	int r1, c1, r2, c2;
	std::cin >> r1 >> c1 >> r2 >> c2;
	if (arr[(r2 - 1) * M + c2 - 1] == 'X')
	{
		std::cout << "NO" << std::endl;
		return 0;
	}
	std::queue<int> q;
	q.push((r1 - 1) * M + c1 - 1);
	while (!q.empty())
	{
		int node = q.front();
		if (node == (r2 - 1) * M + c2 - 1)
		{
			std::cout << "YES" << std::endl;
			return 0;
		}
		expandNode(arr, M, q, node);
		arr[node] = 'X';
		q.pop();
	}
	std::cout << "NO" << std::endl;
	return 0;
}