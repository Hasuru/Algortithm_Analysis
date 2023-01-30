#include <iostream>
#include <climits>
#include <cmath>
#include <list>

using namespace std;

class Node {
    public:
        list<int> adj;  // adjacent nodes list
        bool visited;   // node status
        int distance;   // distance from starting node of bfs
        int diameter;   // highest distance registered
};

class Graph {
    public:
        int n;
        Node* nodes;

        Graph(int n) {
            this->n = n;
            nodes = new Node[n+1];
        }

        void addLink(int a, int b) {
            nodes[a].adj.push_back(b);
            nodes[b].adj.push_back(a);
        }

        void bfs(int v) {
            list<int> q;
            for (int i = 1; i <= n; i++) nodes[i].visited = false;

            nodes[v].visited = true;
            nodes[v].distance = 0;
            nodes[v].diameter = 0;
            
            q.push_back(v);
            while (!q.empty()) {
                int u = q.front(); q.pop_front();

                for (auto const w : nodes[u].adj) {
                    if (!nodes[w].visited) {
                        q.push_back(w);
                        nodes[w].visited = true;
                        nodes[w].distance = nodes[u].distance+1;
                    }
                }
                nodes[v].diameter = max(nodes[v].diameter, nodes[u].distance);
            }
        }
};

void printList(int v, Graph* g) {
    bool flag = true;
    for (int i = 1; i <= g->n; i++) {
        if (g->nodes[i].diameter == v) {
            if (flag) { 
                printf("%d", i);
                flag = !flag;
            }
            else printf(" %d", i);
        }
    }
    putchar('\n');
}

int main() {
    int n;
    scanf("%d", &n);

    Graph* g = new Graph(n);

    int a;
    scanf("%d", &a);

    int v1, v2;
    for (int i = 0; i < a; i++) {
        scanf("%d %d", &v1, &v2);
        g->addLink(v1, v2);
    }

    int d = 0, r = INT_MAX;
    for (int i = 1; i <= n; i++) {
        g->bfs(i);
        //printf("%d | diameter: %d\n", i, g->nodes[i].diameter);
        d = max(d, g->nodes[i].diameter);
        r = min(r, g->nodes[i].diameter);
    }

    printf("%d\n%d\n", d, r);

    printList(r, g);
    printList(d, g);

    return 0;
}