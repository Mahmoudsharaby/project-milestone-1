#ifndef Database
#define Database
#include <vector>
#include <iostream>
#include <string>

using namespace std;
class Database_handler{
    
    static vector <string> document_names;
    static vector <string> documents_content;

    void get_data(){
        string name_f;
        for(int i = 0; i < document_names.size();i++){
            ifstream r;
            name_f = document_names[i]+=".txt"; 
            r.open(name_f);
            string s , Text;
            while(getline(r,s)){
                Text+=s;
            }
            documents_content[i] = Text; 
        }
    }
    int get_indx(string filename){
        int indx;
        for(int i = 0; i < document_names.size(); i++){
            if (document_names[i] == filename){
                indx = i;        
            } 
        }
        return indx;
    }
    public:
    
    Database_handler(string filename = ""){
        if(filename != ""){
        document_names.push_back(filename);}
        get_data();
        }
    void add_documents(string filename){
        document_names.push_back(filename);}
    void remove_documents(string filename){
        vector <string>:: iterator it;
        it = remove(document_names.begin(), document_names.end() , filename);
        it = remove(documents_content.begin(), documents_content.end() , documents_content[get_indx(filename)]);
    }

    };
