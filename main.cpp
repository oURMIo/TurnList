#include <iostream>

using namespace std;

struct NAME
{
    int num;
    NAME * next;
};

int main()
{
    int N;
    NAME *begin, *ptr1, *ptr2;
    begin = new NAME;
//  begin->num = 0;
    ptr1 = begin;
    cout<<"введите N    :  ";
    cin>>N;
//  заполнение списка

    for(int i=1; i<N; i++){
        ptr1->next = new NAME;
        ptr1 = ptr1->next;
        ptr1->num = i;
    }
    ptr1 -> next = nullptr;

    ptr1=begin;

    while (ptr1)
    {
        cout << ptr1->num << ' ';
        ptr1=ptr1->next;
    }

    cout << endl;

//  алгоритм

    ptr1 = begin->next;
    ptr2 = ptr1->next;
    ptr1->next = begin;

    while (ptr2)
    {
        begin->next = ptr2;
        ptr2 = ptr2->next;
        begin->next->next = ptr1;
        ptr1 = begin->next;
    }

    begin->next = nullptr;


// вывод списка

//    ptr1=begin;
    while (ptr1)
    {
        cout << ptr1->num << ' ';
        ptr1=ptr1->next;
    }

    return 0;

}