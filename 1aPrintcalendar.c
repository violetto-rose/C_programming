#include <stdio.h>
#include <string.h>
struct Day
{
    char name[20];
    int date;
    char activity[100];
};
int main()
{
    struct Day Calendar[7];
    strcpy(Calendar[0].name, "Monday");
    Calendar[0].date = 1;
    strcpy(Calendar[0].activity, "Work from 9AM to 5PM");

    strcpy(Calendar[1].name, "Tuesday");
    Calendar[1].date = 2;
    strcpy(Calendar[1].activity, "Meeting at 10AM");

    strcpy(Calendar[2].name, "Wednesday");
    Calendar[2].date = 3;
    strcpy(Calendar[2].activity, "Gym at 6PM");

    strcpy(Calendar[3].name, "Thursday");
    Calendar[3].date = 4;
    strcpy(Calendar[3].activity, "Dinner with friends at 7PM");

    strcpy(Calendar[4].name, "Friday");
    Calendar[4].date = 5;
    strcpy(Calendar[4].activity, "Movie night at 8PM");

    strcpy(Calendar[5].name, "Saturday");
    Calendar[5].date = 6;
    strcpy(Calendar[5].activity, "Weekend getaway");

    strcpy(Calendar[6].name, "Sunday");
    Calendar[6].date = 7;
    strcpy(Calendar[6].activity, "Relax and recharge");

    printf("Calendar of the week:\n");
    for (int i = 0; i < 7; i++)
    {
        printf("%s(Date:%d):%s\n", Calendar[i].name, Calendar[i].date, Calendar[i].activity);
    }
    return 0;
}