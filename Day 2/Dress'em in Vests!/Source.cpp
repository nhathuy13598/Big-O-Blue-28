#include <iostream>
#include <vector>

struct Vest
{
	int x, y;
	Vest(int a, int b)
	{
		x = a;
		y = b;
	}
};
int main()
{
	int N, M, X, Y;
	std::cin >> N >> M >> X >> Y;
	std::vector<int> soldiers(N), clothes(M);
	for (int i = 0; i < N; i++)
	{
		std::cin >> soldiers[i];
	}
	for (int i = 0; i < M; i++)
	{
		std::cin >> clothes[i];
	}
	std::vector<Vest> ans;
	int i = 0, j = 0;
	int count = 0;
	while (i < N && j < M)
	{
		if (clothes[j] >= soldiers[i] - X && soldiers[i] + Y >= clothes[j])
		{
			count += 1;
			i += 1;
			j += 1;
			ans.emplace_back(i, j);
		}
		else if (soldiers[i] + Y < clothes[j])
		{
			i += 1;
		}
		else
		{
			j += 1;
		}
	}
	
	std::cout << count << std::endl;
	for (const Vest& v : ans)
	{
		std::cout << v.x << " " << v.y << std::endl;
	}
	return 0;
}