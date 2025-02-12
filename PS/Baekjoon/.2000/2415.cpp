#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;
typedef array<int, 5> ftp;

const int MAX = 2000;

int X[MAX], Y[MAX];

int sz(pr A, pr B, pr C) { return abs(A[0] * B[1] + B[0] * C[1] + C[0] * A[1] - B[0] * A[1] - C[0] * B[1] - A[0] * C[1]); }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 0, S;
    ftp K;
    vector<ftp> arr;
    vector<pr> st;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> X[i] >> Y[i];

    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++)
            arr.push_back({X[i] + X[j], Y[i] + Y[j], (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]), i, j});
    sort(arr.begin(), arr.end());

    N = arr.size();
    for (int i = 0; i < N; i++) {
        K = arr[i], st.push_back({arr[i][3], arr[i][4]});
        while (i + 1 < N && arr[i + 1][0] == K[0] && arr[i + 1][1] == K[1] && arr[i + 1][2] == K[2])
            i++, st.push_back({arr[i][3], arr[i][4]});

        S = st.size();
        for (int j = 0; j < S; j++)
            for (int k = j + 1; k < S; k++)
                ans = max(ans, sz({X[st[j][0]], Y[st[j][0]]}, {X[st[j][1]], Y[st[j][1]]}, {X[st[k][0]], Y[st[k][0]]}));
        st.clear();
    }

    cout << ans << '\n';
}