#include <bits/stdc++.h>
#define MAX 1001
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;
typedef array<int, 5> ftp;

class UnionFind {
  private:
    vector<int> uf_parent, rank;
    stack<tp> st;

  public:
    UnionFind() {
        uf_parent.resize(MAX);
        rank.resize(MAX);
        clear(MAX - 1);
    }
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
        for (int i = 1; i <= N; i++) {
            uf_parent[i] = i;
            rank[i] = 0;
        }
    }
};

class OfflineDynamicConnectivity {
  private:
    vector<tp> tree[MAX << 2];
    ftp edge_time[MAX];
    map<pr, int> mp;
    vector<ftp> edges;

    UnionFind uf[10];

    void update(int n, int s, int e, int l, int r, tp k) {
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
        int cnt[10] = {};
        for (tp i : tree[n]) {
            for (int j = i[2]; j < 10; j++)
                cnt[j] += uf[j].uni(i[0], i[1]);
        }

        if (s == e) {
            int check = -1;
            for (int i = 0; i < 10; i++) {
                if (uf[i].find(query[s].first) == uf[i].find(query[s].second)) {
                    check = i;
                    break;
                }
            }
            ans.push_back(check);
        } else {
            divide(n << 1, s, (s + e) >> 1);
            divide(n << 1 | 1, ((s + e) >> 1) + 1, e);
        }
        for (int i = 0; i < 10; i++)
            uf[i].rollback(cnt[i]);
    }

  public:
    int N, Q, query_cnt = 0, query_num = 0;
    pr query[MAX];
    vector<int> ans;

    OfflineDynamicConnectivity(int n) : N(n) {}

    void add_line(int A, int B, int C) {
        mp[{A, B}] = ++query_num;
        edge_time[query_num] = {A, B, query_cnt + 1, -1, C};
    }

    void remove_line(int A, int B) {
        int K = mp[{A, B}];
        edge_time[K][3] = query_cnt;
    }

    void add_query(int A, int B) {
        query[++query_cnt] = {A, B};
    }

    void update_queries() {
        for (int i = 1; i <= query_num; i++) {
            if (edge_time[i][3] == -1)
                edge_time[i][3] = query_cnt;
            update(1, 1, query_cnt, edge_time[i][2], edge_time[i][3], {edge_time[i][0], edge_time[i][1], edge_time[i][4]});
        }
    }

    void run() { divide(1, 1, query_cnt); }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q, A, B, C, D;
    cin >> N >> Q;

    OfflineDynamicConnectivity odc(N);
    while (Q--) {
        cin >> A >> B >> C;
        if (B > C)
            swap(B, C);
        if (A == 0) {
            cin >> D;
            odc.add_line(B, C, D);
        } else if (A == 1) {
            odc.remove_line(B, C);
        } else {
            odc.add_query(B, C);
        }
    }

    odc.update_queries();
    odc.run();

    for (int i : odc.ans)
        cout << i << '\n';

    return 0;
}