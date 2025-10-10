#include <iostream>
using namespace std;

void decimalToM(int x, int m) {
    if (x == 0) return;
    decimalToM(x / m, m);
    char c = (x % m) < 10 ? (x % m) + '0' : (x % m) - 10 + 'A';
    cout << c;
}

int main() {
    int X, M;
    cin >> X >> M;
    if (X == 0) {
        cout << "0";
    } else {
        decimalToM(X, M);
    }
    cout << endl;
    return 0;
}

