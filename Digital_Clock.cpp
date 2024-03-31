#include<iostream>
using namespace std;

class DigitalC{
    private:
    int hour,sec,min;

    public:
    DigitalC(int h,int m,int s):hour(h),min(m),sec(s){

    }
    void DisplayTime(){
        if(hour>0 && hour<=11){
            if(hour==0) hour=12;
            cout<<"Your Time is : "<<hour<<": "<<min<<": "<<sec<<": "<<"AM";
        }else{
            if(hour>12) hour = hour -12;
            cout<<"Your Time is : "<<hour<<": "<<min<<": "<<sec<<": "<<"AM";
        }
    }

};

int main(){
    int hours,minutes,seconds;
    cout<<"Enter Hours : ";
    cin>>hours;
    cout<<"Enter Minutes : ";
    cin>>minutes;
    cout<<"Enter Seconds : ";
    cin>>seconds;

DigitalC digital = DigitalC(hours,minutes,seconds);
digital.DisplayTime();

}