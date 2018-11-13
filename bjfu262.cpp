//bjfu262
//
#include <iostream>
#include <cstring>
using namespace std;

typedef struct Node{
    int weight;
    int father;
    int L;
    int R;
}Node,*HuffTree;



void showHuff(HuffTree tree, int len){   //begin = 0
    for (int i = 1; i <= len; ++i) {
        cout<<i<<' ';
        cout<<tree[i].weight<<' ';
        cout<<tree[i].father<<' ';
        cout<<tree[i].L<<' ';
        cout<<tree[i].R<<endl;
    }
}

void frequency(char *str, int *fre){    //ftrlen=26
    int len=strlen(str);
    for (int i = 0; i < 26; ++i) {
        fre[i]=0;
    }
    for (int i = 0; i < len; ++i) {
        fre[str[i]-'a']++;
    }
    int flag=0;
    for (int i = 0; i < 26; ++i) {
        if(fre[i]){
            if(flag){
                cout<<' ';
            }
            cout<<(char)('a'+i)<<':'<<fre[i];
            flag=1;
        }
    }
    cout<<endl;
}

void getMax(HuffTree tree, int &len, int &b){
    int m=-1,n=-1;
    int min1=1e6;
    for (int i = 1; i <= len; ++i) {
        if(tree[i].weight<min1&&tree[i].father==0){
            min1=tree[i].weight;
            m=i;
        }
    }
    int min2=1e6;
    for (int i = 1; i <= len; ++i) {
        if(tree[i].weight<min2&&i!=m&&tree[i].father==0){
            min2=tree[i].weight;
            n=i;
        }
    }
    len=m;
    b=n;
}

int initHuffman(char *str, HuffTree &tree, int *fre){
    tree=new Node[100];
    int len=strlen(str); //length of str
    int num=0;             //numbers of characters
    for (int i = 0,j = 0; i < 26; ++i) {
        if(fre[i]>0){
            j++;
            tree[j].weight=fre[i];
            tree[j].father=0;
            tree[j].L=0;
            tree[j].R=0;
            num++;
        }
    }
    return num;
}

void BuildHuff(HuffTree &tree, int len){
    for (int i = len+1,j=0; i <=len*2-1; ++j,++i) {
        int a=len+j,b;
        getMax(tree, a, b);
        tree[i].father=0;
        tree[i].L=a;
        tree[i].R=b;
        tree[i].weight=tree[a].weight+tree[b].weight;
        tree[a].father=i;
        tree[b].father=i;
    }
}

void reverse(char *c){
    int len=strlen(c);
    for (int i = 0; i < len/2; ++i) {
        char t=c[i];
        c[i]=c[len-1-i];
        c[len-1-i]=t;
    }
}

void getCode(HuffTree tree, char** &code, int len){  //len = number of characters,code begin from 1
    code = new char*[30];
    for (int i = 1; i <=len; ++i) {
        int j=i;
        int pos=0;
        code[i] = new char[100];
        while (1){
            int father=tree[j].father;
            if(father==0){
                code[i][pos]=0;
                break;
            }
            if(tree[father].L==j){
                code[i][pos]='0';
            } else{
                code[i][pos]='1';
            }
            pos++;
            j=tree[j].father;
        }
        reverse(code[i]);
    }
}

void trans(char *tar,int *fre, char **code,int num){
    for (int i = 0,j = 1; i < 26; ++i) {
        if(fre[i]>0){
            fre[i]=j;
            j++;
        } else{
            fre[i]=0;
        }
    }
    int len=strlen(tar);
    for (int i = 0; i < len; ++i) {
        int car_num=tar[i]-'a';
        int index=fre[car_num];
        cout<<code[index];
    }
    cout<<endl;
}


int main(){
    while (1){
        char c[100];
        cin>>c;
        if(c[0]=='0'&&c[1]==0){
            break;
        }
        HuffTree tree;
        int num;
        int fre[26];
        frequency(c, fre);
        num=initHuffman(c, tree, fre);
        BuildHuff(tree, num);
        showHuff(tree, 2*num-1);
        char **code;
        getCode(tree, code, num);
        int dict[26];
        for (int i = 0,j=0; i < 26; ++i) {
            if(fre[i]>0){
                dict[j]=i;
                j++;
            }
        }
        for (int i = 0+1; i < num; ++i) {
            //reverse(code[i]);
            cout<<(char)(dict[i-1]+'a')<<':'<<code[i]<<' ';
        }
        //reverse(code[num-1]);
        cout<<(char)(dict[num-1]+'a')<<':'<<code[num]<<endl;
        trans(c, fre, code, num);
        cout<<c<<endl;
    }
    return 0;
}

