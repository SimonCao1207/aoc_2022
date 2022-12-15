#include<stdio.h>
#include<bits/stdc++.h>
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<numeric>
using namespace std;

template <typename T> void printVec(vector<T> v){
    for(T i: v){
        cout << i << " ";
    }
    cout << "\n";
}

template <typename T> vector<T> slicing(vector<T>& v, int s, int e){
    auto start = v.begin() + s;
    auto end = v.begin() + e;
    vector<T> res(e-s);
    copy(start, end, res.begin());
    return res;
}

int main(void){
    string line;
    // ifstream f ("smol.txt");
    ifstream f ("input.txt");
    int ans = 0;
    vector<char> p1;
    vector<char> p2;
    map<char, char> win {
        {'A', 'Y'}, 
        {'B', 'Z'}, 
        {'C', 'X'}
    };
    map<char, char> draw {
        {'A', 'X'}, 
        {'B', 'Y'}, 
        {'C', 'Z'}
    };

    map<char, int> point {
        {'X', 1}, 
        {'Y', 2}, 
        {'Z', 3}
    };

    if (f.is_open()){
        while (getline(f, line)) {
            char c1 = line[0], c2 = line[2]; 
            set<char> s{'X', 'Y', 'Z'}; 
            if (c2 == 'Y') {
                ans += 3;
                ans += point[draw[c1]];
                // cout << "draw: " <<  draw[c1] << "\n"; 
                // cout << point[draw[c1]] << "\n"; 
            }
            else if (c2 == 'Z'){
                ans += 6;
                ans += point[win[c1]];
                // cout << "win :" << win[c1] << "\n"; 
                // cout << point[win[c1]] << "\n"; 
            }
            else {
                s.erase(win[c1]); 
                s.erase(draw[c1]); 
                // cout << "lose: " << *s.begin() << "\n"; 
                // cout << point[*s.begin()] << "\n"; 
                ans += point[*s.begin()];
            }
        }
        f.close();
    }
    else cout << "Cannot open file\n";

    cout << "sol: " << ans << "\n";
    return 0; 
}