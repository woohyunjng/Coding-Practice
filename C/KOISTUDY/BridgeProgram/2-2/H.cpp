#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    long long H, B, C, S;
    cin >> H >> B >> C >> S;
    cout << fixed << setprecision(1) << (double)H * B * C * S / (8 * 1024 * 1024) << " MB";
}