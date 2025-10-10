#include <iostream>
using namespace std;

int josephus(int n, int m) {
    int pos = 0; 
    for (int i = 2; i <= n; ++i) {
        pos = (pos + m) % i;
    }
    return pos;
}

int main() {
    int k;
    cin >> k;
    int total = 2 * k; 

    
    for (int m = 1;; ++m) {
        bool valid = true;
        for (int i = 1; i <= k; ++i) {
            int pos = josephus(total - (i - 1), m); 
            if (pos < k) {
                valid = false;
                break;
            }
        }
        if (valid) {
            cout << m << endl;
            break;
        }
    }

    return 0;
}

