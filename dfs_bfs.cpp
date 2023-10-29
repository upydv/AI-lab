#include<bits/stdc++.h>
using namespace std;

void adj_list(int v,vector<int>adj[]){

        for(int i=0;i<v;i++){
            cout<<i<<"-->";
            for(auto l:adj[i])
                cout<<l<<" ";
             cout<<endl;   
        }
}
void adj_matrix(int v,vector<int>adj[]){
        vector<vector<int>>a_m(v,vector<int>(v,0));
        vector<int>::iterator it;
        for(int i=0;i<v;i++){
            for(auto l:adj[i]){
                    a_m[i][l]=1;
            }       
        }
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                    cout<<a_m[i][j]<<" ";
            }
            cout<<endl;
        }
}
void bfs(int v,vector<int>adj[]){
    vector<bool>vis(v,0);
    queue<int>q;
    q.push(0);
    vis[0]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
}
void df(int node,vector<bool>&vis,vector<int>adj[]){
    cout<<node<<" ";
    vis[node]=1;
    df(node,vis,adj);
}
void dfs(int v,vector<int>adj[]){
    vector<bool>vis(v,false);
    df(0,vis,adj);
}
int main(){
    int v,e;
    cout<<"Enter number of nodes :";
    cin>>v;
    cout<<endl<<"Enter number of edges : "<<endl;
    cin>>e;
    vector<int>adj[100];
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);    
    }
    int choice;
    cout<<"Enter your choice : "<<endl<<"1. Adjecency list    2. Adjecency matrix       3. BFS    4. DFS     5. Exit"<<endl;
    cin>>choice;
    switch (choice)
    {
    case 1:
        adj_list(v,adj);
        break;
    case 2:
        adj_matrix(v,adj);
        break;
    case 3:
        bfs(v,adj);
         break;
    case 4:
        dfs(v,adj);
        break;
    
    default:
        exit(0);
        break;
    }
    return 0;
}