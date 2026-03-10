#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;

    unordered_map<int,int> mp;

    for(int i=0;i<nums.size();i++){
        int complement = target - nums[i];

        if(mp.count(complement)){
            cout << mp[complement] << " " << i;
            return 0;
        }

        mp[nums[i]] = i;
    }

    return 0;
}