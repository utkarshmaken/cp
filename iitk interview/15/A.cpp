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
#define mp make_pair
#define pb push_back
#define sz(x) (int) (x).size()
#define all(x) x.begin(),x.end()
using namespace std;
const int mod = 1000000007;

int shortest_unsorted(vector<int> &a){
     int n = a.size();
     

}

int main()
{
	int n;
	scanf("%d", &n);

	vector<int> a(n);
	for(auto &ele : a)
		scanf("%d", &ele);

	int res = shortest_unsorted(a);
	printf("%d\n", res);

	return 0;
}