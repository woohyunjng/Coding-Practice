#include <bits/stdc++.h>
#define MAX 1000
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int subst(int A, int B) { return A * MAX + B; }
pr to_pair(int K) { return {K / MAX, K % MAX}; }

// 경로 압축
class UnionFind {
  private:
    int uf_parent[MAX];

  public:
    UnionFind(int N) { clear(N); }

    int find(int K) {
        if (uf_parent[K] != K)
            uf_parent[K] = find(uf_parent[K]);
        return uf_parent[K];
    }

    void uni(int A, int B) {
        A = find(A), B = find(B);
        if (A > B)
            swap(A, B);
        uf_parent[B] = A;
    }

    void clear(int N) {
        for (int i = 1; i <= N; i++)
            uf_parent[i] = i;
    }
};

// union-by-rank
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