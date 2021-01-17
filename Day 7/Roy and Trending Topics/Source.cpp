#include <iostream>
#include <queue>
struct Post {
	int id;
	long cur;
	long change;
};
struct Compare {
	bool operator() (const Post& a, const Post& b)
	{
		if (a.change < b.change || (a.change == b.change && a.id < b.id))
		{
			return true;
		}
		return false;
	}
};

int main()
{
	int N;
	std::cin >> N;
	int id;
	long cur, p, l, c, s;
	std::priority_queue<Post, std::vector<Post>, Compare> pq;
	for (int i = 0; i < N; i++)
	{
		std::cin >> id >> cur >> p >> l >> c >> s;
		long change = p * 50 + l * 5 + c * 10 + s * 20 - cur;
		pq.push({ id,cur + change,change });
	}
	for (int i = 0; i < 5 && !pq.empty(); i++)
	{
		Post top = pq.top();
		pq.pop();
		std::cout << top.id << " " << top.cur << std::endl;
	}
	return 0;
}