class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        int sum = 0;
    
        for (int i = 0; i < n; i++) sum += nums[i];
        
        if(sum < S || (S + sum) % 2 != 0) return 0;
        
        sum = (S + sum)/2;
        
        int DP[n + 1][sum + 1];
        for(int i = 0; i <= n; i++) DP[i][0] = 1;
        for(int i = 1; i <= sum; i++) DP[0][i] = 0;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= sum; j++){
                if(nums[i - 1] > j) DP[i][j] = DP[i - 1][j];
                if(nums[i - 1] <= j) DP[i][j] = DP[i - 1][j] + DP[i - 1][j - nums[i - 1]];
            }
        }
        return DP[n][sum];
    }
};
