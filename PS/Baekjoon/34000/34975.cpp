#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 1000000;

typedef array<int, 2> pr;

int X[MAX], Y[MAX], D[MAX], uf[MAX], V[MAX];

int find(int K) { return K == uf[K] ? K : uf[K] = find(uf[K]); }
void uni(int A, int B) {
    A = find(A), B = find(B);
    if (A == B)
        return;
    if (A > B)
        swap(A, B);
    uf[B] = A;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, S, Z, PX, PY;
    pr K, L;
    vector<int> comp;

    set<pr> st;
    set<pr>::iterator iter;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i], D[i] = abs(X[i]) + abs(Y[i]);
        comp.push_back(D[i]);
    }

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), S = comp.size();
    for (int i = 0; i < S; i++) {
        uf[i] = i, V[i] = comp[i];
        st.insert({V[i], i});
    }

    for (int i = 0; i < N; i++)
        D[i] = lower_bound(comp.begin(), comp.end(), D[i]) - comp.begin();

    cin >> M;
    while (M--) {
        cin >> Z, iter = st.lower_bound(pr{Z + 1, -1});
        if (iter == st.begin())
            continue;
        iter = prev(iter), K = *iter;
        if (iter == st.begin() || (*prev(iter))[0] != K[0] - 1)
            st.erase(st.find(K)), V[K[1]]--, K[0] = V[K[1]], st.insert(K);
        else {
            L = *prev(iter), st.erase(st.find(K)), st.erase(st.find(L));
            uni(L[1], K[1]), st.insert(L);
        }
    }

    for (int i = 0; i < N; i++) {
        Z = abs(X[i]) + abs(Y[i]) - V[find(D[i])], PX = abs(X[i]), PY = abs(Y[i]);
        S = min(PX, Z), PX -= S, Z -= S;
        S = min(PY, Z), PY -= S, Z -= S;

        PX = X[i] < 0 ? -PX : PX, PY = Y[i] < 0 ? -PY : PY;
        cout << PX << ' ' << PY << '\n';
    }

    return 0;
}