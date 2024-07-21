#include <bits/stdc++.h>
#define int long long
#define MAX 200100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<pr> arr[MAX];
int sz[MAX];
bool checked[MAX];

int get_size(int node, int parent) {
    sz[node] = 1;
    for (pr i : arr[node]) {
        if (i.first == parent || checked[i.first])
            continue;
        sz[node] += get_size(i.first, node);
    }
    return sz[node];
}

int get_centroid(int node, int parent, int cap) {
    for (pr i : arr[node]) {
        if (i.first == parent || checked[i.first])
            continue;
        if (sz[i.first] * 2 > cap)
            return get_centroid(i.first, node, cap);
    }
    return node;
}

int get_res(int node, int parent, int dist, int depth) {
    // 분할 정복
}

int divide_and_conquer(int node) {
    get_size(node, -1);
    int res = LLONG_MAX, cent = get_centroid(node, -1, sz[node]);
    checked[cent] = true;
    mp.clear();

    for (pr i : arr[cent]) {
        if (checked[i.first])
            continue;
    }

    for (pr i : arr[cent]) {
        if (checked[i.first])
            continue;
        res = min(res, divide_and_conquer(i.first));
    }
    return res;
}