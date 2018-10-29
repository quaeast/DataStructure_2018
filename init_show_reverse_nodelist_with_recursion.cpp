//init show reverse nodelist with recursion
#include <iostream>
using namespace std;

typedef struct Node{
    int datum;
    Node *next;
}Node,*List;

void initList(List &head, int n){
    if (n==0){
        return;
    }
    if(head==NULL){
        head = new Node;
    }
    head->next=NULL;
    head->next=new Node;
    cin>>head->next->datum;
    initList(head->next, n-1);
}

void showList(List head){
    if (head->next->next==NULL){
        cout<<head->next->datum<<endl;
        return;
    }
    cout<<head->next->datum<<' ';
    showList(head->next);
}

void reverseList(List head){
    if(head->next==NULL||head->next->next==NULL){
        return;
    }
    Node *end_pre=head;
    Node *head_next;
    while (end_pre->next->next!=NULL){
        end_pre=end_pre->next;
    }
    Node *end=end_pre->next;
    head_next=head->next;
    head->next=end;
    end->next=head_next;
    end_pre->next=NULL;
    List (head->next);
}


int main() {
    int n;
    cin>>n;
    List lis;
    initList(lis, n);
    reverseList(lis);
    showList(lis);
    return 0;
}