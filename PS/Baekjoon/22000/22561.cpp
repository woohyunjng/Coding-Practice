#include <bits/stdc++.h>
#define MAX 4000100
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;
typedef array<int, 4> ftp;

class UnionFind {
  private:
    vector<int> uf_parent, rank;
    stack<tp> st;

  public:
    UnionFind(int N) : uf_parent(N + 1), rank(N + 1, 0) { clear(N); }

    int find(int K) { return uf_parent[K] == K ? K : find(uf_parent[K]); }

    bool uni(int A, int B) {
        A = find(A), B = find(B);
        if (A == B)
            return false;

        if (rank[A] < rank[B])
            swap(A, B);
        st.push({A, B, rank[A] == rank[B]});
        uf_parent[B] = A;
        rank[A] += rank[A] == rank[B];
        return true;
    }

    void rollback(int cnt = 1) {
        while (cnt--) {
            tp cur = st.top();
            st.pop();
            uf_parent[cur[1]] = cur[1];
            rank[cur[0]] -= cur[2];
        }
    }

    void clear(int N) {
        for (int i = 0; i <= N; i++) {
            uf_parent[i] = i;
            rank[i] = 0;
        }
    }
};

vector<pr> tree[MAX << 2];
ftp edge_time[MAX];
pr query[MAX];
int ans[MAX];

UnionFind uf(MAX - 1);

void update(int n, int s, int e, int l, int r, pr k) {
    if (l <= s && e <= r) {
        tree[n].push_back(k);
        return;
    }
    if (e < l || r < s)
        return;

    update(n << 1, s, (s + e) >> 1, l, r, k);
    update(n << 1 | 1, ((s + e) >> 1) + 1, e, l, r, k);
}

void divide(int n, int s, int e) {
    int cnt = 0;
    for (pr i : tree[n])
        cnt += uf.uni(i.first, i.second);

    if (s == e)
        ans[s] = (uf.find(query[s].first) == uf.find(query[s].second));
    else {
        divide(n << 1, s, (s + e) >> 1);
        divide(n << 1 | 1, ((s + e) >> 1) + 1, e);
    }
    uf.rollback(cnt);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, A, B, C, K, cnt = 0;
    cin >> N >> M;

    map<pr, int> mp;
    vector<ftp> edges;

    for (int i = 1; i <= M; i++) {
        cin >> A >> B >> C;
        B++, C++;

        if (A == 1) {
            mp[{B, C}] = i;
            edge_time[i] = {B, C, cnt + 1, -1};
        } else if (A == 2) {
            K = mp[{B, C}];
            edge_time[K][3] = cnt;
        } else if (A == 3)
            query[++cnt] = {B, C};
    }

    if (!cnt)
        return 0;

    for (int i = 1; i <= M; i++) {
        if (edge_time[i][2] == 0)
            continue;
        if (edge_time[i][3] == -1)
            edge_time[i][3] = cnt;

        update(1, 1, cnt, edge_time[i][2], edge_time[i][3], {edge_time[i][0], edge_time[i][1]});
    }

    divide(1, 1, cnt);

    for (int i = 1; i <= cnt; i++)
        cout << (ans[i] ? "YES" : "NO") << '\n';

    return 0;
}