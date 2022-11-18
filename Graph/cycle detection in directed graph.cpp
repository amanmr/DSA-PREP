#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<list>
#include<deque>
#include<map>
#include<unordered_map>
using namespace std;
 
//vertices from 0 to v-1
class graph{
    int v;
    map<int,list<int>> g;
    public:
    graph(int v){
        this->v=v;
    }
    void newEdge(int x,int y){
        g[x].push_back(y);
    }

    bool cycleHelper(int src, map<int,bool> visited, map<int,int> stack){
        visited[src]=true;
        stack[src]=1;
        for(auto x:g[src]){
            if(stack[x]==1){
                return true;
            }
            else if(!visited[x]){
                bool next=cycleHelper(x,visited,stack);
                if(next==true){
                    return true;
                }
            }
            stack[x]=0;
        }
        return false;
    }

    bool cycle(int src){
        map<int,bool> visited;
        map<int,int> stack;
        for(auto x: g){
            visited[x.first]=false;
            stack[x.first]=0;
        }
        return cycleHelper(src,visited,stack);
    }

};

int main()
{
    graph g(3);
    g.newEdge(1,2);
    g.newEdge(2,3);
    g.newEdge(1,3);
    cout<<g.cycle(1);
    
    return 0;
}