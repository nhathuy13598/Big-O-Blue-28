#include <iostream>
#include <vector>

int main()
{
	int N, T;
	std::vector<int> books;
	std::cin >> N >> T;
	
	books.reserve(N);
	for (int i = 0; i < N; i++)
	{
		int tmp;
		std::cin >> tmp;
		books.push_back(tmp);
	}

	std::vector<int> accumulate;
	accumulate.resize(N + 1, 0);
	for (int i = 0; i < N; i++)
	{
		accumulate[i + 1] = accumulate[i] + books[i];
	}

	int L = 0, R = 1;
	int max_book = 0;
	while (R != L)
	{
		if (R == N + 1)
		{
			break;
		}
		if (accumulate[R] - accumulate[L] <= T)
		{
			if (R - L >= max_book)
			{
				max_book = R - L;
			}
			R += 1;
		}
		else
		{
			L += 1;
		}
	}
	std::cout << max_book << std::endl;
}