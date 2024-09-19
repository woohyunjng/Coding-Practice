#include <bits/stdc++.h>
#define int long long

#define MAX 3000100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int grundy[MAX], fib[MAX];
bool checked[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0, K;

    cin >> N;

    fib[0] = 0, fib[1] = 1, fib[2] = 2;
    for (int i = 3; i < MAX; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    for (int i = 1; i <= 3000000; i++) {
        K = 1;
        while (fib[K] <= i) {
            checked[grundy[i - fib[K]]] = true;
            K++;
        }

        K = 0;
        while (checked[K])
            K++;
        grundy[i] = K;

        K = 1;
        while (fib[K] <= i) {
            checked[grundy[i - fib[K]]] = false;
            K++;
        }
    }

    for (int i = 1; i <= N; i++) {
        cin >> K;
        res ^= grundy[K];
    }

    cout << (res == 0 ? "cubelover" : "koosaga");

    return 0;
}