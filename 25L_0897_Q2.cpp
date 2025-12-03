#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char text[200];
    char pattern[200];

    cout << "Enter text: ";
    cin.getline(text, 200);
    cout << "Enter pattern: ";
    cin.getline(pattern, 200);

    cout << "answer = ";
    bool first = true;
    int len = strlen(text);

    for (int i = 0; i < len; i++) {
        int curr_text_idx = i;
        int curr_pattern_idx = 0;
        int star_idx = -1;
        int match_idx = -1;
        bool match = false;

        while (true) {
            if (pattern[curr_pattern_idx] == '\0') {
                match = true;
                break;
            }

            if (text[curr_text_idx] != '\0' && (pattern[curr_pattern_idx] == '?' || pattern[curr_pattern_idx] == text[curr_text_idx])) {
                curr_text_idx++;
                curr_pattern_idx++;
            }
            else if (pattern[curr_pattern_idx] == '*') {
                star_idx = curr_pattern_idx;
                match_idx = curr_text_idx;
                curr_pattern_idx++;
            }
            else if (star_idx != -1) {
                if (text[match_idx] == '\0') {
                    break;
                }
                curr_pattern_idx = star_idx + 1;
                match_idx++;
                curr_text_idx = match_idx;
            }
            else {
                break;
            }
        }

        if (match) {
            if (!first) cout << ", ";
            cout << i;
            first = false;
        }
    }
    cout << endl;

    return 0;
}
