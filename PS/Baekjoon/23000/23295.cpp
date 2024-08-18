#include <bits/stdc++.h>
#define int long long

#define MAX 100100
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

    int N, T, K, S, E, res = 0, start = 0, cur = 0;
    cin >> N >> T;

    while (N--) {
        cin >> K;
        while (K--) {
            cin >> S >> E;
            arr[S]++;
            arr[E]--;
        }
    }

    for (int i = 1; i <= 100000; i++)
        arr[i] += arr[i - 1];

    for (int i = 0; i < T; i++)
        cur += arr[i];
    res = cur;

    for (int i = 1; i + T - 1 <= 100000; i++) {
        cur += arr[i + T - 1] - arr[i - 1];
        if (res < cur) {
            res = cur;
            start = i;
        }
    }

    cout << start << ' ' << start + T;

    return 0;
}