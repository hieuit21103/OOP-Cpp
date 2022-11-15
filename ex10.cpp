#include <iostream>
#include <cstring>
using namespace std;
class student{
public:
    static char name[50];
    static float avg,toeic;
    student(){
        avg=0;
        toeic=0;
    }
    ~student(){
        avg=NULL;
        toeic=NULL;
    }
    friend istream &operator>>(istream &is,student &st){
        cout<<"Nhap ten hoc sinh: ";
        fflush(stdin);
        is.get(name,50);
        cout<<"Nhap diem trung binh: ";
        is>>avg;
        cout<<"Nhap diem tieng Anh: ";
        is>>toeic;
        return is;
    }
    friend ostream &operator<<(ostream &os,student &st){
        cout<<"Ho va ten: "<<name<<" ";
        cout<<"Diem trung binh"<<avg<<" ";
        cout<<"Diem tieng Anh"<<toeic<<endl;
        return os;
    }
    bool check(){
        if(this->avg>=7 && this->toeic>=400 ){
            return true;
        }
        return false;
    }
};
class prioritized_student : public student{
    static float bonus;
    bool check(){
        if((this->avg+this->bonus)>=7 && this->toeic>=400 ){
            return true;
        }
        return false;
    }
    friend istream &operator>>(istream &is,student &st){
        cout<<"Nhap ten hoc sinh: ";
        fflush(stdin);
        is.get(name,50);
        cout<<"Nhap diem trung binh: ";
        is>>avg;
        cout<<"Nhap diem tieng Anh: ";
        is>>toeic;
        cout<<"Nhap diem uu tien: ";
        is>>bonus;
        return is;
    }
    friend ostream &operator<<(ostream &os,student &st){
        cout<<"Ho va ten:"<<name<<" ";
        cout<<"Diem trung binh:"<<avg<<" ";
        cout<<"Diem tieng Anh:"<<toeic<<" ";
        cout<<"Diem uu tien:"<<bonus<<endl;
        return os;
    }
};
int main(){
    int i,j,m,n;
    student *a;
    prioritized_student *b;
    cin>>n;
    for (i = 0; i < n; i++)
    {
        
    }
    
    return 0;
}