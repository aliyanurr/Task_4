void deleteLast(List &L, address &P)
{
    if(L.first == NULL)
    {
        cout << "List Kosong"<<endl;
    }
    else if (L.first->next == NULL)
    {
        deleteFirst(L,P);
    }
    else {
        P = L.last;
        L.last = P->prev;
        L.last->next = L.first;
        L.first->prev = L.last;
        P->prev = NULL;
        P->next = NULL;
        dealokasi(P);
    }
}

void deleteAfter(List &L, address &P, address &Prec)
{
    address S = L.first;
    for (int i = 1; i <= countElm(L); i++){
        if (Prec->info.ID == S->info.ID) {
            break;
        }
        S = S->next;
    }
    Prec = S;

    P = Prec->next;
    Prec->next = P->next;
    P->next = NULL;
    P->prev = NULL;
    dealokasi(P);
}

address findElm(List L, infotype x){
    address Q = First(L);
    while(Q != NULL){
        if(Info(Q).ID == x.ID){
            return Q;
        }
        Q = Next(Q);
    }
    return NULL;
}
