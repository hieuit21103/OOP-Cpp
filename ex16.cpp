#include <iostream>
using namespace std;
class Candidate{
protected:
    char name[50];
    float avg,eng;
public:
    Candidate(){
        avg=0;
        eng=0;
    }
    ~Candidate(){}
    virtual void in(){
        cout<<"Nhap ho ten: ";
        fflush(stdin);
        cin.get(name,50);
        cout<<"Nhap diem trung binh: ";
        cin>>avg;
        cout<<"Nhap diem tieng Anh: ";
        cin>>eng;
    }
    virtual void out(){
        cout<<"Ten: "<<name<<" ";
        cout<<"Diem trung binh: "<<avg<<" ";
        cout<<"Diem tieng Anh: "<<eng<<endl;
    }
    virtual bool check(){
        if(avg >= 7 && eng >=400){
            return true;
        }
    }
    virtual bool isPriotized(){
        return false;
    }
};
class Priotized_Candidate : public Candidate{
protected:
    float bonus;
public:
    Priotized_Candidate(){
        bonus=0;
    }
    void in(){
        Candidate::in();
        cout<<"Nhap diem uu tien:";
        cin>>bonus;
    }
    void out(){
        Candidate::out();
        cout<<"Diem uu tien: "<<bonus<<endl;
    }
    bool check(){
        if(avg+bonus >= 7 && eng>=400){
            return true;
        }
    }
    bool isPriotized(){
        return true;
    }
};
void swap(Candidate a,Candidate b){
    Candidate c=a;
    a=b;
    b=c;
}
int main(){
    int n,i,j,response;
    Candidate *data[100];
    cin>>n;
    cout<<"Nhap danh sach"<<endl;
    for(i=0;i<n;i++){
        cout<<"Chon loai thi sinh: 1-Binh thuong 2-Uu tien"<<endl;
        cin>>response;
        switch (response)
        {
        case 1:
            data[i] = new Candidate;
            break;
        case 2:
            data[i] = new Priotized_Candidate;
            break;
        }
        data[i]->in();
    }
    for(i=0;i<n;i++){
        data[i]->out();
    }
    Candidate *data1[100];
    int x = 0;
    for(i=0;i<n;i++){
        if(data[i]->isPriotized()){
            data1[x]=new Priotized_Candidate();
        }else{
            data1[x]=new Candidate();
        }
        if(data[i]->check()){
            data1[x]=data[i];
            x++;
        }
    }
    for(i=0;i<=((float)(n*3/10));i++){
        data1[i]->out();
    }
    return 0;
}