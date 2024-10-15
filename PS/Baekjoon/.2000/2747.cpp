#include <bits/stdc++.h>
#define int long long

#define MAX 50
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int fib[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    fib[0] = 0, fib[1] = 1;

    cin >> N;
    for (int i = 2; i <= N; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    cout << fib[N];

    return 0;
}