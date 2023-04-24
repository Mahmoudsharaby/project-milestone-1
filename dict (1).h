#ifndef dict
#define dict
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Paraphrasing_tool{

map <string , string> thesaurs_PD;
string read_sentences,syns_ants,key;
bool is_read_before = 0;
ifstream reading_instance;

string tolower_str(string sub){
string res = "";
for(int i = 0 ; i < sub.length();i++){
res += tolower(sub[i]);
}
return res;
}

public:

Paraphrasing_tool(){

reading_instance.open("samp.txt");
while(getline(reading_instance,read_sentences)){
if(read_sentences.length() < 5 ) {continue;}
if(tolower(read_sentences.at(3)) >= 'a' && tolower(read_sentences.at(3)) <= 'z'){
key = tolower_str(read_sentences.substr(3,read_sentences.length()-3));
is_read_before = true;
}
if((tolower(read_sentences.at(4)) >= 'a' && tolower(read_sentences.at(4)) <= 'z') && (is_read_before == false)){
key = tolower_str(read_sentences.substr(4,read_sentences.length()-4));
is_read_before = true;
}
if((tolower(read_sentences.at(5)) >= 'a' && tolower(read_sentences.at(5)) <= 'z') && (is_read_before == false)){
key = tolower_str(read_sentences.substr(5,read_sentences.length()-5));
}


else if (tolower_str(read_sentences.substr(0,3)) == "syn"){
syns_ants = tolower_str(read_sentences.substr(7,read_sentences.length()-4));
}

else if (tolower_str(read_sentences.substr(0,3)) == "ant"){
syns_ants+=' ';
syns_ants+= tolower_str(read_sentences.substr(7,read_sentences.length()-3));
thesaurs_PD.insert({key,syns_ants});
is_read_before = false;
}
}
}


string first_token(string n){
	
    //create  a vector of tokens
    
    vector <string> tokens;
    
    string intermediate_str;
     
    stringstream check(n);
     
     
    // Tokenizing the string of synonyms
    while(getline(check, intermediate_str, ' '))
    {
        tokens.push_back(intermediate_str);
    }
     
    // return one of the synonms to the word. In particular, the first one.
    return tokens[0];
}

string get_synonyms(string word){
    map <string, string> :: iterator it;
    string res = word;
    bool k = 0;
    for(it = thesaurs_PD.begin(); it != thesaurs_PD.end() ; it++){
    if (it->first == word){
    res = first_token(it->second);
    
    }
    }
    return res;
}

void print_dict(){ 
    map <string, string> :: iterator it;
    for(it = thesaurs_PD.begin(); it != thesaurs_PD.end() ; it++){
    cout <<it->first << "  "  << it->second << endl;
    }
}

string process_text(string txt){
    vector <string> tokens;
     
    // stringstream class check1
    stringstream check1(txt);
     
    string intermediate;
     
    // Tokenizing w.reading_instance.t. space ' '
    while(getline(check1, intermediate, ' '))
    {
        tokens.push_back(intermediate);
    }
     
    // Printing the token vector
    string new_sent = "";
    for(int i = 0; i < tokens.size(); i++){
        new_sent += get_synonm(tokens[i]);
        new_sent+=' ';
    }
    return new_sent;
}
};
#endif
