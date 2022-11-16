#include<iostream>
#include<queue>
#include<list>
#include<map>
using namespace std;

template<typename t>
class graph{
    map<t,list<t>> g;
    public:
    void addEdge(t x,t y){
        g[x].push_back(y);
    }

    void dfs_helper(t src, map<t,bool> &visited,list<int> &v){
        visited[src] = true;
        for(auto x:g[src]){
            if(!visited[x]){
                dfs_helper(x,visited,v);
            }
        }
        v.push_front(src);
    }

    list<int> dfs(t src)
    {
        list<int> v;
        map<t, bool> visited;
        for (auto x : g)
        {
            visited[x.first] = false;
        }
        for (auto x : g)
        {
            auto y=x.first;
            if (!visited[y])
            {
                dfs_helper(y, visited,v);
            }
        }
        return v;
    }

};

int main()
{
    graph<int> g;
    g.addEdge(1,2);
    g.addEdge(2,4);
    g.addEdge(1,3);
    g.addEdge(3,4);
    g.addEdge(5,3);
    list<int> v=g.dfs(1);
    for(auto x:v){
        cout<<x<<" ";
    }
    return 0;
}