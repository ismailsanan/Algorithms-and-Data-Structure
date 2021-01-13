#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


typedef struct list_t
{
    char *dealer;
    int price;
    struct list_t* other ;

} list_t;

typedef struct list_t2
{
    int best;
    char *name;
    char *model;
    struct list_t2* next;


} list_t2;



typedef struct node_t
{
    char *model;
    struct node_t* left;
    struct node_t* right;
    struct list_t* charac;

} node_t;

list_t* insertList(list_t* head,char* dealer,int price);
void bst2list(node_t*,list_t2**);
node_t* insertTree(node_t *,char *,list_t*);
node_t* newNode(char*,list_t*);
list_t* newList(char*,int);
void printfInTree(node_t* root);
void printfList(list_t*);
list_t2* newList2(list_t2**,node_t*);
void printfList2(list_t2*);
void splitList(list_t2**,int,list_t2**,list_t2**);

int main()
{
    node_t* root=NULL;
    list_t* BMW =NULL;
    BMW=insertList(BMW,"AHMAD",30);
    BMW=insertList(BMW,"KAMAL",21);
    BMW=insertList(BMW,"EL ZEIN",42);

    list_t* FIAT =NULL;
    FIAT=insertList(FIAT,"HASSAN",23);
    FIAT=insertList(FIAT,"KHALIL",36);
    FIAT=insertList(FIAT,"ZIAD",12);
    FIAT=insertList(FIAT,"ABED",35);

    list_t* MERCEDES=NULL;
    MERCEDES=insertList(MERCEDES,"ALI",16);
    MERCEDES=insertList(MERCEDES,"DAWOOD",28);
    MERCEDES=insertList(MERCEDES,"MAHDI",39);

    list_t* AMG =NULL;
    AMG=insertList(AMG,"ZOLFIKAR",114);
    AMG=insertList(AMG,"OKAB",100);
    AMG=insertList(AMG,"ZIAETER",134);

    root=insertTree(root,"BMW",BMW);
    insertTree(root,"FIAT",FIAT);
    insertTree(root,"MERCEDES",MERCEDES);
    insertTree(root,"AMG",AMG);

    printfInTree(root);
    printf("\n");
    printf("\n");
    printf("BMW");
    printfList(BMW);
    printf("\n");
    printf("MERCEDES");
    printfList(MERCEDES);
    printf("\n");
    printf("FIAT");
    printfList(FIAT);

    list_t2* list2=(list_t2*)malloc(sizeof(list_t2));
    if(list2==NULL)
    {
        printf("ERROR MEMORY ALLOCATION\n");
        exit(EXIT_FAILURE);
    }
    list2=NULL;
    bst2list(root,&list2);
    printfList2(list2);
    list_t2 *original=(list_t2*)malloc(sizeof(list_t2));
    if(original==NULL)
    {
        printf("ERROR MEMORY ALLOCATION\n");
        exit(EXIT_FAILURE);
    }

    list_t2* part1=(list_t2*)malloc(sizeof(list_t2));
    if(part1==NULL)
    {
        printf("ERROR MEMORY ALLOCATION\n");
        exit(EXIT_FAILURE);
    }


    list_t2* part2=(list_t2*)malloc(sizeof(list_t2));
    if(part2==NULL)
    {
        printf("ERROR MEMORY ALLOCATION\n");
        exit(EXIT_FAILURE);
    }
    original=list2;
    part2=NULL;
    part1=NULL;

   splitList(&original,18,&part1,&part2);
 //  printfList2(original);
   printfList2(part1);
   printfList2(part2);

    return 0;
}

node_t* newNode(char* model ,list_t* charac)
{
    node_t* p=(node_t*)malloc(sizeof(node_t));
    if(p==NULL)
    {
        printf("ERROR MEMORY ALLOCATION\n");
        exit(EXIT_FAILURE);

    }

    p->model=strdup(model);
    p->left=NULL;
    p->right=NULL;
    p->charac=charac;

    return p;
}

list_t* newList(char *dealer , int price)

{

    list_t* p=(list_t*)malloc(sizeof(list_t));
    if(p==NULL)
    {
        printf("ERROR MEMORY ALLOCATION\n");
        exit(EXIT_FAILURE);

    }


    p->dealer=dealer;
    p->price=price;
    p->other=NULL;

    return p;


}

list_t* insertList(list_t* head,char* dealer,int price)
{

    if(head==NULL)
    {
        return newList(dealer,price);
    }

    if(price<head->price)
    {
        list_t* node=newList(dealer,price);
        node->other=head;
        head=node;
        return head;

    }

    else
    {
        list_t* p=head;

        while(p->other!=NULL && price>p->other->price)
        {

            p=p->other;
        }

        list_t* node=newList(dealer,price);
        node->other=p->other;
        p->other=node;

    }

    return head;

}



node_t* insertTree(node_t* root,char * model,list_t* charac)
{
    if(root==NULL)
    {
        return newNode(model,charac);

    }
    else
    {
        if(strcmp(model,root->model)>0)
        {
            root->right=insertTree(root->right,model,charac);
        }
        else
        {
            root->left=insertTree(root->left,model,charac);
        }


    }
    return root;
}



void printfInTree(node_t* root)
{

    if(root!=NULL)
    {
        printfInTree(root->left);
        printf("%s ",root->model);
        printfInTree(root->right);
    }



}

void printfList(list_t* model)

{
    list_t*p=model;
    printf(" MODEL HAS THESE OWNERS : \n");

    while(p!=NULL)
    {
        printf("%s %d\n",p->dealer,p->price);
        p=p->other;
    }


}

void bst2list(node_t* root ,list_t2** list2)
{

    if(root==NULL)
    {
        return;
    }


    bst2list(root->left,list2);


    if(*list2==NULL)
    {
        list_t2* p=(list_t2 *)malloc(sizeof(list_t2));
        if(p==NULL)
        {
            printf("ERROR MEMORY ALLOCATION\n");
            exit(EXIT_FAILURE);
        }

        p->best=root->charac->price;
        p->model=root->model;
        p->name=root->charac->dealer;
        p->next=NULL;

        *list2=p;

    }

    else
    {
        list_t2* ptr=*list2;
        list_t2* pt=newList2(list2,root);


        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }

        pt->next=ptr->next;
        ptr->next=pt;

    }



    bst2list(root->right,list2);

}

list_t2* newList2(list_t2 **list2,node_t* m)
{
    list_t2* p=(list_t2*)malloc(sizeof(list_t2));
    if(p==NULL)
    {
        printf("ERROR MEMORY ALLOCATION\n");
        exit(EXIT_FAILURE);
    }

    p->name=m->charac->dealer;
    p->best=m->charac->price;
    p->model=m->model;
    p->next=NULL;

    return p;
}

void printfList2(list_t2* list2)
{
    list_t2*p=list2;
    printf("\nBEST CARS SELLERS : \n");

    while(p!=NULL)
    {
        printf("%s %s %d\n",p->model,p->name,p->best);
        p=p->next;
    }


}

void splitList(list_t2** original,int thre ,list_t2** part1,list_t2** part2)
{
    list_t2* p=*original;

        while(p!=NULL)
        {

            if(p->best<thre)
            {
                if(*part1==NULL)
                {
                    list_t2* w=(list_t2*)malloc(sizeof(list_t2));
                    if(w==NULL)
                    {
                        printf("ERROR MEMORY ALLOCATION\n");
                        exit(EXIT_FAILURE);

                    }
                    w->best=p->best;
                    w->model=p->model;
                    w->name=p->name;
                    w->next=NULL;

                    *part1=w;

            }

                else
                {

                    list_t2* p1=*part1;
                    list_t2* w=(list_t2*)malloc(sizeof(list_t2));
                    if(w==NULL)
                    {
                        printf("ERROR MEMORY ALLOCATION\n");
                        exit(EXIT_FAILURE);

                    }

                    w->best=p->best;
                    w->model=p->model;
                    w->name=p->name;
                    w->next=NULL;

                    while(p1->next!=NULL)
                    {
                        p1=p1->next;
                    }
                    w->next=p1->next;
                    p1->next=w;

                }
            }
            else
            {
                if(*part2==NULL)
                {

                    list_t2* w=(list_t2*)malloc(sizeof(list_t2));
                    if(w==NULL)
                    {
                        printf("ERROR MEMORY ALLOCATION\n");
                        exit(EXIT_FAILURE);

                    }
                    w->best=p->best;
                    w->model=p->model;
                    w->name=p->name;
                    w->next=NULL;

                    *part2=w;

                }

                else
                {
                    list_t2* p2=*part2;
                   list_t2* w=(list_t2*)malloc(sizeof(list_t2));
                    if(w==NULL)
                    {
                        printf("ERROR MEMORY ALLOCATION\n");
                        exit(EXIT_FAILURE);

                    }

                    w->best=p->best;
                    w->model=p->model;
                    w->name=p->name;
                    w->next=NULL;

                   while(p2->next!=NULL)
                    {
                        p2=p2->next;
                    }
                    w->next=p2->next;
                    p2->next=w;

                }
            }

            p=p->next;

        }
        *original=p;
    }






