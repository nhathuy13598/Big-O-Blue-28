#include <iostream>
#include <vector>
#include <stack>
#include <string>
int main()
{
	int N;
	std::cin >> N;
	std::vector<std::string> arr(N);
	std::stack<char> s;
	for (int i = 0; i < N; i++)
	{
		std::cin >> arr[i];
	}
	for (int i = 0; i < N; i++)
	{
		std::string ans = "";
		for (int j = 0; j < arr[i].size(); j++)
		{
			if (arr[i][j] >= 'a' && arr[i][j] <= 'z')
			{
				ans += arr[i][j];
			}
			else if (arr[i][j] == ')')
			{
				while (s.top() != '(')
				{
					ans += s.top();
					s.pop();
				}
				s.pop();
			}
			else
			{
				s.push(arr[i][j]);
			}
		}
		while (!s.empty())
		{
			ans += s.top();
			s.pop();
		}
		std::cout << ans << std::endl;
	}
	return 0;
}