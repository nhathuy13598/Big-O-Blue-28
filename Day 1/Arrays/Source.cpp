#include <iostream>
#include <vector>
int main()
{
	int na, nb;
	int k, m;
	std::cin >> na >> nb;
	std::cin >> k >> m;
	std::vector<int> a, b;
	a.reserve(na);
	b.reserve(nb);
	for (int i = 0; i < na; i++)
	{
		int tmp;
		std::cin >> tmp;
		a.push_back(tmp);
	}

	for (int i = 0; i < nb; i++)
	{
		int tmp;
		std::cin >> tmp;
		b.push_back(tmp);
	}

	for (int i = 0; i < nb; i++)
	{
		if (b[i] > a[k - 1])
		{
			if (i + m - 1 < nb)
			{
				std::cout << "YES" << std::endl;
				return 0;
			}
		}
	}
	std::cout << "NO" << std::endl;
	return 0;
}