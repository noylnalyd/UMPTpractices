#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(int argc, char const *argv[])
{
    int n,m;
    cin >> n >> m;
    
    int cities[n];
    int radios[m];

    for(int i=0;i<n;i++)
        cin >> cities[i];
    for(int i=0;i<m;i++)
        cin >> radios[i];
    // Method: Can't do nxm, dope. Simple idea is to bin search, but thats too slow and redundant
    //  Can't we just sweep this somehow? and binsearch for r?
    //  ok yes but thats so silly idk
    //  ig ig
    //  wait just one sweep and u reset value each time
    //  lolloollo

    int rptr = 0,r=0;
    for(int cityptr=0;cityptr<n;cityptr++){
        // sweep rptr until rptr on/left of cityptr, rptr+1 on/right of cityptr and existent
        //  exceptions: city > radio
        while(rptr+1<m && (radios[rptr]<cities[cityptr] &&  radios[rptr+1]<cities[cityptr]))
            rptr++;
        
        // okay
        r = max(r,max(abs(cities[cityptr]-radios[rptr]),abs(cities[cityptr]-radios[rptr+1])));

        
    }
    cout << r;

    return 0;
}
