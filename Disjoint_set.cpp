#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
  private:
  vector<int> parent, rank,size; 
  public: 
  DisjointSet(int n){
      parent.resize(n+1); 
      rank.resize(n+1, 0); 
      size.resize(n+1,0); 
      for (int i = 0;i<n+1;i++){
          parent[i] = i; 
          size[i] = 1; 
      }
  }
  
  int findUParent(int node){
      if(node == parent[node]){
          return node; 
      }
      return parent[node] = findUParent(parent[node]);
  }
  
  void unionByRank(int u, int v){
      int ult_u = findUParent(u); 
      int ult_v = findUParent(v); 
      // this means that they are the part of a same component already. 
      if(ult_u == ult_v) return; 
      if(rank[ult_u] < rank[ult_v]){
          parent[ult_u] = ult_v; 
      }
      else if (rank[ult_u] > rank[ult_v]){
          parent[ult_v] = ult_u; 
      }
      else{
          parent[ult_u] = ult_v; 
          rank[ult_v]++; 
      }
  }
  
  void unionBySize(int u, int v){
      int ult_u = findUParent(u); 
      int ult_v = findUParent(v); 
      if(ult_v == ult_u) return; 
      if(size[ult_u] < size[ult_v]){
          parent[ult_u] = ult_v; 
          size[ult_v] += size[ult_u];
      }else{
          parent[ult_v] = ult_u; 
          size[ult_u] += size[ult_v]; 
      }
  }
};

int main()
{

    return 0;
}
