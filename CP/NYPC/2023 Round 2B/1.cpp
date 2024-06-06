#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, a = 0, b = 0, res = 0;
    cin >> N;

    string S;
    cin >> S;

    for (int i = 0 ; i < N * 2 ; i ++) {
        if (S[i] == '(') {
            a ++;
        } else {
            b += 1;
            if (a > 0) {
                a -= 1;
                b -= 1;
                res += 1;
            }
        }
    }

    cout << res + 2 * a;
}
