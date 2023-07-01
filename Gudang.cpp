#include "MkeN.h"

adrGudang newGudang(infotypeGudang X){
    adrGudang G = new elmntGudang;
    info(G) = X;
    next(G) = nul;
    relasi(G) = nul;
    return G;
}
adrBarang newBarang(infotypeBarang Y){
    adrBarang B = new elmntBarang;
    info(B) = Y;
    next(B) = nul;
    prev(B) = nul;
}
void insertFirstGudang(listGudang &L1,adrGudang P){
    next(P) = first(L1);
    first(L1) = P;
}
void insertLastGudang(listGudang &L1,adrGudang P){
    adrGudang a = first(L1);
    while(next(a) != nul){
        a = next(a);
    }
    next(a) = P;
}
void showAllGudang(listGudang L1){
    adrGudang P = first(L1);
    while(next(P) != nul){
        cout<<info(P).name<<" - ";
        P = next(P);
    }
    cout<<info(P).name<<endl;
}
void deleteGudang(listGudang &L1, adrGudang P){
    //menghapus semua relasi dari gudang sampai relasinya nul
    while(relasi(P) != nul){
        deleteRelasi(L1,P,relasi(P));
    }
    //menghapus gudang dari list sesuai posisi data gudang di list
    if(first(L1) == nul){
        cout<<"List Kosong!";
    }else if(P == first(L1)){
        first(L1) = next(P);
        next(P) = nul;
    }else{
        adrGudang prec = first(L1);
        while(next(prec) != P){
            prec = next(prec);
        }
        next(prec) = next(P);
        next(P) = nul;
    }
}
adrGudang searchGudang(listGudang L1, string id){
    adrGudang P = first(L1);
    while(P != nul && info(P).id != id){
        P = next(P);
    }
    return P;
}
adrBarang searchBarang(listBarang L2, string id){
    adrBarang P = first(L2);
    while(P != nul && info(P).id != id){
        P = next(P);
    }
    return P;
}
void insertBarang(listBarang &L2, adrBarang P){
    if(first(L2) == nul){
        first(L2) = P;
    }else{
        adrBarang prec = first(L2);
        while(next(prec) != nul){
            prec = next(prec);
        }
        next(prec) = P;
        prev(P) = prec;
    }
}
void tambahRelasi(listGudang &L1, listBarang &L2, adrGudang P, adrBarang Q){
    adrRelasi R = new elmntRelasi;
    barang(R) = Q;
    next(R) = nul;
    if(relasi (P) == nul){
        relasi(P) = R;
    }else{
        adrRelasi r = relasi(P);
        while(next(r) != nul){
            r = next(r);
        }
        next(r)= R;
    }
}
void showAllRelasiGudang(listGudang L1){
    adrGudang P = first(L1);
    adrRelasi R;
    while(P != nul){
        cout<<"Gudang "<<info(P).name<<endl<<"Barang : ";
        R = relasi(P);
        if(R != nul){
            while(next(R) != nul){
                cout<<info(barang(R)).name<<" - ";
                R = next(R);
            }
            cout<<info(barang(R)).name<<endl;
        }else{
            cout<<"Tidak ada barang"<<endl;
        }
        P = next(P);
    }
}
adrRelasi searchRelasi(listBarang L1, adrGudang P, adrBarang Q){
    adrRelasi R = relasi(P);
    while(R != nul && barang(R) != Q){
        R = next(R);
    }
    return R;
}
void deleteRelasi(listGudang &L1, adrGudang P, adrRelasi Q){
    if(relasi(P) == nul){
        cout<<"Relasi Kosong"<<endl;
    }else if(Q == relasi(P)){
        relasi(P) = next(Q);
        next(Q) = nul;
    }else{
        adrRelasi prec = relasi(P);
        while(next(prec) != Q){
            prec = next(prec);
        }
        next(prec) = nul;
    }
}
int jumlahBarang(listGudang L1, adrGudang P){
    adrRelasi R = relasi(P);
    int jum = 0;
    while(R != nul){
        jum++;
        R = next(R);
    }
    return jum;
}
