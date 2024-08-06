#include <bits/stdc++.h>
#define int long long

#define MAX 1000100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX], two_power[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, res = 0, cur = 0, mn = 0, mx = 0, X, Y, Z;
    string S;

    cin >> N;
    cin >> M;
    cin >> S;

    for (int i = 1; i <= N; i++)
        arr[i] = (S[i - 1] == 'M' ? 0 : 1);

    two_power[0] = 1;
    for (int i = 1; i <= N; i++)
        two_power[i] = (two_power[i - 1] * 2) % M;

    for (int i = 1; i <= N; i++) {
        if (arr[i]) {
            X = cur - 1, Y = mx, Z = min(mn, cur - 1);
            if (Y - Z <= 2) {
                if (Y - Z == 1)
                    res = (res + two_power[(N + 1 - i) / 2] + two_power[(N - i) / 2] - 1 + M) % M;
                else {
                    if (X == Z + 1)
                        res = (res + two_power[(N + 1 - i) / 2]) % M;
                    else
                        res = (res + two_power[(N - i) / 2]) % M;
                }
            }
            cur++;
        } else
            cur--;

        mx = max(mx, cur);
        mn = min(mn, cur);
    }

    cout << (res + 1) % M;

    return 0;
}