#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bat
{
    int match,run,fifty,best;
    double average,strike_rate;
};
struct ball
{
    char best[10];
    int match,wicket,fiveW;
    double economy,average;
};
struct Player
{
    char name[100];
    char country[200];
    char role[100];
    struct bat batting;
    struct ball bowling;

};
struct Team
{
    char name[250];
    char owner[250];
    char rank[50];
    char worth[250];
    char match[25];
    char won[25];
    char lost[25];
    struct Player plist[16];
} team[7];


void load_team(int year);
void search_team(int year);
void pirnt(void);
void searchdisplay(void);
void display(struct Player p);
void team_display(struct Team T);
void standing(int year);




void load_team(int year)
{
    FILE *fp147;

    if(year==2015)
    {
        fp147=fopen("bpl_2015.txt","r");
    }

    else if(year==2013)
    {
        fp147=fopen("bpl_2013.txt","r");
    }

    int it,it2;
    char str[100],str1[100];
    for(it=0; it<7; ++it)
    {
        if((year==2015) && (it==6))
        {
            break ;
        }
        fflush(stdin);
        fgets(team[it].name,sizeof(team[it].name),fp147);
        fgets(team[it].owner,sizeof(team[it].owner),fp147);
        fgets(team[it].rank,sizeof(team[it].rank),fp147);
        fgets(team[it].worth,sizeof(team[it].worth),fp147);
        fgets(team[it].match,sizeof(team[it].match),fp147);
        fgets(team[it].won,sizeof(team[it].won),fp147);
        fgets(team[it].lost,sizeof(team[it].lost),fp147);

        for(it2=0; it2<16; it2++)
        {
            fgets(team[it].plist[it2].name,sizeof(team[it].plist[it2].name),fp147);
            fgets(team[it].plist[it2].country,sizeof(team[it].plist[it2].country),fp147);
            fgets(team[it].plist[it2].role,sizeof(team[it].plist[it2].role),fp147);
            fgets(str,sizeof str,fp147);
            sscanf(str,"%d%d",&team[it].plist[it2].batting.match,&team[it].plist[it2].batting.run);
            fgets(str,sizeof str,fp147);
            sscanf(str,"%d%d",&team[it].plist[it2].batting.fifty,&team[it].plist[it2].batting.best);
            fgets(str,sizeof str,fp147);
            sscanf(str,"%lf%lf",&team[it].plist[it2].batting.average,&team[it].plist[it2].batting.strike_rate);
            fgets(str,sizeof str,fp147);
            sscanf(str,"%s%d%d%d",&team[it].plist[it2].bowling.best,&team[it].plist[it2].bowling.match,&team[it].plist[it2].bowling.wicket,&team[it].plist[it2].bowling.fiveW);
            fgets(str,sizeof str,fp147);
            sscanf(str,"%lf%lf",&team[it].plist[it2].bowling.economy,&team[it].plist[it2].bowling.average);
        }
    }
    fclose(fp147);
}

void pirnt(void)
{
    int it=0,it2=0;
    for(it=0; it<6; ++it)
    {
        if(it==6 && strcmp(team[6].name,"\0")==0)
        {
            break ;
        }
        printf("@*@*@*@*@*@*@*@     TEAM    *@*@*@*@*@*@*@*@*@*\n");
        printf("Team:%s\n",team[it].name);
        printf("Owner:\n%s\n",team[it].owner);
        printf("Rank:\n%s\n",team[it].rank);
        printf("Estimated worth:\n%s\n",team[it].worth);
        printf("Match:\n%s\n",team[it].match);
        printf("Match won:\n%s\n",team[it].won);
        printf("Match lost:\n%s\n",team[it].lost);
        printf("\n@@@@@@@@@@@@@@  Player's Database @@@@@@@@@@@\n");

        for(it2=0; it2<16; it2++)
        {
            printf("\n !!!!!!!!!!!!!!!  PLAYER  !!!!!!!!!!!!!\n");
            printf("Name:\n%s\n",team[it].plist[it2].name);
            printf("Country:\n%s\n",team[it].plist[it2].country);
            printf("Role:\n%s\n",team[it].plist[it2].role);

            printf("Batting innings:%d\nRun:\n%d\n",team[it].plist[it2].batting.match,team[it].plist[it2].batting.run);

            printf("Fifty:\n%d\nBest batting:\n%d\n",team[it].plist[it2].batting.fifty,team[it].plist[it2].batting.best);

            printf("Batting average:\n%.2f\nStrike rate:\n%.2f\n",team[it].plist[it2].batting.average,team[it].plist[it2].batting.strike_rate);

            printf("Bowling innings:\n%d\nWickets:\n%d\nfiveW:\n%d\nBest Bowling:\n%s\n",team[it].plist[it2].bowling.match,team[it].plist[it2].bowling.wicket,team[it].plist[it2].bowling.fiveW,team[it].plist[it2].bowling.best);

            printf("Bowling economy:\n%.2f\nBowling average:\n%.2f\n",team[it].plist[it2].bowling.economy,team[it].plist[it2].bowling.average);

        }
    }
    return ;
}

void searchdisplay(void)
{
    printf("Enter player name to search:\n");
    char str[100];
    fgets(str,sizeof str,stdin);
    int i,j,flag=0;
    for(i=0; i<7; i++)
    {
        for(j=0; j<16; j++)
        {
            if(!strcmp(str,team[i].plist[j].name))
            {
                printf("Player is found\n");
                display(team[i].plist[j]);
                flag=-1;
                break;

            }
        }
        if(flag==-1)
        {
            break;
        }
    }
}

void display(struct Player p)
{
    printf("\n\n@@@@@@@@@     Player Statistics    *********\n\n");
    printf("Name:%s\n",p.name);
    printf("Country:%s\n",p.country);
    printf("Role:%s\n",p.role);

    printf("Run:%d\n\n",p.batting.run);

    printf("Fifty:%d\n\nBest:%d\n\n",p.batting.fifty,p.batting.best);

    printf("Batting average:%.2f\n\nStrike rate:%.2f\n\n",p.batting.average,p.batting.strike_rate);

    printf("Wicket:%d\n\nFiveW:%d\n\n",p.bowling.wicket,p.bowling.fiveW);

    printf("Economy:%.2f\n\nBowling average:%.2f\n\n",p.bowling.economy,p.bowling.average);

}


void search_team(int year)
{
    int i,ch,loop=0;
    if(year==2015)
    {
        loop=7;
    }
    else if(year==2013)
    {
        loop=8;
    }

    for(i=0; i<loop-1; i++)
    {
        printf("(%d)%s\n",i+1,team[i].name);
    }

    printf("Please select a team(1 to last):\n");
    scanf("%d",&ch);

    if(ch>0 && ch <loop)
    {
        team_display(team[ch-1]);
    }
}

void team_display(struct Team T)
{
    printf("@@@@@@******@@@@@@********\n");
    printf("Team Name:\n");
    puts(T.name);
    printf("Team Rank:\n");
    puts(T.rank);
    printf("Team owner:\n");
    puts(T.owner);
    printf("Team worth:\n");
    puts(T.worth);
    printf("Match Played:\n");
    puts(T.match);
    printf("Match won:\n");
    puts(T.won);
    printf("Match lost:\n");
    puts(T.lost);
}

void standing(int year)
{
    FILE *fp;
    if(year==2015)
    {
        fp=fopen("team_standing-2015.txt","r");
    }
    if(year==2013)
    {
        fp=fopen("team_standing-2013.txt","r");
    }
    char ch;
    printf("\n BPL  %d Team Standing\n",year);
    while((ch=fgetc(fp))!=EOF)
    {
        putchar(ch);
    }
}

void select_show(void)
{
    printf("\n");
    printf("#####   You can select any player from any team");
    printf(" and see his performance   @@@@@@\n\n");
    int i,a,b;
    while(1)
    {

        printf("Select a team, press any of(1 to last)\n");
        for(i=0; i<7; i++)
        {
            if(i==6 && strcmp(team[6].name,"\0")==0)
            {
                break ;
            }
            printf("(%d) %s\n",i+1,team[i].name);
        }
        scanf("%d",&a);
        getchar();
        if(a>0 && a<8)
        {
            printf("Select the desired player(1 to 16)\n");
            for(i=0; i<16; i++)
            {
                printf("(%d) %s\n",i+1,team[a-1].plist[i].name);
            }
            scanf("%d",&b);
            getchar();
            if(b>0 && b<17)
            {
                display(team[a-1].plist[b-1]);
            }
        }
        else
        {
            continue ;
        }
        printf("\nDo you want to continue seeing ?\n");
        printf("(press 'y' for yes and 'n' for no.\n)");
        char c;
        c=getchar();
        if(c=='y' || c=='Y')
        {
            continue;
        }
        else
        {
            break;
        }
    }
}
