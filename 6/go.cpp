#include<stdio.h>
#include<bits/stdc++.h>
#include<fstream>
#include<iostream>
#include<string>
#include <set>

using namespace std;
// #define FILE "smol.txt"
#define FILE "input.txt"

int ifRepeat(string str, int num){
    if (str.length() != num)
        cout << "String is not length " << num << "\n";
    set<char> a;
    for(auto& ch: str)
        a.insert(ch);
    return a.size() == num;
}

int main(void){
    int ans, num=14;
    string line;
    ifstream f (FILE);
    if (f.is_open()){
        while (getline(f, line)) {
            int r=num-1;
            while (r < line.length()){
                if (ifRepeat(line.substr(r-num+1, num), num)){
                    ans = r;
                    break;
                }
                r++;
            }
         }
        f.close();
    }
    else cout << "Cannot open file\n";
    cout << "sol: " << ans+1 << "\n";
    return 0; 
}