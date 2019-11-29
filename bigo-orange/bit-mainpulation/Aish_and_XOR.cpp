#include <iostream>
#include <vector>

using namespace std;

vector<bool> input(vector<unsigned int> &unset_count) {
    vector<bool> array;
    bool tmp;
    int N;
    bool holder;
    cin >> N;
    unset_count.assign(N, 0);
    array.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        array[i] = tmp;
        if (i == 0) {
            unset_count[i] += (!array[i]);
        } else {
            unset_count[i] = unset_count[i-1] + (!array[i]);
        }
    }

    /*
    while (N > 0) {
        cin >> holder;
        array.push_back(holder);
        N--;
    }
*/
    return array;
}

/*
vector<unsigned int> pre_calc_unset_count(vector<bool> arr) {
    vector<unsigned int> output;
    output.assign(arr.size(), 0);
    output[0] += (!arr[0]);
    for (int i = 1; i < arr.size(); i++) {
        output[i] = output[i-1] + (!arr[i]);
    }

    return output;
}
*/
void query(vector<bool> array, vector<unsigned int> unset_count,  unsigned int left, unsigned int right, bool &xor_value, unsigned int &zero_count) {
    zero_count = unset_count[right-1] - unset_count[left-1] + (!(array[left-1] & array[right-1]));
    
    xor_value = (left - right + 1 - zero_count)%2;
}

int main() {
    unsigned int Q, L, R, zero_count;
    bool xor_value;
    //vector<unsigned int> unset_count = pre_calc_unset_count(array);
    vector<unsigned int> unset_count;
    vector<bool> array = input(unset_count);
    cin >> Q;
    while (Q > 0) {
        cin >> L >> R;
        query(array,unset_count, L, R, xor_value, zero_count);
        cout << xor_value << " " << zero_count << endl;
        zero_count = 0;
        Q--;
    }     
    return 0;
}