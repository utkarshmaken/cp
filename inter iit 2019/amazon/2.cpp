//INFIX EVALUATION
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

int calc(int a, int b, char c){
    if(c == '+') return a+b;
    if(c == '-') return a-b;
    if(c == '*') return a*b;
    if(c == '/') return a/b;
}
int main(){
    string infix;
    cin>>infix;
    stack<int> operand;
    stack<char> operato;
    int n = infix.size();
    map<char,int> m;
    m['*'] = 2;m['/'] = 2;m['+'] = 1;m['-'] = 1;
    int i = 0;
    while(i < n){
        char ch = infix[i];
        if(ch>='0' && ch<='9')
            operand.push(ch-'0');
        else{
            if(ch == '(')
                operato.push('(');
            else if(ch == ')'){
                while(operato.top()!='('){
                    char c = operato.top();
                    operato.pop();
                    int op2 = operand.top();
                    operand.pop();
                    int op1 = operand.top();
                    operand.pop();
                    int x = calc(op1,op2,c);
                    operand.push(x);
                }
                operato.pop();
            }
            else{
                while(!operato.empty() && m[operato.top()]>=m[ch]){
                    char c = operato.top();
                    operato.pop();
                    int op2 = operand.top();
                    operand.pop();
                    int op1 = operand.top();
                    operand.pop();
                    int x = calc(op1,op2,c);
                    operand.push(x);
                }
                operato.push(ch);
            }
            
        }
        ++i;
    }
    while(!operato.empty()){
        char c = operato.top();
        operato.pop();
        int op2 = operand.top();
        operand.pop();
        int op1 = operand.top();
        operand.pop();
        int x = calc(op1,op2,c);
        operand.push(x);
    }
    cout<<operand.top()<<endl;
}