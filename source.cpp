#include <iostream>
#include <vector>

int main() {
    int n, l, k;
    std::cin >> n >> l >> k;
    std::vector<int> A(n);
    for (int i = 0; i < n; i++)std::cin >> A.at(i);
    int left = -1, right = A.at(n - 1) + 1;
    int center;
    while (right - left > 1) {
        center = left + (right - left) / 2;
        int cut = 0, count = 0;
        for (int i = 0; i < n; i++) {
            if (A.at(i) - cut > center) {
                cut = A.at(i);
                count++;
            }
        }

        if ((l - cut > center && count >= k) || count > k)left = center;
        else right = center;
    }
    std::cout << right;
}