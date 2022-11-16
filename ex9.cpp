#include <iostream>
#include <cstring>
#include <limits>
using namespace std;
class Staff{
protected:
    float hsluong,phucap;
    char hoten[50];
public:
    Staff(){
        hsluong=0;
        phucap=0;
    }
    ~Staff(){
        hsluong=NULL;
        phucap=NULL;
    }
    virtual void in(){
        cout<<"Ho ten: ";
        fflush(stdin); cin.get(hoten,50);
        cout<<"He So luong: ";
        cin>>hsluong;
        cout<<"Phu cap: ";
        cin>>phucap;
    }
    virtual void out(){
        cout<<"Ho ten: "<<hoten<<" ";
        cout<<"He so luong: "<<hsluong<<" ";
        cout<<"Phu cap: "<<phucap<<endl;
    }
    virtual float salary(){
        return hsluong*1310+phucap;
    }
    float getHsl(){
        return hsluong;
    }
};
class Operator : public Staff{
protected:
    float hschucvu;
public:
    void in(){
        Staff::in();
        cout<<"He so chuc vu: ";
        cin>>hschucvu;
    }
    void out(){
        Staff::out();
    }
    float salary(){
        return (hsluong+hschucvu)*1310+phucap;
    }
};
void swap(Staff a,Staff b){
    Staff c=a;
    a=b;
    b=c;
}
int main(){
    Staff *data[50];
    int n,i,j,response;
    cout<<"Nhap so luong Nhan vien/Can bo:";
    cin>>n;
    cout<<"Nhap danh sach"<<endl;
    for(i=0;i<n;i++){
        cout<<"Nhan vien/Can bo thu "<<i<<":"<<endl;
        cout<<"Chon nhap: 1-Nhan vien 2-Can bo"<<endl;
        cin>>response;
        if(response==1){
            data[i]=new Staff;
        }else{
            data[i]=new Operator;
        }
        data[i]->in();
    }
    for(i=n-1;i>=0;i--){
        for(j=1;j<=i;j++){
            if(data[j]->getHsl() < 3.0){
                if(data[j-1]->getHsl() > data[j]->getHsl()){
                    swap(data[j-1],data[j]);
                }
            }
        }
    }
    for(i=0;i<n;i++){
        data[i]->out();
    }
    return 0;
}