#ifndef rabin
#define rabin
#define d 256
#include "Database.h"
#include <bits/stdc++.h>

using namespace std;
// d is the number of characters in the input alphabet

class Rabin_Karp_algorithm{

string pattern, text;
Database_handler * documents_for_search;

public:

void run_rabin_karp(int q)
{
	int M = pat.length();
	int N = txt.length();
	int i, j;
	int p = 0, h = 1  , t = 0;


	for (i = 0; i < M - 1; i++)
		h = (h * d) % q;

	for (i = 0; i < M; i++) {
		p = (d * p + pat[i]) % q;      //p =pat[i]+p; it turns out that we can use ASCII table
		t = (d * t + txt[i]) % q;      //t =txt[i]+t; it turns out that we can use ASCII table
	}

	for (i = 0; i <= N - M; i++) {

		// Check the value of the chunck of text and pattern
		// If the hash values match then check corresponding characters

		if (p == t) {
			for (j = 0; j < M; j++) {
				if (txt[i + j] != pat[j]) {
					break;
				}
			}

			if (j == M)
				cout << "Pattern found at index " << i
					<< endl;
		}
		if (i < N - M) {
			t = (d * (t - txt[i] * h) + txt[i + M]) % q;  //t = (t-txt[i]); using ASCII
			t += txt[i+M];
			
            // to handle negative t values

			if (t < 0)
				t = (t + q);
		}
	}
}
void set_pattern(string pat_to_set) {pattern = pat_to_set;}
void set_text(string txt_to_set) {text = txt_to_set;}
string get_text(){
    return text;
}
string get_pattern(){
    return pattern;
}
};
#endif