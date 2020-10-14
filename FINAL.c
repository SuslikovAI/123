#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <malloc.h>
#include <locale.h>
#include <time.h>
#define MAXS 10

void delete_student()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char Zachetka[7];
    FILE* fin;
    FILE* fout;
    char strp[100], str[100], strprov[100];
    printf("%s", "Номер зачетной книжки: ");
    scanf("%s", Zachetka);
    fin = fopen("students.csv", "r");
    fout = fopen("students_help.csv", "w");
    while (fgets(strp, 80, fin) != NULL)
    {
        int p = 2;
        int cnt = 0, i = 0;
        for (i; i < 7; i++)
        {
            if (strp[i] == Zachetka[i])
            {
                cnt++;
            }
        }
        if (cnt < 6)
        {

            fprintf(fout, "%s", strp);
            fgets(str, 100, fin);
            fprintf(fout, "%s", str);
        }
        else if (cnt == 6)
        {
            cnt = 0;
            fgets(strp, 80, fin);
        }
    }
    fclose(fin);
    fclose(fout);
    fin = fopen("students.csv", "w");
    fout = fopen("students_help.csv", "r");
    while (fgets(str, 100, fout) != NULL)
    {
        fprintf(fin, "%s", str);
    }
    fclose(fin);
    fclose(fout);
}

void add_student()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    FILE* f;
    printf("Введите данные нового студента:");
    char* str = (char*)malloc(sizeof(char));
    getchar();
    int i = 0, j = 0;
    while ((str[i] = getchar()) != '\n')
    {
        i++;
        str = (char*)realloc(str, (i + 1) * sizeof(char));
    }
    f = fopen("students.csv", "a");
    fputc('\n', f);
    for (j; j < i; j++)
    {
        fputc(str[j], f);
    }
    fclose(f);
    free(str);
}

void info_chek_student()//поиск по фамилии
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char Zachetka[16];
    FILE* f; int d;
    char strp[100], str[100];
    printf("%s", "Введите фамилию: ");
    scanf("%s", Zachetka);
    d = strlen(Zachetka);
    f = fopen("students.csv", "r"); int g = 15 + d;
    while (fgets(strp, 80, f) != NULL)
    {
        int cnt = 0, i = 0;
        for (i; i < g; i++)
        {
            for (int t = 0; t < 30; t++)
            {

                if (strp[i] == Zachetka[t])
                {
                    cnt++;
                }
            }
            if (cnt == d) {

                for (int j = 0; j < 90; j++) {
                    printf("%c", strp[j]); int u = j + 1; if (strp[u] == 'М') { fclose(f); return; }
                }
            }
            cnt = 0;
        }
    }
    fclose(f);
}

void CreateBackUp()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int c = 0;
    printf("VVOD NAME\n");
    scanf("%d", &c);
    char file[128];
    sprintf(file, "students_%d.csv", c);
    FILE* fin;
    FILE* fout;
    FILE* fprov;
    char strp[100], str[100], strprov[100];

    fin = fopen("students.csv", "r");
    fout = fopen(file, "w");
    while (fgets(str, 100, fin) != NULL)
    {
        fprintf(fout, "%s", str);
    }
    fclose(fin);
    fclose(fout);

}

void BackUp()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int c = 0;
    printf("VVOD NAME\n");
    scanf("%d", &c);
    char file[128];
    sprintf(file, "students_%d.csv", c);

    FILE* fin;
    FILE* fout;
    FILE* fprov;
    char strp[100], str[100], strprov[100];

    fin = fopen("students.csv", "w");
    fout = fopen(file, "r");
    while (fgets(str, 100, fout) != NULL)
    {
        fprintf(fin, "%s", str);
    }
    fclose(fin);
    fclose(fout);
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("color 0A");
    FILE* fuser;
    int i = 0, j = 0, cnt = 0, count = 0;
    printf("Добро пожаловать в библиотеку!\n");
up_menu:
    printf("1. Добавить ученика\n");
    printf("2. Удалить ученика (По номеру зачетки)\n");
    printf("5. Cоздать Backup\n");
    printf("6. Восстановить Backup\n");
    printf("7. Получить информацию об ученике\n");
    printf("8. Закончить работу программы\n\n");
    printf("Введите команду: ");
    scanf("%d", &count);
    switch (count)
    {
    case 1:
        add_student();
        break;
    case 2:
        delete_student();
        break;
    case 5:
        CreateBackUp();
        break;
    case 6:
        BackUp();
        break;
    case 7:
        info_chek_student();
        break;
    case 8:
        exit(0);
        break;
    default:
        printf("\nТакой команды нет\n");
        goto up_menu;
    }
    printf("\n\n\n\a");
    goto up_menu;



    return 0;
}
