#include <bits/stdc++.h>
#define int long long

#define MAX 4000100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX], K;
bool checked[MAX];

int fpow(int X) {
    int res = 1;
    for (int i = 1; i <= K; i++)
        res *= X;
    return res;
}

int get_dp(int X) {
    if (checked[X])
        return dp[X];
    checked[X] = true;

    int A = 0, B = X, res = X;
    stack<int> st;

    while (B) {
        A += fpow(B % 10);
        B /= 10;
    }

    if (checked[A]) {
        if (dp[A])
            res = min(res, dp[A]);
        else {
            while (A != X) {
                st.push(A);
                res = min(res, A);
                B = A, A = 0;
                while (B) {
                    A += fpow(B % 10);
                    B /= 10;
                }
            }
        }
    } else
        res = min(res, get_dp(A));

    return dp[X] = res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int A, B, res = 0;

    cin >> A >> B >> K;
    for (int i = A; i <= B; i++)
        res += get_dp(i);

    cout << res;

    return 0;
}