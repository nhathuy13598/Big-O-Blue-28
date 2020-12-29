#include <iostream>
#include <vector>

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
	int L, R, max, min;
	L = 0;
	R = 0;
	max = INT32_MIN;
	min = INT32_MAX;
	int len = 0;
	while (R < N)
	{
		if (nums[R] >= max)
		{
			max = nums[R];
		}
		if (nums[R] <= min)
		{
			min = nums[R];
		}
		if (nums[L] >= max)
		{
			max = nums[L];
		}
		if (nums[L] <= min)
		{
			min = nums[L];
		}
		if (max - min <= 1)
		{
			if (R - L >= len)
			{
				len = R - L + 1;
			}
			R += 1;
		}
		else
		{
			L += 1;
		}
	}
	std::cout << len << std::endl;
	return 0;
}