#include <bits/stdc++.h>
using namespace std;
struct Location {
    long pin;
    string address;
};
struct Person
{
    int roll;
    int marks;
    struct Location location;
};
int main()
{
    int n;
    cin >> n;
    struct Person person[n];
    for (int i = 0; i < n; i++)
    {
        cout << "enter for person " << i + 1 << endl;
        cout << "enter roll: ";
        cin >> person[i].roll;
        cout << "enter marks: ";
        cin >> person[i].marks;
        cout << "enter location ";
        cin>>person[i].location.address;
    }
    cout << "entered values are " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "for person " << (i + 1) << ":  marks " << person[i].marks 
        << " roll no " << person[i].roll << " location "
         <<person[i].location.address << endl;
    }

    return 0;
}