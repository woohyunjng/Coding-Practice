#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

int A[MAX][MAX], ans[2];

string dnc(int X, int Y, int S) {
    int cnt = 0;
    for (int i = X; i < X + S; i++)
        for (int j = Y; j < Y + S; j++)
            cnt += A[i][j];

    if (cnt == S * S)
        return "1";
    else if (cnt == 0)
        return "0";

    string res;

    res += '(';
    res += dnc(X, Y, S / 2);
    res += dnc(X, Y + S / 2, S / 2);
    res += dnc(X + S / 2, Y, S / 2);
    res += dnc(X + S / 2, Y + S / 2, S / 2);
    res += ')';

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    string S;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S;
        for (int j = 0; j < N; j++)
            A[i][j] = S[j] - '0';
    }

    cout << dnc(0, 0, N) << '\n';

    return 0;
}