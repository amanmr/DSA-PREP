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

class DSU{
    int *parent;
    int *rank;
    public:
    DSU(int v){
        parent=new int[v];
        rank=new int[v];
        for(int i=0;i<v;i++){
            parent[i]=-1;
            rank[i]=1;
        }
    }
    int find(int x){
        if(parent[x]==-1){
            return x;
        }
        return parent[x]=find(parent[x]);
    }

    void unionSet(int x,int y){
        int s1=find(x);
        int s2=find(y);
        if(s1!=s2){
            if(rank[s1]<rank[s2]){
                parent[s1]=s2;
                rank[s2]+=rank[s1];
            }
            else{
                parent[s2]=s1;
                rank[s1]+=rank[s2];
            }
        }
    }
};

class graph{
    int v;
    vector<vector<int>> vec;
    public:
    graph(int v){
        this->v=v;
    }
    void addEdge(int x,int y,int wt){
        vec.push_back({wt,x,y});
    }
    int kruskal_mst(){
        DSU s(v);
        sort(vec.begin(),vec.end());
        int ans=0;
        for(auto edge:vec){
            int weight=edge[0];
            int x=edge[1];
            int y=edge[2];
            
            int s1=s.find(x);
            int s2=s.find(y);
            if(s1!=s2){
                s.unionSet(x,y);
                ans+=weight;
            }
        }
        return ans;
    }
};

int main()
{
    graph g(4);
    g.addEdge(0,1,1);
    g.addEdge(0,2,2);
    g.addEdge(1,3,3);
    g.addEdge(2,3,3);
    g.addEdge(0,3,2);
    g.addEdge(1,2,2);
    cout<<g.kruskal_mst();
    
    return 0;
}