#include <bits/stdc++.h>
#define int long long

#define MAX 200100
using namespace std;

int cnt[5][5], score[5], A[5], S[5];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, D[5], K, M;
    vector<int> arr;

    cin >> N >> K >> M;

    arr.push_back(1), arr.push_back(2), arr.push_back(3), arr.push_back(4);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 4; j++)
            cin >> A[j];
        for (int j = 1; j <= 4; j++) {
            cin >> S[j];
            cnt[A[j]][j]++, score[A[j]] += S[j];
        }
    }

    for (D[1] = -100; D[1] <= 100; D[1]++) {
        for (D[2] = -100; D[2] <= D[1]; D[2]++) {
            for (D[3] = -100; D[3] <= D[2]; D[3]++) {
                D[4] = -D[1] - D[2] - D[3];
                if (D[4] > D[3] || D[4] < -100 || D[4] > 100)
                    continue;

                A[1] = score[1], A[2] = score[2], A[3] = score[3], A[4] = score[4];
                for (int i = 1; i <= 4; i++)
                    for (int j = 1; j <= 4; j++)
                        A[i] += cnt[i][j] * D[j];

                sort(arr.begin(), arr.end(), [&](int X, int Y) { return A[X] == A[Y] ? X < Y : A[X] > A[Y]; });
                if (arr[M - 1] == K) {
                    cout << D[1] << ' ' << D[2] << ' ' << D[3] << ' ' << D[4] << endl;
                    return 0;
                }
            }
        }
    }

    cout << -1 << '\n';

    return 0;
}