#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
	int N;
	int L, R;
	int min = INT32_MAX, max = INT32_MIN;
	std::cin >> N;
	int ans = -1;
	for (int i = 0; i < N; i++)
	{
		std::cin >> L >> R;
		
		int M, m;
		m = std::min(L, min);
		M = std::max(R, max);

		if (m == L && M == R)
		{
			ans = i + 1;
		}
		else
		{
			if (L < min || R > max)
			{
				ans = -1;
			}
		}
		
		min = m;
		max = M;
	}
	std::cout << ans << std::endl;
	
	return 0;
}