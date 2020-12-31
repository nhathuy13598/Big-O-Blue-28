#include <iostream>
#include <string>
#include <algorithm>
int main()
{
	std::string s, t;
	std::cin >> s >> t;

	bool automaton = false, arr = false;

	int count_s[26] = { 0 }, count_t[26] = { 0 };
	for (int i = 0; i < s.size(); i++)
	{
		count_s[s[i] - 'a'] += 1;
	}
	for (int i = 0; i < t.size(); i++)
	{
		count_t[t[i] - 'a'] += 1;
	}

	for (int i = 0; i < 26; i++)
	{
		if (count_t[i] != 0 && count_s[i] == 0)
		{
			std::cout << "need tree" << std::endl;
			return 0;
		}
		if (count_s[i] > count_t[i])
		{
			automaton = true;
		}
	}

	int index = -1;
	for (int i = 0; i < t.size(); i++)
	{
		index = s.find_first_of(t[i], index + 1);
		if (index == std::string::npos)
		{
			arr = true;
			break;
		}
	}

	if (arr && automaton)
	{
		std::cout << "both" << std::endl;
	}
	else if (arr)
	{
		std::cout << "array" << std::endl;
	}
	else
	{
		std::cout << "automaton" << std::endl;
	}
	return 0;
}