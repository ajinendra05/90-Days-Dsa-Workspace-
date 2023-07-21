#include<bits/stdc++.h>

using namespace std;

class disjoint{
    vector<int> rank, parents;  

    public:
        disjoint(int size){
            rank.resize(size+1, 0);
            parents.resize(size+1);
            
            for(int i=0; i<= size; i++){
                parents[i] = i;
            }
        }

        // find parent + pathcompression
        int findPar(int node){
            if(node<parents.size() && parents[node] == node)
                return node;

            return parents[node] = findPar(parents[node]);    
        }

        //union by rank
        void unionRank(int u, int v){
            int ulp_u = findPar(u);
            int ult_v = findPar(v);

            if(ult_v == ulp_u){
                return ;
            }

            if(rank[ult_v] < rank[ulp_u]){
                parents[ulp_u] = ult_v;
                return ;
            }

            if(rank[ult_v] > rank[ulp_u]){
                parents[ult_v] = ulp_u;
                return ;
            }

            parents[ult_v] = ulp_u;
            rank[ult_v]++;
            return ;
            
        }
};

int main(){

    return 0;
}