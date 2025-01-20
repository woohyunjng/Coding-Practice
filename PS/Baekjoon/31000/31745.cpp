#include <bits/stdc++.h>
#define int long long

#define MAX 600000
using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

int A[MAX], B[MAX];
vector<int> AX[MAX], BX[MAX];
vector<pr> arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0, X, Y, V = 0, C = 0;
    tp K;

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i], AX[A[i]].push_back(i);
    for (int i = 1; i <= N; i++)
        cin >> B[i], BX[B[i]].push_back(i);

    for (int i = 1; i <= N; i++) {
        X = 0;
        for (int j : AX[i]) {
            while (X + 1 < BX[i].size() && BX[i][X + 1] <= j)
                X++;
            if (X < BX[i].size() && BX[i][X] <= j)
                arr[i].push_back({BX[i][X], j});
        }
        X = 0;
        for (int j : BX[i]) {
            while (X + 1 < AX[i].size() && AX[i][X + 1] <= j)
                X++;
            if (X < AX[i].size() && AX[i][X] <= j)
                arr[i].push_back({AX[i][X], j});
        }
    }

    set<tp> st;
    set<tp>::iterator iter;

    st.insert({0, N + 1, 0});

    for (int i = N; i >= 1; i--) {
        for (pr j : arr[i]) {
            X = j[0], Y = N + 1 - j[1];
            iter = st.lower_bound({X, 0, 0});
            if (iter != st.end() && (*iter)[1] >= Y)
                continue;
            iter = st.lower_bound({X, N + 1, 0});
            while ((*prev(iter))[1] <= Y) {
                C -= (*prev(iter))[2], st.erase(prev(iter));
                iter = st.lower_bound({X, N + 1, 0});
            }
            if (iter != st.end()) {
                K = *iter, st.erase(iter);
                C -= K[2], st.insert({K[0], K[1], (K[0] - X) * K[1]}), C += (K[0] - X) * K[1];
            }

            iter = st.lower_bound({X, N + 1, 0});
            K = {X, Y, (X - (*prev(iter))[0]) * Y}, C += K[2];
            st.insert(K);
        }
        res += (C - V) * i, V = C;
    }

    cout << res << '\n';

    return 0;
}