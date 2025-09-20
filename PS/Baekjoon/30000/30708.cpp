#include <bits/stdc++.h>
using namespace std;

const int MAX = 200003;

int A[MAX], V[MAX], C[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K = -1, L = 1;
    bool ans_chk = true;

    vector<int> arr[2], val;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i], arr[A[i] % 2].push_back(A[i]);

    sort(arr[0].begin(), arr[0].end()), sort(arr[1].begin(), arr[1].end());
    if (arr[0].size() < arr[1].size())
        swap(arr[0], arr[1]);

    for (int i : arr[0])
        V[K += 2] = i;
    for (int i : arr[1])
        C[i]++;

    for (int i = 2; i + 1 <= K; i += 2) {
        if (V[i - 1] < V[i + 1])
            V[i] = V[i - 1] + 1;
        else if (C[V[i - 1] - 1] > 0)
            V[i] = V[i - 1] - 1;
        else
            V[i] = V[i - 1] + 1;
        ans_chk &= --C[V[i]] >= 0;
    }

    for (int i : arr[1])
        while (C[i] > 0)
            val.push_back(i), C[i]--;

    ans_chk &= val.size() <= 2;
    if (val.size() == 1) {
        if (abs(val[0] - V[1]) == 1)
            V[0] = val[0], L = 0;
        else if (abs(val[0] - V[K]) == 1)
            V[++K] = val[0];
        else
            ans_chk = false;
    } else if (val.size() == 2) {
        V[0] = val[0], V[++K] = val[1], L = 0;
        ans_chk &= abs(val[0] - V[1]) == 1 && abs(val[1] - V[K - 1]) == 1;
    }

    if (!ans_chk)
        cout << -1 << '\n';
    else {
        for (int i = L; i <= K; i++)
            cout << V[i] << ' ';
        cout << '\n';
    }

    return 0;
}