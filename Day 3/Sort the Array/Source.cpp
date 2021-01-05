#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
	int n;
	std::cin >> n;
	std::vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}

	std::vector<int> temp_arr(arr);
	std::sort(temp_arr.begin(), temp_arr.end());
	bool hasReverse = false;
	int start = 0, end = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] != temp_arr[i])
		{
			if (hasReverse)
			{
				std::cout << "no" << std::endl;
				return 0;
			}
			for (int j = n - 1; j >= 0; j--)
			{
				if (arr[j] != temp_arr[j])
				{
					std::reverse(temp_arr.begin() + i, temp_arr.begin() + j + 1);
					hasReverse = true;
					start = i;
					end = j;
					break;
				}
			}
		}
	}
	if (hasReverse)
	{
		std::cout << "yes\n" << start + 1 << " " << end + 1 << std::endl;
	}
	else
	{
		std::cout << "yes\n1 1" << std::endl;
	}
	
	return 0;
}