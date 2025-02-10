#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 200000;

int S[MAX], T[MAX], W[MAX], A[MAX], B[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, X;
    vector<int> arr;

    set<pr> st;
    set<pr>::iterator iter;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> S[i] >> T[i], arr.push_back(i);
        A[i] = T[i] - S[i], B[i] = T[i] + S[i];
    }

    sort(arr.begin(), arr.end(), [&](int x, int y) { return A[x] != A[y] ? A[x] < A[y] : B[x] < B[y]; });
    for (int i : arr) {
        if (st.empty() || (*st.begin())[0] > B[i])
            X = st.size() + 1;
        else {
            iter = prev(st.lower_bound({B[i] + 1, 0}));
            X = (*iter)[1], st.erase(iter);
        }
        W[i] = X, st.insert({B[i], W[i]});
    }

    cout << st.size() << '\n';
    for (int i = 1; i <= N; i++)
        cout << S[i] << ' ' << T[i] << ' ' << W[i] << '\n';

    return 0;
}