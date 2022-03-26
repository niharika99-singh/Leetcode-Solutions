// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	string fractionToDecimal(int numerator, int denominator) {
	    // Code here
	    string res="";
	    int rem=numerator%denominator;
	    unordered_map<int, int> m;
	    
	    while(rem!=0 && m.find(rem)==m.end()){
	        m[rem]=res.length();
	        
	        rem*=10;
	        
	        res+=to_string(rem/denominator);
	        rem%=denominator;
	    }
	    string ans="";
	    if(rem==0){
	        if(res!="")
	        ans+=to_string(numerator/denominator)+"."+res;
	        else
	        ans+=to_string(numerator/denominator);
	    }
	    else{
	        ans+=to_string(numerator/denominator)+"."+res.substr(0, m[rem])+"("+res.substr(m[rem])+")";
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int numerator, denominator;
		cin >> numerator >> denominator;
		Solution ob;
		string ans = ob.fractionToDecimal(numerator, denominator);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends