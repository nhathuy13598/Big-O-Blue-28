#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
	int N;
	std::cin >> N;
	std::vector<int> nums;
	nums.reserve(N);
	for (int i = 0; i < N; i++)
	{
		int temp;
		std::cin >> temp;
		nums.push_back(temp);
	}
	std::vector<int> F;
	F.resize(100000 + 1, 0);
	int L = 0, R = 0;
	int count = 0;
	int ans = 0;
	while (R < N)
	{
		if (F[nums[R]] == 0)
		{
			F[nums[R]] += 1;
			count += 1;
		}
		while (count > 2)
		{
			F[nums[L]] -= 1;
			if (F[nums[L]] == 0)
			{
				count -= 1;
			}
			L += 1;
		}
		R += 1;
		ans = std::max(ans, R - L);
	}
	std::cout << ans << std::endl;
	return 0;
}