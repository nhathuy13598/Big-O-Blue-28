#include <iostream>
#include <string>
#define MIN(a,b) ((a) <= (b) ? (a) : (b))
#define ABS(a) ((a) >= 0 ? (a) : -(a))
int main()
{
	std::string name;
	std::cin >> name;
	char init = 'a';
	int step = 0;
	for (int i = 0; i < name.size(); i++)
	{
		step += MIN(ABS(name[i] - init), 26 - ABS(name[i] - init));
		init = name[i];
	}
	std::cout << step << std::endl;
	return 0;
}