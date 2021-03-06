#include <iostream>
#include <vector>
#include <string>
void unionSet(std::vector<int>&, std::vector<int>&, char, char);
int findSet(std::vector<int>&, int);
void makeSet(std::vector<int>&);
int main()
{
    size_t test;
    std::cin >> test;
    for (size_t i = 0; i < test; i++)
    {
        char max_node;
        std::cin >> max_node;
        if (max_node == ' ')
        {
            std::cin >> max_node;
        }
        std::vector<int> parent(max_node - 'A' + 1);
        std::vector<int> ranks(max_node - 'A' + 1);
        std::vector<bool> check(max_node - 'A' + 1, false);
        makeSet(parent);
        std::string in;
        while(std::cin >> in)
        {
            if (!std::cin.good())
            {
                break;
            }
            if (in == " ")
            {
                break;
            }
            unionSet(parent, ranks, in[0], in[1]);
        }
        int count = 0;
        for (size_t j = 0; j < max_node - 'A' + 1; j++)
        {
            int ret = findSet(parent, j);
            if (!check[ret])
            {
                count += 1;
                check[ret] = true;
            }
        }
        std::cout << "\nAnswer: " << count << std::endl;
    }
    return 0;
}

void makeSet(std::vector<int> &parent)
{
    for (size_t i = 0; i < parent.size(); i++)
    {
        parent[i] = i;
    }
}

int findSet(std::vector<int> &parent, int value)
{
    if (parent[value] != value)
    {
        parent[value] = findSet(parent, parent[value]);
    }
    return parent[value];
}

void unionSet(std::vector<int> &parent, std::vector<int> &rank, char u, char v)
{
    int up = findSet(parent, u - 'A');
    int vp = findSet(parent, v - 'A');

    if (up == vp)
    {
        return;
    }

    if (rank[up] > rank[vp])
    {
        parent[vp] = up;
    }
    else if (rank[up] < rank[vp])
    {
        parent[up] = vp;
    }
    else
    {
        parent[up] = vp;
        rank[vp] += 1;
    }
}
