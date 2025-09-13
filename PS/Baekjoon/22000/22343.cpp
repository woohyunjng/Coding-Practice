#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 4'000'000;

int V[2][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, M[2], D, X, ans;
    string A, B;
    bool flag;

    cin >> T;
    while (T--) {
        cin >> A >> B, M[0] = M[1] = 0;

        D = 0, flag = false;
        for (char i : A) {
            if (i == '(')
                D++, flag = true;
            else if (i == ')') {
                D--;
                if (flag) {
                    V[0][D]++, X = D, M[0] = max(M[0], D);
                    while (V[0][X] > 1)
                        V[0][X] = 0, V[0][X + 1]++, M[0] = max(M[0], ++X);
                }
                flag = false;
            }
        }

        D = 0, flag = false;
        for (char i : B) {
            if (i == '(')
                D++, flag = true;
            else if (i == ')') {
                D--;
                if (flag) {
                    V[1][D]++, X = D, M[1] = max(M[1], D);
                    while (V[1][X] > 1)
                        V[1][X] = 0, V[1][X + 1]++, M[1] = max(M[1], X + 1), X++;
                }
                flag = false;
            }
        }

        if (M[0] != M[1])
            ans = M[0] < M[1] ? 0 : 1;
        else {
            ans = -1;
            for (int i = M[0]; i >= 0; i--) {
                if (V[0][i] != V[1][i]) {
                    ans = V[0][i] < V[1][i] ? 0 : 1;
                    break;
                }
            }
        }

        if (ans == 0)
            cout << '<' << '\n';
        else if (ans == 1)
            cout << '>' << '\n';
        else
            cout << '=' << '\n';

        fill(V[0], V[0] + M[0] + 1, 0), fill(V[1], V[1] + M[1] + 1, 0);
    }

    return 0;
}