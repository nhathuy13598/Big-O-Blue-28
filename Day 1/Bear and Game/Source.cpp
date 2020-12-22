#include <iostream>
#include <vector>
int main()
{
	int N;
	std::cin >> N;
	std::vector<int> minutes;
	for (int i = 0; i < N; i++)
	{
		int input;
		std::cin >> input;
		minutes.push_back(input);
	}
	int watch = 0;
	int init = 0;
	for (int i = 0; i < N; i++)
	{
		if (minutes[i] - init <= 15)
		{
			watch += minutes[i] - init;
			init = minutes[i];
		}
		else
		{
			watch += 15;
			std::cout << watch << std::endl;
			return 0;
		}
	}
	if (watch + 15 >= 90)
	{
		std::cout << 90 << std::endl;
	}
	else
	{
		std::cout << watch + 15 << std::endl;
	}
	return 0;
}