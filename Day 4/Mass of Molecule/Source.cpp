#include <iostream>
#include <string>
#include <stack>
int main() {
	std::string str;
	std::cin >> str;
	std::stack<int> s;
	for (size_t i = 0; i < str.size(); i++)
	{
		switch (str[i])
		{
		case '(':
			s.push(-1);
			break;
		case 'H':
			s.push(1);
			break;
		case 'C':
			s.push(12);
			break;
		case 'O':
			s.push(16);
			break;
		case ')':
		{
			int sum = 0;
			while (s.top() != -1)
			{
				sum += s.top();
				s.pop();
			}
			s.pop();
			s.push(sum);
		}
			break;
		default:
			break;
		}
		if (str[i] >= '2' && str[i] <= '9')
		{
			int top = s.top();
			s.pop();
			s.push(top * (str[i] - '0'));
		}
	}
	int sum = 0;
	while (!s.empty())
	{
		sum += s.top();
		s.pop();
	}
	std::cout << sum << std::endl;
	return 0;
}