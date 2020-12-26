#include <iostream>
#include <vector>
int main()
{
	int N;
	int L, R;
	int min = INT32_MAX, max = INT32_MIN;
	std::cin >> N;
	int res = -1;
	bool isChange = false;
	int rootL = 0, rootR = 0;
	for (int i = 0; i < N; i++)
	{
		std::cin >> L >> R;
		if (i == 0)
		{
			rootL = L;
			rootR = R;
		}
		if (L == R)
		{
			if (L < min)
				min = L;
			if (L > max)
				max = L;
			continue;
		}
		if (R <= min)
		{
			min = L;
			res = -1;
		}
		else if (R > max)
		{
			max = R;
			res = -1;
		}
		if (L >= max)
		{
			max = R;
			res = -1;
		}
		else if (L < min)
		{
			min = L; 
			res = -1;
		}

		if (min == L && max == R)
		{
			if (i != 0)
			{
				res = i + 1;
			}
		}
	}
	if (min == rootL && max == rootR)
	{
		std::cout << 1 << std::endl;
	}
	else
	{
		std::cout << res << std::endl;
	}
	
	return 0;
}