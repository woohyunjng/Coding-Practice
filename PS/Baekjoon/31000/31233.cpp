#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

int arr[200100];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, mx = -1;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    for (int i = 1; i <= N - 1; i++)
        mx = max(mx, min(arr[i], arr[i + 1]));
    for (int i = 1; i <= N - 2; i++)
        mx = max(mx, (arr[i] + arr[i + 1] + arr[i + 2]) - min(arr[i], min(arr[i + 1], arr[i + 2])) - max(arr[i], max(arr[i + 1], arr[i + 2])));

    cout << mx;
    return 0;
}