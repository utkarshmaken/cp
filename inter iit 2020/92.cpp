#include<bits/stdc++.h>
using namespace std;

void find(int pre[], int &i, int n, int mini, int maxi){
    if(i == n) return;
    if(pre[i] < mini || pre[i] > maxi)
        return;
    int val = pre[i];
    ++i;
    find(pre,i,n,mini,val);
    find(pre,i,n,val,maxi);
    cout<<val<<endl;
}

void findPostOrder(int pre[], int n){
    int mini = INT_MIN,maxi = INT_MAX;
    int i = 0;
    find(pre,i,n,mini,maxi);
}

int main() 
{ 
    int pre[] = { 40, 30, 35, 80, 100 }; 
    findPostOrder(pre, 5); 
    return 0; 
} 