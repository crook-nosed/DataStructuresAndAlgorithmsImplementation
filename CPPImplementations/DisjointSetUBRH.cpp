  // implementation of Disjoint Set data structure using UBRH(Union By Rank Heuristic) .
#define DisjointSetUBRH dsubrh
#define MS 1000
#include <iostream>
using namespace std;

class dsubrh{
  private:
  int parent[MS]={0};
  int rank[MS]={0};
  int len = 0;
  public:
  // dsubrh();
  void makeSet(int x);
  int find(int x);
  void Union(int x, int y);
  void printParent() const;
  void printRank() const;

};
void dsubrh::printRank()const{
  // int len = sizeof(rank)/sizeof(int);
  for(int i=1;i<=len;i++)
     cout<<rank[i]<<" ";
  cout<<"\n";
}
void dsubrh::printParent()const{
  // int len = sizeof(parent)/sizeof(int);
  for(int i=1;i<=len;i++)
     cout<<parent[i]<<" ";
  cout<<"\n";
}
// dsubrh::dsubrh(){
//   parent[MS] = {0};
//   rank[MS] = {0};
// }

void dsubrh::makeSet(int i){
  parent[i] = i;
  rank[i] = 0;
  len++;
}
int dsubrh::find(int i){
  while(i != parent[i])
     i=parent[i];
  return i;
}
void dsubrh::Union(int i, int j)
{
  int i_id = find(i);
  int j_id = find(j);
  if(i_id == j_id)
     return;
  if(rank[i_id]>rank[j_id])
      parent[j_id] = i_id;
  else{
    parent[i_id] = j_id;
    if(rank[i_id] == rank[j_id])
        rank[j_id]++;
  }
}

int main()
{
  dsubrh first;
  first.makeSet(1);
  first.makeSet(2);
  first.makeSet(3);
  first.makeSet(4);
  first.makeSet(5);
  first.makeSet(6);
  first.printParent();
  first.printRank();
  first.Union(2, 4);
  first.printParent();
  first.printRank();
  first.Union(5,2); 
  first.Union(3,1); 
  first.Union(2,3); 
  first.Union(2,6); 
  first.printParent();
  first.printRank();

  return 0;
}