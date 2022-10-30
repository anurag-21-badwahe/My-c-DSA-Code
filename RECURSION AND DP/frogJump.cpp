#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

// recursive solution
// TIME COMPLEXITY = 0(N*K);
// S.C(0[N]);
/*
int minEnergy(int h[],int ind,int k)
{
    if(ind == 0)return 0;

    int minStep = INT_MAX;

    for(int j = 1; j <=k; j++)
    {
        if(ind-j >= 0){
        int jump = minEnergy(h,ind-j,k) + abs(h[ind]-h[ind-j]);
        minStep = min(minStep,jump);
        }
    }
    return minStep;

}*/

// MEM0IZATION
// TIME COMPLEXITY = 0(N*K);
// S.C(0[N]);
/*

int minEnergy(int h[],int ind,int k,vector<int>dp)
{
    if(ind == 0)return 0;

    int minStep = INT_MAX;

    if(dp[ind] != 0)return dp[ind];

    for(int j = 1; j <=k; j++)
    {
        if(ind-j >= 0){
        int jump = minEnergy(h,ind-j,k,dp) + abs(h[ind] - h[ind-j]);
        minStep = min(minStep,jump);
        }
    }
    return dp[ind] = minStep;

}
*/

// int main(){
// 	int n, k;
//     cout << "ENTER THE SIZE OF THE ARRAY" << endl;
//      cin>>n;
//      cout << "ENTER THE VALUE OF K" << endl;
//      cin>>k;
//      cout <<"ENTER THE VALUE OF ARRAY"<<endl;
//      int h[n];
// 	for(int i=0; i<n; i++){
// 		cin>>h[i];
// 	}
//     vector<int>dp(n,0);

//    cout <<"Min Energy required to reach the target is ->" << minEnergy(h,n-1,k,dp) << endl;
// }

int main()
{
    int n, k;
    cout << "ENTER THE SIZE OF THE ARRAY" << endl;
    cin >> n;
    cout << "ENTER THE VALUE OF K" << endl;
    cin >> k;
    cout << "ENTER THE VALUE OF ARRAY" << endl;
    int h[n];
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    int dp[n];
    dp[0]=0;
	for(int i=1; i<n; i++){
		int mini=INT_MAX;
		for(int j=1; j<=k; j++){
			if(i-j>=0 and (dp[i-j]+abs(h[i]-h[i-j]))<mini) mini=dp[i-j]+abs(h[i]-h[i-j]);
		}
		dp[i]=mini;
	}
	cout<<dp[n-1];


    //we can space optimize it from o(n)->o(k);but in wirst case it will be o(n)
}
