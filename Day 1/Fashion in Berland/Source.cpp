#include <iostream>
#include <vector>
int main() {
	int N;
	std::cin >> N;
	std::vector<int> buttons;
	for (int i = 0; i < N; i++) 
	{
		int a;
		std::cin >> a;
		buttons.push_back(a);
	}
	if (N == 1)
	{
		if (buttons[0] == 0)
		{
			std::cout << "NO" << std::endl;
		}
		else
		{
			std::cout << "YES" << std::endl;
		}
	}
	else
	{
		int count = 0;
		for (int i = 0; i < N; i++)
		{
			if (buttons[i] == 0)
			{
				count += 1;
			}
			if (count >= 2)
			{
				std::cout << "NO" << std::endl;
				return 0;
			}
		}
		if (count == 1)
		{
			std::cout << "YES" << std::endl;
		}
		else
		{
			std::cout << "NO" << std::endl;
		}
	}
	return 0;
}