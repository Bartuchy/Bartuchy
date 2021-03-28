#include <iostream>
#include <windows.h>
#include <math.h>
#include <fstream>
#include <iomanip>

using namespace std;

void podstawowa(double **macierz, int n)
{
    cout<<"MACIERZ"<<endl<<endl;

    for(int i=0; i<n; i++){
        for(int j=0; j<=n; j++){
            cout<<setw(6)<<macierz[i][j];
        }
        cout<<endl;
    }

    double p;
    for(int i=0; i<n-1; i++){
        if(fabs(macierz[i][i])>1e-7){
            for(int j=i+1; j<n; j++){
                p=macierz[j][i]/macierz[i][i];
                for(int k=0; k<=n; k++){
                    macierz[j][k] -= p*macierz[i][k];
                }
            }
        }
        else continue;
    }

    cout<<endl<<"MACIERZ po przeksztalceniach"<<endl<<endl;

    for(int i=0; i<n; i++){
        for(int j=0; j<=n; j++){
            cout<<setw(15)<<macierz[i][j];
        }
        cout<<endl;
    }

    double *X = new double[n];
    bool rozw=true;



    for(int i=n-1; i>=0; i--){
        if(fabs(macierz[i][i])<=1e-7){
            rozw=false;
            break;
        }
        double b = macierz[i][n];
        for(int j=n-1; j>i; j--){
            b -= macierz[i][j]*X[j];
        }
        X[i]=b/macierz[i][i];
    }
    cout<<endl;

    if(rozw==false)
        cout<<"Brak rozwiazan, 0 na glownej przekatnej"<<endl;

    else{
         cout<<"Rozwiazania ukladu:"<<endl;
    for(int i=0; i<n; i++)
        cout<<"x"<<i+1<<" = "<<X[i]<<endl;
    cout<<endl<<endl;
    }

    delete[] macierz;
    delete[] X;
}

void maxKolumna(double **macierz, int n)
{
    cout<<"MACIERZ"<<endl<<endl;

    for(int i=0; i<n; i++){
        for(int j=0; j<=n; j++){
            cout<<setw(6)<<macierz[i][j];
        }
        cout<<endl;
    }
    cout<<endl;

    double p;
    int kk;
    double a;

    for(int i=0; i<n-1; i++){
        a=0;
        if(fabs(macierz[i][i])>1e-7){
            for(int j=i; j<n; j++){
                    if(fabs(macierz[j][i])>a){
                        a=fabs(macierz[j][i]);
                        kk=j;
                    }
                }


            if(i != kk){
                for(int j=0; j<=n; j++){
                    swap(macierz[i][j],macierz[kk][j]);
                }
            }

           for(int j=i+1; j<n; j++){
                p=macierz[j][i]/macierz[i][i];
                for(int k=0; k<=n; k++){
                    macierz[j][k] -= p*macierz[i][k];
                }
            }
        }
        else continue;
    }

    cout<<endl<<"MACIERZ po przeksztalceniach"<<endl<<endl;

    for(int i=0; i<n; i++){
        for(int j=0; j<=n; j++){
            cout<<setw(15)<<macierz[i][j];
        }
        cout<<endl;
    }

    double *X = new double[n];
    bool rozw=true;

    for(int i=n-1; i>=0; i--){
        if(fabs(macierz[i][i])<=1e-7){
            rozw=false;
            break;
        }
        double b = macierz[i][n];
        for(int j=n-1; j>i; j--){
            b -= macierz[i][j]*X[j];
        }
        X[i]=b/macierz[i][i];
    }
    cout<<endl;

    if(rozw==false)
        cout<<"Brak rozwiazan, 0 na glownej przekatnej"<<endl;
    else{
         cout<<"Rozwiazania ukladu:"<<endl;
    for(int i=0; i<n; i++)
        cout<<"x"<<i+1<<" = "<<X[i]<<endl;
    cout<<endl<<endl;
    }



    delete[] macierz;
    delete[] X;
}

void maxWiersz(double **macierz, int n)
{
    cout<<"MACIERZ"<<endl<<endl;

    for(int i=0; i<n; i++){
        for(int j=0; j<=n; j++){
            cout<<setw(6)<<macierz[i][j];
        }
        cout<<endl;
    }
    cout<<endl;

    double p;
    int jj, kk;
    double a;
    double *historia = new double[n];
    for(int l=0; l<n; l++)
        historia[l]=l;

    for(int i=0; i<n-1; i++){
        a=0;
        if(fabs(macierz[i][i])>1e-7){
            for(int j=i; j<n; j++){
                    if(fabs(macierz[i][j])>a){
                        a=fabs(macierz[i][j]);
                        jj=j;
                    }
                }

            if(i != jj ){
                for(int j=0; j<n; j++){
                    swap(macierz[j][i],macierz[j][jj]);
                }
                swap(historia[i],historia[jj]);
            }


           for(int j=i+1; j<n; j++){
                p=macierz[j][i]/macierz[i][i];
                for(int k=0; k<=n; k++){
                    macierz[j][k] -= p*macierz[i][k];
                }
            }
        }
        else continue;
    }

    cout<<endl<<"MACIERZ po przeksztalceniach"<<endl<<endl;

    for(int i=0; i<n; i++){
        for(int j=0; j<=n; j++){
            cout<<setw(15)<<macierz[i][j];
        }
        cout<<endl;
    }

    double *X = new double[n];
    bool rozw=true;

    for(int i=n-1; i>=0; i--){
        if(fabs(macierz[i][i])<=1e-7){
            rozw=false;
            break;
        }
        double b = macierz[i][n];
        for(int j=n-1; j>i; j--){
            b -= macierz[i][j]*X[j];
        }
        X[i]=b/macierz[i][i];
    }
    cout<<endl;

    if(rozw==false)
        cout<<"Brak rozwiazan, 0 na glownej przekatnej"<<endl;
    else{
         cout<<"Rozwiazaniaukladu:"<<endl;
    for(int i=0; i<n; i++)
        cout<<"x"<<historia[i]+1<<" = "<<X[i]<<endl;
    cout<<endl<<endl;
    }

    delete[] macierz;
    delete[] X;
}

void maxPelna(double **macierz, int n)
{

    cout<<"MACIERZ"<<endl<<endl;

    for(int i=0; i<n; i++){
        for(int j=0; j<=n; j++){
            cout<<setw(6)<<macierz[i][j];
        }
        cout<<endl;
    }
    cout<<endl;

    double p;
    int jj, kk;
    double a;
    double *historia = new double[n];
    for(int l=0; l<n; l++)
        historia[l]=l;

    for(int i=0; i<n-1; i++){
        a=0;
        if(fabs(macierz[i][i])>1e-7){
            for(int j=i; j<n; j++){
                for(int k=i; k<n; k++){
                    if(fabs(macierz[j][k])>a){
                        a=fabs(macierz[j][k]);
                        jj=j;
                        kk=k;
                    }
                }
            }

            if(i != jj ){
                for(int j=0; j<=n; j++)
                    swap(macierz[i][j],macierz[jj][j]);
            }

            if(i != kk){
                for(int j=0; j<n; j++){
                    swap(macierz[j][i],macierz[j][kk]);
                }
                swap(historia[i],historia[kk]);
            }

           for(int j=i+1; j<n; j++){
                p=macierz[j][i]/macierz[i][i];
                for(int k=0; k<=n; k++){
                    macierz[j][k] -= p*macierz[i][k];
                }
            }
        }
        else continue;
    }

    cout<<endl<<"MACIERZ po przeksztalceniach"<<endl<<endl;

    for(int i=0; i<n; i++){
        for(int j=0; j<=n; j++){
            cout<<setw(15)<<macierz[i][j];
        }
        cout<<endl;
    }

    double *X = new double[n];
    bool rozw=true;

    for(int i=n-1; i>=0; i--){
        if(fabs(macierz[i][i])<=1e-7){
            rozw=false;
            break;
        }

        double b = macierz[i][n];

        for(int j=n-1; j>i; j--){
            b -= macierz[i][j]*X[j];
        }
        X[i]=b/macierz[i][i];
    }
    cout<<endl;

    if(rozw==false)
        cout<<"Brak rozwiazan, 0 na glownej przekatnej"<<endl;

    else{
         cout<<"Rozwiazania ukladu:"<<endl;

        for(int i=0; i<n; i++)
            cout<<"x"<<historia[i]+1<<" = "<<X[i]<<endl;
        cout<<endl<<endl;
    }
    delete[] macierz;
    delete[] X;
}

double **wczytajDane(int &n, double **macierz)
{

    ifstream file;
    file.open("dane.csv");

    file>>n;
    macierz = new double*[n];
    for(int i=0; i<n; i++)
        macierz[i] = new double[n+1];

    char semicolumn;
    for(int i=0; i<n+1; i++)
        file>>semicolumn;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            file>>macierz[i][j];
            file>>semicolumn;
        }
        file >> semicolumn;
        file >> macierz[i][n];
    }
    file.close();
    cout<<"\nDane zostaly wczytane"<<endl<<endl;
    return macierz;
}

int main()
{
    int x=0;
    int n;
    double **macierz;

    while(x!=5){

        cout<<"WYBIERZ OPCJE"<<endl;
        cout<<"1 - wczytanie danych z pliku"<<endl;
        cout<<"2 - metoda eliminacji Gaussa bez wyboru elementu"<<endl;
        cout<<"31 - metoda eliminacji Gaussa z wyborem elementu w wierszach"<<endl;
        cout<<"32 - metoda eliminacji Gaussa z wyborem elementu w kolumnach"<<endl;
        cout<<"4 - metoda eliminacji Gaussa z pelnym wyborem elementu"<<endl;
        cout<<"5 - EXIT"<<endl;
        cin>>x;

        switch(x){

            case 1:
                wczytajDane(n, macierz);
                break;

            case 2:
                system("cls");
                podstawowa(wczytajDane(n, macierz), n);
                break;

            case 31:
                system("cls");
                maxWiersz(wczytajDane(n, macierz), n);
                break;

            case 32:
                system("cls");
                maxKolumna(wczytajDane(n, macierz), n);
                break;

            case 4:
                system("cls");
                maxPelna(wczytajDane(n, macierz), n);
                break;

            case 5:
                system("cls");
                cout<<"Wychodzenie..."<<endl;
                break;

            default:
                system("cls");
                cout<<"Niepoprawny wybor!"<<endl;
                break;
        }
    }

    return 0;
}
