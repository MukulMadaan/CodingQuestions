//Top Down
int UBknapSack(int W, int wt[], int val[], int n) 
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
                DP[i][w] = max(val[i - 1] + DP[i][w - wt[i - 1]],  DP[i - 1][w]);
            else
                DP[i][w] = DP[i - 1][w];
	    }
    }
	return DP[n][W];
}


//Bottom Up
vector<vector<int>> DP(1001 , vector<int> (1001, -1));
int UBknapSack(int W, int wt[], int val[], int n) 
{ 
   if(W == 0 || n == 0) return 0;
   if(DP[n][W] != -1) return DP[n][W]; 
   if (wt[n - 1] > W)  DP[n][W] =  UBknapSack(W, wt, val, n - 1);  
   else DP[n][W] = max(val[n - 1] + UBknapSack(W - wt[n - 1], wt, val, n), UBknapSack(W, wt, val, n - 1));  
}
