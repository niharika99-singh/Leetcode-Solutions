class Solution {
public:
    
    bool solve(vector<int>& nums, vector<int>& s, vector<bool>& vis, int sum, int k, int n, int curr, int last){
        if(s[curr]==sum){
            if(curr==k-2) return true;
            
            return solve(nums, s, vis, sum, k, n, curr+1, n-1);
        }
        
        for(int i=last; i>=0; i--){
            if(vis[i]) continue;
            
            int temp=s[curr]+nums[i];
            if(temp<=sum){
                vis[i]=true;
                s[curr]+=nums[i];
                bool flag=solve(nums, s, vis, sum, k, n, curr, i-1);
                vis[i]=false;
                s[curr]-=nums[i];
                if(flag) return true;
            }
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int n=nums.size();
        if(k==1) return true;
        if(n<k) return false;
        
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%k!=0) return false;
        sum/=k;
        vector<int> s(k, 0);
        vector<bool> vis(n, false);
        
        s[0]=nums[n-1];
        vis[n-1]=true;
        
        return solve(nums, s, vis, sum, k, n, 0, n-1);
    }
};