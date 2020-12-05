#include <stdlib.h>
#include <stdio.h>
#define MAX_CHAR 200

int main() {

    int no_correct = 0;

    while(!feof(stdin)) {
        /* // part1
        char pass[MAX_CHAR];
        char c;
        int mini, maxi;
        int i = 0;
        int count = 0;

        scanf("%d-%d %c: %s",&mini,&maxi,&c,pass);
        
        while (pass[i])
        {
            if(pass[i] == c)
                count++;
            i++;
        }
        
        if(count >= mini && count <= maxi)
            no_correct++;
        */
        // part2
        char pass[MAX_CHAR];
        char c;
        int index1, index2;
        int count = 0;

        scanf("%d-%d %c: %s",&index1,&index2,&c,pass);
        
        if(pass[index1 - 1] == c)
            count++;
        if(pass[index2 - 1] == c)
            count++;
        
        if(count == 1)
            no_correct++;
    }

    printf("%d\n",no_correct);

    return 0;
}