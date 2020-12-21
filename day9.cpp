#include <bits/stdc++.h>
#define PREAMBLE_SIZE 25

using namespace std;

bool check_sum(int val, int tab[PREAMBLE_SIZE]) {
    for(int i = 0; i < PREAMBLE_SIZE - 1; i++) {
        for(int j = i + 1; j < PREAMBLE_SIZE; j++) {
            if(tab[i]+tab[j] == val)
                return true;
        }
    }

    return false;
}

int main() {

    int prevs[PREAMBLE_SIZE];
    int i = -1;
    int next_num;

    while (cin >> next_num)
    {
        i++;
        if(i < PREAMBLE_SIZE) {
            prevs[i] = next_num;
            continue;
        }
        
        if(check_sum(next_num, prevs)) {
            prevs[i % PREAMBLE_SIZE] = next_num;
            continue;
        }

        cout << next_num << endl;
        break;
    }
    
    return EXIT_SUCCESS;
}