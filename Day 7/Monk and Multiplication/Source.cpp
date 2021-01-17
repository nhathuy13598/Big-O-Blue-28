#include <iostream>
#include <queue>
#include <numeric>
int main()
{
	std::priority_queue<int> pq;
	int N;
	std::cin >> N;
	std::vector<int> nums(3);
	for (int i = 0; i < N; i++)
	{
		int value;
		std::cin >> value;
		pq.push(value);
		unsigned long long int multi = 1;
		if (pq.size() < 3)
		{
			std::cout << "-1" << std::endl;
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				nums[i] = pq.top();
				pq.pop();
			}
			for (int& a : nums)
			{
				multi *= a;
				pq.push(a);
			}
			std::cout << multi << std::endl;
			multi = 1;
		}
		
	}
}