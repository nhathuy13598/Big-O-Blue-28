#include <iostream>
#include <queue>
int main()
{
	int P, C;
	std::cin >> P >> C;
	int test = 1;
	while (P != 0 && C != 0)
	{
		std::cout << "Case " << test++ << ":" << std::endl;
		std::queue<int> q;
		int size = std::min(C, P);
		for (int i = 1; i <= size; i++)
		{
			q.push(i);
		}
		for (int i = 0; i < C; i++)
		{
			char c;
			int p;
			std::cin >> c;
			if (c == 'N')
			{
				std::cout << q.front() << std::endl;
				q.push(q.front());
				q.pop();
			}
			else
			{
				std::cin >> p;
				int size = q.size();
				q.push(p);
				for (int i = 0; i < size; i++)
				{
					int temp = q.front();
					q.pop();
					if (temp != p) {
						q.push(temp);
					}
				}
			}
		}
		std::cin >> P >> C;
	}
	return 0;
}