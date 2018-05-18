#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

struct Edge
{
    int v1;
    int v2;
    int w;
    Edge() {}
    Edge(int v1_, int v2_, int w_) : v1(v1_), v2(v2_), w(w_) {}
};

bool comparator(const Edge& a, const Edge& b) { return (a.w < b.w); }

class Graph
{
private:
    int n;
    std::vector<Edge> edges;

public:
    Graph();
    Graph(int n_, const std::vector<Edge>& edges_) : n(n_), edges(edges_) { }
    int get_number() const { return n; }
    const std::vector<Edge>& get_edges() const { return edges; }
    void sort() { std::sort(edges.begin(), edges.end(), comparator); }
};

class Kruskal
{
private:
    Graph graph;
    int length = 0;

    std::vector<int> parent;
    std::vector<int> rank = std::vector<int>(graph.get_number(), 1);

    void sets(int v1, int v2) {
        if (rank[v1] < rank[v2]) {
            std::swap(v1, v2);
        }
        parent[v2] = v1;
        if (rank[v1] == rank[v2]) {
            ++rank[v2];
        }
    }

public:
    Kruskal();
    Kruskal(const Graph& g) : graph(g) {}
    int get_parent(int v) {
        if (v == parent[v]) {
            return v;
        }
        else {
            return parent[v] = get_parent(parent[v]);
        }
    }

    int get_length() const { return length; }

    void kruskal() {
        graph.sort();
        parent.resize(graph.get_number());
        for (int i = 0; i < graph.get_number(); ++i) {
            parent[i] = i;
        }

        int edges_count = 0;

        for (int i = 0; i < graph.get_edges().size(); ++i) {
            int v1_parent = get_parent(graph.get_edges()[i].v1);
            int
                    v2_parent = get_parent(graph.get_edges()[i].v2);
            if (v1_parent != v2_parent) {
                ++edges_count;
                sets(v1_parent, v2_parent);
                length += graph.get_edges()[i].w;
            }
            if (edges_count == graph.get_number() - 1) {
                break;
            }
        }
    }

};


int main()
{
    int n, m , i, j , w;
    std::vector<Edge> edges;

    std::cin >> n >> m;
    edges.resize(m);

    for (int e(0); e < m; e += 1) {
        std::cin >> i >> j >> w;
        edges[e] = Edge(i - 1, j - 1, w);
    }
    Graph graph(n, edges);

    Kruskal kruskal(graph);
    kruskal.kruskal();

    std::cout << kruskal.get_length();

    return 0;
}