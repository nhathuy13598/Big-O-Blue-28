#include <iostream>
#include <queue>
int main()
{
	int n;
	std::cin >> n;
	std::priority_queue<int> q;
	for (int i = 0; i < n; i++)
	{
		int type, value;
		std::cin >> type;
		if (type == 1)
		{
			std::cin >> value;
			q.push(value);
		}
		else
		{
			int min = 1000000001;
			std::vector<int> store;
			for (int i = q.size() / 3; i >= 1 ; i--)
			{
				if (q.top() < min)
				{
					min = q.top();
				}
				store.push_back(q.top());
				q.pop();
			}
			for (int i = 0; i < store.size(); i++)
			{
				q.push(store[i]);
			}
			if (min != 1000000001)
			{
				std::cout << min << std::endl;
			}
			else
			{
				std::cout << "No reviews yet" << std::endl;
			}
			
		}
	}
	return 0;
}