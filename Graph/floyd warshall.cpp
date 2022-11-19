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
#define inf 30000
class graph{
    int v;
    vector<int> *g;
    public:
    graph(int v){
        this->v=v;
        g=new vector<int>[v];
        for(int i=0;i<v;i++){
            for(int j=0;j<4;j++){
                if(i==j){
                    g[i].push_back(0);
                    continue;
                }
                g[i].push_back(inf);
            }
        }
    }
    void addEdge(int x,int y,int w){
        g[x][y]=w;
    }
    vector<int> * floyd(){
        for(int k=0;k<v;k++){
            for(int i=0;i<v;i++){
                for(int j=0;j<v;j++){
                    if(g[i][j]> (g[i][k]+g[k][j])){
                        g[i][j]= g[i][k]+g[k][j];
                    }
                }
            }
        }
        return g;
    }
    void print(){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                cout<<g[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    graph g(4);
    g.addEdge(0,2,-2);
    g.addEdge(1,0,4);
    g.addEdge(1,2,3);
    g.addEdge(2,3,2);
    g.addEdge(3,1,-1);
    vector<int> *v;
    v=g.floyd();
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}