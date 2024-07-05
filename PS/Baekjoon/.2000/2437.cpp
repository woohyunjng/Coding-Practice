#include <bits/stdc++.h>
#define int long long
#define MAX 100100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K = 0;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    sort(arr + 1, arr + N + 1);
    for (int i = 1; i <= N; i++) {
        if (K + 1 < arr[i])
            break;
        K += arr[i];
    }

    cout << K + 1 << '\n';

    return 0;
}