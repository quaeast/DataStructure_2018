//bjfu224
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class item{
public:
    int n;
    int i;
};

bool cmp(item a, item b){
    return a.i>b.i;
}

void showF(vector<item> &a){
    if (a.size()==0){
        cout<<0<<endl;
        return;
    }
    for (int i = 0; i < a.size(); ++i) {
        if (a[i].i==0){
            cout<<a[i].n;
        } else{
            cout<<a[i].n<<'x'<<'^'<<a[i].i;
        }
        if(i==a.size()-1){
            cout<<endl;
        } else{
            if (a[i+1].n>0){
                cout<<'+';
            }
        }
    }
}

void deWeight(vector<item> &a){
    for (int i = 0; i < a.size()-1; ++i) {
        if(a[i+1].i==a[i].i){
            a[i].n+=a[i+1].n;
            a.erase(a.begin()+i+1);
            if(a[i].n==0){
                a.erase(a.begin()+i);
                --i;
            }
            --i;
        }
    }
}

void initF(vector<item> &a, int n){
    for (int i = 0; i < n; ++i) {
        item t;
        cin>>t.n>>t.i;
        a.push_back(t);
    }
    sort(a.begin(), a.end(), cmp);
    deWeight(a);
}



void add(vector<item> &a, vector<item> &b){
    a.insert(a.end(),b.begin(),b.end());
    sort(a.begin(), a.end(), cmp);
    deWeight(a);
}

void sub(vector<item> &a, vector<item> &b){
    for (int i = 0; i < b.size(); ++i) {
        b[i].n=-b[i].n;
    }
    add(a, b);
}

vector<item> mulOne(item single, vector<item> &b){
    vector<item> res;
    for (int i = 0; i < b.size(); ++i) {
        item temp;
        temp.i=b[i].i+single.i;
        temp.n=b[i].n*single.n;
        res.push_back(temp);
    }
    return res;
}

vector<item> mulAll(vector<item> &a, vector<item> &b){
    vector<item> res=mulOne(b[0], a);
    for (int i = 1; i < b.size(); ++i) {
        vector<item> p=mulOne(b[i], a);
        add(res, p);
    }
    sort(res.begin(), res.end(), cmp);
    deWeight(res);
    return res;
}

void derivation(vector <item> &a){
    for (int i = 0; i < a.size(); ++i) {
        a[i].n*=a[i].i;
        a[i].i--;
    }
}



int main() {
    int sum;
    cin>>sum;
    for(int j=0; j<sum; ++j){
        int a,b;
        cin>>a>>b;
        if (a==0&&b==0){
            break;
        }
        vector <item> l1,l2;
        for (int i = 0; i < a; ++i) {
            item t;
            cin>>t.n>>t.i;
            l1.push_back(t);
        }
        for (int i = 0; i < b; ++i) {
            item t;
            cin>>t.n>>t.i;
            l2.push_back(t);
        }
        char c;
        cin>>c;
        if (c=='+'){
            add(l1, l2);
            showF(l1);
        } else if (c=='-'){
            sub(l1, l2);
            showF(l1);
        } else if (c=='*'){
            vector<item> p=mulAll(l1 ,l2);
            showF(p);
        } else{
            derivation(l1);
            derivation(l2);
            showF(l1);
            showF(l2);
        }
    }
}