#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

// O(n^2)
int main_n2() {
  int v[] = {-5, 6, 7, 1, 4, -8, 16};
  int s = 7;
  int globalMax, currentMax;
  int globalLeft, globalRight, currentLeft;
  globalMax = v[0];
  globalLeft = globalRight = 0;

  for (int j = 0; j < s; j++) {
    currentMax = v[j];
    currentLeft = j;
    for (int i = j + 1; i < s; i++) {
      currentMax += v[i];
      if (currentMax > globalMax) {
        globalMax = currentMax;
        globalLeft = currentLeft;
        globalRight = i;
      }
    }
  }
  cout << globalLeft << " - " << globalRight << " : ";
  cout << globalMax << endl;

  return 0;
}

int maxSumCrossArray(int A[], int low, int mid, int hight) {
  int sum, leftSum, rightSum;
  sum = leftSum = A[mid];
  for (int i = mid - 1; i >= low; i--) {
    sum += A[i];
    if (sum > leftSum)
      leftSum = sum;
  }

  sum = rightSum = A[mid+1];
  for (int i = mid + 2; i <= hight; i++) {
    sum += A[i];
    if (sum > rightSum)
      rightSum = sum;
  }

  return leftSum + rightSum;
}

// O(nlogn)
int maxSumSubArray(int A[], int low, int hight) {
  if (low == hight)
    return A[low];

  int mid = low + (hight - low)/2;
  int res = max(maxSumSubArray(A, low, mid), maxSumSubArray(A, mid+1, hight));
  res = max(res, maxSumCrossArray(A, low, mid, hight));
  return res;
}

// O(n)
pair<int, pair<int, int> > kadane(int *A, int sz) {
  if (sz <= 0)
    return make_pair(INT_MIN, make_pair(-1, -1));

  int current_max, global_max, bg, end, current_bg;
  current_max = global_max = A[0];
  bg = end = current_bg = 0;
  for (int i = 1; i < sz; i++) {
    if (current_max + A[i] < A[i]) {
      current_max = A[i];
      current_bg = i;
    } else {
      current_max += A[i];
    }

    if (current_max > global_max) {
      global_max = current_max;
      bg = current_bg;
      end = i;
    }
  }

  return make_pair(global_max, make_pair(bg, end));
}

int main() {
  //int v[] = {4, -3, -2, 2, 3, 1, -2, -3, 4, 2, -6, -3, -1, 3, 1, 2};
  int v[] = {-2, -3, 4, -1, -2, 1};
  int sz = 6;
  pair<int, pair<int, int> > res = kadane(v, sz);
  cout << "Sum: " << res.first << endl;
  cout << res.second.first << " - " << res.second.second << endl;
  return 0;
}
