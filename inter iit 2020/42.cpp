//VOLATILE ROY
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
 
#define f(i,a,b) for(int i = a;i<b;i++)
#define rep(i,a,b) for(int i = a;i<=b;i++)
#define fd(i,a,b) for(int i = a;i>b;i--)
#define repd(i,a,b) for(int i = a;i>=b;i--)
 
#define pii pair<int,int>
#define pll pair<ll,ll>
 
#define fi first
#define se second
#define pb push_back
#define sz(x) (int) (x).size()
#define all(x) x.begin(),x.end()
#define endl '\n'
using namespace std;
const int mod = 1000000007;
const int maxn = 2e5;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

int main(){
    int grid[3][3];
    f(i,0,3) f(j,0,3) cin>>grid[i][j];
    vector<int> prime(20);
    prime[2] = 1;prime[3] = 1;prime[5] = 1;
    prime[7] = 1;prime[11] = 1;prime[13] = 1;
    prime[17] = 1;

    string final = "123456789";
    map<string,int> m;
    m[final] = 0;
    queue<string> q;
    q.push(final);
    while(!q.empty()){
        string s = q.front();
        q.pop();
        for(int i = 0;i<9;i++){
            int r = i/3,c = i%3;
            for(int d = 0;d<4;++d){
                int nr = r+dx[d],nc = c+dy[d];
                if(nr<0 || nc<0 || nr>=3 || nc>=c)
                    continue;
                int sum = s[i]-'0' + s[nr*3 + nc] - '0';
                if(prime[sum]){
                    string temp = s;
                    swap(temp[i],temp[nr*3 + nc]);
                    if(m.find(temp) == m.end()){
                        m[temp] = m[s] + 1;
                        q.push(temp);
                    }
                }
            }
        }
    }
    string t = "";
    f(i,0,3) f(j,0,3) t+=('0'+grid[i][j]);
    if(m.find(t)!=m.end()) cout<<m[t]<<endl;
    else cout<<-1<<endl;
}