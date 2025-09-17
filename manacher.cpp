#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
    if (s.empty()) return "";
    
    // Step 1: Transform the string
    string t = "^";
    for (char c : s) {
        t += "#" + string(1, c);
    }
    t += "#$";
    
    int n = t.size();
    vector<int> P(n, 0);
    int C = 0, R = 0;  // current center and right boundary
    
    // Step 2: Main loop
    for (int i = 1; i < n - 1; i++) {
        int mirror = 2*C - i;
        
        if (i < R) 
            // means we can use previously computed values
            // if minimum is r-i then it means the palindrome can be more longer 
            // if it is mirror then no computation needed more 
            P[i] = min(R - i, P[mirror]);
        
        // Expand around center i
        while (t[i + (1 + P[i])] == t[i - (1 + P[i])])
            P[i]++;
        
        // Update center and right boundary
        // if right boundary==center then it means
        // we can found a longer palindrome

        // and here just below it means
        // palindrome may contain only one value involving the center character
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    for(auto x:P)cout<<x<<" ";
    cout<<endl;
    
    // Step 3: Find the max length
    int maxLen = 0, centerIndex = 0;
    for (int i = 1; i < n - 1; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }
    
    // Step 4: Extract result
    int start = (centerIndex - maxLen) / 2; // map back to original string
    return s.substr(start, maxLen);
}

int main() {
    string s;
    cin >> s;
    cout << longestPalindrome(s) << endl;
}
