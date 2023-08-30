#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, A, B;
    cin >> T;

    while (T--) {
        cin >> A >> B;
        int depth_A = log2(A), depth_B = log2(B);
        if (depth_A < depth_B) {
            swap(A, B);
            swap(depth_A, depth_B);
        }

        while (depth_A != depth_B) {
            A /= 2;
            depth_A --;
        }

        while (A != B) {
            A /= 2;
            B /= 2;
        }

        cout << A * 10 << '\n';
    }
}
