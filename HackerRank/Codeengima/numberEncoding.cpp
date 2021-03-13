#include <bits/stdc++.h>
using namespace std;

void printCharWithFreq(string str)
{
    int n = str.size();
    int freq[n];
    int ones =0, twos =0, threes=0, fours=0,fives=0,sixes =0,sevens=0,eights=0,nines=0;
    // map<Character, Integer> map = new map<Character, Integer>();

    memset(freq, 0, sizeof(freq));
    for(int i=0;i<n;i++){
        if(str[i]== '1')
        {
            ones++;
            freq['1'] = ones;
        } 
        if(str[i]== '2')
        {
            twos++;
            freq['2'] = twos;
        }
        if(str[i]== '3')
        {
            threes++;
            freq['3'] = threes;
        }
        if(str[i]== '4')
        {
            fours++;
            freq['4'] = fours;
        }
        if(str[i]== '5')
        {
            fives++;
            freq['5'] = fives;
        }
        if(str[i]== '6')
        {
            sixes++;
            freq['6'] = sixes;
        }
        if(str[i]== '7')
        {
            sevens++;
            freq['7'] = sevens;
        }
        if(str[i]== '8')
        {
            eights++;
            freq['8'] = eights;
        }
        if(str[i]== '9')
        {
            nines++;
            freq['9'] = nines;
        }
    }
    vector<int> v;
    v.push_back(ones);
    v.push_back(twos);
    v.push_back(threes);
    v.push_back(fours);
    v.push_back(fives);
    v.push_back(sixes);
    v.push_back(sevens);
    v.push_back(eights);
    v.push_back(nines);

    for(int i=0;i<n;i++){
        if(str[i]=='1')
            cout<<v[0]<<str[i];
        if(str[i]=='1')
            cout<<v[0]<<str[i];
        if(str[i]=='1')
            cout<<v[0]<<str[i];
        if(str[i]=='1')
            cout<<v[0]<<str[i];
        if(str[i]=='1')
            cout<<v[0]<<str[i];
        if(str[i]=='1')
            cout<<v[0]<<str[i];
        if(str[i]=='1')
            cout<<v[]<<str[i];
        if(str[i]=='8')
            cout<<v[7]<<str[i];
        if(str[i]=='9')
            cout<<v[8]<<str[i];
    }
}
int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string st;
        cin >> st;
        printCharWithFreq(st);
    }
    return 0;
}
