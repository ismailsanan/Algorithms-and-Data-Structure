#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data_s
{
    int n;
    char ***a;

}data_s;

void menu_create_r(char**,char***,int,int);
void menu_create(char *** ,int);
void printMat(char***a,int n);

int main()
{
    int n=3;
    int pri=5,sec=4,des=4;
    data_s *data=(data_s *)malloc(sizeof(data_s));

    if(data==NULL)
    {
        printf("ERROR MEMORY ALLOCATION ....\n");
        exit(EXIT_FAILURE);
    }
    data->n=n;
    data->a=(char***)malloc(sizeof(char**)*n);


        data->a[0]=(char**)malloc(sizeof(char*)*pri);
         if(data->a[0]==NULL)
    {
        printf("ERROR MEMORY ALLOCATION ....\n");
        exit(EXIT_FAILURE);
    }
        data->a[1]=(char**)malloc(sizeof(char*)*sec);
         if(data->a[1]==NULL)
    {
        printf("ERROR MEMORY ALLOCATION ....\n");
        exit(EXIT_FAILURE);
    }
     data->a[2]=(char**)malloc(sizeof(char*)*des);
         if(data->a[2]==NULL)
    {
        printf("ERROR MEMORY ALLOCATION ....\n");
        exit(EXIT_FAILURE);
    }

    data->a[0][0]="Duck_Salad";
    data->a[0][1]="Scotch_Egg";
    data->a[0][2]="Soupe_And_Bread";
    data->a[0][3]="Baby_Squid";
    data->a[0][4]="NULL";
    data->a[1][0]="Rabbit_And_Bacon";
    data->a[1][1]="Fish_And_Chips";
    data->a[1][2]="Roast_Lamb";
    data->a[1][3]="NULL";
    data->a[2][0]="Gateaux_Opera";
    data->a[2][1]="Ice_Cream";
    data->a[2][2]="Cheese_Cake";
    data->a[2][3]="NULL";



    printMat(data->a,n);
    menu_create(data->a,n);
    return 0;
}
 void printMat(char***a,int n)
{
    int i;
    int j;
    for(i=0;i<n;i++)
   {
           int co=0;

        for(j=0;;j++)
    {
        if(strcmp(a[i][j],"NULL")==0)
        break;

        else
        {
            co++;
            printf("%s ",a[i][j]);
        }

    }
        printf("THE LENGTH OF THE ARRAY IS : %d",co);
        printf("\n");

    }



}

void menu_create(char*** data,int n)
{
    char **sol=(char**)malloc(sizeof(char*)*n);

if(sol==NULL)
    {
        printf("ERROR MEMORY ALLOCATION ....\n");
        exit(EXIT_FAILURE);
    }

    menu_create_r(sol,data,n,0);

}

void menu_create_r(char **sol,char*** a,int n , int level )
{
    static int nsol=1;

    if(level==n)
    {
        int i;
        printf("MENU %d : ",nsol);
        for(i=0;i<n;i++)
        {
                printf("%s ",sol[i]);
        }
        nsol++;
        printf("\n");

    }

    else
        {
            int i=0;
            while(a[level][i]!="NULL")
                {
                sol[level]=a[level][i];
                menu_create_r(sol,a,n,level+1);
                i++;
                }

                                }


    }


