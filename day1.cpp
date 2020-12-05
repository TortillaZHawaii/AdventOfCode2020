#include <bits/stdc++.h>

using namespace std;

int main() {
    int linia;
    vector<int> v;
    while (cin>>linia)
    {
        v.push_back(linia);
    }

    // O(N^3) brute
    for(int i = 0; i < v.size(); i++) {
        for(int j = i+1; j < v.size(); j++) {
            for(int k = j+1; k < v.size(); k++)
                if(v[i] + v[j] + v[k] == 2020) {
                    cout << v[i]*v[j]*v[k] << endl;
                    return 0;
                }
        }
    }
    return 0;
}