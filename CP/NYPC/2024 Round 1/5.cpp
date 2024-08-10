#include <bits/stdc++.h>
#define int long long

#define MAX 1001000
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

    int N, K, zero = 0, one = 0;
    string S;

    vector<int> res;

    cin >> N >> K;
    cin >> S;

    for (int i = 1; i <= N; i++)
        arr[i] = S[i - 1] - '0';

    for (int i = 1; i <= N; i++) {
        if (arr[i] == 1 && one < K)
            one++;
        else if (arr[i] == 0 && zero < K)
            zero++;
        else
            res.push_back(arr[i]);
    }

    if (one < K)
        for (int i = 1; i <= N - 2 * K; i++)
            cout << 0;
    else if (zero < K)
        for (int i = 1; i <= N - 2 * K; i++)
            cout << 1;
    else
        for (int i : res)
            cout << i;

    return 0;
}