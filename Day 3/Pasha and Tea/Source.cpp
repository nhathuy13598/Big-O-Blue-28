#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int k, N;
	std::cin >> k >> N;
	std::vector<int> wines(size_t(2) * k);
	for (int i = 0; i < 2 * k; i++)
	{
		std::cin >> wines[i];
	}
	std::sort(wines.begin(), wines.end());
	double max = 0.0;
	int L = 0;
	int R = k;
	while (R < 2 * k)
	{
		if (wines[R] / 2.0 < wines[L])
		{
			double wine = (wines[R] / 2.0) * (double(R) - L + 2 * (2.0 * k - R));
			max = std::max(wine, max);
			R += 1;
			continue;
		}
		else if (wines[R] / 2.0 == wines[L])
		{
			double wine = (wines[R] / 2.0) * (double(R) - L + 2 * (2.0 * k - R));
			max = std::max(wine, max);
			L += 1;
			continue;
		}
		if (L == k - 1)
		{
			double wine = wines[R] * (2.0 * k - R);
			max = std::max(wine, max);
			R += 1;
		}
		L += 1;
	}
	max = std::min(max, double(N));
	std::cout << max << std::endl;
	return 0;
}