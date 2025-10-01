#include <bits/stdc++.h>
using namespace std;

const int MAX = 200001;

int A[MAX], S[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, Q, X, Y;
    vector<int> L, R;
    multiset<int> st;

    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 0; i < M; i++)
        cin >> X, L.push_back(X);
    for (int i = 0; i < M; i++)
        cin >> X, R.push_back(X);

    sort(L.begin(), L.end()), sort(R.begin(), R.end());
    for (int i = 0; i < M; i++) {
        if (L[i] > R[i])
            st.insert(1e9);
        else
            S[L[i]]++, S[R[i] + 1]--;
    }

    for (int i = 1; i <= N; i++) {
        S[i] += S[i - 1];
        if (S[i])
            st.insert(A[i]);
    }

    while (Q--) {
        cin >> X >> Y;
        if (X == Y) {
            cout << *st.rbegin() << '\n';
            continue;
        }

        if (S[X])
            st.erase(st.find(A[X]));
        if (S[Y])
            st.erase(st.find(A[Y]));

        swap(A[X], A[Y]);
        if (S[X])
            st.insert(A[X]);
        if (S[Y])
            st.insert(A[Y]);

        cout << *st.rbegin() << '\n';
    }

    return 0;
}