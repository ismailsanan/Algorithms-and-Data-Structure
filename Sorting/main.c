#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void InsertionSort(int *,int );
void BubbleSort(int *,int );
void SelectionSort(int *,int );
void ShellSort(int *,int);
void MergeSort(int*,int,int,int);
void merges(int *,int,int,int,int);
void CountingSort(int *,int,int);
void QuickSort(int*,int,int);
int  Partition(int *,int,int);
void Swap(int *,int,int);
void Heapify(int *,int,int );
void HeapSort(int *a,int );
void BuildHeap(int *a,int);
int* ArrayFill(int);
void PrintArray(int *,int );
int  GreatestFinder(int *,int);


int main ()
{


    int *a,m,greatest;
    char ch,ch1,sorting;

    printf("PLEASE CHOOSE THE DIMENSION OF YOUR ARRAY : \n");
    scanf("%d",&m);
    printf("PLEASE FILL YOUR ARRAY : \n");
    a=ArrayFill(m);
    printf("THIS IS YOUR UNSORTED ARRAY : \n");
    printf("\n");
    PrintArray(a,m);
    printf("\n");
    printf("PLEASE CHOOSE YOUR TYPE OF SORTING YOU WANT TO DO :\n");
    printf("\tINSERTION SORT ---------> (A)\n");
    printf("\tBUBBLE SORT ------------> (B)\n");
    printf("\tSELECTION SORT ---------> (C)\n");
    printf("\tSHELL SORT -------------> (D)\n");
    printf("\tCOUNTING SORT ----------> (E)\n");
    printf("\tMERGE SORT -------------> (F)\n");
    printf("\tQUICK SORT -------------> (G)\n");
    printf("\tHEAP  SORT -------------> (H)\n");

    scanf("%.*c",&ch1);

    scanf("%c",&ch);
    sorting=toupper(ch);

    switch(sorting)
    {

    case 'A':

        printf("INSERTION SORT ARRAY : \n");
        InsertionSort(a,m);
        break;

    case 'B' :

        printf("BUBBLE SORT ARRAY :  \n");
        BubbleSort(a,m);
        break;

    case 'C' :

        printf("SELECTION SORT ARRAY : \n");
        SelectionSort(a,m);
        break;

    case 'D' :

        printf("SHELL SORT ARRAY : \n" );
        ShellSort(a,m);
        break;

    case 'E' :

        printf("COUNTING SORT ARRAY : \n" );
        greatest=GreatestFinder(a,m);
        CountingSort(a,m,greatest);
        break;

    case 'F' :

        printf("MERGE SORT ARRAY : \n" );
        //we use m-1 so we will use 0--->7 not 8.
        MergeSort(a,0,m-1,m);
        PrintArray(a,m);
        break;

    case 'G' :

        printf("QUICK SORT ARRAY : \n" );
        QuickSort(a,0,m-1);
        PrintArray(a,m);
        break;

    case 'H' :

        printf("HEAP SORT ARRAY : \n" );
        //build heap must be inside the HeapSort
        //but i used it in this way so i can print the normal unsorted heap.
        BuildHeap(a,m);
        printf("THE UN-SORTED HEAP : \n" );
        PrintArray(a,m);
        HeapSort(a,m);
        printf("\n" );
        printf("THE SORTED HEAP : \n" );
        PrintArray(a,m);
        break;

    default :
        printf("Invalid grade\n" );
    }

    return 0;
}



void HeapSort(int *a,int heapsize)
{
    int i;

    for(i=heapsize-1; i>0; i--)
    {
        Swap(a,0,i);
        heapsize--;
        Heapify(a,0,heapsize);
    }
    return;
}


void BuildHeap(int *a,int heapsize)
{
    int i;

    for(i=heapsize/2-1; i>=0; i--)
    {
        Heapify(a,i,heapsize);
    }
    return;
}

void Heapify(int *a,int i,int heapsize)
{
    int l,r,largest;

    l=2*i+1;
    r=2*i+2;

    if(l<heapsize && a[l]>a[i])
        largest=l;
    else
        largest=i;
    if(r<heapsize && a[r]>a[largest])
        largest=r;

    if(largest!=i)
    {
        Swap(a,i,largest);
        Heapify(a,largest,heapsize);
    }
}


void QuickSort(int *a,int l,int r)
{
    int q;
    if(r<=l)
        return;

    q=Partition(a,l,r);

    QuickSort(a,l,q-1);
    QuickSort(a,q+1,r);

    return;
}

int Partition(int *a,int l,int r)
{
    int i,j;
    int x=a[r];

    i=l-1;
    j=r;

    for( ; ; )
    {
        while(a[++i]<x);
        while(a[--j]>x)
            if(j==l)
                break;

        if(i>=j)
            break;
        Swap(a,i,j);
    }

    Swap(a,i,r);
    return i;
}

void Swap(int* a,int i,int y)
{

    int tmp;

    tmp=a[i];
    a[i]=a[y];
    a[y]=tmp;

}

void MergeSort(int *a,int l,int r,int m)
{
    int q;

    if(r<=l)
        return;

    q=(l+r)/2;

    MergeSort(a,l,q,m);
    MergeSort(a,q+1,r,m);
    merges(a,l,q,r,m);

    return;
}

void merges(int *a,int l,int q,int r,int m)
{
    int i,j,k,b[m];

    i=l;
    j=q+1;

    for(k=l; k<=r; k++)
    {
        if(i>q)
        {
            b[k]=a[j++];
        }
        else if (j>r)
        {
            b[k]=a[i++];
        }
        else if (a[i]<=a[j])
        {
            b[k]=a[i++];
        }
        else
        {
            b[k]=a[j++];
        }

    }

    for(k=l; k<=r; k++)
    {
        a[k]=b[k];
    }

    return ;

}



int *ArrayFill(int m)

{
    int *b,i;
    b=malloc(m*sizeof(int));
    for(i=0; i<m; i++)
    {
        scanf("%d",&b[i]);

    }
    return b;
}
int GreatestFinder(int *a,int r)
{
    int i,maxi;
    maxi=0;

    for(i=0; i<r; i++)
    {
        if(a[i]>maxi)
            maxi=a[i];
    }

    return maxi;


}

void CountingSort(int *a,int r,int maxi)
{
    int i,n,j;
    int *b,*c;



    n=maxi+1;

    c = malloc(n * sizeof(int));

    b = malloc(r * sizeof(int));

    for(i=0; i<n; i++)
    {
        c[i]=0;
    }

    for(j=0; j<r; j++)

    {
        c[a[j]]++;

    }

    for(i=1; i<n; i++)
    {
        c[i]+=c[i-1];
    }

    for(i=r-1; i>=0; i--)
    {
        b[c[a[i]]-1]=a[i];
        c[a[i]]--;
    }

    for(i=0; i<r; i++)
    {
        //printf("%d",c[i]);
        a[i]=b[i];
    }

    PrintArray(a,r);
}
void SelectionSort(int *a,int r)
{
    int *sl=a;
    int i,j,min,tmp;

    for(i=0; i<r; i++)
    {
        min=i;
        for(j=i+1; j<r; j++)
        {
            if(sl[j]<sl[min])
                min=j;
        }

        tmp=sl[i];
        sl[i]=sl[min];
        sl[min]=tmp;

    }
    PrintArray(sl,r);


}
void BubbleSort(int *a,int r)
{
    int *b=a;
    int i,j,tmp;
    for(i=1; i<r; i++)
    {
        for(j=0; j<(r-i); j++)
        {
            if(b[j]>b[j+1])
            {
                tmp=b[j];
                b[j]=b[j+1];
                b[j+1]=tmp;
            }
        }
    }
    PrintArray(b,r);


}

void InsertionSort(int *a,int r)
{
    int i,j,x;
    int *s=a;
    for(i=1; i<r; i++)
    {
        x=s[i];
        j=i-1;
        while(j>=0 && x<s[j])
        {
            s[j+1]=s[j];
            j--;
        }
        s[j+1]=x;
    }
    PrintArray(s,r);
}

void ShellSort(int *a,int r)
{
    int h,n,i,j,tmp;
    h=1;
    n=r;

    while (h<=(n/3))
    {
        h=3*h+1;
    }

    while(h>=1)
    {
        for(i=h; i<r; i++)
        {

            for(j=i; j>=h && a[j]<a[j-h]; j-=h)
            {
                tmp=a[j];
                a[j]=a[j-h];
                a[j-h]=tmp;
            }
        }
        h=h/3;
    }

    PrintArray(a,r);

}

void PrintArray(int *a,int r)
{
    int i;
    for(i=0; i<r; i++)
    {
        printf("%d element : %d \n",i+1,a[i]);
    }
}




