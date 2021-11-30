#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> &nums, int n) {
    int minIdx;
    for (int i = 0; i < n - 1; ++i) {
        minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (nums[j] < nums[minIdx]) {
                minIdx = j;
            }
        }
        swap(nums[minIdx], nums[i]);
    }
}

void bubble_sort(vector<int> &nums, int n) {
    bool swapped;
    for (int i = 1; i < n; ++i) {
        swapped = false;
        for (int j = 1; j < n - i + 1; ++j) {
            if (nums[j - 1] > nums[j]) {
                swap(nums[j - 1], nums[j]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void insertion_sort(vector<int> &nums, int n) {
    int tmp;
    for (int i = 1; i < n; ++i) {
        tmp = nums[i];
        for (int j = i - 1; j >= 0 && arr[j] > tmp; --j) {
            nums[j + 1] = nums[j];
        }
        nums[j + 1] = tmp; 
    }
}


void merge(vector<int> &nums, int lo, int mid, int hi) {
    int n = hi - lo + 1;
    vector<int> b(n);
    int l = lo, r = mid + 1, bIdx = 0;
    while (l <= mid && r <= hi) {
        b[bIdx++] = (a[l] < a[r]) ? a[l++] : a[r++];
    }
    while (l <= mid) {
        b[bIdx++] = a[l++];
    }
    while (r <= hi) {
        b[bIdx++] = a[r++];
    }
    for (int i = 0; i < n; ++i) {
        nums[lo + i] = b[i];
    }
}

void merge_sort(vector<int> &nums, int lo, int hi) {
    if (lo < hi) { // base case: low >= high (0 or 1 item)
        int mid = lo + (hi - lo) / 2;
        merge_sort(nums, lo, mid); // divide into two halves then recursively sort them 
        merge_sort(nums, mid + 1, hi);
        merge(nums, lo, mid, hi); // conquer: the merge routine
    }
}

int partition(vector<int> &nums, int i, int j) {
    int p = nums[i]; // p is the pivot
    int m = i; // S1 and S2 are initially empty
    for (int k = i + 1; k <= j; ++k) { // explore the unknown region
        if (nums[k] < p) {
            ++m;
            swap(arr[k], arr[m]);
        } // do nothing in case 1: a[k] >= p
    }
}

void quick_sort(vector<int> &nums, int lo, int hi) {
    if (lo < hi) {
        int pivot = partition(nums, lo, hi);
        // a[lo..hi] ~> a[lo..pivot–1], pivot, a[pivot+1..hi]
        quick_sort(nums, lo, pivot); // recursively sort left subarray
        // a[pivot] = pivot is already sorted after partition
        quick_sort(nums, pivot + 1, hi); // then sort right subarray
    }
}

int main() {
    vector<int> nums = {1,3,5,7,2,6,4,8,9,2,8,7,6,0,3,5,9,4,1,0}; 
    sort(nums.begin(), nums.end());
    quick_sort(nums, 0, nums.size() - 1);
    merge_sort(nums, 0, nums.size() - 1);
    insertion_sort(nums, nums.size());
    bubble_sort(nums, nums.size());
    selection_sort(nums, nums.size());
    return 0;
}