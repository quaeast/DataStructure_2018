//
//  main.cpp
//  bjfu215
//
//  Created by fang on 2018/9/30.
//  Copyright © 2018 fang. All rights reserved.
//

#include <iostream>
#include "cstdio"
#include "cstring"

using namespace std;

typedef struct Books{
    char isbn[200];
    char name[200];
    float price;
    struct Books *next = NULL;
}Book;

//以第一个book作为头指针

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

void deleteBook(Book &lis, int n){
    Book *temp = lis.next;
    for (int i=0; i<n-2; i++) {
        temp = temp->next;
    }
    Book *stemp;
    stemp = temp->next->next;
    delete temp->next;
    temp->next = stemp;
}

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



bool cmp(Book b1, Book b2){
    if (b1.price==b2.price) {
        return strcmp(b1.name,b2.name)>0;
    }
    else{
        return b1.price>b2.price;
    }
}

Book* findMaxPre(Book *lis){       //return maxPre
    if(lis->next==NULL){
        return NULL;
    }
    Book *maxPre=lis;
    Book *max=maxPre->next;
    Book *iPre=max;
    Book *i = iPre->next;
    while (i!=NULL){
        if(cmp(*i, *max)){
            max = i;
            maxPre = iPre;
        }
        i=i->next;
        iPre = iPre->next;
    }
    return maxPre;
}

void sortBook(Book *head){
    for (Book *i=head; i->next!=NULL; i=i->next) {
        Book *maxPre=findMaxPre(i);
        Book *max=maxPre->next;
        //printf("********");
        //printBook(*max);
        maxPre->next=max->next;
        max->next=i->next;
        i->next=max;
        //showBook(head);
        //printf("-----------------------\n");
    }
}

int main(int argc, const char * argv[]) {
    Books lis;
    Book b;
    int count = 0;
    while (getBook(b)) {
        count++;
        appendBook(lis, b);
    }
    sortBook(&lis);
    showBook(&lis);
    return 0;
}