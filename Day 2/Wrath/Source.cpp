#include <iostream>
#include <vector>
#include <numeric>
int main()
{
	int N;
	std::vector<int> claws;
	std::cin >> N;
	claws.reserve(N);
	for (int i = 0; i < N; i++)
	{
		int temp;
		std::cin >> temp;
		claws.push_back(temp);
	}

	std::vector<int> alive;
	alive.resize(N, 0);
	alive[N - 1] = 1;
	int kill = claws[N - 1];
	for (int i = N - 2; i >= 0; i--)
	{
		if (kill == 0)
		{
			alive[i] = 1;
			kill = claws[i];
		}
		else
		{
			kill -= 1;
			if (claws[i] >= kill)
			{
				kill = claws[i];
			}
		}
	}
	std::cout << std::accumulate(alive.begin(), alive.end(), 0) << std::endl;
	return 0;
}