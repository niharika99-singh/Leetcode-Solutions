class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='[' || s[i]=='(' || s[i]=='{')
                st.push(s[i]);
            else{
                
                char ch;
                if(s[i] == ')'){
                    ch = '(';
                }
                else if(s[i] == '}'){
                    ch = '{';
                }
                else if(s[i] == ']'){
                    ch = '[';
                }
                if(st.size()==0)
                    return false;
                else if(ch!=st.top())
                    return false;
                else 
                    st.pop();
            }
        }
        if(st.size()==0)
            return true;
        return false;
    }
};