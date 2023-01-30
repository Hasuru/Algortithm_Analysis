#include <iostream>
#include <climits>
#include <list>
#include <set>

using namespace std;

class node {
    public:
        list<pair<int,int>> adj; // {pair(x,y), weight}
        bool visited;
        int distance;
};

class graph {
    public:
        int n;
        node* nodes;

        graph(int n) {
            this->n = n;
            nodes = new node[n+1];
        }

        void addLink(int a, int b, int c) {
            nodes[a].adj.push_back({b,c});
            nodes[b].adj.push_back({a,c});
        }

        void prim(int s) {
            for (int i = 1; i <= n; i++) {
                nodes[i].visited = false;
                nodes[i].distance = INT_MAX;
            }

            nodes[s].distance = 0;
            set<pair<int,int>> q;
            q.insert({0, s});

            int total = 0;

            while (!q.empty()) {
                int u = q.begin()->second;
                q.erase(q.begin());
                nodes[u].visited = true;
                total += nodes[u].distance;

                for (auto edge : nodes[u].adj) {
                    int v = edge.first;
                    int cost = edge.second;
                    if (!nodes[u].visited && cost < nodes[v].distance) {
                        q.erase({nodes[v].distance, v});
                        nodes[v].visited = cost;
                        q.insert({nodes[v].distance, v});
                    }
                }
            }
        }
};

int main() {
    int n;
    scanf("%d", &n);

    graph* g = new graph(n);

    while (n--) {
        int x, y;
        scanf("%d %d", &x, &y);
    }

    return 0;
}