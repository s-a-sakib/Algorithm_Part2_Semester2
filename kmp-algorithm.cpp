/*
    Programmer : Shahrear Al Sakib
    Title: KMP Algorithms
    Date: Feb 3, 2024
*/

#include <bits/stdc++.h>
using namespace std;
vector < int > createTempArray(string pattern){
    vector < int > lps(pattern.length());
    int index = 0;
    for(int i = 1; i < pattern.length(); ){
        if(pattern[i] == pattern[index]){
            lps[i] = index + 1;
        }else{
            if(index != 0) index = lps[index - 1];
            else{
                lps[index] = index; ++i;
            }
        }
    }
    return lps;
}

void KMP_Algorithm(string text, string pattern){
    vector < int > lps = createTempArray(pattern);
    bool found = false;

    int i = 0, j = 0;
    // i for text and j for pattern

    while(i < text.length()){
        if(pattern[j] == text[i]){
            ++i; j++;
        }else{
            if(j != 0) j = lps[j - 1];
            else i++;
        }

        if(j == pattern.length()){
            cout << "pattern found " << endl;
            found = true;
            cout << "Index : " << i - (pattern.length()) << endl;
            break;
        }
    }
    if(!found){
        cout << "pattern not found in text. " << endl;
    }
}
void sovle(){
    string text , pattern;
    getline(cin , text);
    getline(cin , pattern);
    KMP_Algorithm(text, pattern);
}
int main(){
    int cases = 1;
    // cin >> cases;
    while(cases--) sovle();
    return 0;
}