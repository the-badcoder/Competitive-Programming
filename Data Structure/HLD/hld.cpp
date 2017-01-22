//problem LOJ-1348
#include<bits/stdc++.h>
using namespace std;
#define MAX 30005
#define gc getchar unlocked
#define gc getchar
#define pc putchar_unlocked
#define pc putchar
int chainHead[MAX];
int chainSize[MAX];
int chainPos[MAX];
int chainInd[MAX];
int subsize[MAX];
int parent[MAX];
int store[MAX];
int point[MAX];
int P[MAX][50];
int chainNo=0;
int cost[MAX];
int ptr=0;
int BIT[MAX];
int L[MAX];
vector<int>edge[MAX];
void scan(int &n){
    n=0;
    bool negative=false;
    char c=gc();
    while(c<'0'||c>'9'){
        if(c=='-') negative=true;
        c=gc();
    }
    while(c>='0'&&c<='9'){
        n=n*10+c-48;
        c=gc();
    }
    if(negative) n=~(n-1);
}
void print(int n){
    if(n<0){
        pc('-');
        n=-n;
    }
    if(!n){
        pc('0');
        pc('\n');
        return;
    }
    char buff[12];
    int len=0;
    while(n) buff[len++]=n%10+48,n/=10;
    for(int i=len-1;i>=0;i--) pc(buff[i]);
    pc('\n');
}
int query(int idx){
    int sum=0;
    while(idx>0){
        sum+=BIT[idx];
        idx-=(idx&-idx);
    }
    return sum;
}
void update(int idx,int n,int nn){
    while(idx<=nn){
        BIT[idx]+=n;
        idx+=(idx&-idx);
    }
}
int range_query(int i,int j){
    return query(j)-query(i-1);
}
void dfs2(int from,int u,int depth){
    L[u]=depth;
    parent[u]=from;
    subsize[u]=1;
    for(int i=0;i<edge[u].size();i++){
        int v=edge[u][i];
        if(v==from) continue;
        dfs2(u,v,depth+1);
        subsize[u]+=subsize[v];
    }
}
int LCA_query(int NN, int p, int q){
    if (L[p]<L[q]) swap(p,q);
    int log=1;
    while(1){
        int next=log+1;
        if((1<<next)>L[p])break;
        log++;
    }
    for(int i=log;i>=0;i--){
        if (L[p]-(1<<i)>=L[q]){
            p=P[p][i];
        }
    }
    if(p==q) return p;
    for(int i=log; i>=0;i--){
        if (P[p][i]!=-1&&P[p][i]!=P[q][i]){
            p=P[p][i],q=P[q][i];
        }
    }
    return parent[p];
}

void Sparse(int NN){
    memset(P,-1,sizeof(P));
    for(int i=0;i<NN;i++){
        P[i][0]=parent[i];
    }
    for(int j=1;(1<<j)<NN;j++){
        for(int i=0;i<NN;i++){
            if (P[i][j-1]!=-1){
                P[i][j]=P[P[i][j-1]][j-1];
            }
        }
    }
}
void HLD(int cur){
    if(chainHead[chainNo]==-1) chainHead[chainNo]=cur;
    chainInd[cur]=chainNo;
    chainSize[chainNo]++;
    point[cur]=ptr;
    store[ptr++]=cur;
    int ind =-1,mai=-1;
    for(int i=0;i<edge[cur].size();i++){
        if(chainInd[edge[cur][i]]==-1 and subsize[edge[cur][i]]>mai){
            mai=subsize[edge[cur][i]];
            ind=i;
        }
    }
    if(ind >= 0) HLD( edge[cur][ind] );
    for(int i=0;i<edge[cur].size();i++){
        if(chainInd[edge[cur][i]]==-1){
            chainNo++;
            HLD( edge[cur][i] );
        }
    }
}
int queryup(int u,int v){
    int uchain,vchain=chainInd[v],ans=0;
    while(true){
        uchain=chainInd[u];
        if(uchain==vchain){
            if(u==v){
                ans+=cost[u];
                break;
            }
            int l1=point[u]+1,l2=point[v]+1;
            if(l1>l2) swap(l1,l2);
            ans+=range_query(l1,l2);
            break;
        }
        int uchainhead=chainHead[uchain];
        ans+=range_query(point[uchainhead]+1,point[u]+1);
        u=parent[uchainhead];
    }
    return ans;
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scan(t);
    for(int i=1;i<=t;i++){
        int n;
        ptr=0,chainNo=0;
        scan(n);
        for(int j=0;j<n;j++){
            scan(cost[j]);
        }
        for(int j=1;j<n;j++){
            int u,v;
            scan(u);
            scan(v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        memset(parent,-1,sizeof(parent));
        memset(chainInd,-1,sizeof(chainInd));
        memset(chainHead,-1,sizeof(chainHead));
        parent[0]=0;
        dfs2(0,0,0);
        Sparse(n);
        HLD(0);
        for(int j=0;j<n;j++){
            update(j+1,cost[store[j]],n);
        }
        int q;
        scan(q);
        printf("Case %d:\n",i);
        for(int j=0;j<q;j++){
            int a,b,c;
            scan(a);
            scan(b);
            scan(c);
            if(a==0){
                int LCA=LCA_query(n,b,c);
                //cout<<queryup(b,LCA)+queryup(c,LCA)-cost[LCA]<<endl;
                print(queryup(b,LCA)+queryup(c,LCA)-cost[LCA]);
            }else{
                update(point[b]+1,c-cost[b],n);
                cost[b]=c;
            }
        }
        for(int j=0;j<=n;j++) edge[j].clear();
        memset(chainSize,0,sizeof(chainSize));
        memset(subsize,0,sizeof(subsize));
        memset(store,0,sizeof(store));
        memset(point,0,sizeof(point));
        memset(cost,0,sizeof(cost));
        memset(BIT,0,sizeof(BIT));
        memset(L,0,sizeof(L));
    }
}
