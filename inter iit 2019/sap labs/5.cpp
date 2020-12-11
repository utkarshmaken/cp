//COUNTING PAIRS
#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int dp[2500][1000][4];
int n,x,y;
string s;
int len;
//vector<int> path;

int find(int pos,int i,int state){
    if(i==len && pos == y) return 1;
    if(i == len) return 0;
    if(dp[pos][i][state]!=-1) return dp[pos][i][state];
    if(state == 3) return dp[pos][i][state] = find(pos,i+1,state)%mod;

    int ans = 0;
    if(s[i] == 'l' && state!=1 && pos-1>=0)
        ans = (ans + find(pos-1,i+1,state))%mod;
    
    if(s[i] == 'r' && state!=2 && pos+1<=n)
        ans = (ans + find(pos+1,i+1,state))%mod;
    
    int nstate;
    if(state == 0)
        nstate = (s[i]=='l'?1:2);
    else 
        nstate = (state==1?(s[i]=='l'?1:3):(s[i]=='l'?3:2));

    ans = (ans + find(pos,i+1,nstate))%mod;
    return dp[pos][i][state] = ans;
}

int main(){
    cin>>s;
    cin>>n>>x>>y;
    len = s.size();
    memset(dp,-1,sizeof(dp));
    int ans = find(x,0,0);
    cout<<ans<<endl;
}