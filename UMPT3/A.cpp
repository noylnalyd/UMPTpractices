#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <deque>
#define ll long long

using namespace std;

int main(int argc, char const *argv[])
{
    int ntest,n,nmax = 4*10^5,i,j;
    cin >> ntest;
    int** vals = new int*[nmax];
    int** edges = new int*[nmax];
    bool* visited = new bool[nmax];
    for(i=0;i<n;i++){
        vals[i] = new int[2];
        edges[i] = new int[2];
    }
    for(int itest=0;itest<ntest;itest++){
        cin >> n;
        
        for(j=0;j<2;j++)
            for(i=0;i<n;i++){
                cin >>vals[i][j];
                vals[i][j] -= 1;
            }
        
        // Create graph structure to find loops
        for(i=0;i<n;i++){
            // add to both edges. edgesi1 is top to bottom
            int val1 = vals[i][0];
            int val2 = vals[i][1];
            edges[val1][0] = val2;
            edges[val2][1] = val1;
        }

        int looper = 0;
        for(i=0;i<n;i++)
            visited[i] = false;
        for(i=0;i<n;i++){
            if(!visited[i]){
                visited[i] = true;
                if(edges[i][0] != i){
                    looper++;
                    int nxt = i;
                    visited[nxt] = true;
                    while(true){
                        nxt = edges[nxt][0];
                        visited[nxt] = true;
                        nxt = edges[nxt][0];
                        if(visited[nxt] == true)
                            break;
                        visited[nxt] = true;
                    }
                }
            }
        }
        // 2^(looper/2)
        //looper -=1;
        long long tmp = 1;
        for(int i=0;i<looper;i++)
            tmp=(2*tmp)%(10^9+7);
        cout << tmp << endl;
    }


    return 0;
}
