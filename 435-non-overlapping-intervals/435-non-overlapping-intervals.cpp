class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count=0;
        int left, right;
        left=0; right=1;
        int n=intervals.size();
        
        while(right<n){
            if(intervals[left][1]<=intervals[right][0]){
                left=right;
                right++;
            }
            else if(intervals[left][1]<=intervals[right][1]){
                count++;
                right++;
            }
            else if(intervals[left][1]>intervals[right][1]){
                left=right;
                right++;
                count++;
            }
        }
        return count;
    }
};