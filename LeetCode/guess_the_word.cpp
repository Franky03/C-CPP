#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// This is the Master's API interface.
// You should not implement it, or speculate about its implementation

class Master {
public:
    int guess(string word);
};



class Solution{
    public:
    
        int match(string a, string b) {
            int count = 0;
            for (int i = 0; i < 6; i++) {
                if (a[i] == b[i]) {
                    count++;
                }
            }
            return count;
        }

       void findSecretWord(vector<string>& words, Master& master){
            random_shuffle(words.begin(), words.end());
            for (int i = 0; i < 30; i++) {
                string guess = words[rand() % words.size()];
                int x = master.guess(guess);
                if(x == 6) return;
                vector<string> temp;
                for (string w : words) {
                    if (match(guess, w) == x) {
                        temp.push_back(w);
                    }
                }

                if(temp.size() < words.size() / 2) {
                    swap(words, temp);
                }
        
            
                
            }
        }
};