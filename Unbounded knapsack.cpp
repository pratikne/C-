/*
Below is formula for 0/1 KP
if(wt[i-1] <= j)
    t[i][j] = max( t[i-1][j] , val[i-1] + t[i-1][j-wt[i-1]]);
else
    t[i][j] = t[i-1][j];


Below is formula for Unbounded KP
if(wt[i-1] <= j)
    t[i][j] = max( t[i-1][j] , val[i-1] + t[i][j-wt[i-1]]);
else
    t[i][j] = t[i-1][j];

1) Coin change problem - Max ways

if(wt[i-1] <= j)
    t[i][j] = t[i-1][j] + t[i][j-wt[i-1]]);
else
    t[i][j] = t[i-1][j];

rows = array
col = sum

2) Coin change problem - Min coins

if(wt[i-1] <= j)
    t[i][j] = min( t[i-1][j] , 1 + t[i][j-wt[i-1]]);
else
    t[i][j] = t[i-1][j];

init = 1st row = INT_MAX - 1
       1st col = 0

       2nd row = if(j % arr[0] == 0)
                    t[i][j] = j / arr[0];
                 else
                    t[i][j] = INT_MAX - 1;
*/