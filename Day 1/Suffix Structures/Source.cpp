#include <iostream>
#include <string>
#include <algorithm>
int main()
{
	std::string s, t;
	std::cin >> s >> t;

	if (s.size() < t.size())
	{
		std::cout << "need tree" << std::endl;
		return 0;
	}
	if (s.find(t) != std::string::npos)
	{
		std::cout << "automaton" << std::endl;
		return 0;
	}
	std::string tmp = s;
	for (int i = 0; i < t.size(); i++)
	{
		int index = tmp.find_first_of(t[i]);
		if (index == std::string::npos)
		{
			std::cout << "need tree" << std::endl;
			return 0;
		}
		tmp[index] = '*';
	}

	if (s.size() == t.size())
	{
		std::cout << "array" << std::endl;
		return 0;
	}

	for (int i = 0; i < s.size(); i++)
	{
		if (t.find_first_of(s[i]) == std::string::npos)
		{
			s.erase(std::remove(s.begin(), s.end(), s[i]), s.end());
		}
	}
	if (s.find(t) != std::string::npos)
	{
		std::cout << "automaton" << std::endl;
	}
	else
	{
		std::cout << "both" << std::endl;
	}
	return 0;
}