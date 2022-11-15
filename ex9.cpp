#include <iostream>
#include <cstring>
#include <algorithm>
#define forp(a,b) for(a=0;a<b;a++);
using namespace std;
class Staff{
public:
    static char hoten[50];
    static float hsluong;
    static float phucap;
    Staff(){
        hsluong=0;
        phucap=0;
    }
    ~Staff(){
        hsluong=NULL;
        phucap=NULL;
    }
    friend istream &operator>>(istream &is,Staff &st){
        cout<<"Ho ten: ";
        fflush(stdin); is.get(hoten,50);
        cout<<"He So luong: ";
        is>>hsluong;
        cout<<"Phu cap: ";
        is>>phucap;
        return is;
    }
    friend ostream &operator<<(ostream &os,Staff &st){
        os<<"Ho ten: "<<hoten<<" ";
        os<<"He so luong: "<<hsluong<<" ";
        os<<"Phu cap: "<<phucap<<endl;
        return os;
    }
    float salary(){
        return hsluong*1310+phucap;
    }
};
class Operator : public Staff{
    static float hschucvu;
public:
    friend istream &operator>>(istream &is,Staff &st){
        cout<<"He so chuc vu";
        cin>>hschucvu;
        return is;
    }
    friend ostream &operator<<(ostream &os,Staff &st){
        return os;
    }
    float salary(){
        return (hsluong+hschucvu)*1310+phucap;
    }
};
int main(){
    Staff *data;
    Operator *data1;
    int n,m,i;
    cin>>n>>m;
    data = new Staff[n];
    data1 = new Operator[m];
    forp(i,n){
        cin>>data[i];
    }
    forp(i,n){
        cout<<data[i];
    }
    forp(i,m){
        cin>>data1[i];
    }
    forp(i,m){
        cout<<data1[i];
    }
    return 0;
}