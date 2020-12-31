#include <iostream>
#include <vector>
int main()
{
	int N;
	std::cin >> N;
	std::vector<int> minutes(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> minutes[i];
	}
	
	int T = 0;
	for (int i = 0; i < N; i++)
	{
		if (minutes[i] <= T + 15)
		{
			T = minutes[i];
		}
		else
		{
			T += 15;
			break;
		}
	}
	
	if (T > 90)
	{
		std::cout << 90 << std::endl;
	}
	else
	{
		std::cout << T << std::endl;
	}
	return 0;
}