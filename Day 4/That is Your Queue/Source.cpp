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
		for (int i = 1; i <= P; i++)
		{
			q.push(i);
		}
		std::vector<int> commands(C);
		for (int i = 0; i < C; i++)
		{
			char c;
			int p;
			std::cin >> c;
			if (c == 'N')
			{
				commands[i] = 0;
			}
			else
			{
				std::cin >> p;
				commands[i] = p;
			}
		}
		for (int i = 0; i < C; i++)
		{
			if (commands[i] == 0)
			{
				std::cout << q.front() << std::endl;
				q.push(q.front());
				q.pop();
			}
			else
			{
				q.push(commands[i]);
				bool remove_dup = false;
				while (true)
				{
					if (q.front() != commands[i])
					{
						q.push(q.front());
						q.pop();
					}
					else
					{
						if (remove_dup == false)
						{
							q.pop();
							remove_dup = true;
						}
						else
						{
							break;
						}
					}
				}
			}
		}
		std::cin >> P >> C;
	}
	return 0;
}