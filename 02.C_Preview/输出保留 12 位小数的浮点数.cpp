#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double num;
    cout << fixed << setprecision(12) << (cin >> num, num) << endl;
    return 0;
}

