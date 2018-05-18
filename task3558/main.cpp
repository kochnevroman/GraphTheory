#include <vector>
#include <iostream>
#include <string>

using namespace std;
struct DSU {
    vector <int> parent;

    DSU(int size)
    {
        parent.resize(size, -1);
    }

    void hang(int v, int p)
    {
        parent[v] = p;
    }

    void print()
    {
        for (int i(0); i < parent.size(); ++i) {
            if (parent[i] != -1)
                cout << i << " -> " << parent[i] << '\n';
            else
                cout << i << '\n';
        }
    }

    int find(int v)
    {
        int r = v;
        while (parent[r] != -1)
            r = parent[r];
        while (parent[v] != -1)
        {
            int tmp = v;
            v = parent[v];
            parent[tmp] = r;
        }
        return v;
    }

    void reset(int n)
    {
        parent.resize(n);
        for (int i(0); i < n; i += 1) {
            if (parent[i] != -1) {
                hang(i, -1);
            }
        }
        cout << "RESET DONE" << '\n';
    }

    void check(int j, int k)
    {
        if (find(j) == find(k)) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }

    void join(int j, int k)
    {
        if (find(j) == find(k)) {
            cout << "ALREADY " << j << " " << k << '\n';
        }
        else {
            hang(find(j), find(k));
        }
    }
};

int main() {
    DSU dsu(1);

    dsu.reset(15);

    dsu.join(14, 10);
    dsu.join(13, 8);
    dsu.join(0, 9);
    dsu.join(8, 3);
    dsu.join(4, 1);
    dsu.join(10, 5);
    dsu.join(8, 4);

    dsu.check(2, 11);

    dsu.join(4, 1);
    dsu.join(2, 6);

    dsu.check(9, 1);

    dsu.join(6, 5);

    dsu.check(10, 5);
    return 0;
}