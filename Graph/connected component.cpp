#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <deque>
#include <map>
#include <unordered_map>
using namespace std;

template <typename T>
class graph
{
    map<T, list<T>> g;
public:
    void addEdge(T x, T y)
    {
        g[x].push_back(y);
        g[y].push_back(x);
    }
    void dfs_helper(T src, map<T, bool> &visited)
    {
        cout << src << " ";
        visited[src] = true;
        for (auto x : g[src])
        {
            if (!visited[x])
            {
                dfs_helper(x, visited);
            }
        }
    }
    void dfs(T src)
    {
        map<T, bool> visited;
        int count = 0;
        for (auto x : g)
        {
            visited[x.first] = false;
        }
        for (auto x : g)
        {
            auto y=x.first;
            if (!visited[y])
            {
                cout << "component " << count << " --> ";
                dfs_helper(y, visited);
                count++;
                cout << endl;
            }
        }
    }
};

int main()
{
    graph<int> g;
    g.addEdge(1, 2);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(1, 3);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.dfs(0);
    return 0;
}