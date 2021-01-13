#ifndef BSTTREE_H_INCLUDED
#define BSTTREE_H_INCLUDED

typedef struct Node_t{

    int value;
    struct Node_t * left;
    struct Node_t * right;

}Node_t;


typedef struct Node_pt{

    int value;
    struct Node_pt * left;
    struct Node_pt * right;
    struct Node_pt * p;

}Node_pt;
int distance_r(Node_t* root,int key2,int level);
Node_t* treeMirror(Node_t*);
int distance (Node_t* ,int,int);
int equalTree(Node_t* root,Node_t* rootSub);
int SubTree(Node_t*,Node_t*);
Node_t* newNode(int);
Node_pt* newNodep(Node_pt* ,int);
Node_t* InsertTree(Node_t *,int );
Node_t* DeleteNode(Node_t*,int);
Node_t* RightRot(Node_t*);
Node_t* LeftRot(Node_t*);
Node_t* RootInsertion(Node_t*,int);
void PrintPostTree(Node_t*);
void PrintPreTree(Node_t*);
void PrintInTree(Node_t*);
void PrintInTreep(Node_pt*);

int  NodeCounter(Node_t*);
int  HeightCal(Node_t*);
int  SearchTree(Node_t*,int);
int  MinTree(Node_t*);
int  MaxTree(Node_t*);



#endif // BSTTREE_H_INCLUDED
