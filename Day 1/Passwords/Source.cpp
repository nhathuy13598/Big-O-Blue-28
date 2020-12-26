#include <iostream>
#include <vector>
#include <string>
int main()
{
	int n, k;
	std::vector<std::string> passwords;
	std::cin >> n >> k;
	passwords.reserve(n);
	for (int i = 0; i < n; i++)
	{
		std::string tmp;
		std::cin >> tmp;
		passwords.push_back(tmp);
	}
	std::string pass;
	std::cin >> pass;

	int count_equal_pass_len = 0, count_not_equal_pass_len = 0;
	for (int i = 0; i < n; i++)
	{
		if (passwords[i].size() < pass.size() && passwords[i] != pass)
		{
			count_not_equal_pass_len += 1;
		}
		if (passwords[i].size() <= pass.size() && passwords[i] != pass)
		{
			count_equal_pass_len += 1;
		}
	}
	int worst = 0;
	int best = 0;

	best += count_not_equal_pass_len + count_not_equal_pass_len / k * 5;
	worst += count_equal_pass_len + count_equal_pass_len / k * 5;

	std::cout << best + 1 << " " << worst + 1 << std::endl;
	return 0;
}