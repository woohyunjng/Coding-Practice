#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long int N, x, y, z;
    int K, Q;

    cin >> N >> K >> Q;

    while (Q--) {
        cin >> x >> y;
        if (K == 1) {
            cout << max(x, y) - min(x, y) << '\n';
            continue;
        }

        int depth_x = log((K - 1) * (x - 1) + 1) / log(K), depth_y = log((K - 1) * (y - 1) + 1) / log(K);
        if (depth_x < depth_y) {
            swap(x, y);
            swap(depth_x, depth_y);
        }

        int res = depth_x - depth_y;
        while (depth_x != depth_y) {
            depth_x --;
            x = (x + K - 2) / K;
        }

        while (x != y) {
            res += 2;
            x = (x + K - 2) / K;
            y = (y + K - 2) / K;
        }

        cout << res << '\n';
    }
}
