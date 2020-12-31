#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
	int N, T;
	std::cin >> N >> T;
	std::vector<int> books(N);
	
	for (int i = 0; i < N; i++)
	{
		std::cin >> books[i];
	}
	int i = 0;
	int max = 0;
	for (int j = 0; j < N; j++)
	{
		T -= books[j];
		while (T < 0)
		{
			T += books[i];
			i += 1;
		}
		max = std::max(max, j - i + 1);
	}
	std::cout << max << std::endl;
	return 0;
}