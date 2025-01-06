#include <bits/stdc++.h>
#define int long long

#define MAX 200100
using namespace std;

int arr[MAX], def[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    def[N] = arr[N];
    for (int i = N - 1; i >= 1; i--) {
        def[i] = max(def[i + 1], arr[i]);
        if (arr[i + 1] != def[i + 1])
            def[i] = 2 * def[i + 1] - arr[i + 1];
    }

    cout << def[1] - arr[1];

    return 0;
}