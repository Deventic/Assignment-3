#include <iostream>
#include <cstring>
using namespace std;

int main() {
    const int MAX_SIZE = 100000;
    char dataset[MAX_SIZE];
    char needle[MAX_SIZE];
    
    cout << "=== String Frequency Finder ===" << endl;
    cout << "This program finds how many times the needle text appears in the dataset text." << endl;
    cout << endl;
    
    cout << "Enter the DATASET text (paste content from Dataset.txt):" << endl;
    cout << "(Press Enter, then Ctrl+Z and Enter on Windows to finish input)" << endl;
    
    int datasetIndex = 0;
    char ch;
    while (cin.get(ch) && datasetIndex < MAX_SIZE - 1) {
        dataset[datasetIndex++] = ch;
    }
    dataset[datasetIndex] = '\0';
    
    cin.clear();
    cin.ignore(10000, '\n');
    
    cout << "\nEnter the NEEDLE text (paste content from needle.txt):" << endl;
    cout << "(Press Enter, then Ctrl+Z and Enter on Windows to finish input)" << endl;
    
    int needleIndex = 0;
    while (cin.get(ch) && needleIndex < MAX_SIZE - 1) {
        needle[needleIndex++] = ch;
    }
    needle[needleIndex] = '\0';
    
    cout << "\n=== Processing ===" << endl;
    
    int datasetLen = strlen(dataset);
    int needleLen = strlen(needle);
    
    cout << "Dataset length: " << datasetLen << " characters" << endl;
    cout << "Needle length: " << needleLen << " characters" << endl;
    cout << endl;
    
    int frequency = 0;
    
    if (needleLen > 0 && needleLen <= datasetLen) {
        for (int i = 0; i <= datasetLen - needleLen; i++) {
            int j;
            
            for (j = 0; j < needleLen; j++) {
                if (dataset[i + j] != needle[j]) {
                    break;
                }
            }
            
            if (j == needleLen) {
                frequency++;
            }
        }
    }
    
    cout << "=== RESULT ===" << endl;
    cout << "Frequency of needle in dataset: " << frequency << endl;
    
    return 0;
}
