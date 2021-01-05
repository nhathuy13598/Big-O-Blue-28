#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
int main()
{
	int K;
	std::cin >> K;
	std::vector<int> month(12);
	for (int i = 0; i < 12; i++)
	{
		std::cin >> month[i];
	}
	if (K == 0)
	{
		std::cout << 0 << std::endl;
		return 0;
	}
	std::sort(month.begin(), month.end(), std::greater<int>());
	int increase = 0;
	for (int i = 0; i < 12; i++)
	{
		if (increase + month[i] >= K)
		{
			std::cout << i + 1 << std::endl;
			return 0;
		}
		increase += month[i];
	}
	std::cout << -1 << std::endl;
	return 0;
}