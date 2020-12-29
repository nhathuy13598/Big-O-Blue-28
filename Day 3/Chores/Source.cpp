#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n, a, b;
	std::cin >> n >> a >> b;
	std::vector<int> chores;
	chores.reserve(n);
	for (int i = 0; i < n; i++)
	{
		int tmp;
		std::cin >> tmp;
		chores.push_back(tmp);
	}

	std::sort(chores.begin(), chores.end());
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		count += 1;
		if (count == b)
		{
			if (i != n - 1)
			{
				std::cout << chores[i + 1] - chores[i] << std::endl;
				return 0;
			}
			else
			{
				std::cout << 0 << std::endl;
				return 0;
			}
		}
	}
	return 0;
}