#include <iostream>
#include <climits>
#include <algorithm>
#include <list>
#include <vector>
#include <set>

using namespace std;

set<int> mother;
set<pair<int,int>> q;
vector<int> weights;
int total = 0;

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

        void prim() {
            for (int i = 1; i <= n; i++) {
                nodes[i].visited = false;
            }

            while (!q.empty()) {
                int u = q.begin()->second;
                q.erase(q.begin());
                nodes[u].visited = true;
                total += nodes[u].distance;
                weights.push_back(nodes[u].distance);

                //printf("[%d] -> [dist = %d]\n", u, nodes[u].distance);

                for (auto edge : nodes[u].adj) {
                    int v = edge.first;
                    int cost = edge.second;
                    //printf("[%d] -> [%d]:[cost = %d]\n", u, v, cost);
                    if (!nodes[v].visited && cost < nodes[v].distance) {
                        q.erase({nodes[v].distance, v});
                        nodes[v].distance= cost;
                        q.insert({nodes[v].distance, v});
                    }
                }
            }
        }
};

int main() {
    int n, v, e;
    scanf("%d %d %d", &n, &v, &e);

    for (int i = 1; i <= n; i++) mother.insert(i);

    graph* g = new graph(n+v);

    for (int i = 0; i < e; i++) {
        int v1, v2, w;
        scanf("%d %d %d", &v1, &v2, &w);
        g->addLink(v1, v2, w);
    }

    for (int i = n+1; i <= n+v; i++) {
        int min = INT_MAX/2;
        for (auto edge : g->nodes[i].adj) {
            if (edge.second < min && mother.find(edge.first) != mother.end()) {
                min = edge.second;
            }
        }
        //printf("Node[%d] -> min[%d]\n", i, min);
        g->nodes[i].distance = min;
        q.insert({min, i});
    }

    g->prim();

    sort(weights.begin(), weights.end());

    printf("%d\n", total);
    for (unsigned int i = 0; i < weights.size(); i++) {
        if (i == 0) printf("%d", weights[i]);
        else printf(" %d", weights[i]);
    }
    putchar('\n');

    return 0;
}