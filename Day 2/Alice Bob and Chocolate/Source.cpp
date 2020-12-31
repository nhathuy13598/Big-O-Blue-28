#include <iostream>
#include <vector>

int main()
{
	int N;
	std::cin >> N;
	std::vector<int> chocos(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> chocos[i];
	}

	int L = 0, R = N - 1;
	int alice = 0, bob = 0;
	while (L <= R)
	{
		if (alice + chocos[L] <= bob + chocos[R])
		{
			alice += chocos[L];
			L += 1;
		}
		else
		{
			bob += chocos[R];
			R -= 1;
		}
	}
	std::cout << L << " " << N - L << std::endl;
	return 0;
}