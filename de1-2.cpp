#include <iostream>
#include <cstring>
using namespace std;

class Book{
protected:
    string name;
    string author;
    int yob;
    string nxb;
public:
    Book(){
        name=author=nxb="";
        yob=0;
    }
    ~Book(){}
    virtual void nhap(){
        cin>>name>>author>>yob>>nxb;
    }
    virtual void xuat(){
        cout<<name<<" "<<author<<" "<<yob<<" "<<nxb<<endl;
    }   
};
class ListBook : public Book{
int n; //Số lượng sách trong danh sách
public:
    ListBook(){
        n=0;
    }
    ListBook(int n){
        this->n=n;
    }
    ~ListBook(){}
    void nhap(){
        int i;
        for(i=0;i<n;i++){
            Book::nhap();
        }
    }
    void xuat(){
        int i;
        for(i=0;i<n;i++){
            Book::xuat();
        }
    }
};
class Student{
protected:
    string name; //Tên học sinh
    int id; //Mã số
    string major; //Khoa
    string lop; //Lớp
    string list[100]; //Danh sách sách đã mượn
    int n; // Số lượng sách mượn
public:
    Student(){
        name=major=lop="";
        id=0;
    }
    ~Student(){}
    virtual void nhap(){
        cin>>name>>id>>major>>lop;
        cin>>n;
        cout<<"Nhap danh sach"<<endl;
        for (int i = 0; i < n; i++)
        {
            cin>>list[i];
        }
    }
    virtual void xuat(){
        cout<<name<<" "<<id<<" "<<major<<" "<<lop<<"List: ";
        for(int i=0;i<n-1;i++){
            cout<<list[i]<<",";
        }
        cout<<list[n-1]<<endl;
    }
    int getAmount(){ //Lấy số lượng
        return n;
    }
};
class ListStudent : public Student{
int n; //Số lượng học sinh
Student st[100];
public:
    ListStudent(int n){
        this->n=n;
    }
    ~ListStudent(){}
    void nhap(){
        int i;
        for(i=0;i<n;i++){
            st[i].nhap();
        }
    }
    void xuat(){
        int i;
        for(i=0;i<n;i++){
            st[i].xuat();
        }
    }
    void swap(int a,int b){
        int c=a;
        a=b;
        b=c;
    }
    Student sosanh(){
        int x,i,max=st[0].getAmount();
        for(i=0;i<n;i++){
            if(st[i].getAmount() > max){
                swap(max,st[i].getAmount());
                x=i;
            }
        } // Tìm sv mượn nhiều sách nhất
        return st[x];
    }
};

int main(){
    return 0;
}