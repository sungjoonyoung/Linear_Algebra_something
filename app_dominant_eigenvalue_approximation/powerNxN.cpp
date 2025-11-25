#include<iostream>
#include<cmath>
#include<fstream>
#include<vector>
using namespace std;
ofstream fout("coordinate.txt");
int N;
double A[100][100];
double X[100];
double eigenval=0;
int e=0;
void start(void);
vector<string> string_pasing(string a);
double norm_cal(double arr[]){
    double out=0;
    for(int i=0;i<N;i++){
        out+=arr[i]*arr[i];
    }
    return sqrt(out);
}
void mat_cal(int op){
    for(int i=0;i<N;i++)fout<<X[i]<<",";
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
    for(int i=0;i<N;i++)X[i]=tmp[i]/norm;
}
int main(void){
    while(1){
        start();
        fout.clear();
        for(int i=0;i<e;i++){
            fout<<"(";
            mat_cal((i==e-1));
            fout<<"),\n";
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
        if(op){
            fout.close();
            return 0;
        }
    }
}
void start(void){
    // cout<<"only 2*2 matrix.\n";
    while(1){
        cout<<"N*N matrix(N<=100)\n";
        cout<<"N ? : ";
        cin>>N;
        if(N<=100)break;
    }
    //
    cout<<"\nreading yout matrix (mat.csv)\n";
    string file = "mat.csv";
    ifstream fin(file);
    if(fin){
        string str;
        for(int i=0;i<N;i++){
            fin>>str;
            vector<string> row=string_pasing(str);
            for(int j=0;j<N;j++)A[i][j]=stod(row[j]);
        }
    }
    fin.close();
    //
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
    cout<<"\nX is \n";
    for(int i=0;i<N;i++){
        cout<<X[i]<<", ";
    }
    cout<<"it will be "<<e<<"times.\n";
    cout<<"\nrunning..\n";
}
vector<string> string_pasing(string a) {
    vector<string> data;
    string in="";
    for(int i=0;i<a.size();i++){
        if(a[i]==' ')continue;
        if(a[i]==','){
            data.push_back(in);
            in="";
        }
        else in+=a[i];
    }
    if(in!="")data.push_back(in);
    return data;
}