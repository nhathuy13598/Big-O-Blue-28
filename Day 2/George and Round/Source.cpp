#include <iostream>
#include <vector>
#include <numeric>
int main()
{
	int N, M;
	std::cin >> N >> M;
	std::vector<int> prob(N), prep(M);
	
	for (int i = 0; i < N; i++)
	{
		std::cin >> prob[i];
	}
	for (int i = 0; i < M; i++)
	{
		std::cin >> prep[i];
	}

	int i = 0, j = 0;
	while (i < N && j < M)
	{
		if (prob[i] <= prep[j])
		{
			i += 1;
			j += 1;
		}
		else
		{
			j += 1;
		}
	}
	std::cout << N - i << std::endl;
	return 0;
}