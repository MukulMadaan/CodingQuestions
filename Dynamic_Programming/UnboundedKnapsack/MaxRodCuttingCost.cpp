int maxRodCost(int L, int ln[], int pf[], int n) 
{ 
    vector<vector<int>> DP(n + 1 ,vector<int> (W + 1));
    for (int i = 0; i <= n; i++){
	    for (int l = 0; l <= L; l++) {
                if (i == 0 || l == 0) DP[i][l] = 0;
	    }
    }
    for (int i = 1; i <= n; i++){
	    for (int l = 0; l <= L; l++) {
            if (ln[i - 1] <= l)
                DP[i][l] = max(pf[i - 1] + DP[i][l - ln[i - 1]],  DP[i - 1][l]);
            else
                DP[i][l] = DP[i - 1][l];
	    }
    }
	return DP[n][L];
}
