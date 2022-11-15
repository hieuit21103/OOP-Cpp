#include <iostream>
#include <cstring>
using namespace std;

class Student{
public:
    char name[50];
    int id;
    float avg;
    Student(){
        id=0;
        avg=0;
    }
    ~Student(){}
    void in(){
        cout<<"MSV="; cin>>id;
        cout<<"Ten="; 
        fflush(stdin);
        cin.get(name,50);
        cout<<"Diem trung binh="; cin>>avg;
    }
    void out(){
        cout<<"MSV="<<id<<" ";
        cout<<"Ten="<<name<<" ";
        cout<<"Diem trung binh="<<avg<<endl;
    }

};
class List{
    Student *data;
    int n;
public:
    List(){
        n=0;
        data=NULL;
    }
    ~List(){
        delete[] data;
    }
    List(int size){
        n=size;
        data= new Student[size];
    }
    void in(){
        for (int i = 0; i < n; i++)
        {
            /* code */
            cout<<"Sinh vien thu "<<i+1<<":"<<endl;
            data[i].in();
        }
        
    }
    void out(){
        cout<<"Danh sach sinh vien:"<<endl;
        for (int i = 0; i < n; i++)
        {
            /* code */
            data[i].out();
        }    
    }
    int max(){
        float max=0;
        max=data[0].avg;
        for (int i = 1; i < n; i++)
        {
            /* code */
            if (data[i].avg > max)
            {
                /* code */
                max=data[i].avg;
            }
            
        }
    return max;
    }
    void sort(){
        int i,j;
        for ( i = (n-1); i >=0; i--)
        {
            /* code */
            for ( j = 1; j <= i; j++)
            {
                /* code */
                if(strcmp(data[j-1].name,data[j].name) > 0){
                    strcmp(data[j-1].name,data[j].name);
                }else if (strcmp(data[j-1].name,data[j].name) == 0)
                {
                    /* code */
                    if (data[j-1].id > data[j].id)
                    {
                        /* code */
                        strcmp(data[j-1].name,data[j].name);
                    }
                    
                }
                
            }   
            
        }  
    }
    void swap(Student a,Student b){
        Student mid=a;
        a=b;
        b=mid;
    }
};
int main(){
    int n;
    cin>>n;
    List l1(n);
    l1.in();
    l1.sort();
    l1.out();


    return 0;
}