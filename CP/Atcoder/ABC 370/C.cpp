#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string S, T;
    int N, X;

    vector<string> res;
    stack<int> st;

    cin >> S;
    cin >> T;
    N = S.size();

    for (int i = 0; i < N; i++) {
        if (S[i] == T[i])
            continue;
        if (S[i] > T[i]) {
            S[i] = T[i];
            res.push_back(S);
        } else
            st.push(i);
    }

    while (!st.empty()) {
        X = st.top(), st.pop();
        S[X] = T[X];
        res.push_back(S);
    }

    cout << res.size() << '\n';
    if (!res.empty())
        for (string i : res)
            cout << i << '\n';

    return 0;
}