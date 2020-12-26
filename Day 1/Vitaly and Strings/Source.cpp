#include <iostream>
#include <string>
int main()
{
	std::string S, T;
	std::cin >> S;
	std::cin >> T;

	for (int i = 0; i < S.size(); i++)
	{
		if (S[i] != T[i])
		{
			for (int j = i + 1; j < S.size(); j++)
			{
				if (S[j] + 1 <= 'z')
				{
					S[j] += 1;
					std::cout << S << std::endl;
					return 0;
				}
			}
			if (S[i] + 1 < T[i])
			{
				S[i] += 1;
				std::cout << S << std::endl;
				return 0;
			}
			else
			{
				// S[i] + 1 == T[i]
				S[i] += 1;
				for (int j = i + 1; j < S.size(); j++)
				{
					S[j] = 'a';
					if (S[j] < T[j])
					{
						std::cout << S << std::endl;
						return 0;
					}
				}
			}
		}
		if (i == S.size() - 1)
		{
			std::cout << "No such string" << std::endl;
		}
	}
	return 0;
}