#include <iostream>

using namespace std;

struct NAME
{
    int name;
    NAME * next;
};

int main()
{
    int N;
    NAME *begin, *nom1, *nom2;
    begin = new NAME;
    begin->name = 1;
    nom1 = begin;
    cout<<"введите N    :  ";
    cin>>N;

//  заполнение списка

    for(int i = 2 ;i < N+1 ; i++){
        nom1->next = new NAME;
        nom1 = nom1->next;
        nom1->name = i;
    }

    nom1 -> next = nullptr;

    nom1=begin;

// вывод списка

    while (nom1)
    {
        cout << nom1->name << ' ';
        nom1=nom1->next;
    }

    cout << endl;

//  алгоритм

    nom1 = begin->next;
    nom2 = nom1->next;
    nom1->next = begin;

    while (nom2)
    {
        begin->next = nom2;
        nom2 = nom2->next;
        begin->next->next = nom1;
        nom1 = begin->next;
    }

    begin->next = nullptr;


// вывод списка

//    nom1=begin;
    while (nom1)
    {
        cout << nom1->name << ' ';
        nom1=nom1->next;
    }

    return 0;

}