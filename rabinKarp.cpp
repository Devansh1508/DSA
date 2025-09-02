#include <bits/stdc++.h>
using namespace std;

#define d 256 // number of possible characters (ASCII set)

// q ---> prime modulus 
// used to reduce hash collisions

// Rabin-Karp algorithm for pattern searching
void rabinKarp(string text, string pattern, int q) {
    int n = text.size();
    int m = pattern.size();

    int p = 0; // hash value for pattern
    int t = 0; // hash value for text window
    int h = 1;

    // h = pow(d, m-1) % q
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Initial hash for pattern and first window of text
    // hash will be like d^(m-1) * text[0] + d^(m-2) * text[1] + ... + text[m-1]
    // m is the length of the pattern
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text one by one
    for (int i = 0; i <= n - m; i++) {
        // If hash values match, check characters one by one
        if (p == t) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match)
                cout << "Pattern found at index " << i << endl;
        }

        // Compute hash for next window: remove first char, add next char
        if (i < n - m) {
            // h = d^(m-1) mod q
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            // In case of negative value, convert it to positive
            if (t < 0)
                t = (t + q);
        }
    }
}

int main() {
    string text = "abedabc";
    string pattern = "abc";
    int q = 101; // A prime number to reduce collisions

    rabinKarp(text, pattern, q);

    return 0;
}
