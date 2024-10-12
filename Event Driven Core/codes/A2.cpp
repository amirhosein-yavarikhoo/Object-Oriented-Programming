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
#include <list>
using namespace std;
struct event {
    char new_value;
    int time;
    char* wire;
};
void next_turn (list<vector<event>> &TimingWheel, int &cur_time){
    TimingWheel.pop_front();
    vector<event> emptyvec;
    TimingWheel.push_back(emptyvec);

    cur_time++;
}
vector<event>* access_nth_element(list<vector<event>> &linked_list, int n) {
    auto it = linked_list.begin();
    advance(it, n);
    return &(*it);
}
bool isListEmpty(list<vector<event>> myList) {
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        if (!it->empty()) {
            return false;
        }
    }
    return true;
}
void calevent (event cur_event,vector<GATE*> &All_gates, list<vector<event>> &timingwheel, int &cur_time ){
    for (int i=0; i<All_gates.size(); i++){
        bool found=false;
        for (int j=0; j<All_gates[i]->input_wires.size(); j++){
            if (cur_event.wire==All_gates[i]->input_wires[j]){
                found=true;
                *(All_gates[i]->input_wires[j])=cur_event.new_value;
            }
                
            
        }
        if (found){
            All_gates[i]->evl();
            if (All_gates[i]->check_change()){
                event temp;
                temp.new_value=All_gates[i]->nextval;
                temp.time=All_gates[i]->delay+cur_time;
                temp.wire=All_gates[i]->o1;
                vector<event>* destination= access_nth_element(timingwheel,temp.time);
                destination->push_back(temp);
            }

        }
    }
}
void twfunc (vector<event> &userevents,list<vector<event>> &timingwheel, vector<GATE*> All_GATES, int &cur_time,vector<char*> &output_wires){
    cur_time=0;
    for (int i=0; i<userevents.size();i++){
        vector<event>* destination= access_nth_element(timingwheel,userevents[i].time);
        destination->push_back(userevents[i]);
    }
    while (!isListEmpty(timingwheel)){
        auto it = timingwheel.begin();
        if (it->empty()){
            cout<<"output in "<<cur_time<<"ns: "<<*output_wires[0]<<*output_wires[1]<<*output_wires[2]<<*output_wires[3]<<*output_wires[4]<<*output_wires[5]<<*output_wires[6]<<endl;
            next_turn(timingwheel,cur_time);
        }
        else{
            for(auto it = timingwheel.begin(); it != timingwheel.end(); ++it) {
                vector<event> eventsList = *it;
                for (auto eventIt = eventsList.begin(); eventIt != eventsList.end(); eventIt++) {
                    event currentEvent = *eventIt;
                    calevent(currentEvent,All_GATES,timingwheel,cur_time);
                }
            }
            cout<<"output in "<<cur_time<<"ns: "<<*output_wires[0]<<*output_wires[1]<<*output_wires[2]<<*output_wires[3]<<*output_wires[4]<<*output_wires[5]<<*output_wires[6]<<endl;
            next_turn(timingwheel,cur_time);
        }
           
    }
}
vector <string> str_tokenize(string input){
    vector <string> tokenized;
    int start=0;
    int j;
    string tokened;
            for (j=0;j<input.length();j++){
                if (input[j]==' '){
                tokened=input.substr(start,j-start);
                tokenized.push_back(tokened);
                start=j+1;
                }
        }
        tokened=input.substr(start,j-start);
        tokenized.push_back(tokened);
    return tokenized;
}
vector<event> getinput(string userinpp,vector<char*> input_wires){
    vector<string> tokenized= str_tokenize(userinpp);
    string time;
    tokenized[0].erase(0,1);
    int eventtime=stoi(tokenized[0]);
    event temp;
    vector<event> resultvec;
    for (int i=0; i<tokenized[1].length(); i++){
        temp.time=eventtime;
        temp.wire=input_wires[i];
        temp.new_value=tokenized[1][i];
        resultvec.push_back(temp);
    }
    return resultvec;
}
int main(){
list<vector<event>> TimingWheel (1000);
vector<GATE*> ALL_GATES;
int cur_time=0;
char N1,N4,N8,N11,N14,N17,N21,N24,N27,N30,
       N34,N37,N40,N43,N47,N50,N53,N56,N60,N63,
       N66,N69,N73,N76,N79,N82,N86,N89,N92,N95,
       N99,N102,N105,N108,N112,N115;
char N223,N329,N370,N421,N430,N431,N432;
char N118,N119,N122,N123,N126,N127,N130,N131,N134,N135,
      N138,N139,N142,N143,N146,N147,N150,N151,N154,N157,
      N158,N159,N162,N165,N168,N171,N174,N177,N180,N183,
      N184,N185,N186,N187,N188,N189,N190,N191,N192,N193,
      N194,N195,N196,N197,N198,N199,N203,N213,N224,N227,
      N230,N233,N236,N239,N242,N243,N246,N247,N250,N251,
      N254,N255,N256,N257,N258,N259,N260,N263,N264,N267,
      N270,N273,N276,N279,N282,N285,N288,N289,N290,N291,
      N292,N293,N294,N295,N296,N300,N301,N302,N303,N304,
      N305,N306,N307,N308,N309,N319,N330,N331,N332,N333,
      N334,N335,N336,N337,N338,N339,N340,N341,N342,N343,
      N344,N345,N346,N347,N348,N349,N350,N351,N352,N353,
      N354,N355,N356,N357,N360,N371,N372,N373,N374,N375,
      N376,N377,N378,N379,N380,N381,N386,N393,N399,N404,
      N407,N411,N414,N415,N416,N417,N418,N419,N420,N422,
      N425,N428,N429;
NOT* NOT1_1;
NOT* NOT1_2;
NOT* NOT1_3;
NOT* NOT1_4;
NOT* NOT1_5;
NOT* NOT1_6;
NOT* NOT1_7;
NOT* NOT1_8;
NOT* NOT1_9;
NOT* NOT1_10;
NOT* NOT1_11;
NOT* NOT1_12;
NOT* NOT1_13;
NOT* NOT1_14;
NOT* NOT1_15;
NOT* NOT1_16;
NOT* NOT1_17;
NOT* NOT1_18;
NAND* NAND2_19;
NOR* NOR2_20;
NOR* NOR2_21;
NAND* NAND2_22;
NAND* NAND2_23;
NAND* NAND2_24;
NAND* NAND2_25;
NAND* NAND2_26;
NAND* NAND2_27;
NAND* NAND2_28;
NAND* NAND2_29;
NOR* NOR2_30;
NOR* NOR2_31;
NOR* NOR2_32;
NOR* NOR2_33;
NOR* NOR2_34;
NOR* NOR2_35;
NOR* NOR2_36;
NOR* NOR2_37;
NOR* NOR2_38;
NOR* NOR2_39;
NOR* NOR2_40;
NOR* NOR2_41;
NOR* NOR2_42;
NOR* NOR2_43;
NOR* NOR2_44;
NOR* NOR2_45;
AND* AND9_46;
NOT* NOT1_47;
NOT* NOT1_48;
NOT* NOT1_49;
XOR* XOR2_50;
XOR* XOR2_51;
XOR* XOR2_52;
XOR* XOR2_53;
XOR* XOR2_54;
XOR* XOR2_55;
NAND* NAND2_56;
XOR* XOR2_57;
NAND* NAND2_58;
XOR* XOR2_59;
NAND* NAND2_60;
XOR* XOR2_61;
NAND* NAND2_62;
NAND* NAND2_63;
NAND* NAND2_64;
NAND* NAND2_65;
NAND* NAND2_66;
NAND* NAND2_67;
NAND* NAND2_68;
NAND* NAND2_69;
NAND* NAND2_70;
NAND* NAND2_71;
NAND* NAND2_72;
NAND* NAND2_73;
NAND* NAND2_74;
NAND* NAND2_75;
NAND* NAND2_76;
NAND* NAND2_77;
NAND* NAND2_78;
NAND* NAND2_79;
NAND* NAND2_80;
NAND* NAND2_81;
NAND* NAND2_82;
NAND* NAND2_83;
NAND* NAND2_84;
NAND* NAND2_85;
AND* AND9_86;
NOT* NOT1_87;
NOT* NOT1_88;
NOT* NOT1_89;
NOT* NOT1_90;
NOT* NOT1_91;
NOT* NOT1_92;
NOT* NOT1_93;
NOT* NOT1_94;
NOT* NOT1_95;
NOT* NOT1_96;
NOT* NOT1_97;
NOT* NOT1_98;
XOR* XOR2_99;
XOR* XOR2_100;
XOR* XOR2_101;
XOR* XOR2_102;
NAND* NAND2_103;
XOR* XOR2_104;
NAND* NAND2_105;
XOR* XOR2_106;
NAND* NAND2_107;
XOR* XOR2_108;
NAND* NAND2_109;
XOR* XOR2_110;
NAND* NAND2_111;
XOR* XOR2_112;
NAND* NAND2_113;
NAND* NAND2_114;
NAND* NAND2_115;
NAND* NAND2_116;
NAND* NAND2_117;
NAND* NAND2_118;
NAND* NAND2_119;
NAND* NAND2_120;
NAND* NAND2_121;
NAND* NAND2_122;
NAND* NAND2_123;
NAND* NAND2_124;
NAND* NAND2_125;
AND* AND9_126;
NOT* NOT1_127;
NOT* NOT1_128;
NAND* NAND2_129;
NAND* NAND2_130;
NAND* NAND2_131;
NAND* NAND2_132;
NAND* NAND2_133;
NAND* NAND2_134;
NAND* NAND2_135;
NAND* NAND2_136;
NAND* NAND2_137;
NAND* NAND4_138;
NAND* NAND4_139;
NAND* NAND4_140;
NAND* NAND4_141;
NAND* NAND4_142;
NAND* NAND4_143;
NAND* NAND4_144;
NAND* NAND4_145;
NAND* NAND4_146;
NOT* NOT1_147;
AND* AND8_148;
NOT* NOT1_149;
NOT* NOT1_150;
NOT* NOT1_151;
NOT* NOT1_152;
NOR* NOR2_153;
NAND* NAND2_154;
NAND* NAND4_155;
NAND* NAND3_156;
NAND* NAND4_157;
NAND* NAND4_158;
NAND* NAND4_159;
NAND* NAND4_160;
NOT1_1 = new NOT (N118, N1);
NOT1_2 = new NOT (N119, N4);
NOT1_3 = new NOT (N122, N11);
NOT1_4 = new NOT (N123, N17);
NOT1_5 = new NOT (N126, N24);
NOT1_6 = new NOT (N127, N30);
NOT1_7 = new NOT (N130, N37);
NOT1_8 = new NOT (N131, N43);
NOT1_9 = new NOT (N134, N50);
NOT1_10 = new NOT (N135, N56);
NOT1_11 = new NOT (N138, N63);
NOT1_12 = new NOT (N139, N69);
NOT1_13 = new NOT (N142, N76);
NOT1_14 = new NOT (N143, N82);
NOT1_15 = new NOT (N146, N89);
NOT1_16 = new NOT (N147, N95);
NOT1_17 = new NOT (N150, N102);
NOT1_18 = new NOT (N151, N108);
NAND2_19 = new NAND (N154, N118, N4);
NOR2_20 = new NOR (N157, N8, N119);
NOR2_21 = new NOR (N158, N14, N119);
NAND2_22 = new NAND (N159, N122, N17);
NAND2_23 = new NAND (N162, N126, N30);
NAND2_24 = new NAND (N165, N130, N43);
NAND2_25 = new NAND (N168, N134, N56);
NAND2_26 = new NAND (N171, N138, N69);
NAND2_27 = new NAND (N174, N142, N82);
NAND2_28 = new NAND (N177, N146, N95);
NAND2_29 = new NAND (N180, N150, N108);
NOR2_30 = new NOR (N183, N21, N123);
NOR2_31 = new NOR (N184, N27, N123);
NOR2_32 = new NOR (N185, N34, N127);
NOR2_33 = new NOR (N186, N40, N127);
NOR2_34 = new NOR (N187, N47, N131);
NOR2_35 = new NOR (N188, N53, N131);
NOR2_36 = new NOR (N189, N60, N135);
NOR2_37 = new NOR (N190, N66, N135);
NOR2_38 = new NOR (N191, N73, N139);
NOR2_39 = new NOR (N192, N79, N139);
NOR2_40 = new NOR (N193, N86, N143);
NOR2_41 = new NOR (N194, N92, N143);
NOR2_42 = new NOR (N195, N99, N147);
NOR2_43 = new NOR (N196, N105, N147);
NOR2_44 = new NOR (N197, N112, N151);
NOR2_45 = new NOR (N198, N115, N151);
AND9_46 = new AND (N199, N154, N159, N162, N165, N168, N171, N174, N177, N180);
NOT1_47 = new NOT (N203, N199);
NOT1_48 = new NOT (N213, N199);
NOT1_49 = new NOT (N223, N199);
XOR2_50 = new XOR (N224, N203, N154);
XOR2_51 = new XOR (N227, N203, N159);
XOR2_52 = new XOR (N230, N203, N162);
XOR2_53 = new XOR (N233, N203, N165);
XOR2_54 = new XOR (N236, N203, N168);
XOR2_55 = new XOR (N239, N203, N171);
NAND2_56 = new NAND (N242, N1, N213);
XOR2_57 = new XOR (N243, N203, N174);
NAND2_58 = new NAND (N246, N213, N11);
XOR2_59 = new XOR (N247, N203, N177);
NAND2_60 = new NAND (N250, N213, N24);
XOR2_61 = new XOR (N251, N203, N180);
NAND2_62 = new NAND (N254, N213, N37);
NAND2_63 = new NAND (N255, N213, N50);
NAND2_64 = new NAND (N256, N213, N63);
NAND2_65 = new NAND (N257, N213, N76);
NAND2_66 = new NAND (N258, N213, N89);
NAND2_67 = new NAND (N259, N213, N102);
NAND2_68 = new NAND (N260, N224, N157);
NAND2_69 = new NAND (N263, N224, N158);
NAND2_70 = new NAND (N264, N227, N183);
NAND2_71 = new NAND (N267, N230, N185);
NAND2_72 = new NAND (N270, N233, N187);
NAND2_73 = new NAND (N273, N236, N189);
NAND2_74 = new NAND (N276, N239, N191);
NAND2_75 = new NAND (N279, N243, N193);
NAND2_76 = new NAND (N282, N247, N195);
NAND2_77 = new NAND (N285, N251, N197);
NAND2_78 = new NAND (N288, N227, N184);
NAND2_79 = new NAND (N289, N230, N186);
NAND2_80 = new NAND (N290, N233, N188);
NAND2_81 = new NAND (N291, N236, N190);
NAND2_82 = new NAND (N292, N239, N192);
NAND2_83 = new NAND (N293, N243, N194);
NAND2_84 = new NAND (N294, N247, N196);
NAND2_85 = new NAND (N295, N251, N198);
AND9_86 = new AND (N296, N260, N264, N267, N270, N273, N276, N279, N282, N285);
NOT1_87 = new NOT (N300, N263);
NOT1_88 = new NOT (N301, N288);
NOT1_89 = new NOT (N302, N289);
NOT1_90 = new NOT (N303, N290);
NOT1_91 = new NOT (N304, N291);
NOT1_92 = new NOT (N305, N292);
NOT1_93 = new NOT (N306, N293);
NOT1_94 = new NOT (N307, N294);
NOT1_95 = new NOT (N308, N295);
NOT1_96 = new NOT (N309, N296);
NOT1_97 = new NOT (N319, N296);
NOT1_98 = new NOT (N329, N296);
XOR2_99 = new XOR (N330, N309, N260);
XOR2_100 = new XOR (N331, N309, N264);
XOR2_101 = new XOR (N332, N309, N267);
XOR2_102 = new XOR (N333, N309, N270);
NAND2_103 = new NAND (N334, N8, N319);
XOR2_104 = new XOR (N335, N309, N273);
NAND2_105 = new NAND (N336, N319, N21);
XOR2_106 = new XOR (N337, N309, N276);
NAND2_107 = new NAND (N338, N319, N34);
XOR2_108 = new XOR (N339, N309, N279);
NAND2_109 = new NAND (N340, N319, N47);
XOR2_110 = new XOR (N341, N309, N282);
NAND2_111 = new NAND (N342, N319, N60);
XOR2_112 = new XOR (N343, N309, N285);
NAND2_113 = new NAND (N344, N319, N73);
NAND2_114 = new NAND (N345, N319, N86);
NAND2_115 = new NAND (N346, N319, N99);
NAND2_116 = new NAND (N347, N319, N112);
NAND2_117 = new NAND (N348, N330, N300);
NAND2_118 = new NAND (N349, N331, N301);
NAND2_119 = new NAND (N350, N332, N302);
NAND2_120 = new NAND (N351, N333, N303);
NAND2_121 = new NAND (N352, N335, N304);
NAND2_122 = new NAND(N353, N337, N305);
NAND2_123 = new NAND (N354, N339, N306);
NAND2_124 = new NAND (N355, N341, N307);
NAND2_125 = new NAND (N356, N343, N308);
AND9_126 = new AND (N357, N348, N349, N350, N351, N352, N353, N354, N355, N356);
NOT1_127 = new NOT (N360, N357);
NOT1_128 = new NOT (N370, N357);
NAND2_129 = new NAND (N371, N14, N360);
NAND2_130 = new NAND (N372, N360, N27);
NAND2_131 = new NAND (N373, N360, N40);
NAND2_132 = new NAND (N374, N360, N53);
NAND2_133 = new NAND (N375, N360, N66);
NAND2_134 = new NAND (N376, N360, N79);
NAND2_135 = new NAND (N377, N360, N92);
NAND2_136 = new NAND (N378, N360, N105);
NAND2_137 = new NAND (N379, N360, N115);
NAND4_138 = new NAND (N380, N4, N242, N334, N371);
NAND4_139 = new NAND (N381, N246, N336, N372, N17);
NAND4_140 = new NAND (N386, N250, N338, N373, N30);
NAND4_141 = new NAND (N393, N254, N340, N374, N43);
NAND4_142 = new NAND (N399, N255, N342, N375, N56);
NAND4_143 = new NAND (N404, N256, N344, N376, N69);
NAND4_144 = new NAND (N407, N257, N345, N377, N82);
NAND4_145 = new NAND (N411, N258, N346, N378, N95);
NAND4_146 = new NAND (N414, N259, N347, N379, N108);
NOT1_147 = new NOT (N415, N380);
AND8_148 = new AND (N416, N381, N386, N393, N399, N404, N407, N411, N414);
NOT1_149 = new NOT (N417, N393);
NOT1_150 = new NOT (N418, N404);
NOT1_151 = new NOT (N419, N407);
NOT1_152 = new NOT (N420, N411);
NOR2_153 = new NOR (N421, N415, N416);
NAND2_154 = new NAND (N422, N386, N417);
NAND4_155 = new NAND (N425, N386, N393, N418, N399);
NAND3_156 = new NAND (N428, N399, N393, N419);
NAND4_157 = new NAND (N429, N386, N393, N407, N420);
NAND4_158 = new NAND (N430, N381, N386, N422, N399);
NAND4_159 = new NAND (N431, N381, N386, N425, N428);
NAND4_160 = new NAND (N432, N381, N422, N425, N429);
ALL_GATES.push_back(NOT1_1);
ALL_GATES.push_back(NOT1_2);
ALL_GATES.push_back(NOT1_3);
ALL_GATES.push_back(NOT1_4);
ALL_GATES.push_back(NOT1_5);
ALL_GATES.push_back(NOT1_6);
ALL_GATES.push_back(NOT1_7);
ALL_GATES.push_back(NOT1_8);
ALL_GATES.push_back(NOT1_9);
ALL_GATES.push_back(NOT1_10);
ALL_GATES.push_back(NOT1_11);
ALL_GATES.push_back(NOT1_12);
ALL_GATES.push_back(NOT1_13);
ALL_GATES.push_back(NOT1_14);
ALL_GATES.push_back(NOT1_15);
ALL_GATES.push_back(NOT1_16);
ALL_GATES.push_back(NOT1_17);
ALL_GATES.push_back(NOT1_18);
ALL_GATES.push_back(NAND2_19);
ALL_GATES.push_back(NOR2_20);
ALL_GATES.push_back(NOR2_21);
ALL_GATES.push_back(NAND2_22);
ALL_GATES.push_back(NAND2_23);
ALL_GATES.push_back(NAND2_24);
ALL_GATES.push_back(NAND2_25);
ALL_GATES.push_back(NAND2_26);
ALL_GATES.push_back(NAND2_27);
ALL_GATES.push_back(NAND2_28);
ALL_GATES.push_back(NAND2_29);
ALL_GATES.push_back(NOR2_30);
ALL_GATES.push_back(NOR2_31);
ALL_GATES.push_back(NOR2_32);
ALL_GATES.push_back(NOR2_33);
ALL_GATES.push_back(NOR2_34);
ALL_GATES.push_back(NOR2_35);
ALL_GATES.push_back(NOR2_36);
ALL_GATES.push_back(NOR2_37);
ALL_GATES.push_back(NOR2_38);
ALL_GATES.push_back(NOR2_39);
ALL_GATES.push_back(NOR2_40);
ALL_GATES.push_back(NOR2_41);
ALL_GATES.push_back(NOR2_42);
ALL_GATES.push_back(NOR2_43);
ALL_GATES.push_back(NOR2_44);
ALL_GATES.push_back(NOR2_45);
ALL_GATES.push_back(AND9_46);
ALL_GATES.push_back(NOT1_47);
ALL_GATES.push_back(NOT1_48);
ALL_GATES.push_back(NOT1_49);
ALL_GATES.push_back(XOR2_50);
ALL_GATES.push_back(XOR2_51);
ALL_GATES.push_back(XOR2_52);
ALL_GATES.push_back(XOR2_53);
ALL_GATES.push_back(XOR2_54);
ALL_GATES.push_back(XOR2_55);
ALL_GATES.push_back(NAND2_56);
ALL_GATES.push_back(XOR2_57);
ALL_GATES.push_back(NAND2_58);
ALL_GATES.push_back(XOR2_59);
ALL_GATES.push_back(NAND2_60);
ALL_GATES.push_back(XOR2_61);
ALL_GATES.push_back(NAND2_62);
ALL_GATES.push_back(NAND2_63);
ALL_GATES.push_back(NAND2_64);
ALL_GATES.push_back(NAND2_65);
ALL_GATES.push_back(NAND2_66);
ALL_GATES.push_back(NAND2_67);
ALL_GATES.push_back(NAND2_68);
ALL_GATES.push_back(NAND2_69);
ALL_GATES.push_back(NAND2_70);
ALL_GATES.push_back(NAND2_71);
ALL_GATES.push_back(NAND2_72);
ALL_GATES.push_back(NAND2_73);
ALL_GATES.push_back(NAND2_74);
ALL_GATES.push_back(NAND2_75);
ALL_GATES.push_back(NAND2_76);
ALL_GATES.push_back(NAND2_77);
ALL_GATES.push_back(NAND2_78);
ALL_GATES.push_back(NAND2_79);
ALL_GATES.push_back(NAND2_80);
ALL_GATES.push_back(NAND2_81);
ALL_GATES.push_back(NAND2_82);
ALL_GATES.push_back(NAND2_83);
ALL_GATES.push_back(NAND2_84);
ALL_GATES.push_back(NAND2_85);
ALL_GATES.push_back(AND9_86);
ALL_GATES.push_back(NOT1_87);
ALL_GATES.push_back(NOT1_88);
ALL_GATES.push_back(NOT1_89);
ALL_GATES.push_back(NOT1_90);
ALL_GATES.push_back(NOT1_91);
ALL_GATES.push_back(NOT1_92);
ALL_GATES.push_back(NOT1_93);
ALL_GATES.push_back(NOT1_94);
ALL_GATES.push_back(NOT1_95);
ALL_GATES.push_back(NOT1_96);
ALL_GATES.push_back(NOT1_97);
ALL_GATES.push_back(NOT1_98);
ALL_GATES.push_back(XOR2_99);
ALL_GATES.push_back(XOR2_100);
ALL_GATES.push_back(XOR2_101);
ALL_GATES.push_back(XOR2_102);
ALL_GATES.push_back(NAND2_103);
ALL_GATES.push_back(XOR2_104);
ALL_GATES.push_back(NAND2_105);
ALL_GATES.push_back(XOR2_106);
ALL_GATES.push_back(NAND2_107);
ALL_GATES.push_back(XOR2_108);
ALL_GATES.push_back(NAND2_109);
ALL_GATES.push_back(XOR2_110);
ALL_GATES.push_back(NAND2_111);
ALL_GATES.push_back(XOR2_112);
ALL_GATES.push_back(NAND2_113);
ALL_GATES.push_back(NAND2_114);
ALL_GATES.push_back(NAND2_115);
ALL_GATES.push_back(NAND2_116);
ALL_GATES.push_back(NAND2_117);
ALL_GATES.push_back(NAND2_118);
ALL_GATES.push_back(NAND2_119);
ALL_GATES.push_back(NAND2_120);
ALL_GATES.push_back(NAND2_121);
ALL_GATES.push_back(NAND2_122);
ALL_GATES.push_back(NAND2_123);
ALL_GATES.push_back(NAND2_124);
ALL_GATES.push_back(NAND2_125);
ALL_GATES.push_back(AND9_126);
ALL_GATES.push_back(NOT1_127);
ALL_GATES.push_back(NOT1_128);
ALL_GATES.push_back(NAND2_129);
ALL_GATES.push_back(NAND2_130);
ALL_GATES.push_back(NAND2_131);
ALL_GATES.push_back(NAND2_132);
ALL_GATES.push_back(NAND2_133);
ALL_GATES.push_back(NAND2_134);
ALL_GATES.push_back(NAND2_135);
ALL_GATES.push_back(NAND2_136);
ALL_GATES.push_back(NAND2_137);
ALL_GATES.push_back(NAND4_138);
ALL_GATES.push_back(NAND4_139);
ALL_GATES.push_back(NAND4_140);
ALL_GATES.push_back(NAND4_141);
ALL_GATES.push_back(NAND4_142);
ALL_GATES.push_back(NAND4_143);
ALL_GATES.push_back(NAND4_144);
ALL_GATES.push_back(NAND4_145);
ALL_GATES.push_back(NAND4_146);
ALL_GATES.push_back(NOT1_147);
ALL_GATES.push_back(AND8_148);
ALL_GATES.push_back(NOT1_149);
ALL_GATES.push_back(NOT1_150);
ALL_GATES.push_back(NOT1_151);
ALL_GATES.push_back(NOT1_152);
ALL_GATES.push_back(NOR2_153);
ALL_GATES.push_back(NAND2_154);
ALL_GATES.push_back(NAND4_155);
ALL_GATES.push_back(NAND3_156);
ALL_GATES.push_back(NAND4_157);
ALL_GATES.push_back(NAND4_158);
ALL_GATES.push_back(NAND4_159);
ALL_GATES.push_back(NAND4_160);
BUFFER* BUFFER_1;
BUFFER_1= new BUFFER(N223,N223);
BUFFER* BUFFER_2;
BUFFER_2= new BUFFER(N329,N329);
BUFFER* BUFFER_3;
BUFFER_3= new BUFFER(N370,N370);
BUFFER* BUFFER_4;
BUFFER_4= new BUFFER(N421,N421);
BUFFER* BUFFER_5;
BUFFER_5= new BUFFER(N430,N430);
BUFFER* BUFFER_6;
BUFFER_6= new BUFFER(N431,N431);
BUFFER* BUFFER_7;
BUFFER_7= new BUFFER(N432,N432);
ALL_GATES.push_back(BUFFER_1);
ALL_GATES.push_back(BUFFER_2);
ALL_GATES.push_back(BUFFER_3);
ALL_GATES.push_back(BUFFER_4);
ALL_GATES.push_back(BUFFER_5);
ALL_GATES.push_back(BUFFER_6);
ALL_GATES.push_back(BUFFER_7);
vector<char*> input_wires= {&N1,&N4,&N8,&N11,&N14,&N17,&N21,&N24,&N27,&N30,&N34,&N37,&N40,&N43,&N47,&N50,&N53,&N56,&N60,&N63,&N66,&N69,&N73,&N76,&N79,&N82,&N86,&N89,&N92,&N95,&N99,&N102,&N105,&N108,&N112,&N115};
/*vector <char> values= {'1','0','1','0','0','1','0','1','1','0','1','0','0','0','1','0','0','0','0','0','1','1','0','1','0','0','0','1','0','1','1','0','1','0','1','0'};
for (int i=0; i<input_wires.size(); i++){
    event temp;
    temp.wire=input_wires[i];
    temp.new_value=values[i];
    temp.time=0;
    vector<event>* destination= access_nth_element(TimingWheel,temp.time);
    destination->push_back(temp);
}*/
vector<char*> output_wires={&N223,&N329,&N370,&N421,&N430,&N431,&N432};
//deafult value
    N1='Z';  N4='Z'; N8='Z'; N11='Z'; N14='Z'; N17='Z'; N21='Z'; N24='Z'; N27='Z'; N30='Z'; 
    N34='Z'; N37='Z'; N40='Z'; N43='Z'; N47='Z'; N50='Z'; N53='Z'; N56='Z'; N60='Z'; N63='Z'; 
    N66='Z'; N69='Z'; N73='Z'; N76='Z'; N79='Z'; N82='Z'; N86='Z'; N89='Z'; N92='Z'; N95='Z'; 
    N99='Z'; N102='Z'; N105='Z'; N108='Z'; N112='Z'; N115='Z';
for (int i=0; i<ALL_GATES.size();i++){
    ALL_GATES[i]->evl();
    ALL_GATES[i]->updateval();
}
N223='Z'; N329='Z'; N370='Z'; N421='Z'; N430='Z'; N431='Z'; N432='Z';
vector<event> userevents;
while (true){
    string userinpp;
    getline(cin,userinpp);
    if (userinpp=="done") break;
    userevents=getinput(userinpp,input_wires);
}
twfunc(userevents,TimingWheel,ALL_GATES,cur_time,output_wires);
return 0;
}