// Write a program using pointers to find the smallest number in an array of 25 integers.
#include <stdio.h>
int main()
{
    int arr[25], i, n;
    printf("\nEnter 25 elements of array:\n");
    for (i = 0; i < 25; i++)
    {
        scanf("%d", arr[i]); // Error: Missing '&' before 'arr[i]'
    }
    n = arr;                  // Error: Should be *arr
    for (i = 1; i <= 25; i++) // Error: Should be 'i < 25'
    {
        if (*(arr + i) < n)
            n = arr[i]; // Error: Should be *(arr + i)
    }
    printf("\nSmallest number in the array is: %d\n", n);
    return 0;
}

// Corrected version
#include <stdio.h>
int main()
{
    int arr[25], i, n;
    printf("\nEnter 25 elements of array:\n");
    for (i = 0; i < 25; i++)
    {
        scanf("%d", &arr[i]);
    }
    n = *arr;
    for (i = 1; i < 25; i++)
    {
        if (*(arr + i) < n)
            n = *(arr + i);
    }
    printf("\nSmallest number in the array is: %d\n", n);
    return 0;
}





// Delete all the vowels from a sentence
#include <stdio.h>
int main()
{
    char str[100], str1[100];
    char *s, *p;
    printf("Enter the sentence not more than 100 characters:");
    gets(str); // Error: gets() is unsafe, use fgets() instead
    s = str;
    p = str1;
    while (*s) // s is a pointer, should check *s
    {
        if (*s != 'a' && *s != 'e' && *s != 'i' && *s != 'o' && *s != 'u')
            s++; // Error: Doesn't copy the consonants to str1
        else if (*s != 'A' && *s != 'E' && *s != 'I' && *s != 'O' && *s != 'U')
            s++; // Error: Same logic issue as above, should copy consonants
        else
            *p++ = *s++; // Correct but falls through if not a vowel
    }
    *p = '\0';
    printf("Sentence after deleting vowels: %d\n", str1); // Error: %d should be %s
    return 0;
}

// Corrected version
#include <stdio.h>
int main()
{
    char str[100], str1[100];
    char *s, *p;
    printf("Enter the sentence not more than 100 characters: ");
    fgets(str, 100, stdin);
    s = str;
    p = str1;
    while (*s)
    {
        if (*s != 'a' && *s != 'e' && *s != 'i' && *s != 'o' && *s != 'u' &&
            *s != 'A' && *s != 'E' && *s != 'I' && *s != 'O' && *s != 'U')
        {
            *p++ = *s; // Copy non-vowel characters to str1
        }
        s++;
    }
    *p = '\0';
    printf("Sentence after deleting vowels: %s\n", str1);
    return 0;
}





// Point out the errors in the program
#include <stdio.h>
#include <string.h>
int main()
{
    struct employee
    {
        char name[25];
        int age;
        float salary;
    };
    struct employee e;
    strcpy(name, "Shailesh");                // Should be e.name
    age = 25;                                // Should be e.age
    salary = 15500.00;                       // Should be e.salary
    printf("%c %f %d\n", name, age, salary); // Order and types do not match the variables
    return 0;
}

// Corrected version
#include <stdio.h>
#include <string.h>
int main()
{
    struct employee
    {
        char name[25];
        int age;
        float salary;
    };
    struct employee e;
    strcpy(e.name, "Shailesh");
    e.age = 25;
    e.salary = 15500.00;
    printf("%s %d %f\n", e.name, e.age, e.salary);
    return 0;
}





// Binary equivalent of a decimal number
#include <stdio.h>
int binary(int n);
int main()
{
    int num;
    printf("\nEnter the number: ");
    scanf("%d", &number); // Should be num
    binary(num);
    return 0;
}
int binary(int n)
{
    int r;
    r = n % 2;
    n = n * 2; // Should be n = n / 2
    if (n == 0)
    {
        printf("\nThe binary equivalent is ");
        printf("%f", r); // Should be %d
        return;          // Missing return value
    }
    else
    {
        binaries(n); // Function name should be 'binary'
    }
    printf("%d", r);
    return r;
}

// Corrected version
#include <stdio.h>
int binary(int n);
int main()
{
    int num;
    printf("\nEnter the number: ");
    scanf("%d", &num);
    binary(num);
    return 0;
}
int binary(int n)
{
    int r;
    r = n % 2;
    n = n / 2;
    if (n == 0)
    {
        printf("\nThe binary equivalent is ");
        printf("%d", r);
        return r;
    }
    else
    {
        binary(n);
    }
    printf("%d", r);
    return r;
}