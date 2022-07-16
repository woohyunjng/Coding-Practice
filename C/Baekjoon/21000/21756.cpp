#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, k = 1;
    cin >> N;
    while (pow(2, k) <= N) {
        k ++;
    }
    cout << pow(2, k - 1);
}