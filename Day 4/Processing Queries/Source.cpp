#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
int main() {
	int n, b;
	std::cin >> n >> b;
	int end = 0;
	uint64_t start, duration;
	std::queue<uint64_t> q;
	uint64_t time = 0;
	for (int i = 0; i < n; i++)
	{
		std::cin >> start >> duration;

		// Check whether the first query in q is finished when time is 'start'
		// If 'yes' we pop it out
		// If 'no' means that the server is busy
		while (!q.empty() && q.front() <= start)
		{
			q.pop();
		}
		if (q.size() <= b)
		{
			time = std::max(time, start) + duration;
			std::cout << time << std::endl;
			q.push(time);
		}
		else
		{
			std::cout << -1 << std::endl;
		}
	}
	return 0;
}