#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, mx = -1;
    cin >> N;

    int arr[N];
    for (int i = 0 ; i < N ; i ++) {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }

    int p[mx + 1] = {};
    bool n[mx + 1] = {};
    for (int i = 2 ; i <= ceil(sqrt((double) mx)) ; i ++) {
        if (n[i])
            continue;

        p[i] = i;
        for (int j = i * 2 ; j <= mx ; j += i) {
            n[j] = true;
            if (!p[j])
                p[j] = i;
        }
    }

    for (int i = 0 ; i < N ; i ++) {
        while (arr[i] > 1) {
            if (!p[arr[i]])
                p[arr[i]] = arr[i];
            cout << p[arr[i]] << " ";
            arr[i] = (int) (arr[i] / p[arr[i]]);
        }
        cout << endl;
    }

}
