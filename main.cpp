
#include<iostream>
#include<cstring>
#include <stdio.h>
#include <vector>
#include <cstdio>
#include <fstream>
#include <string>

#define INSERT_COST 3
#define DELETE_COST 2
#define REPLACE_COST 4
#define Right 0

using namespace std;

int flag=0;

FILE *fp;
FILE *newfp;
string fileName, fileName2, newFileName, newFileName2 ;


struct Data         //数据结点类型
{
    string key;     //关键字
    string name;
    int age;
};
struct CLType       //定义链表结构
{
    Data nodeData;
    CLType *nextNode;
};


int min(int a,int b) {
    return ((a < b) ? a : b);
}


class List {
     public:
         List(){create_List();}
         ~List(){clear();}
         void create_List();
         void insert(const char& d);
         void insert_pos(const int& d,const char& d1);
         void erase(const int& d);
         void updata(const int& d,const char& d1);
         void reverse();
         void print();
     private:
         struct Node{
                 char data;
                 Node * next;
                 Node(const char& d):data(d),next(NULL){}
             };
         Node * head;//
         void clear(){
                 Node * p = head;
                 while(p){
                         Node * q = p->next;
                         delete p;
                         p = q;
                     }
             }

         Node* find(const char& d){
                 Node * p = head;
                 for(;p;p=p->next){
                         if(p->next->data==d)
                                 break;
                     }
                 return p;
             }
    Node* findpos(const int& d){
        Node * p = head;

        for(int pos=0;pos<d;){
            if(p->next==NULL)
                break;
            p=p->next;
     //       cout<<"move"<<endl;
            pos++;

        }
        return p;
    }
     };

 void List::create_List()
 {
          head = new Node(0);
     head->next=NULL;
     }
void List::print()
 {
         for(Node * p = head->next;p;p=p->next){
                 cout << p->data;
             }
         }
 void List::insert(const char& d)
 {
         Node *p = new Node(d);
         p->next = head->next;
         head->next = p;
     }
         void List::insert_pos(const int& d,const char& d1)
         {

                 Node * p = findpos(d);
                 Node * q = new Node(d1);
                 q->next = p->next;
                 p->next = q;
             }

         void List::erase(const int& d)
         {
                 Node * p = findpos(d);
                 Node *q = p->next;
                if(p->next==NULL)
                    return;
                 p->next = p->next->next;
                 delete q;
             }

         void List::updata(const int& d,const char& d1)
         {
                 Node * p = findpos(d);
                if(p->next==NULL)
                    return;
                 p->next->data = d1;
             }



void List::reverse()
 {
         Node * p = head->next;//头结点之后的第1个节点
         Node * q = head->next->next;//头结点之后的第2节点
         Node * m = head->next->next->next;//头结点之后的第3个节点
         p->next = NULL;//将头接点之后的第1个节点的next指针置为空
         //根据m是否为空来判断 以此逆序每一个节点
         while(m){
                 q->next = p;
                 p = q;
                 q = m;
                 m = m->next;
             }
         //将最后一个节点逆序
         q->next = p;
         //将头从新指向新的的第1个节点(之前的最后一个节点)
         head ->next = q;
     }

vector<int> transfer;

/* convert str1 to str2 with minimum edits(insert,delete,replace)
 suppose length(str1) = m and length(str2) = n
 cost(i,j) -> cost of converting str1[0...i-1] to str2[0...j-1]
 cost(m,n) -> cost of converting str1 to str2
 Standard recursive formula for computing cost(m,n) :-
 cost(i,j) = min[cost(i-1,j)+D, cost(i,j-1)+I, cost(i-1,j-1)+R]
 D -> delete cost, I -> insert cost, R -> replace cost  */

int editDistance(char str1[],int size1,char str2[],int size2) {
    // cost matrix
    // row -> str1 & col -> str2
    int cost[size1][size2];
    int i,j;
    string str3 = str1;
    // initialize the cost matrix


    //linkedlist


    List list;
    for(int len=0;len<=size1-1;len++)
    {
        list.insert(str1[len]);
    }
    list.reverse();
    list.print();
    cout<<endl;





    //linkedlist

    for (i=0;i<size1;i++) {
        for(j=0;j<size2;j++) {
            if (i == 0) {
                // source string is NULL
                // so we need 'j' insert operations
                cost[i][j] = j*INSERT_COST;
            } else if (j == 0) {
                // target string is NULL
                // so we need 'i' delete operations
                cost[i][j] = i*DELETE_COST;
            } else {
                cost[i][j] = -1;
            }
        }
    } //initialization done


    //compute cost(i,j) and eventually return cost(m,n)
    for(i=1;i<size1;i++) {
        for(j=1;j<size2;j++) {
            int x = cost[i-1][j] + DELETE_COST;//2
            int y = cost[i][j-1] + INSERT_COST;//3
            // if str1(i-1) != str2(j-1), add the replace cost
            // we are comparing str1[i-1] and str2[j-1] since
            // the array index starts from 0
            int z = cost[i-1][j-1] + (str1[i-1] != str2[j-1])*REPLACE_COST;//4
            // as per our recursive formula
            cost[i][j] = min(x, min(y,z));

      //                cout<<"I  "<<i<<"J "<<j<<"str3 "<<str3<<endl;
        }
      //  cout<<"end"<<endl;

        }
    //searh back for get information of ....
    // last cell of the matrix holds the answer




    i = size1-1;
    j = size2-1;
    for( ; i >=0; )
        {       //将数组中的元素全部输出
        for( ; j >=0 ; )
        {
            //    cout<<"cost[i-1][j]"<<cost[i-1][j]<<"cost[i][j-1]"<<cost[i][j-1]<<
             //   "cost[i-1][j-1]"<<cost[i-1][j-1]<<cost[i][j]<<endl;
                    if(cost[i-1][j] + DELETE_COST==cost[i][j])
                    {
                     //   cout<<"delete"<<endl;
                        i=i-1;
                        //j = j;
                        transfer.push_back(DELETE_COST);
                        break;
                    }
                    else if(cost[i][j-1] + INSERT_COST==cost[i][j])
                    {
                     //   cout<<"insert"<<endl;
                        //i = i;
                        j = j-1;
                        transfer.push_back(INSERT_COST);
                        break;
                    }
                    else if((cost[i-1][j-1] + (str1[i-1] != str2[j-1])*REPLACE_COST)==cost[i][j])
                    {

                        if(str1[i-1] != str2[j-1])
                                             {
                               //              cout<<"replace"<<endl;
                                                  transfer.push_back(REPLACE_COST);
                                             }
                                             else
                                             {
                             //                   cout<<"right"<<endl;
                                                 transfer.push_back(Right);
                                             }
                        i = i-1;
                        j = j-1;
                        break;
                    }



                }
     //      cout<<"asasa"<<cost[i][j]<<endl;
     //       cout<<"i"<<i<<"j"<<j<<endl;
            if(i==0&&j==0)
            {
                break;
            }

        }
if(flag==0)
{

    cout<<"------------------------------------------------"<<endl;
    cout<<"Oper        "<<"|"<<"   c" <<"|"<<"Total"<<"|"<<" z   "<<endl;
 //   list.reverse();

    cout<<"initial    "<<"|"<<"   0" <<"  |"<<"  0"<<"|  "<<"*";
    list.print();
    cout<<endl;
  //  list.reverse();
    int summ = 0;
    int  times=0;
    int t = 0;
    for(int size=0;size<=transfer.size()-1;size++)
    {
        switch(transfer[transfer.size()-1-size])
        {
            case INSERT_COST:
            {
             //   list.reverse();
                summ = summ+3;
                times = size -t;
                list.insert_pos(times,str2[times]);
                //cout<<"innnnnnnnn"<<str2[times]<<endl;
              //  t = t-1;
              //  list.reverse();
                cout<<"insert"<<"    |"<<"   3" <<"  |   "<<summ<<"   |  ";
                list.print();
                cout<<endl;
                break;
            }
            case DELETE_COST:
            {
                summ = summ+2;
             //   list.reverse();
                times = size -t;
                list.erase(times);
                t = t+1;
                
              //  list.reverse();
                cout<<"delete"<<"   |"<<"   2" <<"  |   "<<summ<<"   |  ";
                list.print();
                cout<<endl;
                break;
            }
            case REPLACE_COST:
            {
                summ = summ+4;
                times = size -t;
                list.updata(times,str2[times]);
                cout<<"replace"<<"   |"<<"   4" <<"  |   "<<summ<<"   |  ";
                list.print();   
                cout<<endl;
                break;
            }
            case Right:
            {
                cout<<"right"<<"   |"<<"   0" <<"  |  " <<summ<<"   |  ";
                list.print();
                               cout<<endl;
                break;
            }
        }


    }




}


    return cost[size1-1][size2-1];
}

//main
int main() {

    newFileName = "sparseMSF.txt";
    //fscanf(fp, "%[^\n]", &str1);
    cout<<"===================== Question 1 =========================="<<endl;
    flag=0;
    char q1Str1[]="electrical engineering";
    char q1Str2[]="computer science";
    int q1Size1=strlen(q1Str1);
    int q1Size2=strlen(q1Str2);
    int min_cost = editDistance(q1Str1,q1Size1+1,q1Str2,q1Size2+1);
    cout<<"min cost is "<<min_cost<<endl;


    cout<<"===================== Question 2 ==========================="<<endl;
    flag=1;
    for(int i=1;i<=3;i++)
    {
    	switch (i) {
			case 1:{
			    fileName = "input1.txt";
			    int length1,length2;
			    char str1[1024], str2[1024];
			    fp = fopen(fileName.c_str(), "rt+");
			    fscanf(fp, "%d\n", &length1);
			    fscanf(fp, "%[^\n]\n", &str1);
			    fscanf(fp, "%d\n",&length2);
			    fscanf(fp,"%[^\n]\n",&str2);
			    int answer1=editDistance(str1,length1,str2,length2);
			    cout<<"The answer of input1.text: "<<answer1<<endl;
				break;
			}

			case 2:{
			    fileName = "input2.txt";
			    int length1,length2;
			    char str1[1024], str2[1024];
			    fp = fopen(fileName.c_str(), "rt+");
			    fscanf(fp, "%d\n", &length1);
			    fscanf(fp, "%[^\n]\n", &str1);
			    fscanf(fp, "%d\n",&length2);
			    fscanf(fp,"%[^\n]\n",&str2);
			    int answer2=editDistance(str1,length1,str2,length2);
			    cout<<"The answer of input2.text: "<<answer2<<endl;
				break;
			}

			case 3:{
			    fileName = "input3.txt";
			    int length1,length2;
			    char str1[1024], str2[1024];
			    fp = fopen(fileName.c_str(), "rt+");
			    fscanf(fp, "%d\n", &length1);
			    fscanf(fp, "%[^\n]\n", &str1);
			    fscanf(fp, "%d\n",&length2);
			    fscanf(fp,"%[^\n]\n",&str2);
			    int answer3=editDistance(str1,length1,str2,length2);
			    cout<<"The answer of input3.text: "<<answer3<<endl;
				break;
			}
			default:
				break;
		}
    }

    return 0;
}
