#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100+2 // end of line,end of string '/0'
void kill();
void sort(char **mat,int n);
void output(char **mat,FILE *fp1,int n);
void go_free(char **mat,int count);
int main(int argc,char* argv[])
{
    FILE *fp1;
    int r,c,i;
    i=0;
    if(argc!=3) kill();
    fp1 = fopen(argv[1],"r");
    if(!fp1) kill();
    fscanf(fp1,"%d%*c",&r);
    char **mat;
    mat = (char**)malloc(r*sizeof(char*));
    if(!mat) kill();
    char buffer[N];

    while(fscanf(fp1,"%s",buffer)!=EOF){
            c = strlen(buffer) +1 ;
            mat[i]=(char*)malloc(c*sizeof(char));
            if(!mat[i]) kill();
            strcpy(mat[i],buffer);
            i++; }
    sort(mat,r);
    fclose(fp1);
    fp1 = fopen(argv[2],"w");
    if(!fp1) kill();
    output(mat,fp1,r);
    fclose(fp1);
    go_free(mat,r);

    return 0;
}
void kill(){
        printf("an error occured \n");
        exit(EXIT_FAILURE);
  }

void sort(char **mat,int n){
  char *p;
  char  *tmp;
  int min,ind ;
  int i,j;
  int flag =0;
  for(i=0;i<n && !flag;i++){ //°-°
                    flag =1;
                    for(j=0;j<n-i-1;j++){
                    if(mat[j][0]>mat[j+1][0]){
                      flag = 0;
                      tmp = mat[j+1];
                      mat[j+1] = mat[j];
                      mat[j]=tmp;
                                     } } // both and j'th for

    } //°-°
}
void output(char **mat,FILE *fp1,int n){
   int i;
   fprintf(fp1, "%d\n",n);
   for(i=0;i<n;i++){
     fprintf(fp1,"%s\n",mat[i]);
   }
}
void go_free(char **mat,int count){
   int i;
   for ( i = 0; i < count; i++) {
     free(mat[i]);
   }
   free(mat);
 }


