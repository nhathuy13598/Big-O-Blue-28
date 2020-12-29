#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
	int N, x;
	std::cin >> N >> x;
	std::vector<int> chapters;
	chapters.reserve(N);
	for (int i = 0; i < N; i++)
	{
		int temp;
		std::cin >> temp;
		chapters.push_back(temp);
	}

	std::sort(chapters.begin(), chapters.end());
	int64_t ans = 0;
	for (int i = 0; i < N; i++)
	{
		ans += int64_t(chapters[i]) * x;
		if (x != 1)
		{
			x -= 1;
		}
	}
	std::cout << ans << std::endl;
	return 0;
}