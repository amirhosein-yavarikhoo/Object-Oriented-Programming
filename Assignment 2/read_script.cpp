#include <iostream>
#include<fstream>
#include <iterator>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
vector <string> str_tokenize(string input){
    vector <string> tokenized;
    int start=0;
    int j;
    string tokened;
            for (j=0;j<input.length();j++){
                if ((input[j]==' ')){
                tokened=input.substr(start,j-start);
                tokenized.push_back(tokened);
                start=j+1;
                }
        }
        tokened=input.substr(start,j-start);
        tokenized.push_back(tokened);
    return tokenized;
}
int main(){
    vector <string> rf;
    ifstream read_ver ("c432.v");
    string temp1;
    vector<string> tokened;
    vector<string> final;
    vector <string> final2;
    vector <string> final3;
    vector<string> final4;
    int mode=1;
    while (getline(read_ver,temp1)){
            tokened=str_tokenize(temp1);
            string temp2="";
            string temp3="";
            string temp4="";
            string temp6="";
            if (tokened[0]=="module"){
                for (int i=2;i<tokened.size();i++) temp2=temp2+" "+tokened[i];
                temp3= "class "+ tokened[1]+ ' ' + temp2;
                mode=0;
            }
            else if (tokened[0]=="input") {
                for (int i=1;i<tokened.size();i++) temp2=temp2+" *"+tokened[i];
                temp3= "char " +tokened[1]+ ' ' + temp2;
                mode=0;
            }
            else if (tokened[0]=="output"){
                for (int i=1;i<tokened.size();i++) temp2=temp2+" "+tokened[i];
                temp3= "char " +tokened[1]+ ' ' + temp2;
                mode=0;
            }
            else if (tokened[0]=="wire"){
                for (int i=1;i<tokened.size();i++) temp2=temp2+" "+tokened[i];
                temp3= "char " +tokened[1]+ ' ' + temp2;
                mode=0;
            }
            else if (tokened[0]=="not") {
                for (int i=2;i<tokened.size();i++) temp2=temp2+" "+tokened[i];
                temp3="NOT* "+tokened[1]+";";
                temp4=tokened[1]+" "+"="+" "+"new"+" "+"NOT"+temp2;
                temp6="ALL_GATES.push_back("+tokened[1]+");";
            }
            else if (tokened[0]=="nand") {
                for (int i=2;i<tokened.size();i++) temp2=temp2+" "+tokened[i];
                temp3="NAND* "+tokened[1]+";";
                temp4=tokened[1]+" "+"="+" "+"new"+" "+"NAND"+temp2;
                temp6="ALL_GATES.push_back("+tokened[1]+");";
            }
            else if (tokened[0]=="nor") {
                for (int i=2;i<tokened.size();i++) temp2=temp2+" "+tokened[i];
                temp3="NOR* "+tokened[1]+";";
                temp4=tokened[1]+" "+"="+" "+"new"+" "+"NOR"+temp2;
                temp6="ALL_GATES.push_back("+tokened[1]+");";
            }
            else if (tokened[0]=="and") {
                for (int i=2;i<tokened.size();i++) temp2=temp2+" "+tokened[i];
                temp3="AND* "+tokened[1]+";";
                temp4=tokened[1]+" "+"="+" "+"new"+" "+"AND"+temp2;
                temp6="ALL_GATES.push_back("+tokened[1]+");";
            }
            else if (tokened[0]=="xor") {
                for (int i=2;i<tokened.size();i++) temp2=temp2+" "+tokened[i];
                temp3="XOR* "+tokened[1]+";";
                temp4=tokened[1]+" "+"="+" "+"new"+" "+"XOR"+temp2;
                temp6="ALL_GATES.push_back("+tokened[1]+");";
            }
            else {
                for (int i=0;i<tokened.size();i++) temp2=temp2+" "+tokened[i];
                temp3=temp2;
                mode=0;
            }
            final2.push_back(temp3);
            if (!mode) final.push_back(temp4);
            if (!mode) final4.push_back(temp6);
        }
        ofstream output_file("./netlist.txt");
        ostream_iterator<string> output_iterator(output_file, "\n");
        copy(final2.begin(), final2.end(), output_iterator);
        ostream_iterator<string> output_iterator2(output_file, "\n");
        copy(final.begin(), final.end(), output_iterator2);
        ostream_iterator<string> output_iterator4(output_file, "\n");
        copy(final4.begin(), final4.end(), output_iterator4);

            
        
    return 0;
}