#include <iostream>
#include <vector>
#include <numeric>
int main()
{
	int N, M;
	std::vector<int> prob, prep;
	std::cin >> N >> M;

	prob.reserve(N);
	prep.reserve(M);
	for (int i = 0; i < N; i++)
	{
		int tmp;
		std::cin >> tmp;
		prob.push_back(tmp);
	}
	for (int i = 0; i < M; i++)
	{
		int tmp;
		std::cin >> tmp;
		prep.push_back(tmp);
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
	std::cout << N - i<< std::endl;
	return 0;
}