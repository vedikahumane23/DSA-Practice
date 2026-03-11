class Solution {
public:

    bool ispossible(vector<int>& bloomDay,int day, int m, int k){
        int cnt =0;
        int b= 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                cnt++;
                if(cnt ==k){
                    b++;
                    cnt=0;
                }
            }else {
                cnt =0;
            }
        }
        return b>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total = 1LL*k*m;
        if(total> bloomDay.size()) return -1;

        int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());
        
        int low = mini, high = maxi;
        int result = -1;

        while(low<=high){
            int mid = (low + high)/2;

            if(ispossible(bloomDay, mid , m , k)){
                result = mid;
                high = mid -1;
            }else {
                low = mid + 1;
            }
        }
        return result;
    }
};