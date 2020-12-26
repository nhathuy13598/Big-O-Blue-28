#include <iostream>
#include <string>
int main()
{
	std::string S, T;
	std::cin >> S;
	std::cin >> T;

	for (int i = S.size() - 1; i >= 0; i--)
	{
		if (S[i] != 'z')
		{
			S[i] = S[i] + 1;
			break;
		}
		else
		{
			S[i] = 'a';
		}
	}
	if (S == T)
	{
		std::cout << "No such string" << std::endl;
	}
	else
	{
		std::cout << S << std::endl;
	}
	return 0;
}