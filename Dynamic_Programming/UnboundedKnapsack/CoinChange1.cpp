long getWays(int sum, vector<long> c) {
    long n = c.size(); 
    long DP[n + 1][sum + 1]; 
    
    for (int i = 0; i <= n; i++) 
      DP[i][0] = 1;
   
    for (int i = 1; i <= sum; i++) 
      DP[0][i] = 0;   
      
    for (int i = 1; i <= n; i++) { 
       for (int j = 1; j <= sum; j++) { 
          if(j < c[i - 1]) DP[i][j] = DP[i - 1][j]; 
          if (j >= c[i - 1]) DP[i][j] = DP[i-1][j] + DP[i][j - c[i - 1]]; 
       } 
     } 
     
    return DP[n][sum];
}
