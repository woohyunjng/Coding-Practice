#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 600001;

int S[MAX][3];
vector<pr> points[MAX + 1];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, ans = -1;
    char C;

    vector<pr> arr;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X >> C;
        arr.push_back({X, (C == 'R' ? 0 : C == 'G' ? 1
                                                   : 2)});
    }

    sort(arr.begin(), arr.end());

    for (int i = 1; i <= N; i++) {
        S[i][arr[i - 1][1]]++;
        S[i][0] += S[i - 1][0], S[i][1] += S[i - 1][1], S[i][2] += S[i - 1][2];
    }

    for (int i = 0; i < N; i++) {
        X = lower_bound(arr.begin(), arr.end(), (pr){arr[i][0] * 2, 0}) - arr.begin();
        points[S[X][0] - S[i][0] + 1].push_back({S[X][1] - S[i][1] + 1, S[X][2] - S[i][2] + 1});
    }

    set<tp> st;
    set<tp>::iterator iter;
    tp K;

    st.insert({0, MAX * 2, 0});

    X = 0;
    for (int i = N + 1; i >= 1; i--) {
        for (pr j : points[i]) {
            iter = st.lower_bound({j[0], j[1], 0});
            if (iter != st.end() && (*iter)[1] >= j[1])
                continue;
            if (iter != st.end()) {
                K = *iter, st.erase(iter), X -= K[2];
                K[2] = K[1] * (K[0] - j[0]), X += K[2];
                st.insert(K);
            }

            while (true) {
                iter = prev(st.lower_bound({j[0], j[1], 0}));
                if ((*iter)[1] > j[1])
                    break;
                K = *iter, st.erase(iter), X -= K[2];
            }

            K = {j[0], j[1], 0};
            iter = prev(st.lower_bound(K)), K[2] = j[1] * (j[0] - (*iter)[0]), X += K[2];
            st.insert(K);
        }
        ans += X;
    }

    cout << ans << '\n';

    return 0;
}