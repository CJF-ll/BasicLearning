#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


bool isPalindrome(const string &s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}


string reverseNumber(const string &s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    return rev;
}


string addInBaseN(const string &a, const string &b, int base) {
    string result;
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int digitA = (i >= 0) ? (isdigit(a[i]) ? a[i] - '0' : a[i] - 'A' + 10) : 0;
        int digitB = (j >= 0) ? (isdigit(b[j]) ? b[j] - '0' : b[j] - 'A' + 10) : 0;

        int sum = digitA + digitB + carry;
        carry = sum / base;
        int remainder = sum % base;

        char c = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A');
        result.push_back(c);

        i--;
        j--;
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int N;
    string M;
    cin >> N >> M;

    int steps = 0;
    string current = M;

    while (steps <= 30) {
        if (isPalindrome(current)) {
            cout << "STEP=" << steps << endl;
            return 0;
        }
        string reversed = reverseNumber(current);
        current = addInBaseN(current, reversed, N);
        steps++;
    }

    cout << "Impossible!" << endl;
    return 0;
}

