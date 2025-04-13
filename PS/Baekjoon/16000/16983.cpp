#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 200001;

int A[MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 0, X, Y;
    vector<pr> arr;

    cin >> N;
    for (int i = 1; i <= N * 2; i++) {
        cin >> X >> Y;
        if (1 <= X && X <= N && 1 <= Y && Y <= 2)
            A[X][Y - 1]++;
        else if (1 <= X && X <= N)
            A[X][Y > 2]++, ans += abs(Y - (Y > 2 ? 2 : 1));
        else if (1 <= Y && Y <= 2)
            A[X > N ? N : 1][Y - 1]++, ans += abs(X - (X > N ? N : 1));
        else
            A[X > N ? N : 1][Y > 2]++, ans += abs(X - (X > N ? N : 1)) + abs(Y - (Y > 2 ? 2 : 1));
    }

    for (int i = 1; i <= N; i++) {
        A[i][0]--, A[i][1]--;
        if (A[i][0] * A[i][1] < 0) {
            X = min(abs(A[i][0]), abs(A[i][1])), ans += X;
            if (A[i][0] < 0)
                A[i][0] += X, A[i][1] -= X;
            else
                A[i][0] -= X, A[i][1] += X;
        }

        ans += abs(A[i][0]) + abs(A[i][1]);
        A[i + 1][0] += A[i][0], A[i + 1][1] += A[i][1];
    }

    cout << ans << '\n';

    return 0;
}