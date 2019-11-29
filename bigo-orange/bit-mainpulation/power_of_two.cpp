#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool is_power_of_two(unsigned int n) {
    bool bit_set = false;
    for (int i = 0; i < 8*sizeof(n); i++) {
        if (((n >> i) & 1) == 1) {
            if (!bit_set) {
                bit_set = true;
            } else {
                return false;
            }
        }

        if ((n >> i) == 0) {
            break;
        }
    }

    return bit_set;
}

vector<unsigned int> input() {
    int n;
    vector<unsigned int> arr;
    cin >> n;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    return arr;
}

bool find_subset_is_power_of_two(vector<unsigned int> arr) {
    unsigned long long opsize = pow(2,arr.size());

    for (int counter = 1; counter < opsize; counter++) {
        unsigned int AND_result = 0xffffffff;
        for (int i = 0; i < arr.size(); i++) {
            if (counter & (1<<i)) {
                AND_result &= arr[i];
            }
        }

        if (is_power_of_two(AND_result)) {
            return true;
        }
    }

    return false;
}

int main() {
    unsigned int cases;
    cout << sizeof(unsigned int) << endl;
    cin >> cases;
    while (cases) {
        vector<unsigned int> arr = input();
        if (find_subset_is_power_of_two(arr)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        cases--;
    }
    
    return 0;
}