// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    
    bool solve(int a[], int subset[], bool taken[], int s, int k, int n, int curr, int last){
        if(subset[curr]==s){
            if(curr==k-2)
            return true;
            
            return solve(a, subset, taken, s, k, n, curr+1, n-1);
        }
        
        for(int i=last;i>=0;i--){
            if(taken[i]==true)
            continue;
            
            int temp=subset[curr]+a[i];
            
            if(temp<=s){
                taken[i]=true;
                subset[curr]+=a[i];
                bool nxt=solve(a, subset, taken, s, k, n, curr, i-1);
                taken[i]=false;
                subset[curr]-=a[i];
                if(nxt) return true;
            }
        }
        return false;
    }
    
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
         if(k==1) return true;
         if(n<k) return false;
         
         int sum=0;
         for(int i=0;i<n;i++) sum+=a[i];
         
         if(sum%k!=0) return false;
         
         int s=sum/k;
         int subset[k];
         bool taken[n];
         
         for(int i=0;i<k;i++) subset[i]=0;
         for(int i=0;i<n;i++) taken[i]=false;
         
         subset[0]=a[n-1];
         taken[n-1]=true;
         
         return solve(a, subset, taken, s, k, n, 0, n-1);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends