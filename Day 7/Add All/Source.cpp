#include <iostream>
#include <queue>
int main()
{
	int N;
	std::cin >> N;
	while (N != 0)
	{
		std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
		for (int i = 0; i < N; i++)
		{
			int a;
			std::cin >> a;
			pq.push(a);
		}
		unsigned long cost = 0;
		unsigned long first = (unsigned long)pq.top();
		pq.pop();
		while (!pq.empty())
		{
			unsigned long second = (unsigned long)pq.top();
			pq.pop();
			cost += first + second;
			first = first + second;
		}
		std::cout << cost << std::endl;
		std::cin >> N;
	}
	return 0;
}