#include<iostream>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#define forp(i,a,b) for (int i=a; i<b; i++)
#define form(i,a,b) for (int i=a; i>b; i--)
#define forpequal(i,a,b) for (int i=a; i<=b; i++)
#define formequal(i,a,b) for (int i=a; i>=b; i--)
#define pi 3.14
#define ll long long
#define l long
#define db double
#define fl float
#define maxint 2147483647
#define minint -2147483648
using namespace std;
class matrix{
int n,m;
int **x;
public:
matrix(){
n=m=0;
x=new int*[n];
forp(i,0,m){
x[i]=new int[m];
}
}
matrix(const int &rows,const int &cols );
~matrix(){
forp (i,0,n){
delete[] this->x[i];
}
delete[] this->x;
}
matrix(const matrix &other);
friend istream &operator>>(istream &is, matrix &a);
friend ostream &operator<<(ostream &os, matrix &a);
friend matrix operator+(matrix a, matrix b);
// matrix operator+(matrix b);
friend matrix operator-(matrix a, matrix b);
// friend matrix operator*(matrix a, matrix b);
matrix &operator++();//++x
matrix &operator++(int);//x++
// void operator=(const matrix &a)const;
matrix operator=(const matrix &a)const;
};
matrix::matrix(const matrix &other) //copy constructor
{
this->n=other.n;
this->m=other.m;
this->x = new int* [other.n];
for(int i =0;i<other.n;i++)
{
this->x[i]=new int[other.m];
}
for(int i=0;i<other.n;i++)
for(int j=0;j<other.m;j++)
this->x[i][j]=other.x[i][j];
}
///
matrix::matrix(const int &rows, const int &cols){
this->n=rows;
this->m=cols;
x=new int* [cols];
for(int i =0;i<rows;i++)
x[i]=new int[cols];
for(int i=0;i<rows;i++)
for(int j=0;j<cols;j++)
x[i][j]=0;
}
////
matrix matrix::operator=(const matrix &a)const{
if (this != &a){
*this=matrix(a);
forp (i,0,a.n)
forp(j,0,a.m)
this->x[i][j]=a.x[i][j];
}
return *this;
}
matrix& matrix::operator++(){ //r
forp(i,0,n){
forp(j,0,m){
this->x[i][j] = ++x[i][j];
}
}
return *this;
}
matrix& matrix::operator++(int){//r
static matrix temp=*this;
forp(i,0,n){
forp(j,0,m){
temp.x[i][j]=x[i][j];
x[i][j]++;
}
}
return temp;
}
istream &operator>>(istream &is, matrix &a){ //r
cout<<"Nhap kich thuoc ma tran ";
is>>a.n>>a.m;
a.x = new int*[a.n];
forp (i,0,a.n){
a.x[i]=new int[a.m];
forp(j,0,a.m){
cin>>a.x[i][j];
}
}
return is;
}
ostream &operator<<(ostream &os, matrix &a){ //r
forp(i,0,a.n){
forp(j,0,a.m){
os<<a.x[i][j]<<" ";
}
os<<endl;
}
return os;
}
matrix operator+(matrix a, matrix b){
static matrix c(a.n, a.m);
if (a.m==b.m && a.n==b.n){
forp(i,0,c.n){
forp(j,0,c.m){
c.x[i][j] = a.x[i][j]+b.x[i][j];
}
}
}
cout<<c;
return c;
}
matrix operator-(matrix a, matrix b){
matrix c;
forp(i,0,c.n){
forp(j,0,c.m){
c.x[i][j]=a.x[i][j]-b.x[i][j];
}
}
return c;
}
int main(){
matrix a,b,c,d;
cin>>a;
cin>>b;
cout<<a;
cout<<b;
d = a+b;
cout<<d;
return 0;
}