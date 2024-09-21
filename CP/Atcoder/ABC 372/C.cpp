#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, X, cur = 0;
    string S;
    char C;
    cin >> N >> Q >> S;

    for (int i = 1; i <= N; i++) {
        if (i >= 3 && S[i - 1] == 'C' && S[i - 2] == 'B' && S[i - 3] == 'A')
            arr[i] = 1;
        else
            arr[i] = 0;
        cur += arr[i];
    }

    while (Q--) {
        cin >> X >> C;

        cur -= arr[X] + arr[X + 1] + arr[X + 2];
        S[X - 1] = C;

        if (X >= 3 && S[X - 1] == 'C' && S[X - 2] == 'B' && S[X - 3] == 'A')
            arr[X] = 1;
        else
            arr[X] = 0;

        if (X >= 2 && S[X] == 'C' && S[X - 1] == 'B' && S[X - 2] == 'A')
            arr[X + 1] = 1;
        else
            arr[X + 1] = 0;

        if (X >= 1 && S[X + 1] == 'C' && S[X] == 'B' && S[X - 1] == 'A')
            arr[X + 2] = 1;
        else
            arr[X + 2] = 0;

        cur += arr[X] + arr[X + 1] + arr[X + 2];
        cout << cur << '\n';
    }

    return 0;
}