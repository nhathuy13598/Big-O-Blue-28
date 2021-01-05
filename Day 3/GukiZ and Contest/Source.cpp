#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
	int N;
	std::cin >> N;
	std::vector<int> ratings(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> ratings[i];
	}
	std::vector<int> temp(ratings);
	std::sort(temp.begin(), temp.end());

	int count[2000 + 1];
	for (int i = 0; i < N; i++)
	{
		count[temp[i]] = N - i;
	}
	for (int i = 0; i < N; i++)
	{
		std::cout << count[ratings[i]];
		if (i != N - 1)
		{
			std::cout << " ";
		}
	}
	return 0;
}