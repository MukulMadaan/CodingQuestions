// Returns the maximum value that  
// can be put in a knapsack of capacity W 

int knapSack(int W, int wt[], int val[], int n) 
{ 
    vector<vector<int>> DP(n + 1 ,vector<int> (W + 1));
    for (int i = 0; i <= n; i++){
	    for (int w = 0; w <= W; w++) {
                if (i == 0 || w == 0) DP[i][w] = 0;
	    }
    }
    for (int i = 1; i <= n; i++){
	    for (int w = 0; w <= W; w++) {
            if (wt[i - 1] <= w)
                DP[i][w] = max(val[i - 1] + DP[i - 1][w - wt[i - 1]],  DP[i - 1][w]);
            else
                DP[i][w] = DP[i - 1][w];
	    }
    }
	return DP[n][W];
}
