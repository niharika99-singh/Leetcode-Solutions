class Solution {
public:
    
    int solve(vector<string>& arr, string str, int ind){
        unordered_set<char> s(str.begin(), str.end());
        
        if(s.size()!=str.length())
            return 0;
        
        int ret=str.length();
        for(int i=ind; i<arr.size();i++){
            ret=max(ret, solve(arr, str+arr[i], i+1));
        }
        return ret;
    }
    
    int maxLength(vector<string>& arr) {
        int ind=0;
        string str="";
        return solve(arr, str, ind);
    }
};