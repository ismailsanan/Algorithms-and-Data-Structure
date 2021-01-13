#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t
{
    float key;
    int r;
    int c;
    struct Node_t* next;
}Node_t;

typedef struct Matr_t
{
    int nr;
    int nc;
    struct Node_t **a;


}Matr_t;
void listMatprint_h(Node_t*,/*float**matrix*/float ***,int ,int);
void printlist(Matr_t* mat,int);
void listMatprint(Matr_t*,float **,int ,int);
void mat_insert(Matr_t *mat,int r ,int n, float value);
Node_t* createNode(float value ,int r ,int c);
void printMatrix(float**,int ,int);

int main()
{
    int nr=5;
    int nc=5;
    int i,j;
    float **matrix =(float **)malloc(sizeof(float*)*nr);
    if(matrix==NULL)
    {
        printf("ERROR MEMORY ALLOCATION \n");
        exit(EXIT_FAILURE);
    }

    for(i=0;i<nr;i++)
    {
        matrix[i]=(float *)malloc(sizeof(float)*nc);
        if(matrix[i]==NULL)
    {
        printf("ERROR MEMORY ALLOCATION \n");
        exit(EXIT_FAILURE);
    }
    }

    for(i=0;i<nr;i++)
    {
        for(j=0;j<nc;j++)
        {
            matrix[i][j]=0;
        }
    }

    Matr_t* mat=(Matr_t*)malloc(sizeof(Matr_t));
    if(mat==NULL)
    {
        printf("ERROR MEMORY ALLOCATION \n");
        exit(EXIT_FAILURE);
    }

    mat->a=(Node_t*)malloc(sizeof(Node_t)*nr);
    mat->nc=nc;
    mat->nr=nr;

    for(i=0;i<nr;i++)

{
    mat->a[i]=NULL;
}
    mat_insert(mat,0,0,3);
    mat_insert(mat,2,0,1);
    mat_insert(mat,2,4,4);
    mat_insert(mat,3,1,23);
    mat_insert(mat,4,1,21);
    mat_insert(mat,4,2,21);


    printlist(mat,nr);
    listMatprint(mat,matrix,nr,nc);
    printMatrix(matrix,nr,nc);
    return 0;
}

void mat_insert(Matr_t *mat,int r ,int c, float value)
{

    if(value == 0)
    {
        return;
    }

    else
    {
        int i;
        Node_t* node;


        for(i=0;i<mat->nr;i++)
        {

            if(r==i)
            {
                if(mat->a[i]==NULL)
                {
                    node=createNode(value,r,c);
                    mat->a[i]=node;
                }
                else
                {
                    Node_t* p=mat->a[i];
                    node=createNode(value,r,c);

                    while(p->next!=NULL && (c>p->c))
                    {
                        p=p->next;
                    }
                    node->next=p->next;
                    p->next=node;

                }
            }
        }
    }





}

Node_t* createNode(float value ,int r ,int c)
{

    Node_t* p =(Node_t*)malloc(sizeof(Node_t));

    if(p==NULL)
    {
        printf("ERROR MEMORY ALLOCATION \n");
        exit(EXIT_FAILURE);
    }

    p->key=value;
    p->c=c;
    p->r=r;
    p->next=NULL;

    return p;

}

void printlist(Matr_t* mat,int r)
{
    int j;

       for(j=0;j<mat->nr;j++)
        {
            Node_t *ptr=mat->a[j];

           printf("%d ROW MATRIX :\n",j);

            while(ptr!=NULL)
            {

                printf("%.1f of row %d and column %d\n",ptr->key,ptr->r,ptr->c);
                ptr=ptr->next;
            }

        }

        printf("\n");



}
void listMatprint(Matr_t* mat,float **matrix,int r ,int c)
{
    int i;

    for(i=0;i<mat->nr;i++)
    {
         Node_t *ptr=mat->a[i];

            while(ptr!=NULL)
            {

                listMatprint_h(ptr,&matrix,r,c);
                ptr=ptr->next;
            }


    }

}
void listMatprint_h(Node_t* node,/*float**matrix*/float *** matrix,int r,int c)
{

    int i;
    int j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(node->r==i && node->c==j)
                //matrix[i][j]=node->key;
                (*matrix)[i][j]=node->key;
        }
    }



}

void printMatrix(float** matrix,int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%2.0f ",matrix[i][j]);
        }
        printf("\n");

}
}
