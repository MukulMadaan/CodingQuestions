int countSubsetDiff(int set[], int n, int diff) 
{
    int sum = 0;
    
    for (int i = 0; i < n; i++) sum += set[i];
    
    if(sum < diff || (diff + sum) % 2 != 0) return 0;
    
    sum = (diff + sum)/2;
   
    int DP[n + 1][sum + 1]; 
    
    for (int i = 0; i <= n; i++) 
      DP[i][0] = 1;
   
    for (int i = 1; i <= sum; i++) 
      DP[0][i] = 0;   
      
    for (int i = 1; i <= n; i++) { 
       for (int j = 1; j <= sum; j++) { 
          if(j < set[i - 1]) DP[i][j] = DP[i - 1][j]; 
          if (j >= set[i - 1]) DP[i][j] = DP[i-1][j] + DP[i - 1][j - set[i - 1]]; 
       } 
     } 
     
    return DP[n][sum];
}
