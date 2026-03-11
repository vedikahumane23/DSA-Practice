#include <bits/stdc++.h>
using namespace std;

class SmallestDivisorFinder {
public:
    int sumByD(vector<int>& arr, int div) {
        int sum = 0;
        for (int num : arr) {
            sum += ceil((double)num / div);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& arr, int limit) {
        if (arr.size() > limit) return -1;

        int low = 1;
        int high = *max_element(arr.begin(), arr.end());
        while (low <= high) {
            int mid = (low + high) / 2;
            if (sumByD(arr, mid) <= limit) {
                high = mid - 1;  
            } else {
                low = mid + 1;  
            }
        }

        return low;
    }
};

int main() {
    SmallestDivisorFinder solver;
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;
    int ans = solver.smallestDivisor(arr, limit);
    cout << "The minimum divisor is: " << ans << "\n";
    return 0;
}
