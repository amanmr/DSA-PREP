#include<iostream>
#include<stack>
#include<queue>

#include<string>
#include<list>

#include<map>
#include<unordered_map>
using namespace std;

class graph{
    map<int,list<int>> g;
    public:
    void newEdge(int x,int y){
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bool isTrue(int src){
        map<int,int> visited;
        map<int,int> parent;
        queue<int> q;
        for(auto x:g){
            visited[x.first]=false;
            parent[x.first]=x.first;
        }
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(auto x:g[temp]){
                if(visited[x] && parent[temp]!=x){
                    return false;
                }
                else if(!visited[x]){
                q.push(x);
                parent[x]=temp;
                visited[x]=true;
                }
            }
        }
        return true;
    }
};

int main()
{
    graph g;
    g.newEdge(1,2);
    g.newEdge(2,3);
    g.newEdge(3,4);
    g.newEdge(4,1);
    cout<<g.isTrue(1);
    return 0;
}