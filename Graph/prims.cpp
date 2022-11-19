#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<list>
#include<queue>
#include<map>
#include<unordered_map>
using namespace std;

class graph{
    vector<pair<int,int>> *g;
    int v;
    public:
    graph(int v){
        this->v=v;
        g =new vector<pair<int,int>> [v];
    }
    void addEdge(int x,int y,int w){
        g[x].push_back({w,y});
        g[y].push_back({w,x});
    }
    int prims(){
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> q;
        bool *visited=new bool[v]{false};
        q.push({0,0});
        int ans=0;
        
        while(!q.empty()){
            auto temp=q.top();
            q.pop();
            int node=temp.second;
            int w=temp.first;
            if(visited[node]){
                continue;
            }
            ans+=w;
            visited[node]=true;
            for(auto x:g[node]){
                if(visited[x.second]==false){
                    q.push({x.first,x.second});
                }
            }
        }
        return ans;
    }
};

int main()
{
    graph g(4);
    g.addEdge(0,1,1);
    g.addEdge(0,2,1);
    g.addEdge(0,3,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,1);
    g.addEdge(2,3,6);
    cout<<g.prims();
    return 0;
}