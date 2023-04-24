#ifndef brute_force_alg
#define brute_force_alg

#include "Database.h"


class Brute_Force_algorithm{

int Differences = 0;
Database_handler * documents_for_search;
string text,pattern;

int Compute_Hamming_Distance(string one, string two){
    for(int i = 0; i < one.length(); i++){
        if(one[i] != two[i]){Differences++;}
    }
    return Differences;
}

void print_in_context(int index){
    cout << "\nThe context of the searched text in the orginial text: \n";
    for(int i = 50; i > 0; i--){
        cout << text[index - i];
    }
    for(int j = 0; j < 50; j++){
        cout << text[index + j];
    }
}

public:

void brute_force(){
    int n = text.length();
    int m = pattern.length();
    string substring_starting_from_i;
    int res_ham;

    for(int i = 0; i < (n-m); i++){
        substring_starting_from_i = text.substr(i,(m)); 
        res_ham = Compute_Hamming_Distance(substring_starting_from_i , pattern);
        if(res_ham == 0){
            cout << "A matching has occured at position " << i << endl;
            print_in_context(text,i);
        }
        }
}

};
#endif