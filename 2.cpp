#include <iostream>
#include <cmath>
using namespace std;

// Деление по модулю 3 для int
int div3m(int a, int b) {
    return (a + b) % 3;
}

// Деление по модулю 3 для long
long div3m(long a, long b) {
    return (a + b) % 3;
}

// Деление по модулю 3 для float
int div3m(float a, float b) {
    int res = static_cast<int>(round(a + b));
    return res % 3;
}

// Деление по модулю 3 для double
int div3m(double a, double b) {
    int res = static_cast<int>(round(a + b));
    return res % 3;
}

int main() {
    int ai = 7, bi = 5;
    long al = 123456789L, bl = 987654321L;
    float af = 4.7f, bf = 2.3f;
    double ad = 10.5, bd = 8.4;

    cout << "int: " << div3m(ai, bi) << endl;
    cout << "long: " << div3m(al, bl) << endl;
    cout << "float: " << div3m(af, bf) << endl;
    cout << "double: " << div3m(ad, bd) << endl;

    return 0;
}
