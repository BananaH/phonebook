#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt_djb2.h"


unsigned int hash(char *ptr)
{
    unsigned int hash = 5381;
    int c;
    while(c = *ptr++) {
        hash = ((hash << 5) + hash) + c;    //hash = hash * 33 +c
    }
    return hash%26;
}

detail *findName(char lastname[], entry *pHead){
    int key = hash(lastname);
    detail *temp = pHead[key].data;
    while(temp!=NULL){
        if(!strcmp(temp->lastName,lastname))
            return temp;
        else
            temp = temp->next;
    }
    return NULL;
}

entry *append(char lastName[], entry *pHead){
    int key=hash(lastName);
    detail *newNode = (detail *)malloc(sizeof(detail));
    strcpy(newNode->lastName, lastName);
    newNode->next = pHead[key].data;
    pHead[key].data = newNode;
    return pHead;
}

