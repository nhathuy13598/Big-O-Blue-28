#include <iostream>
#include <vector>

int main()
{
	int N;
	std::vector<int> chocos;
	std::cin >> N;
	chocos.reserve(N);
	for (int i = 0; i < N; i++)
	{
		int temp;
		std::cin >> temp;
		chocos.push_back(temp);
	}

	int L = 0, R = N - 1;
	int alice = 0, bob = 0;
	if (L == R)
	{
		std::cout << "1 0" << std::endl;
		return 0;
	}
	alice = 1;
	bob = 1;
	int alice_time = chocos[0];
	int bob_time = chocos[N - 1];
	int count = 0;
	while (L < R)
	{
		if (R - L == 1)
		{
			break;
		}
		if (alice_time < bob_time)
		{
			L += 1;
			alice += 1;
			alice_time += chocos[L];
		}
		else if (bob_time < alice_time)
		{
			R -= 1;
			bob += 1;
			bob_time += chocos[R];
		}
		else
		{
			R -= 1;
			L += 1;
			if (L == R)
			{
				alice += 1;
			}
			else
			{
				alice_time += chocos[L];
				bob_time += chocos[R];
				alice += 1;
				bob += 1;
			}
		}
	}
	std::cout << alice << " " << bob << std::endl;
	return 0;
}