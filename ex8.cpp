#include <iostream>
#include <cstring>
using namespace std;
class Student{
public:
    int msv;
    char ten[50],nganh[50];
    Student(){
        msv=0;
    }
    Student(int id){
        msv=id;
    }
    void in(){
        cout<<"Ma hoc vien:";
        cin>>msv;
        cout<<"Ten Hoc vien:";
        fflush(stdin); 
        cin.get(ten,50);
        cout<<"Nganh:";
        fflush(stdin);
        cin.get(nganh,50);
    }
    void out(){
        cout<<"Ma hoc vien:"<<msv<<" ";
        cout<<"Ten Hoc vien:"<<ten<<" ";
        cout<<"Nganh:"<<nganh<<endl;
    }
};
void swap(Student a,Student b){
    Student c=a;
    a=b;
    b=c;
}
int main(){
    int n,i;
    char find[50];
    Student *data;
    cin>>n;
    data = new Student[n];
    for ( i = 0; i < n; i++)
    {
        /* code */
        data[i].in();
    }
    for ( i = 0; i < n; i++)
    {
        /* code */
        data[i].out();
    }
    fflush(stdin);
    cin.get(find,50);
    for ( i = n-1; i >=0; i--)
    {
        for(int j = 1;j<=i;j++){
            if(strcmp(data[j-1].nganh,data[j].nganh) < 0){
                swap(data[j-1],data[j]);
            }else if(strcmp(data[j-1].nganh,data[j].nganh) == 0){
                if(strcmp(data[j-1].ten,data[j].ten) < 0){
                    swap(data[j-1],data[j]);
                }
            }
        }
        
    }
    for ( i = 0; i < n; i++)
    {
        if(strcmp(find,data[i].nganh)==0){
            data[i].out();
        }
    }
    return 0;
}