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
    ~Candidate(){
        avg=NULL;
        eng=NULL;
    }
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
        if(this->avg >= 7 && this->eng >=400){
            return true;
        }
        return false;
    }
};
class Priotized_Candidate : public Candidate{
protected:
    float bonus;
public:
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
        if(this->avg+this->bonus >= 7 && this->eng>=400){
            return true;
        }
        return false;
    }
};
int main(){
    int n,i,response;
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
    for(i=0;i<(n*3/10);i++){
        if(data[i]->check()){
            data[i]->out();
        }
    }
    return 0;
}