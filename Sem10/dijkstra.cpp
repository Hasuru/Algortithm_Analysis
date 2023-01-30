#include <iostream>
#include <climits>
#include <list>
#include <set>
#include <map>

using namespace std;
typedef map<string,int> msi;

msi places;

class Node {
    public:
        list<pair<int,int>> adj;
        bool visited;
        int distance;
};

class Graph {
    public:
        int n;
        Node *nodes;

        Graph(int n) {
            this->n = n;
            nodes = new Node[n+1];
        }

        void addLink(int a, int b, int c) {
            nodes[a].adj.push_back({b,c});
        }

        void dijkstra(int s) {
            for (int i = 1; i <= n; i++) {
                nodes[i].visited = false;
                nodes[i].distance = INT_MAX;
            }

            nodes[s].distance = 0;

            set<pair<int,int>> q;
            q.insert({0,s});

            while (!q.empty()) {
                int u = q.begin()->second;
                q.erase(q.begin());

                nodes[u].visited = true;
                printf("%c:[dist = %d]\n", u+'A'-1, nodes[u].distance);

                for (auto const edge : nodes[u].adj) {
                    int v = edge.first;
                    int cost = edge.second;
                    if (!nodes[v].visited && nodes[u].distance + cost < nodes[v].distance) {
                        nodes[v].distance = nodes[u].distance + cost;
                        q.insert({nodes[v].distance, v});
                    }
                }
            }
        }
};

int main() {
    int n, e;
    scanf("%d %d", &n, &e);

    Graph* g = new Graph(n);

    string s1, s2;
    for (int i = 0; i < e; i++) {
        int v1, v2, w;
        scanf("%d %d %d", &v1, &v2, &w);
        g->addLink(v1,v2,w);
    }

    g->dijkstra(1);

    return 0;
}