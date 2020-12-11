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
const int maxn = 1e5;
class Node { 
public:
    int data; 
    Node* next; 
};
Node* find(Node *a, Node *b){
    if(a == NULL)
        return b;
    if(b == NULL)
        return a;

    Node* head = NULL;
    Node* tail = NULL;
    while(a!=NULL && b!=NULL){
        if(a->data <= b->data){
            if(head == NULL){
                head = a;
                tail = a;
            }
            else{
                tail->next = a;
                tail = tail->next;
            }
            a = a->next;
        }
        else{
            if(head == NULL){
                head = b;
                tail = b;
            }
            else{
                tail->next = b;
                tail = tail->next;
            }
            b = b->next;
        }
    }
    if(!a) tail->next = b;
    else tail->next = a;
    return head;
    
}
Node* push(Node* head_ref, int new_data){ 
    Node* new_node = new Node();
    new_node->data = new_data; 
    new_node->next = head_ref; 
    head_ref  = new_node;
    return head_ref;
} 
int main(){
    Node* res = NULL; 
    Node* a = NULL; 
    Node* b = NULL; 

    a = push(a, 15); 
    a = push(a, 10); 
    a = push(a, 5); 
 
    b = push(b, 20); 
    b = push(b, 3); 
    b = push(b, 2); 
    res = find(a,b);
    while(res){
        cout<<res->data<<" ";
        res = res->next;
    }
    return 0; 
}