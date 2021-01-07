#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
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
	double m = std::min(1.0 * wines[0], double (1.0) * wines[k] / 2);
	double total = 3 * m * k;
	std::cout << std::setprecision(9) << std::min(total, double (1.0) * N);
	return 0;
}