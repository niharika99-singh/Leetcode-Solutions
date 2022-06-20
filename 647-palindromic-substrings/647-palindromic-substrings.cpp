class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        int ans=n;
        for(int i=0;i<n-1;i++){
            int l=i-1;
            int r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                ans++;
                l--;
                r++;
            }
        }
        for(int i=0;i<n-1;i++){
            int l=i-1;
            int r=i+2;
            if(s[i]==s[i+1]){
                ans++;
                while(l>=0 && r<n && s[l]==s[r]){
                    ans++;
                    l--;
                    r++;
                }
            }
        }
        return ans;
    }
};