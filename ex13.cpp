#include <iostream>
using namespace std;
class Patient{
protected:
    char pname[50],fname[50],dname[50];
    int pid,yob;
public:
    Patient(){
        pid=0;
        yob=0;
    }
    ~Patient(){}
    virtual void in(){
        cout<<"Nhap ma ho so:"; cin>>pid;
        cout<<"Nhap ten benh nhan:"; fflush(stdin); cin.get(pname,50);
        cout<<"Nhap nam sinh:"; cin>>yob;
        cout<<"Nhap ten benh:"; fflush(stdin); cin.get(dname,50);
        cout<<"Nhap khoa dieu tri:"; fflush(stdin); cin.get(fname,50);
    }
    virtual void out(){
        cout<<"Ma ho so:"<<pid<<" "<<"Ten benh nhan:"<<pname<<" "<<"Nam sinh:"<<yob<<" ";
        cout<<"Ten benh:"<<dname<<" "<<"Khoa dieu tri:"<<fname<<" ";
    }
    int getPatientId(){
        return this->pid;
    }
};
class Insider : public Patient{
protected:
    int bid,rid;
public:
    Insider(){
        bid=0;
        rid=0;
    }
    ~Insider(){}
    void in(){
        Patient::in();
        cout<<"Nhap ma phong:"; cin>>rid;
        cout<<"Nhap ma giuong:"; cin>>bid;
    }
    void out(){
        Patient::out();
        cout<<"Ma phong:"<<rid<<" "<<"Ma giuong:"<<bid<<endl;
    }
};
class Outsider : public Patient{
protected:
    int mid;
public:
    Outsider(){
        mid=0;
    }
    ~Outsider(){}
    void in(){
        Patient::in();
        cout<<"Nhap ma don thuoc:"; cin>>mid;
    }
    void out(){
        Patient::out();
        cout<<"Ma don thuoc:"<<mid<<endl;
    }
};
void swap(Patient a,Patient b){
    Patient c=a;
    a=b;
    b=c;
}
int main(){
    int n,i,j,response;
    Patient *list[6969];
    cout<<"Nhap so benh nhan:"; cin>>n;
    cout<<"Nhap danh sach benh nhan"<<endl;
    for(i=0;i<n;i++){
        cout<<"Chon loai benh nhan: 1-Noi tru ; 2-Ngoai tru:"; cin>>response;
        if(response==1){
            list[i]=new Insider;
        }else if(response==2){
            list[i]=new Outsider;
        }else{
            cout<<"Error";
        }
        list[i]->in();
    }
    for(i=n-1;i>=0;i--){
        for(j=1;j<=i;j++){
            if(list[j-1]->getPatientId() > list[j]->getPatientId()){
                swap(list[j-1],list[j]);
            }
        }
    }
    for(i=0;i<n;i++){
        list[i]->out();
    }
    return 0;
}