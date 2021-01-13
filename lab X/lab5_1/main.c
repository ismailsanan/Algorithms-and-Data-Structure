#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 1000+1
typedef struct box{
    char* word;
    int fr;
    struct box *next;
}new;
new* read_count(FILE* fp);
char* set_it(char word[N]);
void kill();
void give_output(FILE *fp,new* phead);
int main(int argc, char *argv[])
{
    FILE *fp;
    new* phead;
    fp = fopen(argv[1],"r");
    if(!fp) kill();
    phead = read_count(fp);
    fclose(fp);
    fp = fopen("out.txt","w");
    if(!fp) kill() ;
    give_output(fp,phead);
    return 0;
}
new* create(){

        new *p;
        p = (new*)malloc(sizeof(new));
        if(!p) kill();
        return p;
}
void kill(){

        printf("an error occured \n ");
        exit(1);
}
char* set_it(char word[N]){
int i;
for(i=0;i<=strlen(word);i++){
   word[i] = tolower(word[i]);
}
return word;
}

new* read_count(FILE* fp){

      new *phead,*p;
      int flag=0;
      int start=0;
      char word[N];
      p = phead;
      while (fscanf(fp,"%s",word)!=EOF) {
                  word = set_it(word);
                  if(!start){
                    p->next = NULL;
                    p->word = strdup(word);
                    p->fr = 1;
                    start=1;
                  }else
    	{
        	while(p!=NULL && !flag){
            	if(!strcmp(p->word,word)){
                	p->fr++;
                	p = phead;
                	flag=1;
            	}else{
            		p = p->next;
            	}
        	}
            if(!flag){
            p = create();
            p->next = phead;
            p->fr = 1 ;
            p->word = strdup(word);
            phead = p;
          }
          flag=0;
    }
  }
  return (phead);
}

void give_output(FILE *fp,new* phead){
    new *p;
    new *pold;
    p= phead;
    while (p!=NULL) {
      fprintf(fp,"%s %d\n",p->word,p->fr);
      free(p->word);
      pold = p;
      p = p->next;
      free(pold);
    }
    fclose(fp);
}
