#include <iostream>
#include <string>
#include <cmath>
#include <vector>

// Function to implement the Rabin-Karp algorithm
void rabinKarp(const std::string& text, const std::string& pattern, long long prime) {
    int n = text.length();
    int m = pattern.length();
    if (m == 0 || m > n) return;

    // A common base for the hash function (e.g., 256 for ASCII characters)
    int base = 256;
    long long patternHash = 0; // Hash value for pattern
    long long textHash = 0;    // Hash value for current text window
    long long h = 1;           // h is pow(base, m-1) % prime

    // Calculate h = pow(base, m-1) % prime
    for (int i = 0; i < m - 1; i++) {
        h = (h * base) % prime;
    }

    // Calculate the initial hash value for the pattern and the first text window
    for (int i = 0; i < m; i++) {
        patternHash = (patternHash * base + text[i]) % prime;
        textHash = (textHash * base + text[i]) % prime;
    }

    // Slide the pattern over the text
    for (int i = 0; i <= n - m; i++) {
        // If hash values match, then only check characters one by one
        if (patternHash == textHash) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                std::cout << "Pattern found at index " << i << std::endl;
            }
        }

        // Calculate hash value for the next window of text
        if (i < n - m) {
            // Remove the leading character's contribution, shift, add the new trailing character, and apply modulo
            textHash = (base * (textHash - text[i] * h) + text[i + m]) % prime;
            
            // We might get a negative value of textHash, convert it to a positive one
            if (textHash < 0) {
                textHash = (textHash + prime);
            }
        }
    }
}

int main() {
    std::string text = "ABCA BCABCABC";
    std::string pattern = "ABC";
    long long prime = 1e9+7; // A large prime number

    std::cout << "Text: " << text << std::endl;
    std::cout << "Pattern: " << pattern << std::endl;
    rabinKarp(text, pattern, prime);

    return 0;
}