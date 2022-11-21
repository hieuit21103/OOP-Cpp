#include <iostream>
#define forp(i,a,b) for(i=a;i<b;i++)
using namespace std;
class Lib_Card{
protected:
    int cid,rdays;
    float feepd;
public:
    Lib_Card(){
        cid=0;
        rdays=0;
        feepd=0;
    }
    ~Lib_Card(){}
    virtual void in(){
        cout<<"Nhap ma the:"; cin>>cid;
        cout<<"Nhap so ngay muon:"; cin>>rdays;
        cout<<"Nhap phi theo ngay:"; cin>>feepd;
    }
    virtual void out(){
        cout<<"Ma the:"<<cid<<" "<<"So ngay muon:"<<rdays<<" "<<"Phi theo ngay:"<<feepd<<endl;
    }
    virtual float calculate_fee(){
        return rdays*feepd;
    }
    float getRDays(){
        return rdays;
    }
};
class Priotized_Lib_Card : public Lib_Card{
protected:
    float discount;
public:
    Priotized_Lib_Card(){
        discount=0;
    }
    ~Priotized_Lib_Card(){}
    void in(){
        Lib_Card::in();
        cout<<"Ti le giam gia(%): "; cin>>discount;
    }
    void out(){
        Lib_Card::out();
        cout<<"Giam gia:"<<discount<<"%"<<endl;
    }
    float calculate_fee(){
        return rdays*feepd*(1-discount/100);
    }
};
void swap(Lib_Card a,Lib_Card b){
    Lib_Card c=a;
    a=b;
    b=c;
}
int main(){
    int n,i,j,response;
    Lib_Card *list[15000];
    cout<<"Nhap so luong the:"; cin>>n;
    cout<<"Nhap danh sach"<<endl;
    forp(i,0,n){
        cout<<"Nhap loai the: 1-Binh thuong 2-Uu tien";
        cin>>response;
        if(response==1){
            list[i]=new Lib_Card;
        }else if(response==2){
            list[i]=new Priotized_Lib_Card;
        }else{
            cout<<"Error";
        }
        list[i]->in();
    }
    forp(i,0,n){
        list[i]->out();
    }
    for(i=n-1;i>=0;i--){
        for(j=1;j<=i;j++){
            if(list[j-1]->calculate_fee() < list[j]->calculate_fee()){
                swap(list[j-1],list[j]);
            }
        }
    }
    int z = n/10;
    forp(i,0,z){
        if(list[i]->getRDays() <= 10){
            if(z<n) z++;
        }else{
            list[i]->out();
        }
    }
    return 0;
}