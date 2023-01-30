#include <iostream>
#include <climits>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef map<string,int> msi;

msi places;
int cnt = 1;

class Node {
    public:
        list<pair<int,float>> adj;
        bool visited;
        float distance;
};

class Graph {
    public:
        int n;
        Node *nodes;

        Graph(int n) {
            this->n = n;
            nodes = new Node[n+1];
        }

        void addLink(int a, int b, float c) {
            nodes[a].adj.push_back({b,c});
            nodes[b].adj.push_back({a,c});
            //printf("Added edge between node[%d] & node[%d] with weight[%f]\n", a, b, c);
        }

        void dijkstra(int s) {
            //printf("s: %d\n", s);
            for (int i = 1; i <= n; i++) {
                nodes[i].visited = false;
                nodes[i].distance = INT_MAX;
                //printf("node[%d] -> %f\n", i, nodes[i].distance);
            }

            nodes[s].distance = 0;

            set<pair<float,int>> q;
            q.insert({0,s});

            while (!q.empty()) {
                int u = q.begin()->second;
                q.erase(q.begin());

                nodes[u].visited = true;
                //printf("%d:[dist = %f]\n", u, nodes[u].distance);

                for (auto const &edge : nodes[u].adj) {
                    int v = edge.first;
                    float cost = edge.second;
                    if (!nodes[v].visited && nodes[u].distance + cost < nodes[v].distance) {
                        nodes[v].distance = nodes[u].distance + cost;
                        q.insert({nodes[v].distance, v});
                    }
                }
            }
        }
};

void addToMap(string s1, string s2) {
    if (places.count(s1) == 0) {
        places.insert({s1, cnt});
        cnt++;
    }
    if (places.count(s2) == 0) {
        places.insert({s2, cnt});
        cnt++;
    }
}

// https://www.geeksforgeeks.org/program-extract-words-given-string/
vector<string> getWords(string line) {
    vector<string> words;
    string token;
    istringstream iss(line);

    while (iss >> token) words.push_back(token);

    return words;
}

int main() {
    int n, e;
    scanf("%d %d\n", &n, &e);

    Graph* g = new Graph(n);

    string line;
    getline(cin, line);

    vector<string> l = getWords(line);

    string start, end;
    start = l[0];
    end = l[1];

    for (int i = 0; i < e; i++) {
        l.clear(); // so para ter a certeza
        getline(cin, line);
        l = getWords(line);
        addToMap(l[0], l[1]);
        g->addLink(places[l[0]], places[l[1]], stof(l[2]));
    }

    /*
    for (auto const &pair: places) {
        cout << "key: " << pair.first << " / " << "value: " << pair.second << endl;
    }*/
g->addLink(places[l[0]], places[l[1]], stof(l[2]));
    g->dijkstra(places[start]);

    printf("%.1f\n", g->nodes[places[end]].distance);

    return 0;
}