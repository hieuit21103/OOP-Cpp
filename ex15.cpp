#include <iostream>
using namespace std;
#define forp(i,a,b) for(i=a;i<b;i++)
class Worker{
protected:
    char wname[50];
    float srate,alw;
public:
    Worker(){
        srate=0;
        alw=0;
    }
    ~Worker(){}
    virtual void in(){
        cout<<"Nhap ten:"; fflush(stdin); cin>>wname;
        cout<<"Nhap he so luong:"; cin>>srate;
        cout<<"Nhap phu cap:"; cin>>alw;
    }
    virtual void out(){
        cout<<"Ten:"<<wname<<endl;
        cout<<"He so luong:"<<srate<<endl;
        cout<<"Phu cap:"<<alw<<endl;
    }
    virtual float salary(){
        return srate*1310+alw;
    }
    virtual float bonus(){
        return 3*this->salary();
    }
    float getSRate(){
        return this->srate;
    }
};
class Staff : public Worker{
protected:
    float oalw;
public:
    Staff(){
        srate=0;
        alw=0;
        oalw=0;
    }
    ~Staff(){}
    void in(){
        Worker::in();
        cout<<"Nhap phu cap dac thu:"; cin>>oalw;
    }
    void out(){
        Worker::out();
        cout<<"Phu cap dac thu:"<<oalw<<endl;
    }
    float salary(){
        return srate*1310+alw+oalw;
    }
    float bonus(){
        return 3.5*this->salary();
    }
};
int main(){
    int n,i,j,response;
    Worker *list[50000];
    cout<<"Nhap so luong nhan vien:"; cin>>n;
    cout<<"Nhap danh sach:";
    forp(i,0,n){
        cout<<"Chon cap bac: 1-Cong nhan 2-Can bo";
        cin>>response;
        if(response==1){
            list[i]=new Worker;
        }else if(response==2){
            list[i]=new Staff;
        }else{
            cout<<"Error";
        }
        list[i]->in();
    }
    for(i=n-1;i>=0;i--){
        for(j=1;j<=i;j++){
            if(list[j-1]->salary() > list[j]->salary()){
                swap(list[j-1],list[j]);
            }
        }
    }
    int z = n/10;
    forp(i,0,z){
        if(list[i]->getSRate() > 3){
            if(z<n) z++;
        }else{
            list[i]->out();
        }
    }
    return 0;
}