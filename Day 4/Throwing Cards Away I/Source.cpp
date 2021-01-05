#include <iostream>
#include <queue>
#include <vector>
int main()
{
	int N;
	std::cin >> N;
	while (N != 0)
	{
		std::queue<int> q;
		for (int i = 1; i <= N; i++)
		{
			q.push(i);
		}
		std::vector<int> discards;
		while (q.size() != 1)
		{
			discards.push_back(q.front());
			q.pop();
			q.push(q.front());
			q.pop();
		}
		std::cout << "Discarded cards:";
		for (int i = 0; i < discards.size(); i++)
		{
			if (i == 0)
			{
				std::cout << " ";
			}
			std::cout << discards[i];
			if (i != discards.size() - 1)
			{
				std::cout << ", ";
			}
		}
		std::cout << std::endl;
		std::cout << "Remaining card: " << q.front() << std::endl;
		
		std::cin >> N;
	}
	return 0;
}