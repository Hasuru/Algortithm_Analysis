#include <iostream>
#include <climits>
#include <list>

using namespace std;

// visited nao e necessario para bellman
class node {
    public: 
        list<pair<int,int>> adj; // par{no conetado, peso da aresta}
        int distance;
};

// nos vao de 0 a n-1
// grafo pesado e direcionado
class graph {
    public:
        int n;
        node *nodes;

        graph(int n) {
            this->n = n;
            nodes = new node[n];
        }

        void addLink(int a, int b, int c) {
            nodes[a].adj.push_back({b,c});
        }

        // true se houver ciclo negativo
        bool bellman_ford(int s) {
            for (int i = 0; i < n; i++) nodes[i].distance = INT_MAX/2;
            nodes[s].distance = 0;

            // relaxar arestas |v|-1 vezes
            for (int i = 0; i < n-1; i++) {
                //printf("Relax: %d\n", i);
                // em todos os relaxamentos temos de passar em todos os nos
                for (int j = 0; j < n; j++) {
                    //printf("%d[dist = %d]\n", j, nodes[j].distance);
                    // analogamente teremos de avaliar todas as arestas ligadas aos nos e atualizar pesos se necessario
                    for (auto edge : nodes[j].adj) {
                        int v = edge.first;
                        int cost = edge.second;
                        if (nodes[j].distance + cost < nodes[v].distance) {
                            nodes[v].distance = nodes[j].distance + cost;
                        }
                    }
                }
                //putchar('\n');
            }

            // estamos meio que a "relaxar" novamente, mas agora para confirmacao de possivel ciclo negativo
            bool flag = false;
            for (int i = 0; i < n; i++) {
                for (auto edge : nodes[i].adj) {
                    int v = edge.first;
                    int cost = edge.second;
                    if (nodes[i].distance + cost < nodes[v].distance) {
                        flag = true;
                    }
                }
            } 

            return flag;
        }
};

int main() {
    int k;
    scanf("%d", &k);

    while (k--) {
        int n, e;
        scanf("%d %d", &n, &e);

        graph *g = new graph(n);

        for (int i = 0; i < e; i++) {
            int v1, v2, w;
            scanf("%d %d %d", &v1, &v2, &w);
            g->addLink(v1, v2, w);
        }

        if (g->bellman_ford(0)) {
            printf("possivel\n");
        } else {
            printf("impossivel\n");
        }
    }

    return 0;
}
