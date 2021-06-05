#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int SubSequence(int arr[],int n){
    int** dp=new int*[n];
    for(int i=0;i<n;i++){
        dp[i]=new int[101];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<101;j++){
            dp[i][j]=0;
        }
    }
    for (int i = 0; i < n; ++i)
		{
			dp[i][arr[i]] = 1;
		}
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                for(int k=1;k<101;k++){
                    if(dp[j][k]>0){
                        int ans=gcd(arr[i],k);
                        dp[i][ans]=(dp[i][ans]+dp[j][k])%mod;
                    }
                }
            }
        }
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        ans=(ans+dp[i][1])%mod;
    }
    return ans%mod;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<SubSequence(arr,n);
    return 0;
}