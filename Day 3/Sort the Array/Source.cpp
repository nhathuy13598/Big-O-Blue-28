#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> arr;
	arr.reserve(n);
	for (int i = 0; i < n; i++)
	{
		int tmp;
		std::cin >> tmp;
		arr.push_back(tmp);
	}

	int begin = 0, end = n - 1;
	bool isDecrease = false;
	bool firstTime = true;
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i + 1] < arr[i])
		{
			if (firstTime == true)
			{
				if (isDecrease == false)
				{
					begin = i;
					isDecrease = true;
				}
			}
			else
			{
				std::cout << "no" << std::endl;
				return 0;
			}
		}
		else
		{
			if (isDecrease == true)
			{
				isDecrease = false;
				end = i;
				firstTime = false;
			}
		}
	}
	std::cout << "yes" << std::endl;
	std::cout << begin + 1 << " " << end + 1 << std::endl;
	return 0;
}