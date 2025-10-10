#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

 
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= N; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }

   
    for (int even = 4; even <= N; even += 2) {
        for (int prime1 = 2; prime1 <= even / 2; ++prime1) {
            if (isPrime[prime1]) {
                int prime2 = even - prime1;
                if (isPrime[prime2]) {
                    cout << even << "=" << prime1 << "+" << prime2 << endl;
                    break; 
                }
            }
        }
    }

    return 0;
}

