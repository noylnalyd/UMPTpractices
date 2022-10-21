#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define ll long long

using namespace std;

int main(int argc, char const *argv[])
{
    int ntest,n,c,tmp;
    cin >> ntest;
    int orbitz[100];
    for(int itest=0;itest<ntest;itest++){
        cin >> n >> c;
        for(int i=0;i<100;i++)
            orbitz[i] = 0;
        for(int i=0;i<n;i++){
            cin >> tmp;
            orbitz[tmp-1]=orbitz[tmp-1]+1;
        }
        int cost = 0;
        for(int i=0;i<100;i++)
            cost = cost + min(c,orbitz[i]);
        
        cout << cost << endl;
    }


    return 0;
}
