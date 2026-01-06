#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

int dis(int X1, int Y1, int X2, int Y2) { return (X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2); }

pr go[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int X0, Y0, X = 0, Y = 0, P = 0, D, ansX = 0, ansY = 0, PX, PY;
    string S;

    cin >> X0 >> Y0 >> S;

    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'S') {
            D = 0;
            while (i + 1 < S.size() && isdigit(S[i + 1]))
                D = D * 10 + (S[i + 1] - '0'), i++;
            PX = X + go[P][0] * D, PY = Y + go[P][1] * D;
            if (PX == X) {
                if (PY < Y0 && Y < Y0) {
                    if (dis(X0, Y0, X, max(Y, PY)) < dis(X0, Y0, ansX, ansY))
                        ansX = X, ansY = max(Y, PY);
                } else if (PY > Y0 && Y > Y0) {
                    if (dis(X0, Y0, X, min(Y, PY)) < dis(X0, Y0, ansX, ansY))
                        ansX = X, ansY = min(Y, PY);
                } else {
                    if (dis(X0, Y0, X, Y0) < dis(X0, Y0, ansX, ansY))
                        ansX = X, ansY = Y0;
                }
            } else {
                if (PX < X0 && X < X0) {
                    if (dis(X0, Y0, max(X, PX), Y) < dis(X0, Y0, ansX, ansY))
                        ansX = max(X, PX), ansY = Y;
                } else if (PX > X0 && X > X0) {
                    if (dis(X0, Y0, min(X, PX), Y) < dis(X0, Y0, ansX, ansY))
                        ansX = min(X, PX), ansY = Y;
                } else {
                    if (dis(X0, Y0, X0, Y) < dis(X0, Y0, ansX, ansY))
                        ansX = X0, ansY = Y;
                }
            }
            X = PX, Y = PY;
        } else
            P = (P + (S[i + 1] - '0')) % 4, i++;

        if ((X0 - X) * (X0 - X) + (Y0 - Y) * (Y0 - Y) < (X0 - ansX) * (X0 - ansX) + (Y0 - ansY) * (Y0 - ansY))
            ansX = X, ansY = Y;
    }

    if (ansX == X0 && ansY == Y0)
        cout << -1 << '\n';
    else
        cout << ansX << ' ' << ansY << '\n';

    return 0;
}