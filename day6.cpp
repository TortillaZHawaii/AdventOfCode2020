#include <bits/stdc++.h>

using namespace std;

int main() {

    string line;
    string group;

    int sum = 0;

    // part1
    // while (getline(cin,line))
    // {
    //     if(line.size() == 0) {
    //         sort(group.begin(),group.end());
    //         group.erase(unique(group.begin(), group.end()), group.end());
    //         sum += group.size();
    //         group = "";
    //     }
    //     else
    //         group += line;
    // }

    //part2
    bool nextline = true;
    while (getline(cin,line))
    {
        if(line.size() == 0) {
            sum += group.size();
            group = "";
            cout << group << endl;
            nextline = true;
        }
        else if (nextline) {
            nextline = false;
            group = line;
            
        } else {
            string pom;
            sort(group.begin(),group.end());
            group.erase(unique(group.begin(), group.end()), group.end());

            for_each(group.begin(),group.end(),[&pom, &line](char c) {
                if(line.find_first_of(c) != string::npos)
                    pom += c;
            });

            group = pom;
        }

        cout << group << endl;
    }
    
    sum += group.size();

    cout << sum << endl;

    return 0;
}