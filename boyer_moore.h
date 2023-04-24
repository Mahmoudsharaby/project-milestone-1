#ifndef boyer_moore_h
#define boyer_moore_h
#include <iostream>
#include <string>
#include "Database.h"
# define NO_OF_CHARS 256
using namespace std;
class Boyer_Moore_algorithm
{
private:
    string text;
    string pattern;
    int bad_chars[NO_OF_CHARS];
    Database_handler *documents_for_search;
    void bad_chars_filler()
    {
        int i;
     
        // Initialize all occurrences as -1
        for (i = 0; i < NO_OF_CHARS; i++)
            bad_chars[i] = -1;
     
        // Fill the actual value of last occurrence
        // of a character
        for (i = 0; i < pattern.size(); i++)
            bad_chars[(int) pattern[i]] = i;
    }
    void preprocess_strong_suffix(int *shift, int *bpos)
    {
        int i=pattern.size();
        int j=pattern.size()+1;
        bpos[i]=j;
      
        while(i>0)
        {
            while(j<=pattern.size() && pattern[i-1] != pattern[j-1])
            {
                if (shift[j]==0)
                    shift[j] = j-i;
                j = bpos[j];
            }
            i--;j--;
            bpos[i] = j;
        }
    }
    void process_case_2(int *shift, int *bpos)
    {
        int i, j;
        j = bpos[0];
        for(i=0; i<=pattern.size(); i++)
        {
            if(shift[i]==0)
                shift[i] = j;
            if (i==j)
                j = bpos[j];
        }
    }
public:
    void search_method_1()
    {
        int m = pattern.size();
        int n = text.size();
        bad_chars_filler();
     
        int s = 0;
        while(s <= (n - m))
        {
            int j = m - 1;
            while(j >= 0 && pattern[j] == text[s + j])
                j--;
     
            if (j < 0)
            {
                cout << "pattern occurs at shift = " <<  s << endl;
     
                s += (s + m < n)? m-bad_chars[text[s + m]] : 1;
     
            }
     
            else
                s += max(1, j - bad_chars[text[s + j]]);
        }
    }
    void search_method_2()
    {
        int s=0, j;
        int m = pattern.size();
        int n = text.size();
      
        int bpos[m+1], shift[m+1];
      
        
        for(int i=0;i<m+1;i++) shift[i]=0;
      
        preprocess_strong_suffix(shift, bpos);
        process_case_2(shift, bpos);
      
        while(s <= n-m)
        {
      
            j = m-1;
            while(j >= 0 && pattern[j] == text[s+j])
                j--;
      
            if (j<0)
            {
                cout << "pattern occurs at shift=" << s <<endl;
                s += shift[0];
            }
            else
    
                s += shift[j+1];
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

#endif /* boyer_moore_h */
