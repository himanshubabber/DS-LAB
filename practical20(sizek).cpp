#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> findFirstNegativeInWindow(const vector<int>& arr, int k) {
    vector<int> result;
    int n = arr.size();
    deque<int> dq;

    int i;
    for (i = 0; i < k; i++) {
        if (arr[i] < 0) {
            dq.push_back(i);
        }
    }

    for (; i < n; i++) {
        if (!dq.empty()) {
            result.push_back(arr[dq.front()]);
        } else {
            result.push_back(0); 
        }


        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        if (arr[i] < 0) {
            dq.push_back(i);
        }
    }

    if (!dq.empty()) {
        result.push_back(arr[dq.front()]);
    } else {
        result.push_back(0); 
    }

    return result;
}

int main() {
    vector<int> arr = {2, -1, -3, 4, -2, 1, 5, -3};
    int k = 3;

    vector<int> result = findFirstNegativeInWindow(arr, k);

    cout << "First negative integers in each window of size " << k << ":" << endl;
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
