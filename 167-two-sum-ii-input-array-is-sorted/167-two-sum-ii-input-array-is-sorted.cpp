class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j=numbers.size()-1;
        vector<int> v;
        while(i<j){
            int x=numbers[i]+numbers[j];
            if(target==x) {
                v.push_back(i+1);
                v.push_back(j+1);
                return v;
            }
            else if(target<x) j--;
            else i++;
        }
        return v;
    }
};