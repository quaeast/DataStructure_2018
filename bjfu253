//bjfu253
//
#include <iostream>
#include <iomanip>
using namespace std;

typedef struct Node{
    int datum;
    struct Node *next;
}Node,*List;

void initList2(List &head, int n){
    if(head==NULL){
        head=new Node;
    }
    if(n==0){
        return;
    }
    head->next=new Node;
    head->next->next=NULL;
    cin>>head->next->datum;
    initList2(head->next, n-1);
}

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

int length(List head){
    if(head->next==NULL){
        return 0;
    }
    int len=length(head->next)+1;
    return len;
}

double GetAverage(List p, int n){
    if(!p->next) return p->datum;
    else{
        double ave=GetAverage(p->next,n-1);
        return (ave*(n-1)+p->datum)/n;
    }
}

int main() {
    List lis;
    int n;
    while (cin>>n){
        if (n==0){
            break;
        }
        initList(lis, n);
        cout<<setiosflags(ios::fixed)<<setprecision(2);
        cout<<GetAverage(lis->next, n)<<endl;
        //showList(lis);
    }
    return 0;
}