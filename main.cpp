#include<fstream>
#include<iostream>
#include<string>
#include<cstdlib>
#include <cstring>
#include<stdio.h>
using namespace std;
class file
{
public:
    file()
    {
        ofstream fout;
        fout.open("anish.txt");
        fout<<"anish";
        fout.close();
    }
};
class earn
{
public:
    double profit;
    void show()
    {
        ifstream x("ooo.txt");
        if(!x)
            cout<<"PROFIT = 0 ";
        else
        {
            x>>profit;
            cout<<"\nPROFIT TOTAL DE INCEPUT:  "<<profit<<endl;
            x.close();
        }

    }

};
class product:public virtual earn
{
public:
    int quan;
    char name[20];
    char id[20];
    double percost;
    double persell;
    double cost;
    double sell;
    void cal()
    {
        cost=percost*quan;
        sell=persell*quan;
        profit=profit +(sell-cost)*365;
    }
    void file();
    void get();

};
void product::get()
{
    int s;
    cout<<"\nNUMAR DE PRODUSE?\n";
    cin>>s;
    for(int i=0; i<s; i++)
    {
        cout<<"\nINTRODU NUMELE PRODUSULUI: \n";
        cin>>name;
        cout<<"\nINTRODU ID PRODUS: \n";
        cin>>id;
        cout<<"\nINTRODU PRET DE CUMPARARE PRODUS: \n";
        cin>>percost;
        cout<<"\nINTRODU PRET DE VANZARE PRODUS: \n";
        cin>>persell;
        cout<<"\nINTRODU CANTITATEA TOTALA: \n";
        cin>>quan;
        cal();
        file();
    }

}
void product::file()
{
    char file[20];
    strcpy(file,id);
    strcat(file,".txt");
    ofstream f(file);
    f<< "\nNUME PRODUS: "<<name<< "\nID PRODUS: "<<id<<"\nPRET CUMPARARE PRODUS: " <<percost<<"\nPRET VANZARE PRODUS: "<<persell<<"\nCANTITATE: "<<quan<<"\n COST TOTAL: "<<cost<<"\nVANZARE: "<<sell;
    f.close();
}

class staff:public virtual earn
{
protected:
    double salary;
    char post[12];
    char empid[10];
    int postquan;
    void cal()
    {
        profit=(profit-salary*postquan)*12;
    }
    void getstaff();
    void file();
};
void staff::getstaff()
{
    cout<<"\nINTRODU SALARIU: \n";
    cin>>salary;
    cout<<"\nINTRODU NUMAR DE ANGAJATI: \n";
    cin>>postquan;
    for(int i=0; i<postquan; i++)
    {
        cout<<"INTRODU NUME ANGAJAT\n";
        cin>>post;
        cout<<"\nINTRODU ID ANGAJAT\n";
        cin>>empid;
        cal();
        file();
    }
}
void staff::file()
{
    char file[20];
    strcpy(file,empid);
    strcat(file,".txt");
    ofstream f(file);
    f<< "\nNUMAR DE ANGAJATI CARE MUNCESC: "<<postquan<< "\nSALARIU ANGAJAT: "<<salary<< "\nNUME ANGAJAT :"<<post<<"\nID ANGAJAT: "<<empid;
    f.close();
}

class amount:public staff, public product
{

public:
    void add();
    void update_item();
    void update_emp();

};
void amount::add()
{
    int ch;
    char name[20];
    while(1)
    {
        cout<<"1.)INTRODU PENTRU PRODUS\n2.)INTRODU PENTRU ANGAJATt\n3.)EXIT\n";
        cout<<"TASTA: \n";
        cin>>ch;
        if(ch==1)
        {
            get();
            ofstream x("ooo.txt");
            x<<profit;
            x.close();
        }
        else if(ch==2)
        {
            getstaff();
            ofstream x("ooo.txt");
            x<<profit;
            x.close();
        }
        else if(ch==3)
            break;
        else
            cout<<"TASTA GRESITA\n";
    }
}


void amount::update_item()
{
    char id[20];
    char pid[20];
    char c;
    cout<<"\nINTRODU ID PRODUS PENTRU MODIFICAT\n";
    cin>>id;
    char file[20];
    char file2[20];
    strcpy(file,id);
    strcat(file,".txt");
    fstream fout(file, ios::in|ios::out);
    if(!fout)
    {
        cout<<"ID NU A FOST GASIT. \n";
    }
    else
    {
        cout<<"ID GASIT! \n";
        cout<<"\nSCHIMBA NUME PRODUS: \n";
        cin>>name;
        cout<<"\nSCHIMBA PRET CUMPARARE PRODUS: \n";
        cin>>percost;
        cout<<"\nSCHIMBA PRET VANZARE PRODUS: \n";
        cin>>persell;
        cout<<"\nSCHIMBA CANTITATE TOTALA PRODUS: \n";
        cin>>quan;
        cost=percost*quan;
        sell=persell*quan;
        profit=profit +(sell-cost)*365;
        fout<<"\nNUME PRODUS: "<<name<< "\nID PRODUS: "<<id<<"\nPRET CUMPARARE PRODUS: " <<percost<<"\nPRET VANZARE PRODUS: "<<persell<<"\nCANTITATE: "<<quan<<"\n COST TOTAL: "<<cost<<"\nVANZARE: "<<sell;
        fout.close();
    }
}
void amount::update_emp()
{
    char id[20];
    char c;
    cout<<"\nINTRODU ID ANGAJAT PENTRU MODIFICAT: ";
    cin>>id;
    char file[20];
    strcpy(file,id);
    strcat(file,".txt");
    fstream fout(file, ios::in|ios::out);
    if(!fout)
    {
        cout<<"ID NU A FOST GASIT. \n";
    }
    cout<<"SCHIMBA NUME ANGAJT: \n";
    cin>>post;
    fout<< "\nNUMAR DE ANGAJATI CARE LUCREAZA: "<<postquan<< "\nSALARIU ANGAJAT: "<<salary<< "\nNUME ANGAJAT :"<<post<<"\nID ANGAJAT: "<<empid;
    fout.close();
}

void admin()
{
    while(1)
    {
        cout<<"\n\t\t\t\t\t==============================\n";
        cout<<"\n\t\t\t\t\t        Bine ai venit!  \n";
        cout<<"\n\t\t\t\t\t==============================\n\n";
        cout<<"\n\t\t\t\t\t* * * * * * * * * * * * * * * *\n";
        cout<<"\n\t\t\t\t\t1. Adauga produs\n\n\t\t\t\t\t2. Arata profit\n\n\t\t\t\t\t3. Cauta detalii produs\n\n\t\t\t\t\t4. Cauta detalii angajat\n\n\t\t\t\t\t5. Modifica detalii produs\n\n\t\t\t\t\t6. Modifica detalii angajat\n\n\t\t\t\t\t7. Inapoi\n";
        cout<<"\n\t\t\n\t\t\t\t\t Tasta:";
        int u;
        cin>>u;
        cout<<endl;
        if(u==1)
        {
            amount a;
            a.show();
            a.add();
        }
        else if(u==2)
        {
            amount d;
            d.show();
        }
        else if(u==3)
        {
            char id[20];
            char c;
            cout<<"\nINPUT ID to search\n";
            cin>>id;
            char file[20];
            strcpy(file,id);
            strcat(file,".txt");
            ifstream x(file);
            if(!x)
            {
                cout<<"ID PRODUS NU A FOST GASIT \n";
            }
            while(x)
            {
                x.get(c);
                cout<<c;
            }


            x.close();
        }
        else if(u==4)
        {
            char eid[20];
            char d;
            cout<<"\nINTRODU ID ANGAJAT DE CAUTAT\n";
            cin>>eid;
            char file[20];
            strcpy(file,eid);
            strcat(file,".txt");
            ifstream y(file);
            if(!y)
            {
                cout<<"ID NU A FOST GASIT \n";
            }
            while(y)
            {
                y.get(d);
                cout<<d;
            }

            y.close();
        }
        else if(u==5)
        {
            amount u;
            u.update_item();
        }
        else if(u==6)
        {
            amount v;
            v.update_emp();
        }
        else if(u==7)
        {
            break;
        }
        else cout<<"TASTA GRESITA\n";
    }

}

int main()
{
    int ch;
    char  username[20];
    char password[20];
    char pwd[20];
    while(1)
    {
        cout<<"\n \t\t\t\t\t===============================\n";
        cout<<"\n\t\t\t\t\tBine ai venit in magazinul meu!  \n";
        cout<<"\n \t\t\t\t\t===============================\n\n";
        cout<<"\n \t\t\t\t\t    * * * * * * * * * * * * ";
        cout<<"\n\t\t\t\t\t      1. Acceseaza sistem";
        cout<<"\n\t\t\t\t\t      2. Inapoi";
        cout<<"\n\t\t\t\t\t    * * * * * * * * * * * *\n";
        cout<<"\n\t\t\t\t\t         Tasta: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            admin();
            break;
        case 2:
            exit(0);
            break;
        default:
            cout<<"Tasta: \n";
            break;
        }
    }
    return 0;
}


