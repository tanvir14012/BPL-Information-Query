#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct bat
{
    int match,run,fifty,best;
    double average,strike_rate;
};
struct ball
{
    char *best;
    int match,wicket,fiveW;
    double economy,average;
};
struct Player
{
    char *name;
    char *country;
    char *role;
    struct bat *batting;
    struct ball *bowling;

};
struct Team
{
    char *name;
    char *owner;
    char *rank;
    char *worth;
    char *match;
    char *won;
    char *lost;
    struct Player *plist;
} *team;


void load_team(int year);
void search_team(int year);
void pirnt(int year);
void print_all(int year);
void searchdisplay(void);
void display(struct Player *p);
void team_display(struct Team *T);
void standing(int year);
void player_prediction(int key);
void Free(struct Team *team,int year);



void load_team(int year)
{
    int q,b;
    team=(struct Team *) calloc(7,sizeof(struct Team));
    if(team==NULL)
    {
        printf("Bad allocation::team\n");
        return ;
    }
    for(q=0; q<7; q++)
    {
        (team+q)->name=( char*) malloc(sizeof(char)*100);
        (team+q)->owner=( char*) malloc(sizeof(char)*100);
        (team+q)->rank=( char*) malloc(sizeof(char)*100);
        (team+q)->worth=( char*) malloc(sizeof(char)*100);
        (team+q)->match=( char*) malloc(sizeof(char)*100);
        (team+q)->won=( char*) malloc(sizeof(char)*100);
        (team+q)->lost=( char*) malloc(sizeof(char)*100);
        (team+q)->plist=(struct Player *) calloc(16,sizeof(struct Player));
        for(b=0; b<16; b++)
        {
            (((team+q)->plist)+b)->name=( char*) malloc(sizeof(char)*100);
            (((team+q)->plist)+b)->country=( char*) malloc(sizeof(char)*100);
            (((team+q)->plist)+b)->role=( char*) malloc(sizeof(char)*100);
            (((team+q)->plist)+b)->batting=(struct bat *) malloc(sizeof(struct bat));
            (((team+q)->plist)+b)->bowling=(struct ball *) malloc(sizeof(struct ball));
            ((((team+q)->plist)+b)->bowling)->best=(char*) malloc(sizeof(char)*100);
        }
    }


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
    char *str=(char *)calloc(100,sizeof(char));
    //char *str1=(char *)calloc(100,sizeof(char));
    for(it=0; it<7; ++it)
    {
        if((year==2015) && (it==6))
        {
            break ;
        }
        fflush(stdin);
        fgets((team+it)->name,_msize((team+it)->name),fp147);
        fgets((team+it)->owner,_msize((team+it)->owner),fp147);
        fgets((team+it)->rank,_msize((team+it)->rank),fp147);
        fgets((team+it)->worth,_msize((team+it)->worth),fp147);
        fgets((team+it)->match,_msize((team+it)->match),fp147);
        fgets((team+it)->won,_msize((team+it)->won),fp147);
        fgets((team+it)->lost,_msize((team+it)->lost),fp147);

        for(it2=0; it2<16; it2++)
        {
            fgets((((team+it)->plist)+it2)->name,_msize((((team+it)->plist)+it2)->name),fp147);
            fgets((((team+it)->plist)+it2)->country,_msize((((team+it)->plist)+it2)->country),fp147);
            fgets((((team+it)->plist)+it2)->role,_msize((((team+it)->plist)+it2)->role),fp147);
            fgets(str,_msize(str),fp147);
            sscanf(str,"%d%d",&(((team+it)->plist)+it2)->batting->match,&(((team+it)->plist)+it2)->batting->run);
            fgets(str,_msize(str),fp147);
            sscanf(str,"%d%d",&(((team+it)->plist)+it2)->batting->fifty,&(((team+it)->plist)+it2)->batting->best);
            fgets(str,_msize (str),fp147);
            sscanf(str,"%lf%lf",&(((team+it)->plist)+it2)->batting->average,&(((team+it)->plist)+it2)->batting->strike_rate);
            fgets(str,_msize (str),fp147);
            sscanf(str,"%s%d%d%d",(((team+it)->plist)+it2)->bowling->best,&(((team+it)->plist)+it2)->bowling->match,&(((team+it)->plist)+it2)->bowling->wicket,&(((team+it)->plist)+it2)->bowling->fiveW);
            fgets(str,_msize (str),fp147);
            sscanf(str,"%lf%lf",&(((team+it)->plist)+it2)->bowling->economy,&(((team+it)->plist)+it2)->bowling->average);
        }
    }
    fclose(fp147);
    free(str);
//    free(str1);
}

void pirnt(int year)
{
    int it=0,it2=0;
    fflush(stdin);

    FILE *fp;
    if(year==2015) fp=fopen("Entire Record-2015","w+");
    else if(year==2013) fp=fopen("Entire Record-2013","w+");

    for(it=0; it<7; ++it)
    {
        if(it==6 && strcmp((team+it)->name,"\0")==0)
        {
            break ;
        }
        fprintf(fp,"@*@*@*@*@*@*@*@     TEAM    *@*@*@*@*@*@*@*@*@*\n");
        fprintf(fp,"Team:%s\n",(team+it)->name);
        fprintf(fp,"Owner:\n%s\n",(team+it)->owner);
        fprintf(fp,"Rank:\n%s\n",(team+it)->rank);
        fprintf(fp,"Estimated worth:\n%s\n",(team+it)->worth);
        fprintf(fp,"Match:\n%s\n",(team+it)->match);
        fprintf(fp,"Match won:\n%s\n",(team+it)->won);
        fprintf(fp,"Match lost:\n%s\n",(team+it)->lost);
        fprintf(fp,"\n@@@@@@@@@@@@@@  Player's Database @@@@@@@@@@@\n");

        for(it2=0; it2<16; it2++)
        {
            fprintf(fp,"\n !!!!!!!!!!!!!!!  PLAYER  !!!!!!!!!!!!!\n");

            fprintf(fp,"Name:\n%s\n",(((team+it)->plist)+it2)->name);
            fprintf(fp,"Country:\n%s\n",(((team+it)->plist)+it2)->country);
            fprintf(fp,"Role:\n%s\n",(((team+it)->plist)+it2)->role);

            fprintf(fp,"Batting innings:%d\nRun:\n%d\n",(((team+it)->plist)+it2)->batting->match,(((team+it)->plist)+it2)->batting->run);

            fprintf(fp,"Fifty:\n%d\nBest batting:\n%d\n",(((team+it)->plist)+it2)->batting->fifty,(((team+it)->plist)+it2)->batting->best);

            fprintf(fp,"Batting average:\n%.2lf\nStrike rate:\n%.2lf\n",(((team+it)->plist)+it2)->batting->average,(((team+it)->plist)+it2)->batting->strike_rate);

            fprintf(fp,"Bowling innings:\n%d\nWickets:\n%d\n",(((team+it)->plist)+it2)->bowling->match,(((team+it)->plist)+it2)->bowling->wicket);

            fprintf(fp,"FiveW:\n%d\nBest Bowling:\n%s\n",(((team+it)->plist)+it2)->bowling->fiveW,(((team+it)->plist)+it2)->bowling->best);
            fprintf(fp,"Bowling economy:\n%.2lf\nBowling average:\n%.2lf\n",(((team+it)->plist)+it2)->bowling->economy,(((team+it)->plist)+it2)->bowling->average);

        }
    }
    fclose(fp);
    return ;
}

void print_all(int year)
{
    FILE *fp;
    if(year == 2015)
    {
        fp=fopen("Entire Record-2015","r");
    }
    else if(year==2013)
    {
        fp=fopen("Entire Record-2013","r");
    }
    printf("Entire record of BPL-%d\n________***________\n",year);
    char ch;
    while((ch=fgetc(fp))!=EOF)
    {
        putchar(ch);
    }
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
            if(!strcmp(str,(((team+i)->plist)+j)->name))
            {
                printf("Player is found\n");
                display(((team+i)->plist)+j);
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

void display(struct Player *p)
{
    printf("\n\n@@@@@@@@@     Player Statistics    *********\n\n");
    printf("Name:%s\n",p->name);
    printf("Country:%s\n",p->country);
    printf("Role:%s\n",p->role);
    printf("Match:%d\n",p->batting->match);
    printf("Run:%d\n\n",p->batting->run);

    printf("Fifty:%d\n\nBest:%d\n\n",p->batting->fifty,p->batting->best);

    printf("Batting average:%.2f\n\nStrike rate:%.2f\n\n",p->batting->average,p->batting->strike_rate);

    printf("Wicket:%d\n\nFiveW:%d\n\n",p->bowling->wicket,p->bowling->fiveW);

    printf("Economy:%.2f\n\nBowling average:%.2f\n\n",p->bowling->economy,p->bowling->average);
    printf("Bowling best=%s\n",p->bowling->best);

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
        printf("(%d)%s\n",i+1,(team+i)->name);
    }

    printf("Please select a team(1 to last):\n");
    scanf("%d",&ch);

    if(ch>0 && ch <loop)
    {
        team_display((team+ch-1));
    }
}

void team_display(struct Team *T)
{
    printf("@@@@@@******@@@@@@********\n");
    printf("Team Name:\n");
    puts(T->name);
    printf("Team Rank:\n");
    puts(T->rank);
    printf("Team owner:\n");
    puts(T->owner);
    printf("Team worth:\n");
    puts(T->worth);
    printf("Match Played:\n");
    puts(T->match);
    printf("Match won:\n");
    puts(T->won);
    printf("Match lost:\n");
    puts(T->lost);
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
            if(i==6 && strcmp((team+6)->name,"\0")==0)
            {
                break ;
            }
            printf("(%d) %s\n",i+1,(team+i)->name);
        }
        scanf("%d",&a);
        getchar();
        if(a>0 && a<8)
        {
            while(1)
            {
                printf("$$$$$$$$  Team Squad  $$$$$$$$\n");
                for(i=0; i<16; i++)
                {
                    printf("(%d) %s\n",i+1,(((team+a-1)->plist)+i)->name);
                }
                printf("+@+@+@  Select the desired player +@+@+@ \n Please press the accociated number (1 to 16)...\n");
                scanf("%d",&b);
                getchar();
                if(b>0 && b<17)
                {
                    display((((team+a-1)->plist)+b-1));
                }
                printf("Press b to _________GO BACK\n");
                printf("Press c to _________CONTINUE\n");
                char w;
                w=getchar();
                getchar();
                if(w=='b'||w=='B')
                {
                    break ;
                }
            }


        }
        printf("\nDo you want to continue exploring other Teams?\n");
        printf("(press 'y' for yes and 'n' for no.\n)");
        char c;
        c=getchar();
        getchar();
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

void player_prediction(int key)
{


    int i,b,j;
    FILE *fp;
    load_team(2015);

    struct Player *b1=(struct Player *) calloc(96,sizeof(struct Player));
    if(b1==NULL)
    {
        printf("Bad allocation::b1\n");
        return ;
    }

    for(b=0; b<96; b++)
    {
        (b1+b)->name=( char*) malloc(sizeof(char)*100);
        (b1+b)->country=( char*) malloc(sizeof(char)*100);
        (b1+b)->role=( char*) malloc(sizeof(char)*100);
        (b1+b)->batting=(struct bat *) malloc(sizeof(struct bat));
        (b1+b)->bowling=(struct ball *) malloc(sizeof(struct ball));
        ((b1+b)->bowling)->best=(char*) malloc(sizeof(char)*100);

    }


    j=0;
    for(i=0; i<6; i++)
    {
        memcpy(b1+j,((team+i)->plist),_msize(((team+i)->plist)));
        j+=16;
    }



//    for(b=0; b<96; b++)
//        display(b1+b);

    load_team(2013);
    struct Player *b2=(struct Player *) calloc(112,sizeof(struct Player));
    if(b2==NULL)
    {
        printf("Bad allocation::b2\n");
        return ;
    }

    for(b=0; b<112; b++)
    {
        (b2+b)->name=( char*) malloc(sizeof(char)*100);
        (b2+b)->country=( char*) malloc(sizeof(char)*100);
        (b2+b)->role=( char*) malloc(sizeof(char)*100);
        (b2+b)->batting=(struct bat *) malloc(sizeof(struct bat));
        (b2+b)->bowling=(struct ball *) malloc(sizeof(struct ball));
        ((b2+b)->bowling)->best=(char*) malloc(sizeof(char)*100);

    }
    j=0;
    for(i=0; i<7; i++)
    {
        memcpy(b2+j,((team+i)->plist),_msize(((team+i)->plist)));
        j+=16;
    }

//    for(b=0; b<112; b++)
//        display(b2+b);


    struct Player *b3=(struct Player *) calloc(220,sizeof(struct Player));
    if(b3==NULL)
    {
        printf("Bad allocation::b3\n");
        return ;
    }

    for(b=0; b<220; b++)
    {
        (b3+b)->name=( char*) malloc(sizeof(char)*100);
        (b3+b)->country=( char*) malloc(sizeof(char)*100);
        (b3+b)->role=( char*) malloc(sizeof(char)*100);
        (b3+b)->batting=(struct bat *) malloc(sizeof(struct bat));
        (b3+b)->bowling=(struct ball *) malloc(sizeof(struct ball));
        ((b3+b)->bowling)->best=(char*) malloc(sizeof(char)*100);

    }
//printf("_____________%d\n",_msize(b1));
    memcpy(b3,b1,460*96);
//    memcpy(b3+96,b2,_msize(b2));
//    for(b=0; b<96+112; b++)
//    {
//        display(b3+b);
//    }


    for(i=0; i<112; i++)
    {
        for(j=0; j<96; j++)
        {
            if((strcmp((b2+i)->name,(b3+j)->name))==0)
            {
                ((b3+j)->batting->average)+=((b2+i)->batting->average);
                ((b3+j)->batting->average)/=2.00;

                ((b3+j)->batting->strike_rate)+=((b2+i)->batting->strike_rate);
                ((b3+j)->batting->strike_rate)/=2.00;

                ((b3+j)->batting->run)+=((b2+i)->batting->run);

                ((b3+j)->batting->match)+=((b2+i)->batting->match);

                ((b3+j)->bowling->match)+=((b2+i)->bowling->match);
                ((b3+j)->bowling->economy)+=((b2+i)->bowling->economy);
                ((b3+j)->bowling->economy)/=2.00;
                ((b3+j)->bowling->wicket)+=((b2+i)->bowling->wicket);
                strcpy((b2+i)->name,"NULL");

            }

        }
    }

    int ct=96;

    for(i=0; i<112; i++)
    {
        if(strcmp((b2+i)->name,"NULL")!=0)
        {
            memcpy(b3+ct,(b2+i),460);
            ct++;
        }
    }


//    for(i=0; i<ct; i++)
//    {
//        display(b3+i);
//    }
    //printf("Total Distinct Players=%d\n",ct-1);


    //printf("here");
    if(key==1)
    {

        for(i=0; i<ct; i++)
        {
            for(j=0; j<ct-i-i; j++)
            {
                if(((b3+j)->batting->average)  <  ((b3+j+1)->batting->average)  &&
                        ((b3+j)->batting->match)  <  ((b3+j+1)->batting->match)      &&
                        ((b3+j)->batting->strike_rate)  <  ((b3+j+1)->batting->strike_rate)  )
                {
                    struct Player *temp=(struct Player *) calloc(1,sizeof(struct Player));
                    temp->name=( char*) malloc(sizeof(char)*100);
                    temp->country=( char*) malloc(sizeof(char)*100);
                    temp->role=( char*) malloc(sizeof(char)*100);
                    temp->batting=(struct bat *) malloc(sizeof(struct bat));
                    temp->bowling=(struct ball *) malloc(sizeof(struct ball));
                    (temp->bowling)->best=(char*) malloc(sizeof(char)*100);
                    memcpy(temp,b3+j,_msize(temp));
                    memcpy(b3+j,b3+j+1,_msize(temp));
                    memcpy(b3+j+1,temp,_msize(temp));
                    free(temp);
                }

                else if(((b3+j)->batting->average)  <  ((b3+j+1)->batting->average)  &&
                        ((b3+j)->batting->match)  <  ((b3+j+1)->batting->match) )
                {
                    struct Player *temp=(struct Player *) calloc(1,sizeof(struct Player));
                    temp->name=( char*) malloc(sizeof(char)*100);
                    temp->country=( char*) malloc(sizeof(char)*100);
                    temp->role=( char*) malloc(sizeof(char)*100);
                    temp->batting=(struct bat *) malloc(sizeof(struct bat));
                    temp->bowling=(struct ball *) malloc(sizeof(struct ball));
                    (temp->bowling)->best=(char*) malloc(sizeof(char)*100);
                    memcpy(temp,b3+j,_msize(temp));
                    memcpy(b3+j,b3+j+1,_msize(temp));
                    memcpy(b3+j+1,temp,_msize(temp));
                    free(temp);
                }

                else if (((b3+j)->batting->average)  <  ((b3+j+1)->batting->average) )
                {
                    struct Player *temp=(struct Player *) calloc(1,sizeof(struct Player));
                    temp->name=( char*) malloc(sizeof(char)*100);
                    temp->country=( char*) malloc(sizeof(char)*100);
                    temp->role=( char*) malloc(sizeof(char)*100);
                    temp->batting=(struct bat *) malloc(sizeof(struct bat));
                    temp->bowling=(struct ball *) malloc(sizeof(struct ball));
                    (temp->bowling)->best=(char*) malloc(sizeof(char)*100);
                    memcpy(temp,b3+j,_msize(temp));
                    memcpy(b3+j,b3+j+1,_msize(temp));
                    memcpy(b3+j+1,temp,_msize(temp));
                    free(temp);
                }


            }
        }

        fp=fopen("prediction-1","w");
        fprintf(fp,"@@@@@@@@@@@@@@@@@@@____________________________******************\n");
        fprintf(fp,"@@_________________PROMISING BATSMANS FOR BPL 2016_________________\n\n");
        for(i=0; i<10; i++)
        {
            fprintf(fp,"@@@_____Precedence Rank:%d_____@@@\n\n",i+1);
            fprintf(fp,"__________________________________\n");
            fprintf(fp,"Name:%s\n",(b3+i)->name);
            fprintf(fp,"Country:%s\n",(b3+i)->country);
            fprintf(fp,"Role:%s\n",(b3+i)->role);
            fprintf(fp,"Match:%d\n",(b3+i)->batting->match);
            fprintf(fp,"Run:%d\n\n",(b3+i)->batting->run);

            fprintf(fp,"Fifty:%d\n\nBest:%d\n\n",(b3+i)->batting->fifty,(b3+i)->batting->best);

            fprintf(fp,"Batting average:%.2f\n\nStrike rate:%.2f\n\n",(b3+i)->batting->average,(b3+i)->batting->strike_rate);
        }
    }
    fclose(fp);
    if(key==1)
    {

        for(i=0; i<ct; i++)
        {
            for(j=0; j<ct-i-i; j++)
            {

                if(((b3+j)->bowling->economy)  >  ((b3+j+1)->bowling->economy)  &&
                        ((b3+j)->bowling->match)  <  ((b3+j+1)->bowling->match)      &&
                        ((b3+j)->bowling->wicket)  <  ((b3+j+1)->bowling->wicket)  )
                {
                    struct Player *temp=(struct Player *) calloc(1,sizeof(struct Player));
                    temp->name=( char*) malloc(sizeof(char)*100);
                    temp->country=( char*) malloc(sizeof(char)*100);
                    temp->role=( char*) malloc(sizeof(char)*100);
                    temp->batting=(struct bat *) malloc(sizeof(struct bat));
                    temp->bowling=(struct ball *) malloc(sizeof(struct ball));
                    (temp->bowling)->best=(char*) malloc(sizeof(char)*100);
                    memcpy(temp,b3+j,_msize(temp));
                    memcpy(b3+j,b3+j+1,_msize(temp));
                    memcpy(b3+j+1,temp,_msize(temp));
                    free(temp);
                }

                else if(((b3+j)->bowling->economy)  >  ((b3+j+1)->bowling->economy)  &&
                        ((b3+j)->bowling->average)  >  ((b3+j+1)->bowling->average) )
                {
                    struct Player *temp=(struct Player *) calloc(1,sizeof(struct Player));
                    temp->name=( char*) malloc(sizeof(char)*100);
                    temp->country=( char*) malloc(sizeof(char)*100);
                    temp->role=( char*) malloc(sizeof(char)*100);
                    temp->batting=(struct bat *) malloc(sizeof(struct bat));
                    temp->bowling=(struct ball *) malloc(sizeof(struct ball));
                    (temp->bowling)->best=(char*) malloc(sizeof(char)*100);
                    memcpy(temp,b3+j,_msize(temp));
                    memcpy(b3+j,b3+j+1,_msize(temp));
                    memcpy(b3+j+1,temp,_msize(temp));
                    free(temp);
                }

                else if (((b3+j)->bowling->wicket)  <  ((b3+j+1)->bowling->wicket) )

                {
                    struct Player *temp=(struct Player *) calloc(1,sizeof(struct Player));
                    temp->name=( char*) malloc(sizeof(char)*100);
                    temp->country=( char*) malloc(sizeof(char)*100);
                    temp->role=( char*) malloc(sizeof(char)*100);
                    temp->batting=(struct bat *) malloc(sizeof(struct bat));
                    temp->bowling=(struct ball *) malloc(sizeof(struct ball));
                    (temp->bowling)->best=(char*) malloc(sizeof(char)*100);
                    memcpy(temp,b3+j,_msize(temp));
                    memcpy(b3+j,b3+j+1,_msize(temp));
                    memcpy(b3+j+1,temp,_msize(temp));
                    free(temp);
                }


            }
        }
        ct=1;
        fp=fopen("prediction-2","w");
        fprintf(fp,"@@@@@@@@@@@@@@@@@@@____________________________******************\n");
        fprintf(fp,"@@_________________PROMISING BOWLERS FOR BPL 2016_________________\n\n");
        for(i=0; i<160; i++)
        {
            if((((strcmp((b3+i)->role,"Bowler\n"))==0)) || (((strcmp((b3+i)->role,"Bowling-allrounder\n"))==0)))
            {
                fprintf(fp,"@@@_____Precedence Rank:%d_____@@@\n\n",ct);
                fprintf(fp,"__________________________________\n");
                fprintf(fp,"Name:%s\n",(b3+i)->name);
                fprintf(fp,"Country:%s\n",(b3+i)->country);
                fprintf(fp,"Role:%s\n",(b3+i)->role);
                fprintf(fp,"Match Played:%d\n\n",(b3+i)->bowling->match);
                fprintf(fp,"Wicket:%d\n\n",(b3+i)->bowling->wicket);
                fprintf(fp,"Economy:%.2lf\n\nBowling average:%.2lf\n\n",(b3+i)->bowling->economy,(b3+i)->bowling->average);
                fprintf(fp,"Bowling best=%s\n",(b3+i)->bowling->best);
                ct++;
                if(ct==11)
                {
                    break ;
                }
            }
        }
    }
    fclose(fp);

//    free(b3);
//    free(b2);
//    free(b1);

    Free(team,2013);
    Free(team,2015);

}
void Free(struct Team *team,int year)
{
    //return ;
    int ct=0,q,b;
    if(year==2015)
    {
        ct=5;
    }
    else if(year==2013)
    {
        ct=6;
    }
    for(q=ct; q>=0; q--)
    {
        for(b=15; b>=0; b--)
        {
            free(((((team+q)->plist)+b)->bowling)->best);
            free((((team+q)->plist)+b)->bowling);
            free((((team+q)->plist)+b)->batting);
            free((((team+q)->plist)+b)->role);
            free((((team+q)->plist)+b)->country);
            free((((team+q)->plist)+b)->name);
        }
        free(((team+q)->plist));
        free((team+q)->lost);
        free((team+q)->won);
        free((team+q)->match);
        free((team+q)->worth);
        free((team+q)->rank);
        free((team+q)->owner);
        free((team+q)->name);
        free((team+q));
    }
    free(team);
    //printf("_____Freed\n");
}

