#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
char role[20], username[30], password[20];
void reg();
void login();
FILE *fp;
int main()
{
    printf("\n\n\n\n\n\n\t\t\t\t\t*************WELCOME TO DASHBOARD************\n\n");
    int n;
    char ch;
    start:
    printf("\n");
    printf("\t\t\t\t     1. REGISTER\t\t\t2. LOG-IN\n\n");
    printf("\t\t\t\t\t\tChoice:- ");
    scanf("%d", &n);
    switch(n)
    {
        case 1:
        {
            reg();
            break;
        }
        case 2:
        {
            login();
            break;
        }
        default:
        {
            printf("\n\n\t\t\t\t\tChoice doesn't match. \n\t\t\t\t\tPress (Y/y) to enter Dashboard:- ");
            scanf(" %c", &ch);
            if(ch=='Y' || ch=='y')
            goto start;
            else
            exit(0);
        }
    }
    return 0;
}

void reg()
{
    system("cls");
    fp= fopen("regster.txt", "w");
    char ch;
    int i;
    printf("\n\n\t\t\t\t\t************REGISTER ZONE*************\n\n");
    fflush(stdin);
    printf("\t\t\t\t     Role : ");
    gets(role);
    fflush(stdin);
    printf("\t\t\t\t     Username : ");
    gets(username);
    fflush(stdin);
    printf("\t\t\t\t     Password : ");
    for(i = 0;i < 100;i++)
    {
    ch = getch();
    if(ch == 13)
    break;
    password[i] = ch;
    ch = '*' ;
    printf("%c ", ch);
    }
    password[i] = '\0';
    printf("\n\n\t\t\t\t     Successfully Registered. \n");

    fprintf(fp, "%s %s %s", role, username, password);
    fclose(fp);
}

void login()
{
    system("cls");
    fp= fopen("regster.txt", "r");
    if(fp==NULL)
    {
        printf("\n\n\t\t\t\t     You have to register first, if you are new user. \n");
        exit (0);
    }
    fscanf(fp, "%s %s %s", role, username, password);
    printf("\n\n\t\t\t\t\t************LOG-IN ZONE*************\n\n");
    char role1[20], username1[30], password1[20], ch, chs;
    int i, count=1, f;
    static int temp=3;
    start:
    fflush(stdin);
    printf("\t\t\t\t     Your Role:- ");
    gets(role1);
    fflush(stdin);
    printf("\t\t\t\t     Username:- ");
    gets(username1);
    fflush(stdin);
    printf("\t\t\t\t     Password:- ");
    for(i = 0;i < 100;i++)
    {
    ch = getch();
    if(ch == 13)
    break;
    password1[i] = ch;
    ch = '*' ;
    printf("%c ", ch);
    }
    password1[i] = '\0';
    if((strcmp(role1, role))==0 && (strcmp(username1, username)==0) && (strcmp(password1, password)==0))
    {
        system("cls");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  Role:- %s", strupr(role1));
        printf("\n\n\n\n\t\t\t\t\t\t\t\t     Hi %s. \n", strupr(username1));
        printf("\n\n\n\n\n\t\t\t\t\t\t\t     LOG-OUT (Y/N):- ");
        scanf(" %c", &chs);
        if(chs=='Y' || chs=='y')
        printf("\n\n\t\t\t\t     You are Successfully log out.");
        exit (0);
    }
    else if((strcmp(username1, username))==0 && (strcmp(password1, password))!=0)
    {
        printf("\n\n\t\t\t\t     Wrong Password. \n");
        count++;
        if(count<=4)
        {
            printf("\t\t\t\t     You have %d more chances: \n\n", temp);
            temp--;
            goto start;
        }   
        else
        {
            printf("\n\t\t\t\t     Sorry!, Failed to log in. Try again after 30 sec.\n");
        }
    }
    else if((strcmp(username1, username))!=0 || (strcmp(role1, role))!=0)
    {
        printf("\n\t\t\t\t     Invalid username or password. \n\t Would you like to re-login? (Y/N):- ");
        scanf(" %c", &chs);
        if(chs=='Y' || chs=='y')        
        goto start;
        else
        exit (0);
    }
    fclose(fp);
}