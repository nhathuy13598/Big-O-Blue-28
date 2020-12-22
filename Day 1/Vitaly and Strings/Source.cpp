#include <iostream>
#include <string>
int main()
{
	std::string S, T;
	std::cin >> S;
	std::cin >> T;

	for (int i = 0; i < S.size(); i++)
	{
		if (S[i] == T[i])
		{
			if (i == S.size() - 1)
			{
				std::cout << "No such string" << std::endl;
			}
		}
		else
		{
			if (i != S.size() - 1)
			{
				std::cout << "No such string" << std::endl;
			}
			else
			{
				if (S[i] + 1 < T[i])
				{
					S[i] = S[i] + 1;
					std::cout << S[i] << std::endl;
				}
				else
				{
					std::cout << "No such string" << std::endl;
				}
			}
		}
	}
	return 0;
}