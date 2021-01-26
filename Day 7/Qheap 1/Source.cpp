#include <iostream>
#include <queue>
#include <unordered_map>
int main()
{
	int Q;
	std::cin >> Q;
	int type, value;
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	std::unordered_map<int, bool> del;
	for (int i = 0; i < Q; i++)
	{
		std::cin >> type;
		if (type == 1)
		{
			std::cin >> value;
			pq.push(value);
		}
		else if (type == 2)
		{
			std::cin >> value;
			del[value] = true;
		}
		else
		{
			while (del.find(pq.top()) != del.end())
			{
				del.erase(pq.top());
				pq.pop();
			}
			std::cout << pq.top() << std::endl;
		}
	}
	return 0;
}