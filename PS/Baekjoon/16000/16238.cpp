#import <bits/stdc++.h>
using namespace std;
int N, K, A[1001], i;
main() {
    for (; cin >> (N ? A[++i] : N);)
        ;
    sort(A, A + N);
    while (i)
        K += max(i - N + A[--i], 0);
    cout << K;
}