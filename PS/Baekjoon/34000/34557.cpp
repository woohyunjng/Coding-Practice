#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 101;

pr go[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int A[MAX][MAX], C[MAX], F[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, T, B = -1, R;

    string S;

    cin >> N >> M;
    C['W' - 'A'] = 0, C['A' - 'A'] = 1, C['S' - 'A'] = 2, C['D' - 'A'] = 3;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
            if (A[i][j] == 2)
                A[i][j] = 0, X = i, Y = j;
        }

    for (int i = 0; i < 4; i++) {
        cin >> S;
        if (S == "Down")
            F[i] = 0;
        else if (S == "Stay")
            F[i] = 1;
        else if (S == "Up")
            F[i] = 2;
    }

    function<bool(int, int)> OOB = [&](int X, int Y) {
        return X < 1 || X > N || Y < 1 || Y > N || A[X][Y] == 1;
    };

    cin >> S;
    for (char i : S) {
        R = C[i - 'A'];
        if (R == B) {
            if (F[B] == 1 && !OOB(X + go[R][0], Y + go[R][1]))
                X += go[R][0], Y += go[R][1];
        } else if (R != B) {
            if (R < B) {
                if (F[R] == 0 && !OOB(X + go[R][0], Y + go[R][1]))
                    X += go[R][0], Y += go[R][1];
                if (B != -1 && F[B] == 2 && !OOB(X + go[B][0], Y + go[B][1]))
                    X += go[B][0], Y += go[B][1];
            } else {
                if (B != -1 && F[B] == 2 && !OOB(X + go[B][0], Y + go[B][1]))
                    X += go[B][0], Y += go[B][1];
                if (F[R] == 0 && !OOB(X + go[R][0], Y + go[R][1]))
                    X += go[R][0], Y += go[R][1];
            }
        }
        B = R;
    }

    cout << X << ' ' << Y << '\n';

    return 0;
}