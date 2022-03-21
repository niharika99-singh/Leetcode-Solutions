class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        int maxi=nums[0];
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxi=max(maxi, sum);
            sum=max(sum, 0);
        }
        
        return maxi;
    }
};