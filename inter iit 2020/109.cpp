//SAMSUNG
#include <iostream> 
#define f(i,a,b) for(int i = a;i<b;i++)
using namespace std;

int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

int n,k;
int grid[21][21];
int rare[5][2];

int dist[21][21];
bool visited[21][21];

typedef struct pair{
    int first;
    int second;
}pii;

class queue{
public:
   pii arr[1000];
   int fron,back,size;

    queue(){
        fron = 0;
        back = 0;
        size = 0;
    }
    void push(int r, int c){
        pii newp;
        newp.first = r;
        newp.second = c;
        arr[fron++] = newp;
        ++size;
    }
    pii front(){
        pii res;
        res = arr[back];
        return res;
    }
    void pop(){
        if(!size) return;
        ++back;
        --size;
    }
    bool empty(){
        return size == 0;
    }
};

void bfs(int r, int c){
    f(i,0,n){
        f(j,0,n){
            dist[i][j] = -1;
            visited[i][j] = false;
        }
    }
    visited[r][c] = true;
    dist[r][c] = 0;
    queue q;
    q.push(r,c);
    while(!q.empty()){
        for(int rep = q.size; rep > 0; --rep){
            pii front = q.front();
            q.pop();
            int r = front.first, c = front.second;
            for(int d = 0; d < 4; ++d){
                int nr = r + dx[d], nc = c + dy[d];
                if(nr<0 || nc<0 || nr>=n || nc>=n || visited[nr][nc] || grid[nr][nc] == 0)
                    continue;
                dist[nr][nc] = 1 + dist[r][c];
                visited[nr][nc] = true;
                q.push(nr,nc);
            }
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
    cin>>n>>k;
    f(i,0,k){
        cin>>rare[i][0]>>rare[i][1];
        --rare[i][0];--rare[i][1];
    }
    f(i,0,n)
        f(j,0,n)
            cin>>grid[i][j];
    
    int ans = 1000;
    f(i,0,n){
        f(j,0,n){
            if(grid[i][j]){
                bfs(i,j);
                int maxi = 0;
                bool poss = true;
                f(l,0,k){
                    if(dist[rare[l][0]][rare[l][1]] == -1){
                        poss = false;
                        break;
                    }
                    maxi = max(maxi,dist[rare[l][0]][rare[l][1]]);
                }
                if(poss)
                    ans = min(ans,maxi);
            }
        }
    }
    if(ans != 1000) cout<<ans<<endl;
    else cout<<-1<<endl;
    }
   
}