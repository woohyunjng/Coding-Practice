#include <bits/stdc++.h>

using namespace std;

int A[4];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int K;

    vector<int> arr;
    arr.push_back(0), arr.push_back(1), arr.push_back(2), arr.push_back(3);

    cin >> K >> A[0] >> A[1] >> A[2] >> A[3];

    while (true) {
        cout << A[0] << ' ' << A[1] << ' ' << A[2] << ' ' << A[3] << '\n';
        sort(arr.begin(), arr.end(), [&](int x, int y) { return A[x] < A[y]; });

        K = A[arr[0]] + A[arr[1]] + A[arr[2]];
        if (K == 0)
            break;
        else if ((K & 1) || A[arr[1]] == 0)
            A[arr[0]] += 2, A[arr[2]]--, A[arr[3]]--;
        else if (A[arr[0]] + A[arr[1]] < A[arr[2]])
            A[arr[0]] += 2, A[arr[1]]--, A[arr[2]]--;
        else
            A[arr[1]]--, A[arr[2]]--, A[arr[3]] += 2;
    }

    return 0;
}