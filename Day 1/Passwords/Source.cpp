#include <iostream>
#include <vector>
#include <string>
int main()
{
	int n, k;
	std::cin >> n >> k;
	int count[101] = { 0 };
	std::string pass;
	for (int i = 0; i < n; i++)
	{
		std::cin >> pass;
		count[pass.size()] += 1;
	}
	
	std::cin >> pass;

	int worst = 0, best = 0;
	for (int i = 1; i < pass.size(); i++)
	{
		best += count[i];
	}
	worst = best + count[pass.size()] - 1;
	best += best / k * 5 + 1;
	worst += worst / k * 5 + 1;
	std::cout << best << " " << worst << std::endl;
	return 0;
}