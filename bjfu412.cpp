//bjfu412
//
#include <iostream>
using namespace std;

typedef struct Node{
    int datum;
    struct Node *next;
}Node,*List;

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

void showList(List &head){
    Node *temp=head->next;
    while (temp){
        cout<<temp->datum;
        if (temp->next!=NULL){
            cout<<' ';
        }
        temp=temp->next;
    }
    cout<<endl;
}

void divideList(List head){
    List even;
    even=new Node;
    even->next=NULL;
    Node *tEven=even;
    Node *pre=head->next;
    while (pre!=NULL&&pre->next!=NULL){
        tEven->next=pre->next;
        tEven=tEven->next;
        pre->next=tEven->next;
        if (pre->next!=NULL){
            pre=pre->next;
        }
    }
    tEven->next=NULL;
    pre->next=even->next;
}



int main() {
    int n;
    while (cin>>n){
        if (n==0){
            break;
        }
        List lis;
        List l1;
        initList(lis, n);
        divideList(lis);
        showList(lis);
    }
    return 0;
}