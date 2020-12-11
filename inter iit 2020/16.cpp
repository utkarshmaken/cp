//LARGEST SUBARRAY WHICH HAS EQUAL NUMBER OF 0's and 1's
#include <bits/stdc++.h>
#define f(i,a,b) for(int i = a;i<b;i++)
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    f(i,0,n) cin>>a[i];
    f(i,0,n) if(a[i] == 0) a[i] = -1;
    unordered_map<int,int> m;
    m[-1] = 0;
    int sum = 0,ans = 0;
    f(i,0,n){
        sum+=a[i];
        if(m.find(sum)!=m.end())
            ans = max(ans,i - m[sum]);
        else
            m[sum] = i;
    }
    cout<<ans<<endl;

}