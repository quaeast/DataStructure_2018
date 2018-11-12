//bjfu268
//
#include <iostream>
#include <cstring>
using namespace std;

typedef struct Node{
    char datum;
    struct Node *L;
    struct Node *R;
}Node,*BiTree;

int init(BiTree &root){
    char t;
    cin>>t;
    if(t=='0'){
        root=NULL;
        return 0;
    }
    root=new Node;
    root->datum=t;
    init(root->L);
    init(root->R);
    return 1;
}

void Pre(BiTree &root){
    if(root==NULL){
        return;
    }
    cout<<root->datum;
    Pre(root->L);
    Pre(root->R);
}

void RevOut(char *c, int len){
    for (int i = len-1; i >= 0; --i) {
        cout<<c[i];
    }
    cout<<endl;
}

void PreAll(BiTree &root, char *out, int len){
    if(root==NULL){
        return;
    }
    out[len]=root->datum;
    len++;
    if(root->L==NULL&&root->R==NULL){
        RevOut(out, len);
        return;
    }
    PreAll(root->L, out, len);
    PreAll(root->R, out, len);
}

int main() {
    while (1){
        BiTree tree;
        if(!init(tree)){
            break;
        }
        //Pre(tree);
        //cout<<endl;
        char a[500];
        a[0]=0;
        PreAll(tree, a, 0);
    }
    return 0;
}