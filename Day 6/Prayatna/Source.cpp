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
	std::vector<int> ans;
	for (int i = 0; i < T; i++)
	{
		int N, E;
		std::cin >> N >> E;
		std::vector<std::vector<int>> vertices(N);
		std::vector<bool> visited(N, false);
		
		
		for (int j = 0; j < E; j++)
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
		if (E == 0)
		{
			ans.push_back(vertices.size());
			continue;
		}
		int count = 0;
		for (int j = 1; j < N; j++)
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