#include<iostream>
#include<conio.h>
using namespace std;
class bank{
    int id;
    char name[20];
    float bal;

    public:
        void input(){
            cout<<"Enter your Name , Balance and ID :- \n";
            cin>>name>>bal>>id;
        }
        void depo(float amt){
            bal+=amt;
            cout<<"Balance Updated Successfully\nYour Current Balance = "<<bal<<endl;
        }
        void with(float amt){
            float temp = bal-amt;
            if(temp<0)
                cout<<"\nInsufficient Money To Withdrawl\n";
            else{
                bal-=amt;
                cout<<"Amount Withrowl Successfully\nYour Current Balance = "<<bal<<endl;
            }
        }
        int getid(){
            return id;
        }
        void show(){
            cout<<id<<"\t"<<name<<"\t"<<bal<<endl;
        }
};
int main(){
    bank acc[10];
    int i=0,choice,id,j,temp,flag=1;
    char ch;
    float amt;
    acc[i].input();
    do
    {
        flag = 1;
        cout<<"\n1.Create Account\n2.Deposite Balance\n3.Withrow balance\n4.Find Record\n5.Show All Record\n0.Exit\n";
        cin>>choice;
        if(choice == 0){
            break;
        }else{
            switch (choice)
            {
                case 1:

                    i++;
                    acc[i].input();
                    break;
                case 2:
                    do{
                    cout<<"Enter Id and Deposite Amount\n";
                    cin>>id>>amt;
                    for(j=0; j<=i; j++){
                        temp = acc[j].getid();
                        if(id==temp){
                            acc[j].depo(amt);
                            flag = 0;
                        }
                    }
                    if(flag == 1)
                        cout<<"Enter valid Id\n";
                    }while(flag);
                    break;
                case 3:
                    do{
                    cout<<"Enter Id and Withrowl Amount\n";
                    cin>>id>>amt;
                    for(j=0; j<=i; j++){
                        temp = acc[j].getid();
                        if(id==temp){
                            acc[j].with(amt);
                            flag = 0;
                        }
                    }
                    if(flag == 1)
                        cout<<"Enter valid Id\n";
                    }while(flag);
                    break;
                case 4:
                    flag=1;
                    do{
                    cout<<"Enter Your Bank ID\n";
                    cin>>id;
                    for(j=0; j<=i; j++){
                        temp = acc[j].getid();
                        if(id==temp){
                            acc[j].show();
                            flag = 0;
                        }
                    }
                    if(flag == 1)
                        cout<<"Enter Valid id\n";
                    }while(flag);
                    break;
                case 5:
                    for(j=0; j<=i; j++){
                        acc[j].show();
                    }
                    break;
                default:
                    cout<<"Enter Valid Choice\n";
                    break;
            }
        }
        cout<<"\nPress ANY KEY to Continue\n";
        ch = getch();
    } while(ch);
    return 0;
}