#include <bits/stdc++.h>
#define MAX 1000
#define int long long

using namespace std;
typedef pair<int, int> pr;

int uf_parent[MAX], parent[MAX];
set<int> S[MAX];

void clear(int K, bool set_clear = true) {
    for (int i = 1; i <= K; i++) {
        uf_parent[i] = i;
        if (set_clear) {
            S[i].clear();
            S[i].insert(i);
        }
    }
}

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

    if (S[A].size() < S[B].size())
        swap(S[A], S[B]);
    for (int i : S[B])
        S[A].insert(i);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q, A, B, C;
    cin >> N >> Q;

    clear(N, false);
    for (int i = 2; i <= N; i++) {
        cin >> A;
        parent[i] = A;
    }

    for (int i = 1; i <= N; i++) {
        cin >> A;
        S[i].insert(A);
    }

    vector<pr> queries;
    Q += N - 1;
    for (int i = 1; i <= Q; i++) {
        cin >> A >> B;
        queries.push_back({A, B});
    }
    reverse(queries.begin(), queries.end());

    stack<int> ans;
    for (int i = 0; i < Q; i++) {
        A = queries[i].first, B = queries[i].second;

        if (A == 1)
            uni(B, parent[B]);
        else if (A == 2) {
            B = find(B);
            ans.push(S[B].size());
        }
    }

    while (!ans.empty()) {
        cout << ans.top() << '\n';
        ans.pop();
    }

    return 0;
}