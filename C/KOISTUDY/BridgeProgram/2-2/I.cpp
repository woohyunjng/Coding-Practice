#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    long long W, H, B;
    cin >> W >> H >> B;
    cout << fixed << setprecision(2) << (double)W * H * B / (8 * 1024 * 1024) << " MB";
}