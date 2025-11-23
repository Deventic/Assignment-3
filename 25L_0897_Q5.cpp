#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    char word[100];
    char compressed[100] = {'\0'};
    cin.getline(word, 100);

    int compidx = 0;

    int count = 0;
    while (word[count] != '\0')
        count++;

    for (int i = 0; i < count;)
    {
        char ch = word[i];
        int wordcount = 0;

        while (i < count && word[i] == ch)
        {
            wordcount++;
            i++;
        }
        char wordcountchar = static_cast<char>(wordcount + 48);
        compressed[compidx] = ch;
        compressed[compidx+1] = wordcountchar;
        compidx +=2;
    }

    cout << compressed << '\n';
    compidx = 0;
    cout << "Decompressed\n";
    while(compressed[compidx] != '\0'){
        char ch2 = compressed[compidx];
        char charcount = compressed[compidx+1];
        int counter = charcount - '0';
        for(int i = 0; i < counter; i++){
            cout << ch2;
        }
        compidx +=2;
    }
}