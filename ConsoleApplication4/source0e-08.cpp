
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;

int main() {
    int n, i, j, k, num;
    std::cin >> num;
    for (int _ = 0; _ < num; ++_) {
        std::cin >> n >> i >> j;
        k = (1 << i) & n;
        k += (~n) & (1 << j);
        for (int l = i + 1; l < j; ++l) {
            k += 1 << l;
        }
        cout << std::setbase(16) << k << endl;
    }
    return 0;
}