#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<int> adj[], int V);
void DFSUtil(int u, vector<int>adj[], vector<bool>&visited);
void addEdge(vector<int> adj[], int u, int v);

int main(){
	int V = 5;
	vector<int> adj[5];
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 4);
	addEdge(adj, 1, 2);
	addEdge(adj, 1, 3);
	addEdge(adj, 1, 4);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 4);
	DFS(adj, V);
	cout << endl;

}


void addEdge(vector<int> adj[], int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);

}

void DFS(vector<int> adj[], int V){
	vector<bool> visited(V, false);
	for(int i = 0; i < V; i++){
		if(visited[i] == false)
			DFSUtil(i, adj, visited);
	}
}


void DFSUtil(int u, vector<int>adj[], vector<bool>&visited){
	visited[u]= true;
	cout << u << " ";
	for(int i = 0; i < adj[u].size(); i++){
		if(visited[adj[u][i]] == false)
			DFSUtil(adj[u][i], adj, visited);
	}
}