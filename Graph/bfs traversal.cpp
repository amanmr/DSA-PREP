#include <iostream>
#include <queue>
#include <map>
#include <list>
using namespace std;

template <typename t>
class graph 
{
    map<t, list<t>> g;

public:
    void addEdge(t x, t y) 
    {
        g[x].push_back(y);
        g[y].push_back(x);
    }
    void bfs(t src)
    {
        queue<t> q;
        map<t, bool> visited;
        q.push(src);
        visited[src] = true;
        while (!q.empty())
        {
            t temp = q.front();
            q.pop();
            cout << temp << " ";
            for (t x : g[temp])
            {
                if (! visited[x])
                {
                    q.push(x);
                    visited[x] = true;
                }
            }
        }
    }
};
int main()
{

    graph<int> g;
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(1, 2);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.bfs(0);

    return 0;
}