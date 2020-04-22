//Bottom Up

int t[1001][1001];
memset(t, -1, sizeof(t));
int lcs( char *X, char *Y, int m, int n )  
{  
    if (m == 0 || n == 0)  
        return 0;
    if(t[m][n] != -1)
      return t[m][n];
    if (X[m-1] == Y[n-1])  
        return 1 + lcs(X, Y, m-1, n-1);  
    else
        return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));  
}  

//Top Down
int lcs( char *X, char *Y, int m, int n )  
{  
    int L[m + 1][n + 1];  
    int i, j;  
    
    for (i = 0; i <= m; i++)  
    {  
        for (j = 0; j <= n; j++)  
        {  
        if (i == 0 || j == 0)  
            L[i][j] = 0;  
      
        else if (X[i - 1] == Y[j - 1])  
            L[i][j] = L[i - 1][j - 1] + 1;  
      
        else
            L[i][j] = max(L[i - 1][j], L[i][j - 1]);  
        }  
    }  
    return L[m][n];  
}  
