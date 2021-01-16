#include <iostream>
#include <vector>
#include <stack>

struct Point {
	int x, y;
	Point(int i, int j)
	{
		x = i;
		y = j;
	}
};
std::vector<Point> lake;
std::vector<Point> ocean;
bool isValid(int x, int y, int n, int m)
{
	return x >= 0 && x < n&& y >= 0 && y < m;
}
bool isBorder(int x, int y, int n, int m)
{
	return (x == 0 || x == n - 1 || y == 0 || y == m - 1);
}
void DFS(int x, int y, std::vector<std::vector<char>>& arr, std::vector<std::vector<bool>>& visited, 
	int& count, int& change, bool transform = false)
{
	std::stack<Point> st;
	st.emplace(x, y);
	visited[x][y] = true;
	int off_x[] = { -1, 0,0,1 };
	int off_y[] = { 0,-1,1,0 };
	bool isOcean = isBorder(x, y, arr.size(), arr[0].size());
	std::vector<Point> path;
	while (!st.empty())
	{
		Point u = st.top();
		path.push_back(u);
		st.pop();
		for (int i = 0; i < 4; i++)
		{
			int vx = u.x + off_x[i];
			int vy = u.y + off_y[i];
			if (isValid(vx, vy , arr.size(), arr[0].size()))
			{
				if (visited[vx][vy] == false && arr[vx][vy] == '.')
				{
					st.emplace(vx, vy);
					visited[vx][vy] = true;
					if (isBorder(vx, vy, arr.size(), arr[0].size()))
					{
						isOcean = true;
					}
				}
			}
		}
	}
	if (!isOcean)
	{
		lake.push_back({ x,y });
		count += 1;
	}
	else
	{
		ocean.push_back({ x,y });
	}
	if (transform)
	{
		for (int i = 0; i < path.size(); i++)
		{
			if (isOcean && isBorder(path[i].x, path[i].y, arr.size(), arr[0].size()))
			{
				arr[path[i].x][path[i].y] = '*';
				change += 1;
			}
			else if (isOcean == false)
			{
				arr[path[i].x][path[i].y] = '*';
				change += 1;
			}
		}
	}
}
int main()
{
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<std::vector<char>> arr(n);
	std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
	for (int i = 0; i < n; i++)
	{
		arr[i].resize(m);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cin >> arr[i][j];
		}
	}

	int count = 0;
	int change = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == '*')
			{
				continue;
			}
			if (visited[i][j] == false)
			{
				DFS(i, j, arr, visited, count, change);
			}
		}
	}
	std::vector<std::vector<bool>> temp(n, std::vector<bool>(m, false));
	visited = temp;

	if (count < k)
	{
		for (int i = 0; i < ocean.size(); i++)
		{
			DFS(ocean[i].x, ocean[i].y, arr, visited, count, change, true);
			count += 1;
			if (count == k)
			{
				break;
			}
		}
	}
	else if (count > k)
	{
		for (int i = 0; i < lake.size(); i++)
		{
			DFS(ocean[i].x, ocean[i].y, arr, visited, count, change, true); 
			count -= 1;
			if (count == k)
			{
				break;
			}
		}
	}
	std::cout << change << std::endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cout << arr[i][j];
		}
		std::cout << std::endl;
	}
	return 0;
}