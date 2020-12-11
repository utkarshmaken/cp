//https://leetcode.com/discuss/interview-question/356935/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> pizza(n),topping(m);
    for(int i = 0;i<n;i++) cin>>pizza[i];
    for(int i = 0;i<m;i++) cin>>topping[i];
    int x;cin>>x;
    sort(pizza.begin(),pizza.end());
    for(int i = 0;i<m;i++)
        for(int j = i+1;j<m;j++)
            topping.push_back(topping[i] + topping[j]);
    sort(topping.begin(),topping.end());
    int total,mini = INT_MAX;
    for(int i = 0;i<n;i++){
        if(abs(pizza[i]-x) < mini){
            mini = abs(pizza[i]-x);
            total = pizza[i];
        }

        if(pizza[i] < x){
            int diff = x-pizza[i];
            auto it1 = upper_bound(topping.begin(),topping.end(),diff);
            if(it1!=topping.end()){
                int temp = pizza[i] + *it1;
                if(abs(temp-x) < mini){
                    mini = abs(temp-x);
                    total = temp;
                }
            }
            if(it1!=topping.begin()){
                --it1;
                int temp = pizza[i] + *it1;
                if(abs(temp-x) < mini){
                    mini = abs(temp-x);
                    total = temp;
                }
            }
        }
    }
    cout<<total<<endl;
   
}
