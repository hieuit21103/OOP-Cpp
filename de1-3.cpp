#include <iostream>
#include <bits/stdc++.h>
#include <cstring>
using namespace std;
class Student{
protected:
    string name; //Tên học sinh
    int id; //Mã số
    int dtl;
public:
    Student(){
        name="";
        id=0;
        dtl=0;
    }
    ~Student(){}
    void nhap(){
        cin>>name>>id>>dtl;
    }
    void xuat(){
        cout<<name<<" "<<id<<" "<<dtl<<" ";
    }
};
template <class a,class n,class m,class x>  
void Search(a arr[],n p,m q,x st[]){
    int i;
    string key;
    cin>>key;
    for(i=p;i<=q;i++){
        if(st[i].name==key){
            st[i].xuat();
            return;
        }
    }
    cout<<"<NONE>";
    
}
int main(){
    Student st[100];
    Search(st,0,10,st);
    return 0;
}