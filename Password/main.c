#include <stdio.h>
#include <stdlib.h>

void passwordGenerator(int ,int );
void passwordGenerator_r(char *,int *,int *,int ,int,int,int,int);

int main()
{

    int nrep=2;
    int lengthOfPass=5;

     passwordGenerator(nrep,lengthOfPass);

    return 0;
}

void passwordGenerator(int nr,int len)
{
    int nc=3;
    int ni=2;
    char* sol =(char*)malloc(sizeof(char)*len);
    if(sol==NULL)
    {
        printf("ERROR MEMORY ALLOCATION \n");
        exit(EXIT_FAILURE);

    }

    int* mark1 =(int *)calloc(10,sizeof(int));
    if(mark1==NULL)
    {
        printf("ERROR MEMORY ALLOCATION \n");
        exit(EXIT_FAILURE);

    }
     int* mark2 =(int *)calloc(27,sizeof(int));
    if(mark2==NULL)
    {
        printf("ERROR MEMORY ALLOCATION \n");
        exit(EXIT_FAILURE);

    }
    passwordGenerator_r(sol,mark1,mark2,nr,len,nc,ni,0);


}


void passwordGenerator_r(char *sol,int *mark1,int *mark2,
                         int nr,int len,int nc,int ni,int level)

{

    if(level==len)
    {
        int i;
        for(i=0;i<len;i++)
        {
            printf("%c ",sol[i]);

        }
            printf("\n");

    }

    else if(level<nc)
    {   int j;
        for(j=0;j<26;j++)
        {

        if(mark2[j]<2)
        {
            mark2[j]++;
            sol[level]=(char)(((int)'A')+j);
            passwordGenerator_r(sol,mark1,mark2,nr,len,nc,ni,level+1);
            mark2[j]--;
        }
        }
    }

    else {
        int i;
        for(i=0;i<10;i++)
        {

        if(mark1[i]<2)
        {
            mark1[i]++;
            sol[level]=(char)(((int)'0')+i);;
            passwordGenerator_r(sol,mark1,mark2,nr,len,nc,ni,level+1);
            mark1[i]--;
        }
        }
    }


}
