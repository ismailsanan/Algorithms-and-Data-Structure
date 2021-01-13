#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M_NAME 50+1
#define M_ID 16+1
#define D 12
#define N 100
typedef struct mylist{
    char name[M_NAME];
    char id[M_ID];
    char date[D];
    int salery;
    struct mylist *nx;
    struct mylist *pr;
    }list;
void kill();
list* read_my_file(FILE *fp);
void print_it_out(list *phead,char *name,char *style);
void free_my_memory(list *phead);
int main(int argc, char *argv[])
{
    FILE *fp;
    list *phead;
    char *style;
    if(argc != 4) kill();
    fp=fopen(argv[1],"r");
    if(!fp) kill();
    phead = read_my_file(fp);
    fclose(fp);
    style = strdup(argv[3]);
    print_it_out(phead,argv[2],style);
    free_my_memory(phead);
    free(style);
    return 0;
}
void kill(){
    printf("an error occured \n");
    exit(EXIT_FAILURE);
    }
list* read_my_file(FILE *fp){
  list *phead;
  list *tmp;
  int start=0;
  char buffer[N];
  while (fgets(buffer,N,fp)) {
      tmp = phead;
      phead = (list*)malloc(sizeof(list));
      if(!phead) kill();
      if(!start){
                    phead->nx = NULL;
                    phead->pr = NULL;
                    start=1;
                  }else{
                    phead->nx = tmp;
                    tmp->pr = phead;
                    phead->pr= NULL;
                  }
      sscanf(buffer,"%s %s %s %d",phead->name,phead->id,phead->date,&phead->salery);
  }
  return phead;
}
void print_it_out(list *phead,char *name,char *style){
    list *p;
    int i=0;
    int found=0;
    p = phead;
    while(p && !found){
      if(!strcmp(p->name,name)){
          found =1;
        }else{
          p = p->nx;
        }
    }
    while(found){
        printf("%s %s %s %d \n",p->name,p->id,p->date,p->salery);
          if(style[i]=='+'){
                if(p->nx) p = p->nx;
              }else
          if(style[i]=='-') {
                if(p->pr) p = p->pr;
          }else{
                found =0;
                }
        i++;
    }
}
void free_my_memory(list *phead){
          list *tmp;
          while(phead){
                tmp = phead;
                phead = phead->nx;
                free(tmp);
          }
          return;
}
