#include <iostream>
using namespace std;

int main() {
    int t;
	cin>>t;
	for(int i = 0; i < t; i++) {
	    int n;
	    cin>>n;
	    int dp[n + 1];
	    dp[0] = 0; dp[1] = 1; dp[2] = 2;
	    for(int x = 3; x < n + 1; x++){
	        if(x % 2 != 0){
	            dp[x] = dp[x - 1] + 1;
	        } else{
	            dp[x] = dp[x/2] + 1;
	        }
	    }
	    cout<<dp[n]<<endl;
	}
	return 0;
}
