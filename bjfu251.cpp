//bjfu251
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

void showList(List head){
    if (head->next->next==NULL){
        cout<<head->next->datum<<endl;
        return;
    }
    cout<<head->next->datum<<' ';
    showList(head->next);
}

int findMax(List head){
    if (head->next->next==NULL){
        return head->next->datum;
    }
    int max=findMax(head->next);
    return head->next->datum>max?head->next->datum:max;
}

int main() {
    List lis;
    int n;
    while (cin>>n){
        if (n==0){
            break;
        }
        initList(lis, n);
        cout<<findMax(lis)<<endl;
        //showList(lis);
    }
    return 0;
}