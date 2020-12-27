#include <iostream>
#include <vector>
int main()
{
	int n, k;
	std::cin >> n >> k;
	std::vector<int> arr;
	arr.reserve(n);
	for (int i = 0; i < n; i++)
	{
		int tmp;
		std::cin >> tmp;
		arr.push_back(tmp);
	}

	int L = 0, R = 0;
	int count = 0;
	std::vector<int> F;
	F.resize(100000 + 1, 0);
	while (R < n)
	{
		if (F[arr[R]] == 0)
		{
			count += 1;
		}
		R += 1;

		while (count == k)
		{
			F[arr[L]] -= 1;
			if (F[arr[L]] == 0)
			{

			}
		}
	}
	return 0;
}