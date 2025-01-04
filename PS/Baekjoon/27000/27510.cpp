#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

class ConvexHullTrick {
  public:
    vector<tp> F;

    void insert(tp K) {
        while (!F.empty()) {
            if (F.back()[0] == K[0]) {
                if (F.back()[1] <= K[1])
                    return;
            } else {
                K[2] = (F.back()[1] - K[1]) / (K[0] - F.back()[0]);
                if (F.back()[2] < K[2])
                    break;
            }
            F.pop_back();
        }
        F.push_back(K);
    }

    int query(int x) {
        if (F.empty())
            return INF;

        int res = F.size() - 1, st = 0, en = F.size() - 1, mid;
        if (x < F.back()[2]) {
            while (st + 1 < en) {
                mid = (st + en) / 2;
                if (x < F[mid][2])
                    en = mid;
                else
                    st = mid;
            }
            res = st;
        }
        return F[res][0] * x + F[res][1];
    }
};

ConvexHullTrick cht[MAX];

vector<pr> adj[MAX];
map<int, int> dis[MAX];

int res[MAX], sz[MAX], parent[MAX];
bool vst[MAX];

int get_size(int node, int par) {
    int res = 1;
    for (pr i : adj[node]) {
        if (vst[i.first] || i.first == par)
            continue;
        res += get_size(i.first, node);
    }
    return sz[node] = res;
}

int get_centroid(int node, int par, int cap) {
    for (pr i : adj[node]) {
        if (vst[i.first] || i.first == par)
            continue;
        if (sz[i.first] * 2 > cap)
            return get_centroid(i.first, node, cap);
    }
    return node;
}

void get_dis(int node, int par, int cent, int depth) {
    dis[node][cent] = depth;
    for (pr i : adj[node]) {
        if (vst[i.first] || i.first == par)
            continue;
        get_dis(i.first, node, cent, depth + i.second);
    }
}

void build_tree(int node, int par) {
    int cent = get_centroid(node, -1, get_size(node, -1));
    vst[cent] = true, parent[cent] = par, get_dis(cent, -1, cent, 0);

    for (pr i : adj[cent]) {
        if (vst[i.first])
            continue;
        build_tree(i.first, cent);
    }
}

vector<int> travel(vector<int> A,
                   vector<signed> B, vector<signed> U, vector<signed> V, vector<signed> W) {

    int N = A.size(), K, X;
    vector<int> ans(N - 1), arr;

    fill(res, res + N, INF);

    for (int i = 0; i < N; i++)
        arr.push_back(i);
    sort(arr.begin(), arr.end(), [&](int a, int b) { return B[a] > B[b]; });

    for (int i = 0; i < N - 1; i++) {
        adj[U[i]].push_back({V[i], W[i]});
        adj[V[i]].push_back({U[i], W[i]});
    }

    build_tree(0, -1);

    for (int i = 0; i < N; i++)
        if (arr[i] == 0) {
            X = i, res[0] = 0;
            break;
        }

    for (int i = X; i < N; i++) {
        K = arr[i];
        while (K != -1)
            res[arr[i]] = min(res[arr[i]], cht[K].query(dis[arr[i]][K])), K = parent[K];

        K = arr[i];
        while (K != -1)
            cht[K].insert({B[arr[i]], res[arr[i]] + A[arr[i]] + B[arr[i]] * dis[arr[i]][K], 0}), K = parent[K];
    }

    for (int i = 1; i < N; i++) {
        K = i;
        while (K != -1)
            res[i] = min(res[i], cht[K].query(dis[i][K])), K = parent[K];
    }

    for (int i = 1; i < N; i++)
        ans[i - 1] = res[i];
    return ans;
}
