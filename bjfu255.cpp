//bjfu255
//
#include <iostream>
using namespace std;

typedef struct Intersection{
    int left;
    int forward;
    int right;
}Intersection;

class Maze{
private:
    int MazeSize;//迷宫交通路口数
    int Exit;          //迷宫出口号码
    Intersection * intsec;  //迷宫路口数组
public:
    Maze(int n);   //读取迷宫数据
    int TraverseMaze(int CurrentPos=1); //迷宫求解
};

Maze::Maze(int n){
    MazeSize=n;
    intsec=new Intersection[MazeSize+1];
    for(int i=1;i<=MazeSize;i++) {
        cin >> intsec[i].left >> intsec[i].forward >> intsec[i].right;
    }
    cin>>Exit;
}

int flag=0;

int Maze::TraverseMaze(int CurrentPos){
    if(CurrentPos==0) return 0;
    else if(CurrentPos==Exit){
        //cout<<"";
        flag=1;
        return 1;
    }
    else if (TraverseMaze( intsec[CurrentPos].left)) {
        return 1;
    }
    else if(TraverseMaze(intsec[CurrentPos].forward)){
        return 1;
    }
    else if(TraverseMaze(intsec[CurrentPos].right)){
        return 1;
    }
}


int main(){
    while (1){
        int n;
        cin>>n;
        if (n==0){
            break;
        }
        flag=0;
        Maze maze(n);
        maze.TraverseMaze(1);
        if (flag){
            cout<<"YES"<<endl;
        } else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}

