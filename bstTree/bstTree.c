#include <stdio.h>
#include <stdlib.h>
#include "bstTree.h"


Node_t* InsertTree(Node_t * root,int key )
{
    if(root==NULL)
    {
        return newNode(key);
    }


    if(key>=root->value)
    {
        root->right=InsertTree(root->right,key);
    }
    else if(key<root->value)
    {
        root->left=InsertTree(root->left,key);
    }


    return root;

}


Node_pt* InsertTreeWp(Node_pt * root,Node_pt * root1,int key )
{
    if(root==NULL)
    {
        return newNodep(root1,key);
    }


    if(key>=root->value)
    {
        root->right=InsertTreeWp(root->right,root,key);
    }
    else if(key<root->value)
    {
        root->left=InsertTreeWp(root->left,root,key);
    }


    return root;

}


Node_t* newNode(int key )

{
    Node_t* node=(Node_t*)malloc(sizeof(Node_t));

    if(node==NULL)
    {
        printf("MEMORY ALLOCATION PROBLEM .... \n");
        exit(EXIT_FAILURE);
    }

    node->value=key;
    node->left=NULL;
    node->right=NULL;

    return node;
}

Node_pt* newNodep(Node_pt* pr ,int key )

{
    Node_pt* node=(Node_pt*)malloc(sizeof(Node_pt));

    if(node==NULL)
    {
        printf("MEMORY ALLOCATION PROBLEM .... \n");
        exit(EXIT_FAILURE);
    }

    node->value=key;
    node->left=NULL;
    node->right=NULL;
    node->p=pr;
    return node;
}

void PrintPostTree(Node_t* root)
{
    if(root==NULL)
    {
        return;
    }

    else
    {
        PrintPostTree(root->left);
        PrintPostTree(root->right);
        printf("%d\n",root->value);

    }
}
void PrintPreTree(Node_t* root)
{
    if(root==NULL)
    {
        return;
    }

    else
    {
        printf("%d\n",root->value);
        PrintPreTree(root->left);
        PrintPreTree(root->right);
        return;

    }
}

void  PrintInTree(Node_t* root)
{
    if(root==NULL)
        return;
    else
    {

        PrintInTree(root->left);
        printf("%d\n",root->value);
        PrintInTree(root->right);

        return;


    }
}

void  PrintInTreep(Node_pt* root)
{
    if(root==NULL)
        return;
    else
    {

        PrintInTreep(root->left);
        printf("%d HAS PARENT ",root->value);
        if(root->p!=NULL)
            printf("%d\n",root->p->value);
        else
            printf(" NULL\n");
        PrintInTreep(root->right);

        return;


    }
}


int  NodeCounter(Node_t* root)
{
    int u,v;

    if(root==NULL)
        return 0;

    else
    {
        u=NodeCounter(root->left);
        v=NodeCounter(root->right);
    }

    return (u+v+1);

}

int HeightCal(Node_t*root)
{

    int u,v;

    if(root==NULL)
        return -1;
    else
    {
        u=HeightCal(root->left);
        v=HeightCal(root->right);
    }
    if(u>v)
        return (u+1);
    else
        return (v+1);


}

int SearchTree(Node_t* root,int key)
{
    if(root==NULL)
        return 0;

    else if(key>root->value)
        return SearchTree(root->right,key);
    else if(key<root->value)
        return SearchTree(root->left,key);
    else
        return 1;

}

int MinTree(Node_t* root)
{

    if(root->left==NULL)
    {
        return root->value;
    }
    else
    {
        return MinTree(root->left);

    }


}
int MaxTree(Node_t* root)
{

    if(root->right==NULL)
    {
        return root->value;
    }
    else
    {
        return MaxTree(root->right);

    }


}

Node_t* DeleteNode(Node_t* root,int key)
{
    //if the tree is  NULL
    if(root==NULL)
    {
        return NULL;
    }

    if(key>root->value)
    {
        /** we make a capture so when the needed node is equal to NULL to delete it then it will
        go out of the loop down where root=NULL and return the "return root" at the last which by turn
        the capture root->left or root->right will capture it.
         */

        root->right=DeleteNode(root->right,key);
    }
    else if(key<root->value)
    {
        /** we make a capture so when the needed node is equal to NULL to delete it then it will
        go out of the loop down where root=NULL and return the "return root" at the last which by turn
        the capture root->left or root->right will capture it.
         */
        root->left=DeleteNode(root->left,key);
    }

    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            root=NULL;
            // printf("parent with no children\n");
        }

        else if(root->left==NULL)
        {
            root=root->right;
            // printf("parent with no left children\n");

        }
        else if(root->right==NULL)
        {
            root=root->left;
            //    printf("parent with no right children\n");

        }
        else
        {
            //printf("parent with children\n");

            /**
            find the min of the tree after calling the right child or we can find the max after a  left call which it
            will be the min in the right recur and the max of the left recur.
            */
            int x=MinTree(root->right);
            root->value=x;
            DeleteNode(root->right,x);
        }

    }
    return root;
}


Node_t* RightRot(Node_t* root)
{

    Node_t* p=root->left;
    root->left=p->right;
    p->right=root;
    return p;

}

Node_t* LeftRot(Node_t* root)
{


    Node_t* p=root->right;
    root->right=p->left;
    p->left=root;
    return p;

}

Node_t* RootInsertion(Node_t* root,int key)
{
    if(root==NULL)
    {
        return newNode(key);
    }


    if(key>=root->value)
    {
        root->right=RootInsertion(root->right,key);
        root=LeftRot(root);
    }
    else if(key<root->value)
    {
        root->left=RootInsertion(root->left,key);
        root=RightRot(root);
    }


    return root;

}
int SubTree(Node_t* root,Node_t* rootSub)
{
    if(rootSub==NULL)
    {
        return 1;
    }

    if(root==NULL)
    {
        return 0;
    }
    if(equalTree(root,rootSub))
    {
        return 1;
    }

    return (SubTree(root->left,rootSub) || SubTree(root->right,rootSub));

}
int equalTree(Node_t* root,Node_t* rootSub)
{
    if (root==NULL && rootSub==NULL)
    {
        return 1;
    }
    if(root!=NULL && rootSub==NULL)
    {
        return 0;
    }
    if(root==NULL && rootSub!=NULL)
    {
        return 0;
    }

    return (root->value==rootSub->value && equalTree(root->left,rootSub->left) && equalTree(root->right,rootSub->right));


}


Node_t* treeMirror(Node_t* root)
{
    if(root==NULL)
    {
        return NULL;
    }

    else
    {
        Node_t* tmp=(Node_t*)malloc(sizeof(Node_t));
        if(tmp==NULL)
        {
            printf("ERROR MEMORY ALLOCATION\n");
            exit(EXIT_FAILURE);
        }

        tmp=root->left;
        root->left=root->right;
        root->right=tmp;

        root->left=treeMirror(root->left);
        root->right=treeMirror(root->right);

    }

    return root;
}


int distance (Node_t* root ,int key1,int key2)
{
    if(root==NULL)
    {
        return 0;
    }


        if(key1>root->value && key2>root->value)
        {
            return distance(root->right,key1,key2);
        }

        else if(key1<root->value && key2<root->value)
        {
            return distance(root->left,key1,key2);
        }



        else if(key1<root->value && key2>root->value)
        {
            return (distance_r(root,key1,0)+
            distance_r(root,key2,0));
        }
       else if(key1>root->value && key2<root->value)
        {
            return (distance_r(root,key2,0) +
            distance_r(root,key1,0));
        }

        else
        {
            if(key1==root->value)
            {
               if(key2>key1)
               {
                  return distance_r(root,key2,0);
               }
                  return distance_r(root,key2,0);
            }

            if(key2==root->value)
            {
            if(key1>key2)
               {
                  return distance_r(root,key1,0);
               }
                  return distance_r(root,key1,0);
            }

        }

}
int distance_r(Node_t* root,int key,int level)
    {
        if(key==root->value)
        {
            return level;
        }
        if(key>root->value)
        {
            return distance_r(root->right,key,level+1);
        }
        if(key<root->value)
        {
            return  distance_r(root->left,key,level+1);
        }



    }
