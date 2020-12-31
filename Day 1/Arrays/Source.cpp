#include <iostream>
#include <vector>
int main()
{
	int na, nb;
	int k, m;
	std::cin >> na >> nb;
	std::cin >> k >> m;
	std::vector<int> a(na), b(nb);
	
	for (int i = 0; i < na; i++)
	{
		std::cin >> a[i];
	}

	for (int i = 0; i < nb; i++)
	{
		std::cin >> b[i];
	}
	if (a[k - 1] < b[nb - m])
	{
		std::cout << "YES" << std::endl;
	}
	else
	{
		std::cout << "NO" << std::endl;
	}
	return 0;
}