#include <bits/stdc++.h>
#define int long long

#define MAX 100
using namespace std;

int S[MAX][MAX], T[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    bool flag;
    string s;

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> s;
        for (int j = 1; j <= N; j++)
            S[i][j] = s[j - 1] == '#' ? 1 : 0;
    }

    for (int i = 1; i <= M; i++) {
        cin >> s;
        for (int j = 1; j <= M; j++)
            T[i][j] = s[j - 1] == '#' ? 1 : 0;
    }

    for (int i = 1; i <= N - M + 1; i++) {
        for (int j = 1; j <= N - M + 1; j++) {
            flag = true;
            for (int k = 1; k <= M; k++)
                for (int l = 1; l <= M; l++)
                    if (S[i + k - 1][j + l - 1] != T[k][l]) {
                        flag = false;
                        break;
                    }
            if (flag) {
                cout << i << ' ' << j << '\n';
                return 0;
            }
        }
    }

    return 0;
}