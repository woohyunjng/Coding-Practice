#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

int ans[MAX], V[MAX], K[MAX], U[MAX];

vector<pr> val[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, Q, T, A, S, C, X, MX = 100'000;
    bool flag;

    pr Y;
    vector<int> arr;

    multiset<pr> st;
    vector<pr> tmp;

    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> A >> S >> C >> X;
        if (X != 0) {
            val[(C + X - 1) / X].push_back({A + S, 1}), C--;
            val[(C + X - 1) / X].push_back({A, C % X});
            val[C / X].push_back({A, -i}), V[i] = X, K[i] = C / X + 1;
        } else {
            val[MX].push_back({A + S, 1});
            if (C > 1)
                val[MX].push_back({A, C - 1});
        }
    }

    for (int i = MX; i >= 1; i--) {
        for (pr j : val[i])
            st.insert(j);

        for (int j = 1; j <= M; j++) {
            flag = false;
            while (!flag && !st.empty()) {
                Y = *st.rbegin(), st.erase(prev(st.end())), flag = true;
                if (Y[1] > 0) {
                    arr.push_back(Y[0]), Y[1]--;
                    if (Y[1])
                        st.insert(Y);
                } else {
                    if ((K[-Y[1]] - i) * V[-Y[1]] - U[-Y[1]] > 0)
                        arr.push_back(Y[0]), U[-Y[1]]++, st.insert({Y[0], Y[1]});
                    else
                        tmp.push_back({Y[0], Y[1]}), flag = false;
                }
            }
        }

        while (!tmp.empty())
            st.insert(tmp.back()), tmp.pop_back();
    }

    sort(arr.rbegin(), arr.rend());

    for (int i = 1; i <= MX; i++) {
        ans[i] = ans[i - 1];
        for (int j = 1; j <= M && (i - 1) * M + j - 1 < arr.size(); j++)
            ans[i] += arr[(i - 1) * M + j - 1];
    }

    while (Q--) {
        cin >> T;
        cout << ans[T] << '\n';
    }

    return 0;
}