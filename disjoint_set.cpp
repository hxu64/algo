#include <bits/stdc++.h>
using namespace std;

#define SIZE 10000

vector<int> parent, sz;

void make_set(int x)
{
    parent[x] = x;
    sz[x] = 1;
}

int find_set(int x)
{
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find_set(parent[x]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] <= sz[b]) {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
}
 
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
}
