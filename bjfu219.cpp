//
//  main.cpp
//  bjfu219
//
//  Created by fang on 2018/9/30.
//  Copyright © 2018 fang. All rights reserved.
//

#include <iostream>
#include "cstdio"
#include "cstring"

using namespace std;

typedef struct Books{
    char isbn[100];
    char name[100];
    float price;
    struct Books *next = NULL;
}Book;

//以第一个book作为头指针

inline int getBook(Book &b){
    scanf("%s%s%f",b.isbn, b.name, &b.price);
    if (b.isbn[0]=='0'&&b.name[0]=='0'&&b.price<1e-6) {
        return 0;
    }
    return 1;
}

inline void printBook(Book a){
    printf("%s %s %.2f\n", a.isbn, a.name ,a.price);
}

void appendBook(Book &lis,Book &t){
    Book* temp = &lis;
    while (temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next = new Book;
    strcpy(temp->next->isbn, t.isbn);
    strcpy(temp->next->name, t.name);
    temp->next->price=t.price;
}

int showBook(Book *lis){
    if(lis->next==NULL){
        return 0;                    //return 0表示链表为空
    }
    Book *temp = lis->next;
    while (temp!=NULL) {
        printBook(*temp);
        temp = temp->next;
    }
    return 1;
}

int main(int argc, const char * argv[]) {
    Books lis;
    Book b;
    int count;
    scanf("%d",&count);
    for (int i=0; i<count; i++) {
        getBook(b);
        appendBook(lis, b);
    }
    int fnum;
    scanf("%d",&fnum);
    for (int i=0; i< fnum; i++) {
        char tar[100];
        scanf("%s", tar);
        if (lis.next!=NULL) {
            int flag=0;
            Book *temp=lis.next;
            while (temp!=NULL) {
                if (strcmp(temp->name,tar)==0) {
                    //printBook(*temp);
                    flag++;
                }
                temp = temp->next;
            }
            if (flag!=0) {
                printf("%d\n",flag);
            }
        }
        if (lis.next!=NULL) {
            int flag=0;
            Book *temp=lis.next;
            while (temp!=NULL) {
                if (strcmp(temp->name,tar)==0) {
                    printBook(*temp);
                    flag++;
                }
                temp = temp->next;
            }
            if (flag==0) {
                printf("Sorry，there is no your favourite!\n");
            }
        }
    }
    return 0;
}