//
//  main.cpp
//  bjfu223
//
//  Created by fang on 2018/9/30.
//  Copyright © 2018 fang. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct Books {
    char isbn[200];
    char name[200];
    float price;
    Books *next = NULL;
};

typedef Books Book;

//以第一个book作为头指针

// actually, inline is not necessary in modern compilers
inline int getBook(Book &b)
{
    scanf("%s%s%f", b.isbn, b.name, &b.price);
    if (b.isbn[0] == '0' && b.name[0] == '0' && b.price < 1e-6) 
    {
        return 0;
    }
    return 1;
}

inline void printBook(Book a) 
{
    printf("%s %s %.2f\n", a.isbn, a.name ,a.price);
}

void appendBook(Book &lis, Book &t) 
{
    Book* temp = &lis;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    temp->next = new Book();
    strcpy(temp->next->isbn, t.isbn);
    strcpy(temp->next->name, t.name);
    temp->next->price = t.price;
}

void insertBook(Book &lis, int n, Book &t)
{
    Book *temp = lis.next;
    for (int i = 0; i < n - 2; i++) 
    {
        temp = temp->next;
    }
    Book *stemp;
    stemp = temp->next;
    temp->next = &t;
    t.next = stemp;
}

void deleteBook(Book &lis, int n)
{
    Book *temp = lis.next;
    for (int i = 0; i < n - 2; i++) 
    {
        temp = temp->next;
    }
    Book *stemp;
    stemp = temp->next->next;
    delete temp->next;
    temp->next = stemp;
}

int showBook(Book *lis)
{
    if(lis->next == NULL)
    {
        return 0;                    //return 0表示链表为空
    }
    Book *temp = lis->next;
    while (temp != NULL) 
    {
        printBook(*temp);
        temp = temp->next;
    }
    return 1;
}


int main(int argc, const char * argv[])
{
    Books lis;
    Book b;
    int count;
    scanf("%d",&count);
    if(count==0){
        return 0;
    }
    for (int i=0; i<count; i++) {
        getBook(b);
        appendBook(lis, b);
    }
    Book *temp = lis.next;
    int i=0;
    while (1) {
        char tisbn[100];
        strcpy(tisbn, temp->isbn);
        Book *stemp = temp->next;
        Book *pre = temp;
        while (1) {
            if (strcmp(stemp->isbn, tisbn)==0) {
                Book *ttemp = pre->next;
                pre->next = pre->next->next;
                delete ttemp;
                count--;
            }
            pre = pre->next;
            stemp = stemp->next;
            if (stemp==NULL) {
                break;
            }
            i++;
        }
        temp = temp->next;
        if(temp==NULL||temp->next==NULL){
            break;
        }
    }
    printf("%d\n",count);
    showBook(&lis);
    return 0;
}
