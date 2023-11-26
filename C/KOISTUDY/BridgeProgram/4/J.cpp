#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N, M, A, B, C, D;
    cin >> N >> M;
    cin >> A >> C;
    cin >> B >> D;

    int all = N * M / 2;
    C -= A;
    D -= B;

    cout << max(0, max(C * N * M, D * all + max(0, C * (N * M - all * 2))));
}