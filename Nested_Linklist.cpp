#include <iostream>
using namespace std;

struct SNode;

struct CNode{
    int CNo;
    CNode *CNext;
    SNode *stdList;
};

struct SNode{
    int SNo;
    SNode *SNext;
};

CNode *CList=NULL;

void insert_course(int CNo){
    CNode *temp=new CNode;
    temp->CNo=CNo;
    temp->CNext=NULL;
    temp->stdList=NULL;
    temp->CNext=CList;
    CList=temp;
}

void insertStd(int SNo,int CNo){
    CNode *Ccur=CList;
    while(Ccur!=NULL){
        if(CNo=Ccur->CNo){
            SNode *temp=new SNode;
            temp->SNo=SNo;
            temp->SNext=NULL;
            if(Ccur->stdList==NULL){
                Ccur->stdList=temp;
            }else{
                SNode *Scur=Ccur->stdList;
                while(Scur->SNext!=NULL){
                    Scur=Scur->SNext;
                }
            }
            return;
        }
        Ccur=Ccur->CNext;
    }
}

void printCourses(){
    CNode *Ccur=CList;
    while(Ccur!=NULL){
        cout<<"Course "<<Ccur->CNo<<": "; 
        SNode*Scur=Ccur->stdList;
        while(Scur!=NULL){
            cout<<Scur->SNo<<" ";
            Scur=Scur->SNext;
        }
        cout << endl;
        Ccur=Ccur->CNext;
    }
}

int main(){
    insert_course(101);
    insert_course(102);
    insert_course(106);


    insertStd(1,101);
    insertStd(2,101);
    insertStd(3,101);
    insertStd(1,106);
    insertStd(2,106);
    insertStd(3,106);
    insertStd(4,106);
    insertStd(5,106);

    printCourses();
    return 0;
}