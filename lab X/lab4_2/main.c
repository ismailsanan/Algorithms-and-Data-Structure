#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20+1
void kill();
void output(FILE* fp,char** final,int r,int c);
char*** get_mat(char ***mat,int r,int c,FILE* fp);
char** merge_it(char ***mat,int r,int c);
void go_free(char ***mat,char **final,int r,int c);
int main(int argc,char *argv[])
{
    FILE *fp;
    int r,c;
    if(argc != 3) kill();
    char ***mat = NULL;
    char **final;
    fp = fopen(argv[1],"r");
    if(!fp) kill();
    fscanf(fp,"%d%d%*c",&r,&c);
    mat = get_mat(mat,r,c,fp);
           /* for(i=0;i<r;i++){
                for(j=0;j<c;j++){
                    printf(" %s ",mat[i][j]);
                }
                printf("\n");
            } */
    fclose(fp);
    final = merge_it(mat,r,c);
    fp = fopen(argv[2],"w");
    if(!fp) kill();
    output(fp,final,r,c);
    fclose(fp);
    go_free(mat,final,r,c);
    return 0;
}
void kill(){
     printf("an error occured \n");
    exit(EXIT_FAILURE);
}
char*** get_mat(char ***mat,int r,int c,FILE* fp){
    int i,j;
    char buffer[N];
    mat = (char***)malloc(r*sizeof(char**));
    if(!mat) kill();
    for(i=0;i<r;i++){
      mat[i]=(char**)malloc(c*sizeof(char*));
      if(!mat[i]) kill();
    }
    i=0;j=0;
    while(fscanf(fp,"%s",buffer)!=EOF){
        mat[i][j] = strdup(buffer);
        if(!mat[i][j]){
          printf("string allocation error\n");
          exit(1);
        }
        j++;
        if(j==c){
          j=0;
          i++;
        }
    }
    return mat;
}
char** merge_it(char ***mat,int r,int c){
  int i,x,j;
  char **FA;
  int *idx,min_id;
  char *minword;
  FA = (char**)malloc(r*c*sizeof(char*));
  idx = (int*)calloc(r,sizeof(int)); // allocated and initialized to zero
  for(i=0;i<r;i++){
    printf("%d ",idx[i]);
  }
  if(!FA || !idx) kill();
  x=0;j=0;
  while(x < r*c){
      min_id = -1;
      for(j=0;j<r;j++){
        if(idx[j]<c){ //if we have any word remaining in this line
          if((min_id==-1)||(strcmp(mat[j][idx[j]],minword)<0)){ //idx[j] allow us to skip already printed words
                min_id = j;
                minword = mat[min_id][idx[min_id]];
          }
        } // both if's
      } // for loop idx[0]
   FA[x]= mat[min_id][idx[min_id]]; /// when x=10, idx[0] changes from 1 to blabla ??
   printf("%s \n",FA[x]);
   x++;
   idx[min_id]++;
}
    free(idx);
    return(FA);
 }
void output(FILE* fp,char** final,int r,int c){
  int i=0;
  fprintf(fp,"%d\n",r*c);
  while (i < r*c) {
    fprintf(fp, "%s \n",final[i]);
    i++;
  }
}
void go_free(char ***mat,char **final,int r,int c){
  int i,j;
  for(i=0;i<r;i++){
    for (j=0;j < c ;j++) {
      free(mat[i][j]);
    }
  free(mat[i]);
  }
  free(mat);
  free(final);
}
