#include<iostream>
#include<cmath>
using namespace std;
int N;
double A[100][100];
double L[100][100];
double U[100][100];
double B[100][100];
void start(void);
void fail(void);
int scala_cal(int x);
void minus_cal(int x,int y);
void forc_cal(void);
void mat_cal(void){
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)U[i][j]=A[i][j];
    for(int i=0;i<N;i++)L[i][i]=1;

    for(int i=0;i<N;i++)for(int j=0;j<N;j++){
        if(i<j)continue;
        if(i==j){
            if(!scala_cal(i)){fail();return;}
        }
        else{
            if(U[i][j]==0)continue;
            else minus_cal(i,j);
        }
    }
    cout<<"L mat : \n";
    for(int i=0;i<N;i++){
        cout<<"|";
        for(int j=0;j<N;j++){
            cout.precision(2);
            cout.width(8);
            cout<<L[i][j]<<"|";
        }
        cout<<"\n";
    }
    cout<<"U mat : \n";
    for(int i=0;i<N;i++){
        cout<<"|";
        for(int j=0;j<N;j++){
            cout.precision(2);
            cout.width(8);    
            cout<<U[i][j]<<"|";
        }
        cout<<"\n";
    }
    forc_cal();
    cout<<"L*U mat : \n";
    for(int i=0;i<N;i++){
        cout<<"|";
        for(int j=0;j<N;j++){
            cout.precision(2);
            cout.width(8);    
            cout<<B[i][j]<<"|";
        }
        cout<<"\n";
    }
    cout<<"origin mat\n";
    for(int i=0;i<N;i++){
        cout<<"|";
        for(int j=0;j<N;j++){    
            cout.precision(2);
            cout.width(8);    
            cout<<A[i][j]<<"|";
        }    
        // cout<<"|";
        cout<<"\n";
    }
}
int main(void){
    cout<<fixed;
    while(1){
        start();
        mat_cal();


        bool op=1;
        cout<<"exit?(1 or 0) : ";
        cin>>op;
        if(op)return 0;
    }
}
void start(void){
    while(1){
        cout<<"N*N matrix(N<=50)\n";
        cout<<"N ? : ";
        cin>>N;
        if(N<=50)break;
    }
    for(int i=0;i<N;i++)for(int j=0;j<N;j++){
        cout<<"A_"<<i+1<<" "<<j+1<<"? : ";
        cin>>A[i][j];
    }
    
    cout<<"your mat\n";
    for(int i=0;i<N;i++){
        cout<<"|";
        for(int j=0;j<N;j++){    
            cout.precision(2);
            cout.width(8);    
            cout<<A[i][j]<<"|";
        }    
        // cout<<"|";
        cout<<"\n";
    }
    cout<<"\n\nrunning..\n\n\n";
}
void fail(void){
    cout<<"it cannot be decomposion\n";
}
int scala_cal(int x){
    double tmp=U[x][x];
    if(tmp==0)return 0; //cant be decomposition
    if(tmp==1)return 1;
    for(int i=x;i<N;i++){
        U[x][i]/=tmp;
    }
    L[x][x]*=tmp;
    return 1;
}
void minus_cal(int x,int y){
    double tmp=U[x][y];
    for(int i=y;i<N;i++){
        U[x][i]-=tmp*U[y][i];
    }
    L[x][y]+=tmp;
}
void forc_cal(void){
    for(int i=0;i<N;i++)for(int j=0;j<N;j++){
        for(int k=0;k<N;k++){
            B[i][j]+=L[i][k]*U[k][j];
        }
    }
}