#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> count;
        for (int card : hand) count[card]++;

        for (auto it = count.begin(); it != count.end(); ++it) {
            int card = it->first;
            int freq = it->second;
            if (freq > 0) {
                // Try to build group starting from card
                for (int i = 0; i < groupSize; i++) {
                    int needCard = card + i;
                    if (count[needCard] < freq)
                        return false;
                    count[needCard] -= freq;
                }
            }
        }
        return true;
    }
};
