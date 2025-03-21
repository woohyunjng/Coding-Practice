#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

int A[MAX][MAX], ans[2];

void dnc(int X, int Y, int S) {
    int cnt = 0;
    for (int i = X; i < X + S; i++)
        for (int j = Y; j < Y + S; j++)
            cnt += A[i][j];
    if (cnt == S * S) {
        ans[1]++;
        return;
    } else if (cnt == 0) {
        ans[0]++;
        return;
    }

    dnc(X, Y, S / 2), dnc(X + S / 2, Y + S / 2, S / 2);
    dnc(X + S / 2, Y, S / 2), dnc(X, Y + S / 2, S / 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    dnc(0, 0, N);

    cout << ans[0] << '\n';
    cout << ans[1] << '\n';

    return 0;
}