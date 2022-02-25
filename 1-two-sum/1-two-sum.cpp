class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> v;
        unordered_map<int, int> m;
        for(int i=0; i<n;i++){
            //if(target-nums[i]>=0)
            m[target-nums[i]]=i;
        }
        for(int i=0; i<n;i++){
            if(m.find(nums[i])!=m.end()){
                if(m[nums[i]]!=i){
                v.push_back(i);
                v.push_back(m[nums[i]]);
                break;
                }
            }
        }
        
        return v;
    }
};