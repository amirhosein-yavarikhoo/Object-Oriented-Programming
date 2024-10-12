#include <vector>
#include <cstdlib>
#include <iostream>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class GATE {
    public:
    GATE(){};
    ~GATE(){};
    vector<char*> input_wires;
    char *o1,nextval;
    int delay;
    virtual void evl()=0;
    void updateval (){*o1=nextval; };
    bool check_change () {if (nextval!=*o1) return true; else return false; };
};
class AND : public GATE {
	char *i1, *i2, *i3, *i4, *i5, *i6, *i7, *i8, *i9;
	int mode;
	public:
		AND (char &w, char& a, char& b, char& c, char& d, char& e, char& f, char& g, char& h, char& i){
            mode = true; i1 = &a; i2 = &b; i3 = &c; i4 = &d; i5 = &e; i6 = &f; i7 = &g; i8 = &h; i9 = &i; o1 = &w;
            this->input_wires.push_back(i1);
            this->input_wires.push_back(i2);
            this->input_wires.push_back(i3);
            this->input_wires.push_back(i4);
            this->input_wires.push_back(i5);
            this->input_wires.push_back(i6);
            this->input_wires.push_back(i7);
            this->input_wires.push_back(i8);
            this->input_wires.push_back(i9);
            delay=3;
        }
		AND (char &w, char& a, char& b, char& c, char& d, char& e, char& f, char& g, char& h){
            mode = false; i1 = &a; i2 = &b; i3 = &c; i4 = &d; i5 = &e; i6 = &f; i7 = &g; i8 = &h;  o1 = &w;
            this->input_wires.push_back(i1);
            this->input_wires.push_back(i2);
            this->input_wires.push_back(i3);
            this->input_wires.push_back(i4);
            this->input_wires.push_back(i5);
            this->input_wires.push_back(i6);
            this->input_wires.push_back(i7);
            this->input_wires.push_back(i8);
            delay=3;
        }
		void evl9(){if ((*i1=='0')||(*i2=='0')||(*i3=='0')||(*i4=='0')||(*i5=='0')||(*i6=='0')||(*i7=='0')||(*i8=='0')||(*i9=='0')) nextval='0';else if ((*i1=='1')&&(*i2=='1')&&(*i3=='1')&&(*i4=='1')&&(*i5=='1')&&(*i6=='1')&&(*i7=='1')&&(*i8=='1')&&(*i9=='1')) nextval='1';else nextval='X';}
        void evl8(){if ((*i1=='0')||(*i2=='0')||(*i3=='0')||(*i4=='0')||(*i5=='0')||(*i6=='0')||(*i7=='0')||(*i8=='0')) nextval='0';else if ((*i1=='1')&&(*i2=='1')&&(*i3=='1')&&(*i4=='1')&&(*i5=='1')&&(*i6=='1')&&(*i7=='1')&&(*i8=='1')) nextval='1';else nextval='X';
        }
        void evl() {if (mode) evl9(); else evl8(); }
        
};
class NOT : public GATE {
	char *i1;
	public:
		NOT(char& w, char& a){
            i1 = &a; o1 = &w;
            this->input_wires.push_back(i1);
            delay=2;
        }
		~NOT(); 
		void evl ();
};
void NOT::evl () {
	if (*i1=='0') 
		nextval='1';
	else if (*i1=='1') 
		nextval='0';
	else 
		nextval='X';
}
class XOR : public GATE {
	char *i1, *i2;
	public:
		XOR(char& w, char& a, char& b){
            i1 = &a; i2 = &b; o1 = &w;
            this->input_wires.push_back(i1);
            this->input_wires.push_back(i2);
            delay=6;
        }
		~XOR(); 
		void evl();
};
void XOR::evl () {
	if ((*i1 == 'X') || (*i2 == 'X') ||
		(*i1 == 'Z') || (*i2 == 'Z')) 
		nextval = 'X';
	else if (*i1==*i2) 
		nextval='0';
	else 
		nextval='1';
}
class NAND : public GATE{
	char *i1, *i2, *i3, *i4;
	public:
        int mode;
		NAND (char& w, char& a, char& b){
            mode=1; i1=&a; i2=&b; o1=&w;
            this->input_wires.push_back(i1);
            this->input_wires.push_back(i2);
            delay=5;
        }
        NAND (char& w, char& a,char& b, char& c){
            mode=2; i1=&a; i2=&b; i3=&c; o1=&w;
            this->input_wires.push_back(i1);
            this->input_wires.push_back(i2);
            this->input_wires.push_back(i3);
            delay=5;
        }
        NAND (char& w, char& a,char& b, char& c, char& d){
            mode=3; i1=&a; i2=&b; i3=&c; i4=&d; o1=&w;
            this->input_wires.push_back(i1);
            this->input_wires.push_back(i2);
            this->input_wires.push_back(i3);
            this->input_wires.push_back(i4);
            delay=5;
            }
		~NAND(); // destructor
		void evl2(){if ((*i1=='0')||(*i2=='0')) nextval='1'; else if ((*i1=='1')&&(*i2=='1')) nextval='0'; else nextval='X';};
        void evl3(){if ((*i1=='0')||(*i2=='0')||(*i3=='0')) nextval='1'; else if ((*i1=='1')&&(*i2=='1')&&(*i3=='1')) nextval='0'; else nextval='X';};
        void evl4(){if ((*i1=='0')||(*i2=='0')||(*i3=='0')||(*i4=='0')) nextval='1'; else if ((*i1=='1')&&(*i2=='1')&&(*i3=='1')&&(*i4=='1')) nextval='0'; else nextval='X';};
        void evl(){if (mode==1) evl2(); else if (mode==2) evl3(); else if (mode==3) evl4(); }
};
class NOR : public GATE{
    char *i1,*i2;
    public:
    NOR(char& w, char& a, char& b){
        i1=&a; i2=&b; o1=&w;
        this->input_wires.push_back(i1);
        this->input_wires.push_back(i2);
        delay=4;
    }
    ~NOR();
    void evl(){if ((*i1=='1')||(*i2=='1')) nextval='0'; else if ((*i1=='0')&&(*i2=='0')) nextval='1'; else nextval='X'; }
};
class BUFFER : public GATE {
	char *i1;
	public:
		BUFFER(char& w, char& a){
            i1 = &a; o1 = &w;
            this->input_wires.push_back(i1);
            delay=0;
        }
		~BUFFER(); 
		void evl ();
};
void BUFFER::evl () {
	if (*i1=='0') 
		nextval='0';
	else if (*i1=='1') 
		nextval='1';
	else 
		nextval='X';
}