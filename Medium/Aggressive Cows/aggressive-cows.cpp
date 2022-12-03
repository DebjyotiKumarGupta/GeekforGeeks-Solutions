//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool placed(vector<int> &v,int n,int k,int mid){
        int y = v[0],nk=1;
        for(int i=1;i<n;i++){
            if(v[i]-y>=mid){
            nk++;
            y=v[i];
            }
        }
        if(nk>=k) return true;
        return false;
        }

    int solve(int n, int k, vector<int> &stalls) {
       sort(stalls.begin(),stalls.end());
       int j= stalls[n-1]-stalls[0],i=1;
       while(i<=j){
           int mid = (i+j)/2;
           if(placed(stalls,n,k,mid))
               i = mid+1;
           else
               j = mid-1;
       }
       return j;
       
       
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends