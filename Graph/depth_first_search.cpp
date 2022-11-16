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

    void dfs_helper(t src, map<t,bool> &visited){
        cout<<src<<" ";
        visited[src]=true;
        for(auto x:g[src]){
            if(!visited[x]){
                dfs_helper(x,visited);
            }
        }
    }
    void dfs(t src)
    {
        map<t,bool> visited;
        for(auto x:g){
            visited[x.first]=false;
        }
        dfs_helper(src,visited);
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
    g.dfs(0);

    return 0;
}