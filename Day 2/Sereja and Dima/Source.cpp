#include <iostream>
#include <vector>

int main()
{
	int N;
	std::cin >> N;
	std::vector<int> nums(N);

	for (int i = 0; i < N; i++)
	{
		std::cin >> nums[i];
	}

	int L = 0, R = N - 1;

	int ans[2] = {};
	int player = 0;
	while (L <= R)
	{
		if (nums[L] > nums[R])
		{
			ans[player] += nums[L];
			L += 1;
		}
		else
		{
			ans[player] += nums[R];
			R -= 1;
		}
		player = 1 - player;
	}
	std::cout << ans[0] << " " << ans[1] << std::endl;
	return 0;
}