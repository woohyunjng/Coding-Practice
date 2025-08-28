#include <bits/stdc++.h>
using namespace std;

const int MAX = 200001;

int C[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X = 0, B;
    vector<int> arr[2];
    queue<int> q;

    cin >> N;
    for (int i = 1; i < N; i++)
        cin >> C[i];

    for (int i = 2; i < N; i++) {
        if (C[i] - C[i - 1] == 2)
            arr[0].push_back(i);
        else if (C[i] - C[i - 1] == -2)
            arr[1].push_back(i), q.push(i);
        else
            q.push(i);
    }
    q.push(N);

    cout << 1 << ' ', B = 1;
    for (int i = 2; i <= N; i++) {
        if (X < arr[1].size() && B == arr[1][X])
            B = arr[0][X++];
        else
            B = q.front(), q.pop();
        cout << B << ' ';
    }
    cout << '\n';

    return 0;
}