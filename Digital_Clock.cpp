#include<iostream>
using namespace std;

class DigitalC{
    private:
    int hour,sec,min;

    public:
    DigitalC(int h,int m,int s):hour(h),min(m),sec(s){

    }
    void Display(int h,int m,int s){
        if(h>0 && h<=11){
            if(h==0) h=12;
            cout<<"Your Time is : "<<h<<": "<<m<<": "<<s<<": "<<"AM";
        }else{
            if(h>12) h = h -12;
            cout<<"Your Time is : "<<h<<": "<<m<<": "<<s<<": "<<"AM";
        }
    }

};

