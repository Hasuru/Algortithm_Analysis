#include <iostream>
#include <cstring>
#include <climits>
#include <list>

#define set0(a) (memset(a, 0, sizeof(a)))

using namespace std;

class node {
    public:
        list<pair<int,int>> adj;
};

class graph {
    public:
        int n;
        node* nodes;

        graph(int n) {
            this->n = n;
            nodes = new node[n];
        }

        void addLink(int a, int b, int c) {
            nodes[a].adj.push_back({b,c});
            //printf("added link: [%c] -> [%c] => %d\n", a+'A', b+'A', c);
        }

        void floyd_warshall() {
            int dist[n][n];

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = INT_MAX/2;
                }
            }

            for(int i = 0; i < n; i++) {
                dist[i][i] = 1;
            }

            // atualizar pecos das arestas ja existentes
            for (int i = 0; i < n; i++) {
                for (auto edge : nodes[i].adj) {
                    dist[i][edge.first] = edge.second;
                }
            }

            // calculo dos caminhos possiveis entre vertices
            for (int k = 0; k < n; k++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (dist[i][k] + dist[k][j] < dist[i][j]) {
                            dist[i][j] = dist[i][k] + dist[k][j];
                        }
                    }
                }
            }
            
            // ajustar valores de dist para apenas possuir 1's e 0's
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][j] != 1) dist[i][j] = 0;
                }
            }

            // imprimir output
            for (int i = 0; i <= n; i++) {
                if (i != 0) printf(" %c", (i-1) + 'A');
                else printf(" ");
            }
            putchar('\n');

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (j == 0) printf("%c %d", i + 'A', dist[i][j]);
                    else printf(" %d", dist[i][j]);
                }
                putchar('\n');
            }
        }
};

int main() {
    int n;
    scanf("%d", &n);

    graph *g = new graph(n);

    for (int i = 0; i < n; i++) {
        char v1;
        int links;
        scanf(" %c %d", &v1, &links);

        for (int i = 0; i < links; i++) {
            char v2;
            scanf(" %c", &v2);
            g->addLink(v1-'A', v2-'A', 1);
        }
    }

    g->floyd_warshall();

    return 0;
}