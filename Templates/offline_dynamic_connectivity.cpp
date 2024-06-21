#include <bits/stdc++.h>
#define MAX 1001
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
        for (int i = 1; i <= N; i++) {
            uf_parent[i] = i;
            rank[i] = 0;
        }
    }
};

class OfflineDynamicConnectivity {
  private:
    vector<pr> tree[MAX << 2];
    ftp edge_time[MAX];
    map<pr, int> mp;
    vector<ftp> edges;

    UnionFind uf;

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
            ans.push_back(uf.find(query[s].first) == uf.find(query[s].second));
        else {
            divide(n << 1, s, (s + e) >> 1);
            divide(n << 1 | 1, ((s + e) >> 1) + 1, e);
        }
        uf.rollback(cnt);
    }

  public:
    int N, Q, query_cnt = 0, query_num = 0;
    pr query[MAX];
    vector<bool> ans;

    OfflineDynamicConnectivity(int n) : N(n), uf(n) {}

    void add_line(int A, int B) {
        mp[{A, B}] = ++query_num;
        edge_time[query_num] = {A, B, query_cnt + 1, -1};
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
            update(1, 1, query_cnt, edge_time[i][2], edge_time[i][3], {edge_time[i][0], edge_time[i][1]});
        }
    }

    void run() { divide(1, 1, query_cnt); }
};