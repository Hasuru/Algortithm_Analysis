#include <iostream>
#include <climits>
#include <cmath>
#include <list>
#include <set>
#include <map>

using namespace std;

double total = 0;

class node {
    public:
        list<pair<int, double>> adj;
        bool visited;
        double distance;
};

class graph {
    public:
        int n;
        node* nodes;

        graph(int n) {
            this->n = n;
            nodes = new node[n+1];
        }

        void addLink(int a, int b, double c) {
            nodes[a].adj.push_back({b,c});
            //printf("Added node[%d] to node[%d] with weight[%lf]\n", a, b, c);
        }

        void prim(int s) {
            //Inicializar nos como nao visitados e com distancia infinita
            for (int i=1; i<=n; i++) {
                nodes[i].distance = INT_MAX/2;
                nodes[i].visited  = false;
            }
            
            // Inicializar "fila" com no origem
            nodes[s].distance = 0;
            set<pair<double, int>> q;
            q.insert({0, s});      

            while (!q.empty()) {
            
            // Retirar no com menor distancia (o "primeiro" do set, que e uma BST)
                int u = q.begin()->second;
                q.erase(q.begin());
                nodes[u].visited = true;
                total += nodes[u].distance;
                //cout << u << " [dist=" << nodes[u].distance << "]" << endl;

                // Relaxar arestas do no retirado
                for (auto edge : nodes[u].adj) {
                    int v = edge.first;
                    double cost = edge.second;
                    if (!nodes[v].visited && cost < nodes[v].distance) {
                        q.erase({nodes[v].distance, v});
                        nodes[v].distance = cost;
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

    map<pair<int,int>,int> map;


    for (int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        map.insert({{x,y}, i});
    }

    // debug
    /*
    for (auto it : map) {
        printf("point(%d,%d) -> node[%d]\n", it.first.first, it.first.second, it.second);
    }*/

    // fazer clique
    for (auto i : map) {
        for (auto j : map) {
            double dist = pow((i.first.first - j.first.first),2) + pow((i.first.second - j.first.second),2);
            g->addLink(i.second, j.second, sqrt(dist));
        }
    }

    g->prim(1);

    printf("%lf\n", total);

    return 0;
}