#include <iostream>

using namespace std;

int getLengthOfSubArray(int arr[], int n, int k) 
{
    int left = 0, high = 1;
    int len = arr[0] == k ? 1 : 0;
    int sum = arr[0] + arr[1];

    while(left <= high && high < n) {
        if (sum == k) {
            len = max(len, high - left + 1);
        }
        if (sum <= k || left == high) {
            high++;
            sum += arr[high];
        } else {
            sum -= arr[left];
            left++;
        }
    }
    return len;
}

int main() {
    int arr[] = {1, 6, -1, 5, 9, 2};
    cout << getLengthOfSubArray(arr, 6, 2);
}