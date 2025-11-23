#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(){
    char text[100];
    char pattern[100];
    bool matchall = false;
    bool hasquestion = false;
    int patternidx = 0, textidx = 0;
    int singlescounter = 0;
    cout << "Enter a word: ";
    cin.getline(text,100);
    cout << "Enter a pattern: ";
    cin.getline(pattern,100);
    while(pattern[patternidx] != '\0'){
        if(patternidx == 0 && pattern[patternidx] == '*' || pattern[patternidx] == '?'){
            if(pattern[patternidx] == '*' && matchall == false && hasquestion == false){
                matchall = true;
            }
            else{
                cout << "Match all already added";
                return 0;
            }
            if(pattern[patternidx] == '?' && matchall == false){
                while(pattern[patternidx] != '\0' && pattern[patternidx] == '?'){
                    singlescounter++;
                    patternidx++;
                }
            }
            else{
                
            }
        }
    }

    while(text[textidx] != '\0'){

    }

}