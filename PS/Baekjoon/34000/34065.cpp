#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 200001;

int P[MAX], A[MAX], B[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, X;
    vector<pr> ans;

    set<int> st;
    set<int>::iterator it;

    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        cin >> A[i], P[A[i]] = i;
    for (int i = 1; i <= N; i++)
        cin >> X, B[i] = P[X];

    for (int i = 1; i <= N; i++) {
        it = st.lower_bound(-B[i]);
        while (it != st.end() && K > 0)
            ans.push_back({-*it, B[i]}), it = next(it), K--;
        st.insert(-B[i]);
    }

    if (K > 0)
        cout << "No" << '\n';
    else {
        cout << "Yes" << '\n';
        for (pr i : ans)
            cout << A[i[0]] << ' ' << A[i[1]] << '\n';
    }

    return 0;
}