/*2. Design, Develop and Implement a Program in C for the following operations on Strings a. Read a main String (STR), a Pattern String (PAT) and a Replace String (REP) b. Perform Pattern Matching Operation: Find and Replace all occurrences of PAT in STR with REP if PAT exists in STR. Report suitable messages in case PAT does not exist in STR. Support the program with functions for each of the above operations. Don't use Built-in functions.*/

#include <stdio.h>
#include <string.h>

int main() {
    char STR[100], PAT[100], REP[100], ans[100];
    int i = 0, j = 0, c = 0, m = 0, flag = 0;

    printf("Enter the MAIN string:\n");
    fgets(STR, sizeof(STR), stdin);

    printf("Enter the PATTERN string:\n");
    fgets(PAT, sizeof(PAT), stdin);

    printf("Enter the REPLACE string:\n");
    fgets(REP, sizeof(REP), stdin);

    // Remove new line characters from inputs
    STR[strcspn(STR, "\n")] = '\0';
    PAT[strcspn(PAT, "\n")] = '\0';
    REP[strcspn(REP, "\n")] = '\0';

    while (STR[c] != '\0') {
        if (STR[m] == PAT[i]) {
            i++;
            m++;
            if (PAT[i] == '\0') {
                flag = 1;
                // Replace pattern with replacement string
                for (int k = 0; REP[k] != '\0'; k++, j++) {
                    ans[j] = REP[k];
                }
                i = 0;
                c = m;
            }
        } else {
            ans[j] = STR[c];
            j++;
            c++;
            m = c;
            i = 0;
        }
    }

    if (flag == 0) {
        printf("Pattern not found\n");
    } else {
        ans[j] = '\0';
        printf("The RESULTANT string is: %s\n", ans);
    }

    return 0;
}