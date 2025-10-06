#include <bits/stdc++.h>
using namespace std;

class Mo {
public:
    struct Query {
        // l,r --> query range [l,r] 
        // idx --> original pos of each query 
        int l, r, idx;
        bool operator<(const Query &other) const {
            int blockA = l / block_size;
            int blockB = other.l / block_size;
            if (blockA != blockB)
                return blockA < blockB;
            // Optimization: alternate sort order by block to reduce movement
            return (blockA & 1) ? (r > other.r) : (r < other.r);
        }
        // This specific sorting order ensures that the left pointer of the sliding window moves slowly, and the right pointer sweeps back and forth, minimizing total pointer movement.
    };

    static int block_size;

    int n;
    vector<int> arr;
    vector<Query> queries;

    // Problem-specific data
    vector<int> freq;
    long long curr_answer = 0; // Change this type based on the problem

    Mo(const vector<int> &a) {
        arr = a;
        n = (int)a.size();
        block_size = max(1, (int)sqrt(n));
        // freq ---> problem specific DS 
        freq.assign(1e6 + 5, 0); // Adjust depending on value range
    }

    void add_query(int l, int r, int idx) {
        queries.push_back({l, r, idx});
    }

    void add(int idx) {
        int val = arr[idx];
        // Example: distinct count logic
        freq[val]++;
        // it means we encountered that number very first time 
        if (freq[val] == 1) curr_answer++;
    }

    void remove(int idx) {
        int val = arr[idx];
        freq[val]--;
        if (freq[val] == 0) curr_answer--;
    }

    long long get_answer() const {
        return curr_answer;
    }

    vector<long long> process() {
        sort(queries.begin(), queries.end());
        vector<long long> answers(queries.size());
        int cur_l = 0, cur_r = -1;

        for (auto &q : queries) {
            while (cur_l > q.l) add(--cur_l);
            while (cur_r < q.r) add(++cur_r);
            while (cur_l < q.l) remove(cur_l++);
            while (cur_r > q.r) remove(cur_r--);

            answers[q.idx] = get_answer();
        }
        return answers;
    }
};

// Definition for static member
int Mo::block_size = 0;

// ======================= Example Usage =======================
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Mo mo(arr);

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        mo.add_query(l - 1, r - 1, i); // 0-based indexing
    }

    vector<long long> ans = mo.process();

    for (auto x : ans)
        cout << x << "\n";
}
