#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
	int N;
	std::cin >> N;
	std::vector<int> claws(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> claws[i];
	}

	int count = 0;
	int last_kill_pos = N - 1;
	
	for (int i = N - 1; i >= 0; i--)
	{
		last_kill_pos = std::min(i, last_kill_pos);
		int reach = std::max(0, i - claws[i]);
		if (last_kill_pos > reach)
		{
			count += last_kill_pos - reach;
			last_kill_pos = reach;
		}
		
	}
	std::cout << N - count << std::endl;
	return 0;
}