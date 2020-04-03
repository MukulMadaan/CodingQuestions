bool findPartition(int a[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
    }
    if(sum % 2 != 0) return false;
    sum /= 2;
    bool DP[n + 1][sum + 1];
    for(int i = 0; i <= n; i++) DP[i][0] = true;
    for(int i = 1; i <= sum; i++) DP[0][i] = false;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            if(a[i - 1] <= j) DP[i][j] = a[i] + DP[i - 1][j - a[i - 1]] || DP[i - 1][j];
            if(j < a[i - 1]) DP[i][j] = DP[i - 1][j];
        }
    }
    return DP[n][sum];
}
