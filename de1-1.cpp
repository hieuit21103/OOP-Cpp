#include <iostream>
using namespace std;
class matrix{
    int n;
    int **a;
public:
    matrix(){
        this->n=0;
    }
    matrix(int n){
        this->n=n;
    }
    ~matrix(){
        for(int i=0;i<n;i++){
            delete []a[i];
        }
        delete []a;
        n=0;
    }
    friend ostream &operator<<(ostream &os,matrix &mt){
        int i,j;
        for(i=0;i<mt.n;i++){
            for(j=0;j<mt.n;j++){
                os<<mt.a[i][j]<<" ";
            }
            os<<endl;
        }
        return os;
    }
    friend istream &operator>>(istream &is,matrix &mt){
        int i,j;
        cout<<"Nhap size ma tran:"; is>>mt.n;
        mt.a = new int*[mt.n];
        for(i=0;i<mt.n;i++){
            mt.a[i]=new int[mt.n];
        }
        for(i=0;i<mt.n;i++){
            for(j=0;j<mt.n;j++){
                is>>mt.a[i][j];
            }
        }
        return is;
    }
    friend matrix &operator+(matrix &mt1,matrix &mt2){
        matrix mt3;
        int i,j;
        mt3.a = new int*[mt1.n];
        for(i=0;i<mt1.n;i++){
            mt3.a[i]=new int[mt1.n];
        }
        for(i=0;i<mt1.n;i++){
            for(j=0;j<mt1.n;j++){
                mt3.a[i][j]=mt1.a[i][j]+mt2.a[i][j];
            }
        }
        return mt3;
    }
    friend matrix &operator++(matrix &mt1){
        int i,j;
        for(i=0;i<mt1.n;i++){
            for(j=0;j<mt1.n;j++){
                mt1.a[i][j]++;
            }
        }
        return mt1;
    }
    void operator=(const matrix &mt1) {
        n=mt1.n;
        for(int i=0; i<mt1.n; i++) {
            for(int j=0; j<mt1.n; j++) {
                a[i][j]=mt1.a[i][j];
            }
        }
    }
};
int main(){
    matrix mt[100];
    int n,i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>mt[i];
    }
    for(i=0;i<n;i++){
        matrix sum;
        sum=sum+mt[i];
    }
    return 0;
}

/*type tenham(thamso){
    return type;
}*/