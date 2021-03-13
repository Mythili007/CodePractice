/**
 * https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // void resetUnorderedMap()
    // {
    //     unordered_map<char, int> um;
    //     for (int i = 0; i < 26; i++)
    //         um[i + 'a']++;
    // }
    // unordered_set<char> us;
    int countCharacters(vector<string> &words, string chars)
    {
        int count = 0;
        unordered_map<char, int> um;
        for (int i = 0; i < chars.size(); i++)
            um[chars[i]]++;
        for (int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            bool isValid = true;
            unordered_map<char, int> checkFreq;
            for (char ch : word)
            {
                if (um.find(ch) != um.end())
                    checkFreq[ch]++;
                else
                {
                    isValid = false;
                    break;
                }
            }
            for (char ch : word)
            {
                if (checkFreq[ch] > um[ch])
                    isValid = false;
            }

            count += ((isValid) ? word.size() : 0);
        }
        return count;
    }
};

void _main()
{
    Solution sol;
    vector<string> words = {"cat", "bt", "hat", "tree"};
    string chars = "atach";
    words = {"hello", "world", "leetcode"}, chars = "welldonehoneyr";
    words = {"dyiclysmffuhibgfvapygkorkqllqlvokosagyelotobicwcmebnpznjbirzrzsrtzjxhsfpiwyfhzyonmuabtlwin", "ndqeyhhcquplmznwslewjzuyfgklssvkqxmqjpwhrshycmvrb", "ulrrbpspyudncdlbkxkrqpivfftrggemkpyjl", "boygirdlggnh", "xmqohbyqwagkjzpyawsydmdaattthmuvjbzwpyopyafphx", "nulvimegcsiwvhwuiyednoxpugfeimnnyeoczuzxgxbqjvegcxeqnjbwnbvowastqhojepisusvsidhqmszbrnynkyop", "hiefuovybkpgzygprmndrkyspoiyapdwkxebgsmodhzpx", "juldqdzeskpffaoqcyyxiqqowsalqumddcufhouhrskozhlmobiwzxnhdkidr", "lnnvsdcrvzfmrvurucrzlfyigcycffpiuoo", "oxgaskztzroxuntiwlfyufddl", "tfspedteabxatkaypitjfkhkkigdwdkctqbczcugripkgcyfezpuklfqfcsccboarbfbjfrkxp", "qnagrpfzlyrouolqquytwnwnsqnmuzphne", "eeilfdaookieawrrbvtnqfzcricvhpiv", "sisvsjzyrbdsjcwwygdnxcjhzhsxhpceqz", "yhouqhjevqxtecomahbwoptzlkyvjexhzcbccusbjjdgcfzlkoqwiwue", "hwxxighzvceaplsycajkhynkhzkwkouszwaiuzqcleyflqrxgjsvlegvupzqijbornbfwpefhxekgpuvgiyeudhncv", "cpwcjwgbcquirnsazumgjjcltitmeyfaudbnbqhflvecjsupjmgwfbjo", "teyygdmmyadppuopvqdodaczob", "qaeowuwqsqffvibrtxnjnzvzuuonrkwpysyxvkijemmpdmtnqxwekbpfzs", "qqxpxpmemkldghbmbyxpkwgkaykaerhmwwjonrhcsubchs"},
    chars = "usdruypficfbpfbivlrhutcgvyjenlxzeovdyjtgvvfdjzcmikjraspdfp";
    int res = sol.countCharacters(words, chars);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}