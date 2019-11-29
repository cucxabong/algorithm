#include <iostream>
#include <stack>

using namespace std;

string to_shifting_formula(unsigned long long n, unsigned long long m) {
    stack<unsigned short> shift_offsets;
    unsigned short k = 0;

    do {
        if (((m >> k) & 1) == 1) {
            shift_offsets.push(k);
        }
        k++;

    } while( (m >> k) > 0);

    string s = "";
    while (!shift_offsets.empty()) {
        printf("(%llu<<%d)", n, shift_offsets.top());
        shift_offsets.pop();
        if (!shift_offsets.empty()) {
            printf(" + ");
        }
    }

    return s;
}

int main() {
    unsigned long long test_cases, n, m;
    cin >> test_cases;
    while (test_cases > 0) {
        cin >> n >> m;
        string s = to_shifting_formula(n, m);
        cout << s << endl;
        test_cases--;
    }
    return 0;
}