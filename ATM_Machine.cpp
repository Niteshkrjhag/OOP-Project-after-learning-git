#include <iostream>
using namespace std;

static bool show = true;

class ATM{
    private:
    double balance;
    int pinCode;
    public:
    ATM(double b,int pin):balance(b),pinCode(pin){}
   
   void setBalance(double amount){
    balance+=amount;
   }
   double getBalance(){
    return balance;
   }
   void withdrawal(double amount){
    if(amount>balance){
        cout<<"-----------Insufficient Balance-----------"<<endl;
    }else{
        balance = balance - amount;
        cout<<"-----------Withdrawal Successfull---------"<<endl;
    }
   }
   void deposit(double amount){
    balance = balance + amount;
    cout<<"---------Deposit Successfull------------"<<endl;
   }
  void Transfer(double amount,ATM &receiver,int pin){
    char c='n';
    int newpin;
    int count = 3;
    do{
    if(pin == pinCode){
        if(amount>balance){
            cout<<"\n---------- Transfer Unsuccessful due to insufficient balance -----------"<<endl;
        }else{
            cout<<"\n----------- Transfer Successfull---------"<<endl;
            receiver.setBalance(amount);
            balance-=amount;
            show=true;
        }
        c='n';
    }else{
        system("clear");
        count--;
        cout<<"\n....You Have entered wrong pincode...."<<endl;
        cout<<"\nDo You want to try once again yes/no (y/n) : ";
        cin>>c;
        if(c=='y'){
            cout<<"Enter the pincode : ";
            cin>>newpin;
        }
    }
    pin = newpin;
    if(count==0){
        system("clear");
      cout<<"\n.....Limit Reached..... so try after a while!"<<endl;
      show = false;
    }
    }while( c=='y' && count);
   }
};

int main(){
    ATM atm(1000,1234);
    ATM receiver(2000,1235);
    int choice;
    char c;
    do{
        system("clear");
        cout<<"1. View Balance "<<endl;
        cout<<"2. Cash Withdraw "<<endl;
        cout<<"3. Cash Deposit "<<endl;
        cout<<"4. Cash Transfer "<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"\nEnter Your Choice : ";
        cin>>choice;
        switch(choice){
            case 1:{
               cout<<"Your balance is : "<<atm.getBalance()<<endl;
               break;
            }
            case 2:{
                  double amount;
                cout<<"\nYour Available Balance : "<<atm.getBalance()<<endl;
                cout<<"Enter the amount you want to withdraw : ";
                    cin>>amount;
                    atm.withdrawal(amount);
                    break;
            }
            case 3:{
                double amount;
                cout<<"Enter the amount you want to deposite : ";
                cin>>amount;
                atm.deposit(amount);
                break;
            }
            case 4:{
                int pin;
                double amount;
                cout<<"Enter the amount you want to transfer : ";
                cin>>amount;
                cout<<"Enter your pincode : ";
                cin>>pin;

                atm.Transfer(amount,receiver,pin);
                if(show){
                cout<<"\nBalance you have now is : "<<atm.getBalance()<<endl;
                cout<<"Balance in transfered Bank is : "<<receiver.getBalance()<<endl;                    
                }
                break;
            }
           case 5:{
            cout<<"-------------Thanks for using ATM----------------"<<endl;
            exit(1);
           }
           default:{
            cout<<"-------------Invalid Choice------------------"<<endl;
           }
        }
        cout<<"\nDo You Still Want To Continue yes/no (y/n) : ";
        cin>>c; 
    }while(c=='y');
}