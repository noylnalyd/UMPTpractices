#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(int argc, char const *argv[])
{
    int ntest,n;
    cin >> ntest;
    char read[41];
    vector<int> chars;
    for(int itest=0;itest<ntest;itest++){
        cin >> n;
        cin >> read;
        

        for(int i=0;i<n;i++)
            chars.push_back((int)(read[i]-'a'));
        sort(chars.begin(),chars.end());
        int count = 0;

        for(int i=0;i<n;i++){
            if(chars[i]!=((int)(read[i]-'a'))){
                count = count+1;
            }
        }
        chars.clear();
        cout << count << endl;
    }


    return 0;
}
