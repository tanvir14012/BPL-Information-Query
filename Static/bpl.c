#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <unistd.h>
#include "team and player statistics.c"

void top_batsman(int );
void top_bowler(int );
void prompt(void);
void design(void);
void animation(void);
void rocket(void);


int main()
{

    rocket();
    design();
    animation();
    prompt();

    return 0;
}

void top_batsman(int year)
{

    FILE *fp;
    if(year==2015)
    {
        fp=fopen("top_batsman-1","r");
    }
    else if(year==2013)
    {
        fp=fopen("top_batsman-3","r");
    }

    char ch;
    while((ch=fgetc(fp))!=EOF)
    {
        putchar(ch);
    }
    fclose(fp);
}

void top_bowler(int year)
{

    FILE *fp;
    if(year==2015)
    {
        fp=fopen("top_bowler-2","r");
    }
    else if(year==2013)
    {
        fp=fopen("top_bowler-4","r");
    }

    char ch;
    while((ch=fgetc(fp))!=EOF)
    {
        putchar(ch);
    }
    fclose(fp);
}
void prompt(void)
{
    printf("(1) BPL 2015\n");
    printf("(2) BPL 2013\n");
    printf("Please enter choice:(1 or 2)\n");
    int a,choice,flag=0;
    scanf("%d",&a);
    getchar();
    if(a==1)
    {
        while(1)
        {
            printf("\n\n");
            printf("(1)Top Ten Batsman statistics of BPL 2015\n\n");
            printf("(2)Top Ten Bowler statistics of BPL 2015\n\n");
            printf("(3)Search player and display his perfomance\n\n");
            printf("(4)Team ranking of BPL 2015\n\n");
            printf("(5)Search by team and display team information of BPL 2015\n\n");
            printf("(6)Display entire BPL record\n\n");
            printf("(7)Select player from list and see his information\n\n");
            printf("(8)Quit input prompt\n\n");
            printf("Please enter choice:(1 to 8)\n\n");
            scanf("%d",&choice);
            switch(choice)
            {
            case 1:
                top_batsman(2015);
                break;

            case 2:
                top_bowler(2015);
                break;
            case 3:
                load_team(2015);
                ///pirnt();
                searchdisplay();
                break;
            case 4:
                standing(2015);
                break;
            case 5:
                load_team(2015);
                search_team(2015);
                break;
            case 6:
                load_team(2015);
                pirnt();
                break;
            case 7:
                load_team(2015);
                select_show();
                break ;
            case 8:
                exit(0);
                break;
            default:
                prompt();
                break;

            }
        }
    }
    else if(a==2)
    {

        while(1)
        {
            printf("\n\n");
            printf("(1)Top Ten Batsman statistics of BPL 2013\n\n");
            printf("(2)Top Ten Bowler statistics of BPL 2013\n\n");
            printf("(3)Search player and display his perfomance\n\n");
            printf("(4)Team ranking of BPL 2013\n\n");
            printf("(5)Search by team and display team information of BPL 2013\n\n");
            printf("(6)Display entire BPL record\n\n");
            printf("(7)Select player from list and see his information\n\n");
            printf("(8)Quit input prompt\n\n");
            printf("Please enter choice:(1 to 8)\n\n");
            scanf("%d",&choice);
            switch(choice)
            {
            case 1:
                top_batsman(2013);
                break;

            case 2:
                top_bowler(2013);
                break;
            case 3:
                load_team(2013);
                searchdisplay();
                break;
            case 4:
                standing(2013);
                break;
            case 5:
                load_team(2013);
                search_team(2013);
                break;
            case 6:
                load_team(2013);
                pirnt();
                break;
            case 7:
                load_team(2013);
                select_show();
                break;
            case 8:
                exit(0);
                break;
            default:
                prompt();
                break;

            }

        }

    }
    else
    {
        main();
    }
}

void design(void)
{
    FILE *fp;
    fp=fopen("y.txt","r");
    char ch;
    while((ch=fgetc(fp))!=EOF)
    {
        putchar(ch);
    }
    printf("\n\n");
    fclose(fp);
}

void animation(void)
{
    printf("User Prompt\n");
    int i;
    for(i=0; i<5; i++)
    {
        Sleep(100);
        printf(  "."  );
        fflush(stdout);
        Sleep(100);
        printf(  "."  );
        fflush(stdout);
        Sleep(100);
        printf(  "."  );
        fflush(stdout);;
        Sleep(100);
        printf(  "\b\b\b   \b\b\b");
        fflush(stdout);

    }
}

void rocket(void)
{
    int i;

    const char rocket[] =
        "           _\n\
          /^\\\n\
          |-|\n\
          | |\n\
          |B|\n\
          |P|\n\
          |L|\n\
          | |\n\
         /| |\\\n\
        / | | \\\n\
       |  | |  |\n\
        `-\"\"\"-`\n\
";

    for ( i = 0; i < 50; i ++) printf("\n"); // jump to bottom of console
    printf("%s", rocket);
    int j = 300000;
    for ( i = 0; i < 50; i ++)
    {
        usleep(j); // move faster and faster,
        j = (int)(j * .8); // so sleep less each time
        printf("\n"); // move rocket a line upward
    }
}
