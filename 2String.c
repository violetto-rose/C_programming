/*2. Design, Develop and Implement a Program in C for the following operations on Strings a. Read a main String (STR), a Pattern String (PAT) and a Replace String (REP) b. Perform Pattern Matching Operation: Find and Replace all occurrences of PAT in STR with REP if PAT exists in STR. Report suitable messages in case PAT does not exist in STR. Support the program with functions for each of the above operations. Don't use Built-in functions.*/

#include <stdio.h>
#include <string.h>

void main()
{
    char STR[100], PAT[100], REP[100], ans[100];
    int i, j, c, m, k, flag = 0;
    printf("Enter the MAIN string:\n");
    gets(STR);
    printf("Enter the PATTERN string:\n");
    gets(PAT);
    printf("Enter the REPLACE string: \n");
    gets(REP);
    i = m = c = j = 0;
    while (STR[c] != '\0')
    {
        if (STR[m] == PAT[i])
        {
            i++;
            m++;
            if (PAT[i] == '\0')
            {
                flag = 1;
                for (k = 0; REP[k] != '\0'; k++, j++)
                {
                    ans[j] = REP[k];
                }
                i = 0;
                c = m;
            }
        }
        else
        {
            ans[j] = STR[c];
            j++;
            c++;
            m = c;
            i = 0;
        }
    }

    if (flag == 0)
    {
        printf("Pattern not found\n");
    }
    else
    {
        ans[j] = '\0';
        printf("The RESULTANT string is: %s\n", ans);
    }
}