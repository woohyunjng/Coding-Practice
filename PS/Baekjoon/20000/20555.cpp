#include <bits/stdc++.h>
#define int long long

#define MAX 10
using namespace std;

string S[7], dp[MAX][MAX][MAX][MAX][MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A[7], X[7], Y[7];
    bool flag;
    string K;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> S[i];
    for (int i = N; i < 6; i++)
        S[i] = "";

    for (int i = 0; i < 6; i++)
        A[i] = S[i].size();

    for (X[0] = 0; X[0] <= A[0]; X[0]++)
        for (X[1] = 0; X[1] <= A[1]; X[1]++)
            for (X[2] = 0; X[2] <= A[2]; X[2]++)
                for (X[3] = 0; X[3] <= A[3]; X[3]++)
                    for (X[4] = 0; X[4] <= A[4]; X[4]++)
                        for (X[5] = 0; X[5] <= A[5]; X[5]++) {
                            flag = true;
                            for (int i = 0; i < 6; i++)
                                flag = flag && X[i] == 0;
                            if (!flag && dp[X[0]][X[1]][X[2]][X[3]][X[4]][X[5]] == "")
                                continue;

                            for (char c = 'A'; c < 'E'; c++) {
                                flag = false;
                                for (int i = 0; i < 6; i++) {
                                    Y[i] = X[i];
                                    if (X[i] < A[i] && S[i][X[i]] == c)
                                        Y[i]++, flag = true;
                                }

                                K = dp[X[0]][X[1]][X[2]][X[3]][X[4]][X[5]] + c;
                                if (flag && dp[Y[0]][Y[1]][Y[2]][Y[3]][Y[4]][Y[5]] == "" || dp[Y[0]][Y[1]][Y[2]][Y[3]][Y[4]][Y[5]].size() > K.size() || (dp[Y[0]][Y[1]][Y[2]][Y[3]][Y[4]][Y[5]].size() == K.size() && dp[Y[0]][Y[1]][Y[2]][Y[3]][Y[4]][Y[5]] > K))
                                    dp[Y[0]][Y[1]][Y[2]][Y[3]][Y[4]][Y[5]] = K;
                            }
                        }

    cout << dp[A[0]][A[1]][A[2]][A[3]][A[4]][A[5]] << '\n';

    return 0;
}