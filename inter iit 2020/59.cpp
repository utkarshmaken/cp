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
class Node 
{ 
    public: 
    int data;//Node data 
      
    // Next and random reference 
    Node *next, *random; 
  
    Node(int data) 
    { 
        this->data = data; 
        this->next = this->random = NULL; 
    } 
};
void print(Node *start) 
{ 
    Node *ptr = start; 
    while (ptr) 
    { 
        cout << "Data = " << ptr->data << ", Random  = "
             << ptr->random->data << endl; 
        ptr = ptr->next; 
    } 
} 
Node* clone(Node* head){
    unordered_map<Node*,Node*> m;
    Node* temp = head;
    while(temp){
        Node* newNode = new Node(temp->data);
        newNode->next = temp->next;
        m[temp] = newNode;
        temp = temp->next;
    }
    temp = head;
    Node* res = m[temp];
    Node* ans = res;
    while(temp){
        res->random = m[temp->random];
        res = res->next;
        temp = temp->next;
    }
    return ans;
}

int main(){
    Node* start = new Node(1); 
    start->next = new Node(2); 
    start->next->next = new Node(3); 
    start->next->next->next = new Node(4); 
    start->next->next->next->next = new Node(5); 
  
    start->random = start->next->next; 
  
    // 2's random points to 1 
    start->next->random = start; 
  
    // 3's and 4's random points to 5 
    start->next->next->random = 
                    start->next->next->next->next; 
    start->next->next->next->random = 
                    start->next->next->next->next; 
  
    // 5's random points to 2 
    start->next->next->next->next->random = 
                                      start->next; 
  
    cout << "Original list : \n"; 
    print(start); 
  
    cout << "\nCloned list : \n"; 
    Node *cloned_list = clone(start); 
    if(cloned_list == NULL) cout<<"HI";
    print(cloned_list); 
  
    return 0; 
}