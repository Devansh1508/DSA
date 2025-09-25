#include <bits/stdc++.h>
using namespace std;


// Aho–Corasick: relies on suffix links that connect to valid prefixes of other patterns.
class AhoCorasick {
private:
    struct Node {
        array<int, 26> next{};
        int link = -1;              // failure link
        vector<int> out;            // pattern indices ending here
        Node() { next.fill(-1); }
    };

    // it is used for maintaining the trie structure
    vector<Node> trie;

public:
    AhoCorasick() { trie.emplace_back(); }

    // Add a pattern and associate it with an index
    void addPattern(const string &pat, int idx) {
        int v = 0;
        for (char c : pat) {
            int ch = c - 'a';
            if (trie[v].next[ch] == -1) {
                trie[v].next[ch] = trie.size();
                // pushing back the new node 
                // similar to push_back(Node())
                trie.emplace_back();
            }
            v = trie[v].next[ch];
        }
        trie[v].out.push_back(idx); // mark end of pattern
    }

    // Build failure links
    // using BFS 
    void build() {
        queue<int> q;
        // pointing root to root 
        trie[0].link = 0;
        q.push(0);

        while (!q.empty()) {
            // v---> current node 
            // u ---> child node
            int v = q.front(); q.pop();

            for (int ch = 0; ch < 26; ch++) {
                int u = trie[v].next[ch];

                // u==-1 ---> no child for character ch
                if (u == -1) {
                    // if current was root then it means no node to fallback so point it to root
                    // 0 ---> means the root 
                    // if v!=0 --> Follow the failure link of v(parent node)
                    // which means if I can’t go here, jump to the longest suffix that could continue with this character
                    trie[v].next[ch] = (v == 0 ? 0 : trie[trie[v].link].next[ch]);
                    // trie[trie[v].link].next[ch] ---> means that we are moving to the failure link of v because suffix will surely matched with the pattern so now we are checking for the next character
                } else {
                    // connecting the child with a link 
                    // if parent is root then child link will also point to root
//                     Suppose we just built edge v --ch--> u.

                    // If the search fails at u (mismatch later), we want to know:
                    // “What’s the next longest suffix we can still match if we see ch?”

                    // Where do we find that?
                    // 👉 By taking the failure link of v (i.e., best suffix before ch), and asking:
                    // “From there, if I see ch, where would I go?”

                    // That’s exactly trie[trie[v].link].next[ch].
                    trie[u].link = (v == 0 ? 0 : trie[trie[v].link].next[ch]);
                    // now if the next[ch] do not exist for trie[v].link then it will point to root because of the above condition in if part 
                    for (int id : trie[trie[u].link].out)
                        trie[u].out.push_back(id); // merge outputs
                    q.push(u);
                }
            }
        }
    }

    // Search all patterns in the text
    vector<int> search(const string &text, int patternCount) {
        vector<int> found(patternCount, 0);
        int v = 0; // start at root
        for (char c : text) {
            int ch = c - 'a';
            v = trie[v].next[ch];
            for (int id : trie[v].out)
                found[id] = 1; // mark pattern found
        }
        return found;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text;
    cin >> text;
    int k;
    cin >> k;

    vector<string> patterns(k);
    for (int i = 0; i < k; i++) cin >> patterns[i];

    AhoCorasick ac;
    for (int i = 0; i < k; i++) ac.addPattern(patterns[i], i);

    ac.build();

    vector<int> found = ac.search(text, k);

    for (int i = 0; i < k; i++) {
        cout << (found[i] ? "YES" : "NO") << "\n";
    }

    return 0;
}
