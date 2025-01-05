#include <bits/stdc++.h>
#define MAX 1100

using namespace std;

int X[MAX], res[MAX][MAX], parent[MAX];
bool chk[MAX];

int query(int A, int B) {
    if (res[A][B] != 0)
        return res[A][B];
    cout << "? " << A << " " << B << '\n', cout.flush();
    cin >> res[A][B];
    return res[A][B];
}

signed main() {
    int N, K, P, Q, A, B;
    vector<int> st;
    cin >> N;

    for (int i = 2; i <= N; i++)
        X[query(1, i)] = i;

    st.push_back(1);
    for (int i = 2; i <= N; i++) {
        if (chk[i])
            continue;

        while (st.size() >= 2) {
            P = st[st.size() - 1], Q = st[st.size() - 2];
            if (query(X[i], P) == 2) {
                parent[X[i]] = P, st.push_back(X[i]);
                break;
            }

            if (query(X[i], P) > query(X[i], Q))
                st.pop_back();
            else {
                parent[X[i]] = P, st.push_back(X[i]);
                if (query(X[i], P) > 2)
                    parent[X[i + 1]] = X[i], st.push_back(X[i + 1]), chk[i + 1] = true;
                break;
            }
        }

        if (st.size() <= 1) {
            st.push_back(X[i]), parent[X[i]] = 1;
            continue;
        }
    }

    cout << "!\n";
    for (int i = 2; i <= N; i++)
        cout << i << ' ' << parent[i] << '\n';
    cout.flush();

    return 0;
}