#include <iostream>
#include <stack>
#include <vector>
int main()
{
	int N;
	do
	{
		std::cin >> N;
		if (N == 0)
		{
			break;
		}
		std::vector<int> car_num(N);
		for (int i = 0; i < N; i++)
		{
			std::cin >> car_num[i];
		}
		int count = 1;
		std::stack<int> cars;
		for (int i = 0; i < N; i++)
		{
			if (car_num[i] == count)
			{
				count += 1;
			}
			else
			{
				while (!cars.empty())
				{
					if (cars.top() == count)
					{
						cars.pop();
						count += 1;
					}
					else
					{
						break;
					}
				}
				if (car_num[i] == count)
				{
					count += 1;
				}
				else
				{
					cars.push(car_num[i]);
				}
				
			}
		}

		while (!cars.empty())
		{
			if (cars.top() != count)
			{
				std::cout << "no" << std::endl;
				break;
			}
			cars.pop();
			count += 1;
		}
		if (cars.empty())
		{
			std::cout << "yes" << std::endl;
		}
	} while (true);
	return 0;
}