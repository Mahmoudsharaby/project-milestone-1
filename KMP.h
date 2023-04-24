//
//  KMP.h
//  KMP Implementation
//
//  Created by Adham Ali on 22/04/2023.
//

#ifndef KMP_h
#define KMP_h

#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include "Database.h"

class KMP_algorithm
{
private:
    string pattern;
    string text;
    Database_handler *documents_for_search;
    vector<int> calculate()
    {
        int n = pattern.length();
        vector<int> arr(n, 0);
        int len = 0;
        int i = 1;
        while (i < n)
        {
            if (pattern[i] == pattern[len])
            {
                len++;
                arr[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                {
                    len = arr[len - 1];
                }
                else
                {
                    arr[i] = 0;
                    i++;
                }
            }
        }
        return arr;
    }
    
public:
    void kmp()
    {
        int n = text.length();
        int m = pattern.length();
        vector<int> arr = calculate(pattern);
        int i = 0;
        int j = 0;
        while (i < n)
        {
            if (text[i] == pattern[j])
            {
                i++;
                j++;
            }
            
            if (j == m)
            {
                cout << "Found pattern at index " << i - j << endl;
                cout<<"This is plagerized"<<endl;
                j = arr[j - 1];
            }
            else if (i < n && text[i] != pattern[j])
            {
                if (j != 0)
                {
                    j = arr[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }
    }
    void set_pattern(string n)
    {
        pattern=n;
    }
    void set_text(string k)
    {
        text=k;
    }
    string get_pattern()
    {
        return pattern;
    }
    string get_text()
    {
        return text;
    }
    
};


#endif /* KMP_h */
