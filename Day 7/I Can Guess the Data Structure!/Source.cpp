#include <iostream>
#include <stack>
#include <queue>
#include <string>
int main()
{
	std::string a;
	while (!std::cin.eof())
	{
		std::cin >> a;
		if (a == "\n")
		{
			return 0;
		}
		int n = std::stoi(a);
		int type, value;
		std::stack<int> st;
		std::queue<int> q;
		std::priority_queue<int> pq;
		bool isStack = true, isQueue = true, isPriQueue = true;
		for (int i = 0; i < n; i++)
		{
			std::cin >> type >> value;
			if (type == 1)
			{
				st.push(value);
				q.push(value);
				pq.push(value);
			}
			else
			{
				if (isStack && st.top() != value)
				{
					isStack = false;
				}
				if (isQueue && q.front() != value)
				{
					isQueue = false;
				}
				if (isPriQueue && pq.top() != value)
				{
					isPriQueue = false;
				}
				st.pop();
				q.pop();
				pq.pop();
			}
		}
		if (isStack && isPriQueue)
		{
			std::cout << "not sure" << std::endl;
			continue;
		}
		if (isQueue)
		{
			std::cout << "queue" << std::endl;
			continue;
		}
		if (isStack)
		{
			std::cout << "stack" << std::endl;
			continue;
		}
		if (isPriQueue)
		{
			std::cout << "priority queue" << std::endl;
			continue;
		}
		if (!isStack && !isQueue && !isPriQueue)
		{
			std::cout << "impossible" << std::endl;
			continue;
		}
	}
	return 0;
}