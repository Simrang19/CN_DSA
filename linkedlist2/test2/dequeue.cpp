#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string

#define sz size()
using namespace std;
using ls= string;
using ld=double;

class Deque {
    int *data;
    int size;

    public:
    Deque(int s){
        data=new int[10];
        size=0;
    }

    void insertFront(int h){
        if (size<10){
            int j=size;
            while(j>0){
                data[j]=data[j-1];
                j--;
            }
            data[0]=h;
            size++;
            
        }
        else{
            cout<<-1;
            return;
        }
    }

    void insertRear(int k){
        if(size<10){
            data[size]=k;
            size++;
        }
        else{
            cout<<-1;
            return;
        }
    }

    void deleteFront(){
        int i=0;
        if(size==0){
            cout<<-1;
            return;
        }
        while(i<size){
            data[i]=data[i+1];
            i++;
        }
        size--;
    }

    void deleteRear(){
        if (size==0){
            cout<<-1;
            return;
        }
        size--;
    }

    int getFront(){
        if (size==0){
            return -1;
        }
        return data[0];
    }

    int getRear(){
        if(size==0){
            return -1;
        }
        return data[size-1];
    }

    // Complete this class
    
};

int main()
{
    Deque dq(10);
    int choice,input;
    while(true) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                dq.insertFront(input);
                break;
            case 2:
                cin >> input;
                dq.insertRear(input);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                cout << dq.getFront() << "\n";
                break;
            case 6:
                cout << dq.getRear() << "\n";
                break;
            default:
                return 0;
        }
    }
    
    return 0;
}