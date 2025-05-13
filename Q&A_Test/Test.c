#define _CRT_SECURE_NO_WARNINGS
//奖学金
/*#include <stdio.h>

struct Stu {
    int id;
    int chinese;
    int math;
    int english;
    int total;
};

void swap(struct Stu* a, struct Stu* b) {
    struct Stu temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n = 0;
    struct Stu students[300];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &students[i].chinese, &students[i].math, &students[i].english);
        students[i].id = i + 1;
        students[i].total = students[i].chinese + students[i].math + students[i].english;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].total < students[j + 1].total) {
                swap(&students[j], &students[j + 1]);
            }
            else if (students[j].total == students[j + 1].total) {
                if (students[j].chinese < students[j + 1].chinese) {
                    swap(&students[j], &students[j + 1]);
                }
                else if (students[j].chinese == students[j + 1].chinese) {
                    if (students[j].id > students[j + 1].id) {
                        swap(&students[j], &students[j + 1]);
                    }
                }
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        printf("%d %d\n", students[i].id, students[i].total);
    }

    return 0;
}*/

//奶牛塔
/*#include<stdio.h>

int main()
{
    int b = 0;
    int n = 0;
    int arr[20000];

    scanf("%d%d", &n, &b);
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int sum = 0;
    int i = 0;
    while (sum < b&&i<n) {
        sum += arr[i];
        i++;
    }
    printf("%d", i);

    return 0;
}*/

//拼数

/*#include<stdio.h>
int main()
{
    int n = 0;
    int arr[20];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if ((arr[j] / point(arr[j])) < (arr[j + 1] / point(arr[j + 1]))){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            else if ((arr[j] / point(arr[j])) == (arr[j + 1] / point(arr[j + 1]))) {

            }
        }
    }
}*/

//生日
#include<stdio.h>

struct pp {
    char name[20];
    int year;
    int month;
    int day;
};

int main()
{
    struct pp mates[100];
    int n = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s%d%d%d",mates[i].name, & mates[i].year, &mates[i].month, &mates[i].day);
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (mates[j].year < mates[j + 1].year) {
                struct pp temp = mates[j];
                mates[j] = mates[j + 1];
                mates[j + 1] = temp;
            }
            else if (mates[j].year == mates[j + 1].year&& mates[j].month < mates[j + 1].month) {
                struct pp temp = mates[j];
                mates[j] = mates[j + 1];
                mates[j + 1] = temp;
            }
            else if (mates[j].month == mates[j + 1].month && mates[j].day < mates[j + 1].day) {
                struct pp temp = mates[j];
                mates[j] = mates[j + 1];
                mates[j + 1] = temp;
            }
        }
    }

    for (int i = n-1; i>=0; i--)
    {
        printf("%s\n", mates[i].name);
    }

    return 0;
}