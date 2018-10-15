//
//  main.cpp
//  bjfu214.2
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
    int count=0;
    while (getBook(b)) {
        count++;
        appendBook(lis, b);
    }
    float sum=0;
    if (lis.next!=NULL) {
        Book *temp=lis.next;
        while (temp!=NULL) {
            sum+=temp->price;
            //printf("%.2f\n" , sum);
            temp = temp->next;
        }
    }
    float average = sum / count;
    printf("%.2f\n",average);
    if (lis.next!=NULL) {
        Book *temp=lis.next;
        while (temp!=NULL) {
            if (temp->price<average) {
                temp->price*=1.2;
            }
            else{
                temp->price*=1.1;
            }
            temp = temp->next;
        }
    }
    showBook(&lis);
    return 0;
}