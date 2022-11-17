#include <iostream>
using namespace std;
class Candidate{
protected:
    char name[50];
    int sbd;
    float m1,m2,m3;
public:
    Candidate(){
        sbd=0;
        m1=m2=m3=0;
    }
    Candidate(int id){
        sbd=id;
    }
    ~Candidate(){}
    virtual void in(){
        cout<<"Nhap ten:";
        fflush(stdin);
        cin.get(name,50);
        cout<<"Nhap SBD:";
        cin>>sbd;
        cout<<"Nhap diem 3 mon:";
        cin>>m1>>m2>>m3;
    }
    virtual void out(){
        cout<<"Ten: "<<name<<" "<<"SBD: "<<sbd<<" "<<"Diem 3 mon: "<<m1<<" "<<m2<<" "<<m3<<" "<<" "<<"Diem tong:"<<this->calculate()<<" ";
    }   
    virtual float calculate(){
        return (m1+m2+m3);
    }
    float getMark(int id){
        switch(id){
            case 1:
                return m1;
                break;
            case 2:
                return m2;
                break;
            case 3:
                return m3;
                break;
        }
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
        cout<<"Ten: "<<name<<" "<<"SBD: "<<sbd<<" "<<"Diem 3 mon: "<<m1<<" "<<m2<<" "<<m3<<" "<<"Diem uu tien:"<<bonus<<" "<<"Diem tong:"<<this->calculate()<<" ";
    }
    float calculate(){
        return (m1+m2+m3+bonus);
    }
};
int main(){
    int n,i,response;
    Candidate *data[6969];
    cout<<"Nhap so thi sinh: ";
    cin>>n;
    cout<<"Nhap danh sach:"<<endl;
    for(i=0;i<n;i++){
        cout<<"Chon thi sinh: 1-Binh thuong 2-Uu tien"<<endl;
        cin>>response;
        if(response==1){
            data[i]=new Candidate;
        }else{
            data[i]=new Priotized_Candidate;
        }
        data[i]->in();
    }
    for(i=0;i<n;i++){
        if(data[i]->calculate() >= 15){
            if(data[i]->getMark(1)==0 || data[i]->getMark(2)==0 || data[i]->getMark(3)==0){
                data[i]->out();
                cout<<"Trang thai: Truot"<<endl;
            }else{
                data[i]->out();
                cout<<"Trang thai: Do"<<endl;
            }
        }else{
            data[i]->out();
            cout<<"Trang thai: Truot"<<endl;
        }
    }
    return 0;
}