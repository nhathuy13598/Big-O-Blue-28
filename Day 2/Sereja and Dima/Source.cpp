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
		int tmp;
		std::cin >> tmp;
		nums.push_back(tmp);
	}

	int L = 0, R = N - 1;

	int sereja = 0;
	int dima = 0;
	bool player = true;
	while (L <= R)
	{
		if (player)
		{
			if (nums[R] > nums[L])
			{
				sereja += nums[R];
				R -= 1;
			}
			else
			{
				sereja += nums[L];
				L += 1;
			}
			player = false;
		}
		else
		{
			if (nums[R] > nums[L])
			{
				dima += nums[R];
				R -= 1;
			}
			else
			{
				dima += nums[L];
				L += 1;
			}
			player = true;
		}
	}
	std::cout << sereja << " " << dima << std::endl;
	return 0;
}