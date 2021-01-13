#include <stdio.h>
#include <stdlib.h>
#include "bstTree.h"


int main()
{

    Node_t *root=NULL;
    //Node_pt *rootp=NULL;
    int u,x,y,w,z;

//    root=InsertTree(root,15);
//    root=InsertTree(root,9);
//    root=InsertTree(root,17);
//    root=InsertTree(root,7);
//    root=InsertTree(root,11);
//    root=InsertTree(root,16);
//    root=InsertTree(root,19);
//    root=InsertTree(root,6);
//    root=InsertTree(root,10);
//    root=InsertTree(root,14);
//    root=InsertTree(root,18);
//    root=InsertTree(root,21);


root=InsertTree(root,7);
InsertTree(root,3);
InsertTree(root,10);
InsertTree(root,1);
InsertTree(root,4);
InsertTree(root,9);
InsertTree(root,15);
InsertTree(root,0);
InsertTree(root,5);
InsertTree(root,12);
InsertTree(root,11);

z=distance(root,11,5);
printf("%d ",z);

//root=treeMirror(root);
//PrintInTree(root);

//Node_t* rootsub=NULL;
//rootsub=InsertTree(rootsub,7);
//InsertTree(rootsub,1);
//InsertTree(rootsub,15);
//
//int s=SubTree(root,rootsub);
//printf("%d ",s);
//    printf("POSTORDER DISPLAY (LEFT,RIGHT,ROOT): \n");
//    PrintPostTree(root);
//    printf("PREORDER DISPLAY (ROOT,LEFT,RIGHT): \n");
//    PrintPreTree(root);
//    printf("INORDER DISPLAY (ROOT,LEFT,RIGHT): \n");
//    PrintInTree(root);
//    printf("\n");
//    printf("THE TREE CONTAINS %d NODES \n",NodeCounter(root));
//    printf("THE HEIGHT OF THE TREE IS %d\n",HeightCal(root));
//    printf("%d IS THE MINIMUM NUMBER IN THE TREE \n",MinTree(root));
//    printf("%d IS THE MAXIMUM NUMBER IN THE TREE \n",MaxTree(root));
//    printf("\n");
//    printf("PLEASE ENTER THE KEY YOU ARE SEARCHING FOR : \n");
//    scanf("%d",&x);
//    if(SearchTree(root,x))
//        printf("NUMBER %d EXISTS IN THE TREE \n",x);
//    else
//        printf("NUMBER %d DOESN'T EXISTS IN THE TREE\n",x);
//    while(!SearchTree(root,y))
// {
//    printf("PLEASE ENTER THE KEY YOU WANT TO DELETE : \n");
//    scanf("%d",&y);
//}
//    root=DeleteNode(root,y);
//    PrintPostTree(root);
//
//    while(!SearchTree(root,u))
// {
//    printf("PLEASE ENTER THE KEY IN WHICH YOU MUST DO A ROOT INSERTION   : \n");
//    scanf("%d",&u);
// }
//    root=RootInsertion(root,u);
//    PrintPostTree(root);
//
//     while(!SearchTree(root,w))
// {
//    printf("PLEASE ENTER THE KEY YOU WANT FIND ITS SUCCESSOR AND PREDESUCCESSOR : \n");
//    scanf("%d",&w);
//    printf("%d IS THE SUCCESSOR OF THE ITEM : %d\n",SuccessorTree(root,w),w);
//    printf("%d IS THE PREDESUCCESSOR OF THE ITEM : %d\n",PreDessorTree(root,w),w);
//
//
////}
//    rootp=InsertTreeWp(rootp,NULL,20);
//    rootp=InsertTreeWp(rootp,NULL,10);
//    rootp=InsertTreeWp(rootp,NULL,40);
//    rootp=InsertTreeWp(rootp,NULL,18);
//    rootp=InsertTreeWp(rootp,NULL,19);
//    PrintInTreep(rootp);


    return 0;

}
