#include <bits/stdc++.h>
#define int long long

#define MAX 2010
using namespace std;

int A[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++)
            cin >> A[i][j];

    return 0;
}