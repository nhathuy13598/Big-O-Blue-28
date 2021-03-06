#include <iostream>
#include <unordered_map>
#include <vector>
void makeSet(std::vector<int> &data)
{
  for (size_t i = 0; i < data.size(); i++)
  {
    data[i] = i;
  }
}

int findSet(std::vector<int> &data, int find)
{
  if (find != data[find])
  {
    data[find] = findSet(data, data[find]);
  }
  return data[find];
}

void unionSet(std::vector<int> &data, std::vector<int> &ranks, int u, int v)
{
  int up = findSet(data, u);
  int vp = findSet(data, v);
  if (up == vp)
  {
    return;
  }
  if (ranks[up] < ranks[vp])
  {
    data[up] = vp;
  }
  else if (ranks[up] > ranks[vp])
  {
    data[vp] = up;
  }
  else
  {
    data[up] = vp;
    ranks[vp] += 1;
  }
}

int main()
{
  size_t test;
  std::cin >> test;
  for (size_t i = 0; i < test; i++)
  {
    size_t n, m;
    std::cin >> n >> m;
    std::vector<int> friends(n + 1);
    std::vector<int> ranks(n + 1);
    makeSet(friends);
    for (size_t j = 0; j < m; j++)
    {
      int a, b;
      std::cin >> a >> b;
      unionSet(friends, ranks, a, b);
    }
    std::unordered_map<int, int> count;
    for (size_t j = 1; j <= n; j++)
    {
      int parent = findSet(friends, j);
      if (count.find(parent) == count.end())
      {
        count[parent] = 1;
      }
      else
      {
        count[parent] += 1;
      }
    }
    int max = -1;
    for (auto &e : count)
    {
      max = e.second > max ? e.second : max;
    }
    std::cout << max << std::endl;
  }
  return 0;
}
