class Solution {
public:
    void solve(int o, int c, string op, vector<string> &ans){
        if(o==0 && c==0){
            ans.push_back(op);
            return;
        }
        
        if(o!=0){
            string op1=op;
            op1+='(';
            solve(o-1, c, op1, ans);
        }
        
        if(o<c){
            string op2=op;
            op2+=')';
            solve(o, c-1, op2, ans);
        }
        
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        int o, c;
        o=c=n;
        string op="";
        vector<string> ans;
        solve(o, c, op, ans);
        return ans;
    }
};