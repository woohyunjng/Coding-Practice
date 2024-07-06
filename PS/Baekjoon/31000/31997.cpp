#include <bits/stdc++.h>
#define int long long
#define MAX 200100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int sm[MAX], arr[MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, T, A, B;
    cin >> N >> M >> T;

    for (int i = 1; i <= N; i++)
        cin >> arr[i][0] >> arr[i][1];

    while (M--) {
        cin >> A >> B;
        if (arr[A][0] > arr[B][0])
            swap(A, B);
        if (arr[A][1] <= arr[B][0])
            continue;
        else {
            sm[arr[B][0] + 1]++;
            sm[min(arr[A][1], arr[B][1]) + 1]--;
        }
    }

    for (int i = 1; i <= T; i++) {
        sm[i] += sm[i - 1];
        cout << sm[i] << "\n";
    }

    return 0;
}