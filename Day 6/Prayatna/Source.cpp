#include <iostream>
#include <vector>
#include <string>
#include <stack>
void DFS(int src, std::vector<std::vector<int>>& vertices, std::vector<bool>& visited)
{
	std::stack<int> st;
	st.push(src);
	visited[src] = true;
	while (!st.empty())
	{
		int u = st.top();
		st.pop();
		for (int i = 0; i < vertices[u].size(); i++)
		{
			int v = vertices[u][i];
			if (!visited[v])
			{
				st.push(v);
				visited[v] = true;
			}
		}
	}
}
int main()
{
	int T;
	std::cin >> T;
	std::vector<int> peers(T);
	for (int i = 0; i < T; i++)
	{
		std::cin >> peers[i];
	}
	std::vector<int> ans;
	for (int i = 0; i < T; i++)
	{
		std::vector<std::vector<int>> vertices(peers[i]);
		std::vector<bool> visited(peers[i], false);
		for (int j = 0; j < peers[i] / 2; j++)
		{
			std::string input;
			std::getline(std::cin, input);
			if (input == "")
			{
				j -= 1;
				continue;
			}
			int src = 0;
			if (input.find(" ") != std::string::npos)
			{
				size_t p;
				int first = std::stoi(input, &p);
				int second = std::stoi(std::string(input.begin() + p, input.end()));
				vertices[first].push_back(second);
				vertices[second].push_back(first);
				src = first;
			}
		}
		int count = 0;
		for (int j = 0; j < peers[i]; j++)
		{
			if (visited[j] == false)
			{
				DFS(j, vertices, visited);
				count += 1;
			}
		}
		ans.push_back(count);
	}
	for (int i = 0; i < ans.size(); i++)
	{
		std::cout << ans[i] << std::endl;
	}
	return 0;
}