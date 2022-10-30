#include<iostream>
#include<vector>
using namespace std;
int  fibo(int n,vector<int>&dp)
{

  if(n <= 1)
  {
    return n;
  }

  if(dp[n] != -1)return dp[n];

  dp[n] = fibo(n-1,dp) + fibo(n-2,dp);
  return dp[n];
}


int main()
{
    int n;
    cout << "ENTER THE TERM YOU WANT IN FIBO SERIES:-";
    cin >> n;
    vector<int> dp(n+1,-1);
    cout << fibo(n,dp) << " ";
    //T.C = O(N);
    //S.C = O(N);
}