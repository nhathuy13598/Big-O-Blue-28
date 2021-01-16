#include <iostream>
#include <queue>
int main()
{
	int Q;
	std::cin >> Q;
	int type, value;
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	for (int i = 0; i < Q; i++)
	{
		std::cin >> type;
		if (type == 1)
		{
			std::cin >> value;
			if (pq.size() < 2)
			{
				pq.push(value);
			}
			else
			{
				int first = pq.top();
				pq.pop();
				int second = pq.top();
				pq.pop();
				if (value < second)
				{
					pq.push(first);
					pq.push(value);
				}
			}
			
		}
		else if (type == 2)
		{
			std::cin >> value;
			if (pq.size() == 1)
			{
				pq.pop();
			}
			else
			{
				int first = pq.top();
				pq.pop();
				int second = pq.top();
				pq.pop();
				if (value == second)
				{
					pq.push(first);
				}
				else
				{
					pq.push(second);
				}
			}
			
		}
		else
		{
			std::cout << pq.top() << std::endl;
		}
	}
	return 0;
}