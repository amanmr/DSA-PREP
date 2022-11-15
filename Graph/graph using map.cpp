#include<iostream>
#include<list>
#include<map>
using namespace std;

class graph{
    int v;
    map<string,list<pair<string,int>>> g;
    public:
    graph(int v){
        this->v=v;
    }
    void addEdge(string s1,string s2,int weight,bool dir){
         g[s1].push_back(make_pair(s2,weight));
        if(dir){
           g[s2].push_back(make_pair(s1,weight));
        }
    }
    void printEdge(){
        for (auto x:g){
            string s=x.first;
            cout<<s<<" --> ";
            for(auto y: x.second){
                cout<<"("<<y.first<<" , "<<y.second<<") ,";
            }
            cout<<endl;
        }
    }

};
int main(){

    graph g(4);
    g.addEdge("a","b",20,true);
    g.addEdge("b","d",40,true);
    g.addEdge("c","d",30,true);
    g.addEdge("a","c",10,true);
    g.addEdge("a","d",50,false);
    g.printEdge();
    return 0;
}