#include <iostream>
#include <vector>

using namespace std;

vector<unsigned int> input() {
    unsigned int n;
    cin >> n;
    vector<unsigned int> arr;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    return arr;
}

//unsigned int find_min(unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
unsigned int find_min(unsigned int a, unsigned int b) {
    //unsigned int min1 = a < b ? a:b;
    //unsigned int min2 = c < d ? c:d;

    //return  min1 < min2 ? min1:min2;
    return a < b ? a:b;
}

unsigned int do_xor_all_contiguous(vector<unsigned int> arr) {
    vector<unsigned int> no_appear;
    unsigned int n = arr.size();
    unsigned int result = 0;
    no_appear.assign(n, 0);
    for (int k = 1; k <= n; k++) {
        int i, j;
        
        for (i = 0, j = n - 1 - i; i < j; i++, j--) {
            //no_appear[i] += find_min(i + 1, k,n - k + 1, n - i);
            no_appear[i] += find_min(i + 1, k);
            no_appear[j] += find_min(k, n - j);
        }

        if (i == j) {
            no_appear[i] += find_min(i + 1, k);
        }
        for (i = 0; i < n; i++) {
            cout << i+1 << ": " << no_appear[i] << endl;
        } 
        cout << " ============ " << endl;
    }

    for (int i = 0; i < n; i++) {
        if (no_appear[i] % 2 == 1) {
            result ^= arr[i];
        } 
    }

    return result;
}

int main() {
    unsigned int t;
    cin >> t;

    while (t > 0) {
        vector<unsigned int> arr = input();
        cout << do_xor_all_contiguous(arr) << endl;
        t--;
    }

    return 0;
}