#include <iostream>
#include <algorithm>
#include <vector>
struct Point {
	int x, y;
	bool operator== (const Point& a)
	{
		return x == a.x && y == a.y;
	}
};

bool less(const Point& a, const Point& b)
{
	if (a.x < b.x || (a.x == b.x && a.y < b.y))
		return true;
	return false;
}
int main()
{
	std::vector<Point> arr(8);
	for (int i = 0; i < 8; i++)
	{
		int x, y;
		std::cin >> x >> y;
		arr[i] = { x,y };
	}

	std::sort(arr.begin(), arr.end(), less);

	std::vector<int> count_x(3, -1), count_y(3, -1);
	int num_x = 0, num_y = 0;
	for (int i = 0; i < 8; i++)
	{
		if (std::find(count_x.begin(), count_x.end(), arr[i].x) == count_x.end())
		{
			if (num_x == 3)
			{
				std::cout << "ugly" << std::endl;
				return 0;
			}
			count_x[num_x] = arr[i].x;
			num_x += 1;
		}
		if (std::find(count_y.begin(), count_y.end(), arr[i].y) == count_y.end())
		{
			if (num_y == 3)
			{
				std::cout << "ugly" << std::endl;
				return 0;
			}
			count_y[num_y] = arr[i].y;
			num_y += 1;
		}
		
	}
	for (int i = 0; i < 8; i++)
	{
		if (i != 0)
		{
			if (std::find(arr.begin(), arr.begin() + i, arr[i]) != arr.begin() + i)
			{
				std::cout << "ugly" << std::endl;
				return 0;
			}
		}
		if (arr[i].x == count_x[1] && arr[i].y == count_y[1])
		{
			std::cout << "ugly" << std::endl;
			return 0;
		}
	}
	std::cout << "respectable" << std::endl;
	return 0;
}