#include <iostream>
#include <vector>
using namespace std;

void combination_util(vector<int> &arr, int start, int n, int r) {
    int j = (start + r - 1);
    while(j < n) {
        for(int i = start; i < (start + r - 1); i++) {
            cout << arr[i];
        }
        cout << arr[j] << endl;
        j++;
    }
}

void combination(int n, int r) {
    vector<int> arr;
    for(int i = 1; i <= n; i++) 
        arr.push_back(i);
    for(int i = 0; i <= n-r; i++) {
        combination_util(arr, i, n, r);
    }
}

int main() {
    int n = 4, r = 2;
    combination(n, r);
}

/*
{1, 2, 3, 4, 5}
r = 3

123   i = 2
124   i = 3
125   i = 4 -> end

234   i = 3
235   i = 4 -> end

345   i = 4 -> end

*/