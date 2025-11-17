#include<iostream>
#include<cmath>
using namespace std;
int N;
double A[100][100];
double X[100];
double eigenval=0;
int e=0;
void start(void);
double norm_cal(double arr[]){
    double out=0;
    for(int i=0;i<N;i++){
        out+=arr[i]*arr[i];
    }
    return sqrt(out);
}
void mat_cal(int op){
    double tmp[100];
    for(int j=0;j<N;j++){
        tmp[j]=0;
        for(int k=0;k<N;k++){
            tmp[j]+=A[j][k]*X[k];
        }
    }
    //
    eigenval=0;
    for(int i=0;i<N;i++)eigenval+=X[i]*tmp[i];
    //
    double norm=norm_cal(tmp);
    // cout<<"A"<<norm<<"\n";
    for(int i=0;i<N;i++)X[i]=tmp[i]/norm;
}
int main(void){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    while(1){
        start();
        for(int i=0;i<e;i++){
            mat_cal((i==e-1));
        }
        cout<<"eigen vector : ";
        for(int i=0;i<N;i++)cout<<X[i]<<", ";
        cout<<"\n";
        // cout<<X[0]<<", "<<X[1]<<"\n";
        cout<<"eigen value : ";
        cout<<eigenval<<"\n";
        bool op=1;
        cout<<"exit?(1 or 0) : ";
        cin>>op;
        if(op)return 0;
    }
}
void start(void){
    // cout<<"only 2*2 matrix.\n";
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
    for(int i=0;i<N;i++){
        cout<<"X_"<<i+1<<"? : ";
        cin>>X[i];
    }
    cout<<"how many iterate? : ";
    cin>>e;
    cout<<"your mat\n";
    for(int i=0;i<N;i++){
        cout<<"| ";
        for(int j=0;j<N;j++){    
            cout<<A[i][j]<<" ";
        }    
        cout<<"|";
        cout<<"\n";
    }
    cout<<"\n\nX is \n";
    for(int i=0;i<N;i++){
        cout<<X[i]<<", ";
    }
    cout<<"it will be "<<e<<"times.\n";
    cout<<"\n\nrunning..\n\n\n";
}