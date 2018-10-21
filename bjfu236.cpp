//bjfu236
//
#include <iostream>
#include "cmath"
using namespace std;

typedef struct Node{
    int datum;
    struct Node *next;
}Node,*List;

const int Hash=1000;

void initList(List &head, int n){
    head=new Node;
    head->next=NULL;
    Node *cur=head;
    for (int i = 0; i < n; ++i) {
        Node *temp=new Node;
        temp->next=NULL;
        cin>>temp->datum;
        cur->next=temp;
        cur=cur->next;
    }
}

void showList(List head){
    Node *cur=head->next;
    while (cur->next){
        cout<<cur->datum<<' ';
        cur=cur->next;
    }
    cout<<cur->datum<<endl;
}

void deWeight(List head){
    int hash[Hash];
    for (int i = 0; i < Hash; ++i) {
        hash[i]=0;
    }
    Node *pre=head;
    Node *cur=head->next;
    while (cur){
        if (hash[abs(cur->datum)]>0){
            pre->next=cur->next;
            delete cur;
            cur=pre->next;
        } else{
            hash[abs(cur->datum)]=1;
            cur=cur->next;
            pre=pre->next;
        }
    }
}

int main(){
    int n;
    while (cin>>n){
        if (n==0){
            break;
        }
        List lis;
        initList(lis, n);
        deWeight(lis);
        showList(lis);
    }
}