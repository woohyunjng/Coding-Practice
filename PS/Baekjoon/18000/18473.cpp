#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300001;

typedef array<int, 3> pr;

int uf[MAX], W[MAX], A[MAX], B[MAX], S[MAX],
    V[MAX], C[MAX][2];

priority_queue<pr, vector<pr>, greater<pr>> pq[MAX];

int find(int X) { return uf[X] == X ? X : uf[X] = find(uf[X]); }
void merge(int X, int Y) {
    X = find(X), Y = find(Y);
    if (pq[X].size() < pq[Y].size())
        swap(X, Y);
    uf[Y] = X, W[X] += W[Y];
    while (!pq[Y].empty())
        pq[X].push(pq[Y].top()), pq[Y].pop();
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X;
    pr K;

    vector<int> ans, arr;
    set<int> st;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> W[i], uf[i] = i;

    for (int i = 1; i <= M; i++) {
        cin >> A[i] >> B[i] >> S[i];
        S[i] -= W[A[i]] + W[B[i]], C[i][0] = W[A[i]], C[i][1] = W[B[i]];
        if (S[i] <= 0)
            st.insert(i);
        else {
            pq[A[i]].push({(S[i] + 1) / 2 + C[i][0], i, V[i]});
            pq[B[i]].push({(S[i] + 1) / 2 + C[i][1], i, V[i]});
        }
    }

    while (!st.empty()) {
        X = *st.begin(), st.erase(st.begin());
        if (find(A[X]) == find(B[X]))
            continue;
        ans.push_back(X), merge(A[X], B[X]), X = find(A[X]);
        while (!pq[X].empty() && pq[X].top()[0] <= W[X]) {
            K = pq[X].top(), pq[X].pop();
            if (V[K[1]] != K[2])
                continue;
            arr.push_back(K[1]);
        }
        sort(arr.begin(), arr.end()), arr.erase(unique(arr.begin(), arr.end()), arr.end());
        for (int i : arr) {
            if (find(A[i]) == find(B[i]))
                continue;
            V[i]++, S[i] -= W[find(A[i])] - C[i][0] + W[find(B[i])] - C[i][1];
            if (S[i] <= 0) {
                st.insert(i);
                continue;
            }
            C[i][0] = W[find(A[i])], C[i][1] = W[find(B[i])];
            pq[find(A[i])].push({(S[i] + 1) / 2 + C[i][0], i, V[i]});
            pq[find(B[i])].push({(S[i] + 1) / 2 + C[i][1], i, V[i]});
        }
        arr.clear();
    }

    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';

    return 0;
}