#include <iostream>
#include <queue>
#include <list>
#include <map>
using namespace std;

template <typename t>
class graph
{
    map<t, list<t>> g;
    map<t, int> inorder;
public:
    void addEdge(t x, t y)
    {
        g[x].push_back(y);
    }

    void bfs(t src)
    {
        map<t, bool> visited;
        queue<t> q;
        
        for(auto x:g){
            inorder[x.first]=0;
        }
        for (auto x : g)
        {
            visited[x.first] = false;
            for (auto y : x.second)
            {
                inorder[y]++;
            }
        }

        for(auto x:g){
            if(inorder[x.first]==0 && !visited[x.first]){
                q.push(x.first);
                visited[x.first]=true;
            }
        }

        while(!q.empty()){
            auto temp=q.front(); 
            q.pop();
            cout<<temp<<" ";
            for(auto x:g[temp]){
                inorder[x]--;
                if(inorder[x]==0 && !visited[x]){
                    q.push(x);
                    visited[x]=true;
                }
            }
        }
    }
};

int main()
{
    graph<int> g;
    g.addEdge(1, 2);
    g.addEdge(2, 4);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(5,3);
    g.bfs(1);
    return 0;
}