/**
 * https://leetcode.com/problems/maximum-number-of-balloons/
 * 
  */

#include <bits/stdc++.h>
#include <cctype>
using namespace std;

class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        unordered_map<char, int> m;
        for (int i = 0; i < text.size(); i++)
            m[text[i]]++;
        return min(m['b'], min(m['a'], min(m['l'] / 2, min(m['o'] / 2, m['n']))));
    }
};

void _main()
{
    Solution sol;
    string a = "nlaebolko";
    a = "loonbalxballpoon";
    a = "krhizmmgmcrecekgyljqkldocicziihtgpqwbticmvuyznragqoyrukzopfmjhjjxemsxmrsxuqmnkrzhgvtgdgtykhcglurvppvcwhrhrjoislonvvglhdciilduvuiebmffaagxerjeewmtcwmhmtwlxtvlbocczlrppmpjbpnifqtlninyzjtmazxdbzwxthpvrfulvrspycqcghuopjirzoeuqhetnbrcdakilzmklxwudxxhwilasbjjhhfgghogqoofsufysmcqeilaivtmfziumjloewbkjvaahsaaggteppqyuoylgpbdwqubaalfwcqrjeycjbbpifjbpigjdnnswocusuprydgrtxuaojeriigwumlovafxnpibjopjfqzrwemoinmptxddgcszmfprdrichjeqcvikynzigleaajcysusqasqadjemgnyvmzmbcfrttrzonwafrnedglhpudovigwvpimttiketopkvqw";
    int res = sol.maxNumberOfBalloons(a);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}