#include <bits/stdc++.h>
#define int long long
#define MAX 200100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<pr> arr[MAX];
int sz[MAX], K;
bool checked[MAX];

map<int, int> mp;
queue<pr> q;

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
    int res = LLONG_MAX;
    if (dist > K)
        return res;
    if (mp[K - dist])
        res = min(res, mp[K - dist] + depth);
    q.push({dist, depth});
    for (pr i : arr[node]) {
        if (i.first == parent || checked[i.first])
            continue;
        res = min(res, get_res(i.first, node, dist + i.second, depth + 1));
    }
    return res;
}

int divide_and_conquer(int node) {
    get_size(node, -1);
    int res = LLONG_MAX, cent = get_centroid(node, -1, sz[node]);
    checked[cent] = true;
    mp.clear();

    for (pr i : arr[cent]) {
        if (checked[i.first])
            continue;
        res = min(res, get_res(i.first, cent, i.second, 1));
        while (!q.empty()) {
            pr cur = q.front();
            q.pop();
            mp[cur.first] = mp[cur.first] ? min(mp[cur.first], cur.second) : cur.second;
        }
    }

    if (mp[K])
        res = min(res, mp[K]);

    for (pr i : arr[cent]) {
        if (checked[i.first])
            continue;
        res = min(res, divide_and_conquer(i.first));
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, A, B, C, res;
    cin >> N >> K;

    for (int i = 0; i < N - 1; i++) {
        cin >> A >> B >> C;
        A++, B++;
        arr[A].push_back({B, C});
        arr[B].push_back({A, C});
    }

    res = divide_and_conquer(1);
    cout << (res < LLONG_MAX ? res : -1);

    return 0;
}