#ifndef MKEN_H_INCLUDED
#define MKEN_H_INCLUDED

#include <iostream>
using namespace std;

#define nul NULL
#define next(P) (P)->next
#define prev(P) (P)->prev
#define info(P) (P)->info
#define barang(P) (P)->barang
#define relasi(P) (P)->relasi
#define first(P) ((P).first)

//List Gudang
struct infotypeGudang{
    string name;
    string id;
};
typedef struct elmntGudang *adrGudang;
typedef struct elmntRelasi *adrRelasi;
typedef struct elmntBarang *adrBarang;

struct elmntGudang{
    infotypeGudang info;
    adrGudang next;
    adrRelasi relasi;
};
struct listGudang{
    adrGudang first;
};

//Relasi
struct elmntRelasi{
    adrBarang barang;
    adrRelasi next;
};


//List barang
struct infotypeBarang{
        string name;
        string id;
};
struct elmntBarang{
    infotypeBarang info;
    adrBarang next;
    adrBarang prev;
};
struct listBarang{
    adrBarang first;
};

adrGudang newGudang(infotypeGudang X);
adrBarang newBarang(infotypeBarang Y);
void insertFirstGudang(listGudang &L1,adrGudang P);
void insertLastGudang(listGudang &L1,adrGudang P);
void showAllGudang(listGudang L1);
void deleteGudang(listGudang &L1, adrGudang P);
adrGudang searchGudang(listGudang L1, string id);
adrBarang searchBarang(listBarang L2, string id);
void insertBarang(listBarang &L2, adrBarang P);
void tambahRelasi(listGudang &L1, listBarang &L2, adrGudang P, adrBarang Q);
void showAllRelasiGudang(listGudang L1);
adrRelasi searchRelasi(listBarang L1, adrGudang P, adrBarang Q);
void deleteRelasi(listGudang &L1, adrGudang P, adrRelasi Q);
int jumlahBarang(listGudang L1, adrGudang P);




#endif // MKEN_H_INCLUDED
