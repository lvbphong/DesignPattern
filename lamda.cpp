#include <bits/stdc++.h>
using namespace std;

struct {
    void operator()(int x) {
        std::cout << x << "\n";
    }
} something;

void isOddNumber(int x) {
    if (x % 2 == 0) {
        std::cout << "x" << " is even num" << std::endl;
    } else {
        std::cout << "x" << " is odd" << std::endl;
    }
}

int main() {
    int d = 3;
    std::vector<int> v{2, 5, 3, 7, 5};
    std::for_each(v.begin(), v.end(), isOddNumber);
    std::for_each(v.begin(), v.end(), [&d](int x) {
        if (x % d == 0) {
            std::cout << "x" << " is divisible by " << d << std::endl;
        } else {
            std::cout << "x" << " is not divisible by " << d << std::endl;
        }
    });
    return 0;
}