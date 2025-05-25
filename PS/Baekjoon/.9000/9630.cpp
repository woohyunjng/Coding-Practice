#include <bits/stdc++.h>
#define int long long
#define double long double

using namespace std;

const int MAX = 300002;

int D, T[MAX], X[MAX], H[MAX], G[MAX];
double V[MAX][2];

void update(int A, int B) {
    if (G[A] == -1 || (X[B] - X[A]) * (H[G[A]] - H[A]) <= (X[G[A]] - X[A]) * (H[B] - H[A]))
        G[A] = B;
}

double get(int A) { return X[A] - (double)(X[G[A]] - X[A]) / (H[G[A]] - H[A]) * H[A]; }

void solve(vector<int> arr, int t) {
    vector<int> st;
    int A, B;

    for (int i : arr) {
        while (!st.empty() && H[st.back()] <= H[i])
            st.pop_back();

        while (st.size() > 1) {
            A = st[st.size() - 2], B = st.back();
            update(A, i), update(B, i);
            if (get(A) <= get(B))
                st.pop_back();
            else
                break;
        }

        if (T[i])
            st.push_back(i), V[i - t][t] = X[i];
        else if (!st.empty()) {
            A = st.back(), update(A, i);
            V[i - t][t] = min(V[i - t][t], get(A));
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    double ans = 0;

    cin >> N >> D, X[N + 1] = D;

    for (int i = 1; i <= N; i++)
        cin >> T[i] >> X[i] >> H[i];

    for (int i = 0; i <= N; i++)
        V[i][0] = X[i + 1], V[i][1] = D - X[i];

    vector<int> arr;

    for (int i = 1; i <= N; i++)
        arr.push_back(i);
    solve(arr, 0);

    reverse(arr.begin(), arr.end());
    for (int i = 0; i <= N + 1; i++)
        X[i] = D - X[i], G[i] = -1;
    solve(arr, 1);

    for (int i = 0; i <= N + 1; i++)
        X[i] = D - X[i];

    for (int i = 0; i <= N; i++)
        ans += X[i + 1] - V[i][0] + D - X[i] - V[i][1] - max(0.0L, D - V[i][0] - V[i][1]);

    cout << fixed << setprecision(3) << ans << '\n';

    return 0;
}