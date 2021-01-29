#include <iostream>
#include <queue>
int main()
{
	int N;
	std::cin >> N;
	while (N != 0)
	{
		std::priority_queue<unsigned long, std::vector<unsigned long>, std::greater<unsigned long>> pq;
		for (int i = 0; i < N; i++)
		{
			int a;
			std::cin >> a;
			pq.push(a);
		}
		unsigned long cost = 0;
		while (!pq.empty() && pq.size() != 1)
		{
			unsigned long first = (unsigned long)pq.top();
			pq.pop();
			unsigned long second = (unsigned long)pq.top();
			pq.pop();
			cost += first + second;
			pq.push(first + second);
		}
		std::cout << cost << std::endl;
		std::cin >> N;
	}
	return 0;
}