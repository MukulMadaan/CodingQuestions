#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    int n;
    while(t > 0){
        cin>>n;
        int arr[n];
        int dp[n];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
            dp[i] = 1;
        }
        int ans = 0;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(arr[i] > arr[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans,dp[i]);
        }
        cout<<ans<<endl;
        t--;
    }
	return 0;
}
