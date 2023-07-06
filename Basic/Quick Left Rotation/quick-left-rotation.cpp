//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	void reverse(int arr[],int start, int n){
	    int i=start, j = n-1; 
	    while(i<=j) {
	        swap(arr[i], arr[j]);
	        i++;
	        j--;
	    }
	}
	void leftRotate(int arr[], int k, int n) 
	{ 
	   k = k%n;
	    reverse(arr,0,k);
	    reverse(arr,k,n);
	    reverse(arr,0,n);
	    
	    
	   
	} 
		 

};

//{ Driver Code Starts.

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin >> n;
	    int k;
	    cin >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	        // um[a[i]]++;
	    }


       

        Solution ob;
        ob.leftRotate(a,k,n);
        
        for (int i = 0; i < n; i++) 
        	cout << a[i] << " "; 

	    cout << "\n";
	     
    }
    return 0;
}



// } Driver Code Ends