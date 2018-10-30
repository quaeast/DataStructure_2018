//bjfu246
//
#include <iostream>
using namespace std;

typedef struct Node{
    int datum;
    struct Node *next;
    struct Node *tail;
}Node,*List;

void initList(List &head, int n){
    head=new Node;
    head->next=NULL;
    head->tail=NULL;
    Node *cur=head;
    for (int i = 0; i < n; ++i) {
        Node *temp=new Node;
        cin>>temp->datum;
        head->tail=temp;
        cur->next=temp;
        temp->next=head->next;
        cur=cur->next;
    }
}

bool isEmpty(List &head){
    return head->next==NULL;
}

void showList(List &head){
    if(isEmpty(head)){
        return;
    }
    Node *cur=head->next;
    while (cur->next!=head->next){
        cout<<cur->datum<<' ';
        cur=cur->next;
    }
    cout<<cur->datum<<endl;
}


int pop(List &head){
    if(head->next==head->tail){
        int t=head->tail->datum;
        delete head->tail;
        head->next=NULL;
        return t;
    }
    int t=head->next->datum;
    Node *temp=head->next->next;
    delete head->next;
    head->next=temp;
    head->tail->next=head->next;
    return t;
}

int main() {
    while (1){
        int a,b;
        cin>>a>>b;
        if(a==0&&b==0){
            break;
        }
        List head;
        initList(head, a);
        for (int i = 0; i < b; ++i) {
            cout<<pop(head)<<' ';
        }
        cout<<!isEmpty(head)<<endl;
    }
    return 0;
}