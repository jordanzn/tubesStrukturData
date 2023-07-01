#include "MkeN.h"
using namespace std;

int main()
{
    listGudang L1;
    first(L1) = nul;
    listBarang L2;
    first(L2) = nul;

    infotypeGudang X;
    adrGudang P;

    X.id = "123";
    X.name = "Selatan";
    P = newGudang(X);
    insertFirstGudang(L1,P);

    X.id = "1234";
    X.name = "Utara";
    P = newGudang(X);
    insertFirstGudang(L1,P);

    X.id = "12345";
    X.name = "Barat";
    P = newGudang(X);
    insertLastGudang(L1,P);


    infotypeBarang Y;
    adrBarang Q;

    Y.id = "123";
    Y.name = "Rokok";
    Q = newBarang(Y);
    insertBarang(L2,Q);

    Y.id = "1232";
    Y.name = "Baju";
    Q = newBarang(Y);
    insertBarang(L2,Q);

    Y.id = "123123";
    Y.name = "Indomie";
    Q = newBarang(Y);
    insertBarang(L2,Q);

    Y.id = "12312312";
    Y.name = "Laptop";
    Q = newBarang(Y);
    insertBarang(L2,Q);

    tambahRelasi(L1,L2,P,Q);

    Q = searchBarang(L2,"123");
    P = searchGudang(L1,"123");
    tambahRelasi(L1,L2,P,Q);
    showAllGudang(L1);
    cout<<endl;
    showAllRelasiGudang(L1);

    cout<<endl;
    P = searchGudang(L1,"12345");
    cout<<"total barang dari gudang "<<info(P).name<<": "<<jumlahBarang(L1,P)<<endl;

    P = searchGudang(L1,"123");
    Q = searchBarang(L2,"123");
    adrRelasi R = searchRelasi(L2,P,Q);
    deleteRelasi(L1,P,R);

    showAllRelasiGudang(L1);
    return 0;
}
