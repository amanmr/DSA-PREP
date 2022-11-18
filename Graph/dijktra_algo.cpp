#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <string>
#include <list>
#include <climits>
#include <map>
#include <unordered_map>
using namespace std;

template <typename T>
class graph
{
    map<T, list<pair<T, int>>> g;

public:
    void addEdge(T x, T y, int wt)
    {
        g[x].push_back(make_pair(y, wt));
        g[y].push_back(make_pair(x, wt));
    }

    void dijktra(T src)
    {
        set<pair<int, T>> s;
        map<T, int> dist;

        for (auto x : g)
        {
            dist[x.first] = INT_MAX;
        }
        dist[src]=0;
        s.insert(make_pair(0, src));
        while (!s.empty())
        {
            auto temp = *(s.begin());
            s.erase(temp);
            T node=temp.second;
            int dParent=temp.first;
            for (auto x : g[node])
            {
                T childName=x.first;
                int childDist=x.second;
                if (dParent + childDist < dist[childName])
                {
                    auto t = s.find(make_pair(dist[childName], childName));
                    if (t != s.end())
                    {
                        s.erase(t);
                    }
                    s.insert(make_pair(dParent + childDist, childName));
                    dist[childName] = dParent + childDist;
                }
            }
        }
        for (auto x : dist)
        {
            cout << x.first << " - > " << x.second << endl;
        }
    }
};

int main()
{
    graph<int> g;
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 4);
    g.addEdge(1, 4, 7);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 2);
    g.dijktra(1);

    return 0;
}