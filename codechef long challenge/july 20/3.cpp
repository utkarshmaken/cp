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
using namespace std;
const int mod = 1000000007;

void find( vector<vector<char>> &board,vector<vector<bool>> &visited, int &k, int r, int c){
    if(r<0 || r>=8 || c<0 || c>=8 || visited[r][c])
        return;
    visited[r][c] = true;
    if(k==0){
        board[r][c] = 'X';
        return;
    }
    k--;
    rep(i,-1,1){
        rep(j,-1,1){
            if(i==0 && j==0)
                continue;
            find(board,visited,k,r+i,c+j);
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int k,temp;
        cin>>k;
        temp = k;
        vector<vector<char>> board(8,vector<char>(8,'.'));
        vector<vector<bool>> visited(8,vector<bool>(8,false));
        board[0][0] = 'O';
        find(board,visited,temp,0,0);
        f(i,0,8){
            f(j,0,8)
                cout<<board[i][j];
            cout<<endl;
        }
    }
}