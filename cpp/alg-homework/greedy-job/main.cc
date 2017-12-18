#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<pair<int, int>> greedy(vector<pair<int, int>> &jobs) {
    sort(jobs.begin(), jobs.end(), cmp);
    vector<pair<int, int>> seq;
    
    for(auto &job: jobs) {
        if(seq.empty())
            seq.push_back(job);
        else {
            int i = seq.size() - 1;
            for(; i >= 0 && seq[i].second >= job.second && seq[i].second > i + 1; i--);

            i++;
            if(i < seq.size()) {
                seq.emplace_back();
                for(int j = seq.size() - 1; j > i; j--) 
                    seq[j] = seq[j-1];
                seq[i] = job;
            }
        }
    }
    return seq;
}

int main() {
    vector<pair<int, int>> jobs = {{100, 2}, {10, 1}, {15, 2}, {20, 1}};

    cout << "orginal jobs: ";
    for(auto &job: jobs)
        cout << "{" << job.first << "," << job.second << "} ";
    cout << endl;
    
    vector<pair<int, int>> seq = greedy(jobs);
    cout << "best seq: ";
    for(auto &job: seq)
        cout << "{" << job.first << "," << job.second << "} ";
    cout << endl;

    return 0;
}
