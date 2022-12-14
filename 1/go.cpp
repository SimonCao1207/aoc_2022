#include<stdio.h>
#include<bits/stdc++.h>
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<numeric>
using namespace std;

void printVec(vector<int> v){
    for(int i: v){
        cout << i << " ";
    }
    cout << "\n";
}

vector<int> slicing(vector<int>& v, int s, int e){
    auto start = v.begin() + s;
    auto end = v.begin() + e;
    vector<int> res(e-s);
    copy(start, end, res.begin());
    return res;
}

int main(void){
    string line;
    // ifstream f ("smol.txt");
    ifstream f ("input.txt");
    int currentSum = 0 , ans = 0 ; 
    vector<int> lstSum;
    if (f.is_open()){
        while ( getline (f, line)) {
            if (line == ""){
                lstSum.push_back(currentSum);
                currentSum = 0;
            }
            else currentSum += stoi(line);
        }
        lstSum.push_back(currentSum);
        f.close();
        sort(lstSum.begin(), lstSum.end(), greater<int>());
        // printVec(lstSum);
        vector<int> sliceV = slicing(lstSum, 0, 3);
        // printVec(sliceV);
        for_each(sliceV.begin(), sliceV.end(), [&](int n){
            ans += n;
        });
        cout << ans << "\n";
    }
    else cout << "Cannot open file\n";
    return 0; 
}