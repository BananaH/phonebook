#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"

/* original version */
entry *findName(char lastname[], entry *pHead)
{
    while (pHead != NULL) {
        if (strcasecmp(lastname, pHead->lastName) == 0)
            return pHead;
        else if(strlen(lastname)>=strlen(pHead->lastName)){
            pHead=pHead->pNext_right;
        }
        else{
            pHead=pHead->pNext_left;
        }
    }
    return NULL;
}

entry *append(char lastName[], entry *pHead)
{
    entry *root = pHead;
    if(root==NULL){
        root=(entry *) malloc(sizeof(entry));
        root->pNext_left=NULL;
        root->pNext_right=NULL;
        strcpy(root->lastName,lastName);
    }
    while(root!=NULL){
        if(strlen(lastName)>=strlen(root->lastName)){
            if(root->pNext_right!=NULL){
                root=root->pNext_right;
            }
            else{
                root->pNext_right= (entry *) malloc(sizeof(entry));
                root=root->pNext_right;
                strcpy(root->lastName,lastName);
                root->pNext_right=NULL;
                root->pNext_left=NULL;
                return pHead;
            }
        }
        else{
            if(root->pNext_left!=NULL){
                root=root->pNext_left;
            }
            else{
                root->pNext_left= (entry *) malloc(sizeof(entry));
                root=root->pNext_left;
                strcpy(root->lastName,lastName);
                root->pNext_right=NULL;
                root->pNext_left=NULL;
                return pHead;
            }
        }
    }
    return pHead;
}

