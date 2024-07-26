#include <bits/stdc++.h>
#define int long long
#define MAX 100100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> arr[MAX];
int sz[MAX], C[MAX];
bool checked[MAX];

map<int, int> mp;
queue<pr> q;

int get_size(int node, int parent) {
    sz[node] = 1;
    for (int i : arr[node]) {
        if (i == parent || checked[i])
            continue;
        sz[node] += get_size(i, node);
    }
    return sz[node];
}

int get_centroid(int node, int parent, int cap) {
    for (int i : arr[node]) {
        if (i == parent || checked[i])
            continue;
        if (sz[i] * 2 > cap)
            return get_centroid(i, node, cap);
    }
    return node;
}

int get_res(int node, int parent, int depth) {
    int res = LLONG_MAX;
    q.push({C[node], depth});
    if (mp.count(C[node]))
        res = mp[C[node]] + depth;

    for (int i : arr[node]) {
        if (i == parent || checked[i])
            continue;
        res = min(res, get_res(i, node, depth + 1));
    }
    return res;
}

int divide_and_conquer(int node) {
    get_size(node, -1);
    int res = LLONG_MAX, cent = get_centroid(node, -1, sz[node]);
    checked[cent] = true;
    mp.clear();

    mp[C[cent]] = 0;

    for (int i : arr[cent]) {
        if (checked[i])
            continue;
        res = min(res, get_res(i, cent, 1));
        while (!q.empty()) {
            pr cur = q.front();
            q.pop();
            if (mp.count(cur.first))
                mp[cur.first] = min(mp[cur.first], cur.second);
            else
                mp[cur.first] = cur.second;
        }
    }

    for (int i : arr[cent]) {
        if (checked[i])
            continue;
        res = min(res, divide_and_conquer(i));
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> C[i];

    for (int i = 1; i < N; i++) {
        cin >> A >> B;
        arr[A].push_back(B);
        arr[B].push_back(A);
    }

    cout << divide_and_conquer(1) << '\n';

    return 0;
}