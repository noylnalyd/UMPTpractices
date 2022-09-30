#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <deque>
#define ll long long

using namespace std;

int main(int argc, char const *argv[])
{
    // Ok so this is def lca but like... why tho
    //  I'm gonna do this superrrrr naive bc i dont have nlogn lca on hand
    //  also naive loop thru leaves!

    int n,m;
    int tmp1,tmp2;
    cin >> n >> m;

    n = n+1; // assume tree root=0
    int pages[n];
    int cumPages[n];
    int depth[n];
    int parent[n];
    for(int i=1;i<n;i++){
        cin >> pages[i];
        cumPages[i] = pages[i];
        depth[i] = 0;
    }

    //Store children nodes in tree
    vector<int> children[n];
    // isleaf
    bool leaf[n];
    for(int i=0;i<n;i++){
        leaf[i] = true;
        parent[i] = -1;
    }
    leaf[0] = false;
    pages[0] = cumPages[0] = 0;
    for(int i=0;i<m;i++){
        cin >> tmp1 >> tmp2;
        children[tmp1].push_back(tmp2);
        leaf[tmp1] = false;
        parent[tmp2] = tmp1;
    }
    // add root as yaknow root
    for(int i=1;i<n;i++){
        if(parent[i]==-1){
            parent[i] = 0;
            children[0].push_back(i);
        }
    }

    // Now use cumpages to store page count to root
    //  Also update depth
    deque<int> bfs;
    bfs.push_back(0);
    depth[0] = 0;
    while ( !bfs.empty()){
        int ind = bfs.front();
        bfs.pop_front();
        for(int i=0;i<children[ind].size();i++){
            int kid = children[ind][i];
            depth[kid] = depth[ind]+1;
            cumPages[kid] = cumPages[ind] + cumPages[kid]; // only valid for trees!
            bfs.push_back(kid);
        }
    }

    // ok so we did it.. now loop thru all leaf node pairs, find lca, and cost = cumPages[i]+cumPages[j]-cumPages[lca(i,j)]
    vector<int> leaves;
    for(int i=1;i<n;i++)
        if(leaf[i])
            leaves.push_back(i);
    
    int minCost = -1,cumCost;
    int lca,lcb,da,db;
    
    for(int i=0;i<leaves.size();i++){
        for(int j=i+1;j<leaves.size();j++){
            // find lca

            lca = leaves[i];
            lcb = leaves[j];
            da = depth[lca];
            db = depth[lcb];
            while(lca != lcb){
                //cout << lca << " " << lcb << endl;
                if(da < db){
                    lcb = parent[lcb];
                    db = depth[lcb];
                }
                else{
                    lca = parent[lca];
                    da = depth[lca];
                }
            }
            cumCost = cumPages[leaves[i]]+cumPages[leaves[j]]-cumPages[lca];
            if(minCost ==-1 || cumCost < minCost)
                minCost = cumCost;
        }
    }
    cout << minCost;







    
    //vector<int> parents = new vector<int>();

    return 0;
}
