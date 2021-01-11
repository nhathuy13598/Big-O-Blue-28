#include <iostream>
#include <stack>
#include <string>
int main()
{
	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::string expr;
		std::cin >> expr;
		int count = 0;
		std::stack<char> st;
		for (int i = 0; i < expr.size(); i++)
		{
			if (expr[i] == '<')
			{
				st.push('<');
			}
			else
			{
				if (!st.empty() && st.top() == '<')
				{
					st.pop();
					count += 1;
				}
			}
		}
		std::cout << 2 * count << std::endl;
	}
	return 0;
}