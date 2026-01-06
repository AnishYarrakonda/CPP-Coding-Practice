#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to build the LPS array
vector<int> buildLPS(const string& pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int length = 0; // Length of the previous longest prefix suffix
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// Function to search for the pattern in the text using KMP
void KMP_Search(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

    if (m == 0) {
        cout << "Pattern is empty." << endl;
        return;
    }

    vector<int> lps = buildLPS(pattern);

    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Found pattern at index " << i - j << endl;
            // After finding a match, use the LPS array to find the next possible match
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            // Mismatch after some match
            // If j is not 0, use the LPS array to find the next character to check
            if (j != 0) {
                j = lps[j - 1];
            } else {
                // If j is 0, no prefix matched, just move to the next character in the text
                i++;
            }
        }
    }
}

int main() {
    string text = "ABABABCABABABCABAB";
    string pattern = "ABABABCABAB";
    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;
    KMP_Search(text, pattern);

    string text2 = "AAAAAB";
    string pattern2 = "AAAB";
    cout << "\nText: " << text2 << endl;
    cout << "Pattern: " << pattern2 << endl;
    KMP_Search(text2, pattern2);

    return 0;
}