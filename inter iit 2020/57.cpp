unordered_map<string,vector<string>> songsAndGenre(unordered_map<string,vector<string>>& users, unordered_map<string,vector<string>>& genres){
    unordered_map<string,string> songToGenre;
    unordered_map<string,unordered_map<string,int>> userToGenre;
    unordered_map<string,vector<string>> result;
    unordered_map<string,int> max;
    for(auto genre:genres)
    {
        for(auto song: genre.second)
        {
            songToGenre[song] = genre.first;
        }
    }
    
    for(auto user:users)
    {
        for(auto item:user.second)
        {
            userToGenre[user.first][songToGenre[item]]++;
            auto tempMax = userToGenre.at(user.first).at(songToGenre[item]);
            max[user.first] = std::max(tempMax,max[user.first]);
        }
    }
    
    for(auto user:userToGenre)
    {
        for(auto genre:user.second)
        {
            if(genre.second==max.at(user.first))
            {
                result[user.first].push_back(genre.first);
            }
        }
    }
    
    return result;
}

int main() {
    unordered_map<string,vector<string>> users;
    users["David"] = {"song1", "song2", "song3", "song4", "song8"};
    users["Emma"] = {"song5", "song6", "song7"};
    
    unordered_map<string,vector<string>> songs;
    songs["Rock"] = {"song1", "song3"};
    songs["Dubstep"] = {"song7"};
    songs["Techno"] = {"song2", "song4"};
    songs["Pop"] = {"song5", "song6"};
    songs["Jazz"] = {"song8", "song9"};

    auto result = songsAndGenre(users,songs);
    for(auto x: result)
    {
        cout<<x.first<<" : ";
        for(auto song:x.second)
        {
            cout<<song<<" ";
        }
        cout<<endl;
    }
    
    users.clear();
    songs.clear();
    
    users["David"] = {"song1", "song2"};
    users["Emma"] = {"song3", "song4"};
    
    result = songsAndGenre(users,songs);
    for(auto x: result)
    {
        cout<<x.first<<" : ";
        for(auto song:x.second)
        {
            cout<<song<<" ";
        }
        cout<<endl;
    }
    
}
/////////////////////////////////////


////////////////////////////////////

//////////////////////////////////////////
int search(int mat[4][4], int n, int x) 
{ 
    if (n == 0) 
        return -1; 
    
    int smallest = mat[0][0], largest = mat[n - 1][n - 1]; 
    if (x < smallest || x > largest) 
        return -1; 
    
    // set indexes for top right element 
    int i = 0, j = n - 1;  
    while (i < n && j >= 0)  
    { 
        if (mat[i][j] == x)  
        { 
            cout << "n Found at "
                 << i << ", " << j; 
            return 1; 
        } 
        if (mat[i][j] > x) 
            j--; 
        
        // Check if mat[i][j] < x 
        else 
            i++; 
    } 
  
    cout << "n Element not found"; 
    return 0; 
} 
/////////////////////////////////////////
bool areIdentical(node * root1, node *root2)  
{  
    /* base cases */
    if (root1 == NULL && root2 == NULL)  
        return true;  
  
    if (root1 == NULL || root2 == NULL)  
        return false;  
  
    /* Check if the data of both roots is  
    same and data of left and right  
    subtrees are also same */
    return (root1->data == root2->data &&  
            areIdentical(root1->left, root2->left) &&  
            areIdentical(root1->right, root2->right) );  
}  
bool isSubtree(node *T, node *S)  
{  
    /* base cases */
    if (S == NULL)  
        return true;  
  
    if (T == NULL)  
        return false;  
  
    /* Check the tree with root as current node */
    if (areIdentical(T, S))  
        return true;  
  
    /* If the tree with root as current  
    node doesn't match then try left  
    and right subtrees one by one */
    return isSubtree(T->left, S) ||  
        isSubtree(T->right, S);  
}  
////////////////////////////////////
#include <cstring>
#include <iostream>
using namespace std;
#define MAX 100
 
// Structure of a tree node
struct Node {
    char key;
    struct Node *left, *right;
};
 
// A utility function to create a new BST node
Node* newNode(char item)
{
    Node* temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// A utility function to store inorder traversal of tree rooted
// with root in an array arr[]. Note that i is passed as reference
void storeInorder(Node* root, char arr[], int& i)
{
    if (root == NULL) {
        arr[i++] = '$';
        return;
    }
    storeInorder(root->left, arr, i);
    arr[i++] = root->key;
    storeInorder(root->right, arr, i);
}
 
// A utility function to store preorder traversal of tree rooted
// with root in an array arr[]. Note that i is passed as reference
void storePreOrder(Node* root, char arr[], int& i)
{
    if (root == NULL) {
        arr[i++] = '$';
        return;
    }
    arr[i++] = root->key;
    storePreOrder(root->left, arr, i);
    storePreOrder(root->right, arr, i);
}
 
/* This function returns true if S is a subtree of T, otherwise false */
bool isSubtree(Node* T, Node* S)
{
    /* base cases */
    if (S == NULL)
        return true;
    if (T == NULL)
        return false;
 
    // Store Inorder traversals of T and S in inT[0..m-1]
    // and inS[0..n-1] respectively
    int m = 0, n = 0;
    char inT[MAX], inS[MAX];
    storeInorder(T, inT, m);
    storeInorder(S, inS, n);
    inT[m] = '\0', inS[n] = '\0';
 
    // If inS[] is not a substring of inT[], return false
    if (strstr(inT, inS) == NULL)
        return false;
 
    // Store Preorder traversals of T and S in preT[0..m-1]
    // and preS[0..n-1] respectively
    m = 0, n = 0;
    char preT[MAX], preS[MAX];
    storePreOrder(T, preT, m);
    storePreOrder(S, preS, n);
    preT[m] = '\0', preS[n] = '\0';
 
    // If preS[] is not a substring of preT[], return false
    // Else return true
    return (strstr(preT, preS) != NULL);
}
 
// Driver program to test above function
int main()
{
    Node* T = newNode('a');
    T->left = newNode('b');
    T->right = newNode('d');
    T->left->left = newNode('c');
    T->right->right = newNode('e');
 
    Node* S = newNode('a');
    S->left = newNode('b');
    S->left->left = newNode('c');
    S->right = newNode('d');
 
    if (isSubtree(T, S))
        cout << "Yes: S is a subtree of T";
    else
        cout << "No: S is NOT a subtree of T";
 
    return 0;
}
//////////////////////////////////////////
