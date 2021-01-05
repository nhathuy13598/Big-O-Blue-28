#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
	int N;
	std::cin >> N;
	std::vector<int> arr(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> arr[i];
	}

	std::sort(arr.begin(), arr.end());
	int tower = 0;
	int height = 0;
	int F[1000 + 1] = { 0 };
	for (int i = 0; i < N; i++)
	{
		if (F[arr[i]] == 0)
		{
			tower += 1;
		}
		F[arr[i]] += 1;
		height = std::max(height, F[arr[i]]);
	}
	std::cout << height << " " << tower << std::endl;
	return 0;
}