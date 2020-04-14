#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

typedef struct karakter
{
    string data_karakter;
    karakter *next_karakter;
};
karakter *head_karakter;

void initHead();
int Emptykarakter();
void insertkarakter(int datakarakter);
void tampilList();
void hapuskarakter();

void initHead()
    {
        head_karakter = NULL;
    }

int Emptykarakter()
    {
        return (head_karakter==NULL)?1:0;
    }

void insertkarakter(string datakarakter)
{
    karakter *baru,*bantu;
    baru = new karakter;
    baru->data_karakter = datakarakter;
    baru->next_karakter = NULL;
    if(Emptykarakter()==1)
    {
        head_karakter=baru;
        head_karakter->next_karakter=NULL;
    }
    else
    {
        bantu=head_karakter;
        while(bantu->next_karakter!=NULL)
    {
        bantu=bantu->next_karakter;
    }
        bantu->next_karakter = baru;
    }
}

void hapuskarakter()
{
    karakter *hapus,*bantu;
    string d;
    if(Emptykarakter()==0)
    {
        if(head_karakter->next_karakter!=NULL)
        {
        bantu=head_karakter;
        while(bantu->next_karakter->next_karakter!=NULL)
        {
            bantu=bantu->next_karakter;
        }
        hapus=bantu->next_karakter;
        d=hapus->data_karakter;
        bantu->next_karakter=NULL;
        delete hapus;
        }
        else
        {
        d=head_karakter->data_karakter;
        head_karakter=NULL;
        }
        cout<<" "<<d<<" terhapus\n";
        }
    else
        cout<<" (Masih kosong)\n";
}

void tampilList()
{
    karakter *help;
    help=head_karakter;

    if(Emptykarakter()==0)
    {
    cout<<"Data Asli \t\t: ";
    while(help!=NULL)
    {
    cout<<help->data_karakter<<"->";
    help=help->next_karakter;
    }
    cout<<"\n";
    }
    else
    cout<<"(Masih kosong)\n";
}

int main()
{
	cout<<"Nama		: Rifqa A. Aliyya"<<endl;
	cout<<"NIM		: 19051397042"<<endl;
	cout<<"Prodi	: Manajemen Informatika";
    initHead();
    string data_karakter;
    for(int i=1;i<=6;i++)
    {
        cout<<"\nMasukkan Data ke - "<<i<<" \t: ";
        cin>>data_karakter;
        insertkarakter(data_karakter);
    }
    cout<<endl;
    tampilList();
    cout<<endl;
    getch();
}
