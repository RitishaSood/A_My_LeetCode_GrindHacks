class Solution {
public:

bool areSentencesSimilar(string sentence1, string sentence2) {
    vector<string> w1, w2;
    
    // Split sentence1
    stringstream ss1(sentence1);
    string word;
    while (ss1 >> word) {
        w1.push_back(word);
    }
    
    // Split sentence2
    stringstream ss2(sentence2);
    while (ss2 >> word) {
        w2.push_back(word);
    }
    
    // Ensure w1 is the shorter one
    if (w1.size() > w2.size()) {
        swap(w1, w2);
    }
    
    int i = 0;
    // Match prefix
    while (i < w1.size() && w1[i] == w2[i]) {
        i++;
    }
    
    int j = 0;
    // Match suffix
    while (j < w1.size() - i && w1[w1.size() - 1 - j] == w2[w2.size() - 1 - j]) {
        j++;
    }
    
    return (i + j == w1.size());
    }
};