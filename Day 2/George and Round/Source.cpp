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

	std::vector<int> F;
	F.resize(1000000 + 1, 0);

	for (int i = 0; i < N + M; i++)
	{
		if (i >= N && i < N + M)
		{
			if (F[prep[i - N]] != 0)
			{
				F[prep[i - N]] -= 1;
			}
		}
		else
		{
			if (F[prob[i]] == 0)
			{
				F[prob[i]] += 1;
			}
		}
	}
	std::cout << std::accumulate(F.begin(), F.end(), 0) << std::endl;
	return 0;
}