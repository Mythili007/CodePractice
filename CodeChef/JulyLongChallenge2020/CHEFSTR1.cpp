class Solution {
public:
    
    int maximum(vector<int>& nums){
        int mxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mxi)
                mxi = nums[i];
        }
        return mxi;
    }
    int thirdMax(vector<int>& nums) {
        int count=0; int val =0; int diff = 0;
        int minm = INT_MAX;
        int mx = maximum(nums);
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] != mx){
                diff = mx-nums[i];
                if(diff < minm){
                    minm = diff;
                    count++;
                }
            }
            
            if(count == 2){
                val = mx-minm;
                break;
            }
        }
        return val;
    }
};