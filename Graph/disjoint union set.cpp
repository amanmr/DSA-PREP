#include<iostream>
#include<list>
#include<map>
using namespace std;


class graph{
    int v;
    list<pair<int,int>> g;
    map<int,int> parent;
    public:
    graph(int v){
        this->v=v;
    }
    void addEdge(int x,int y){
        g.push_back(make_pair(x,y));
    }

    int findSet(int x,map<int,int> parent){
        if(parent[x]==-1){
            return x;
        }
        return findSet(parent[x],parent);
    }

    void unionSet(int x,int y,map<int,int> &parent){
            parent[y]=x;
    }
    
    bool containCycle(){
        
        for(int i=1;i<=v;i++){
            parent[i]=-1;
        }
        for(auto x:g){
            int a=x.first;
            int b=x.second;
            int s1=findSet(a,parent);
            int s2=findSet(b,parent);

            if(s1==s2 && s1!=-1){
                
                return true;
            }
            else{
                unionSet(s1,s2,parent);
            }
        }
        
        return false;
    }


};

int main()
{
    graph g(4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    //g.addEdge(4,1);
    cout<<g.containCycle();
 
    return 0;
}