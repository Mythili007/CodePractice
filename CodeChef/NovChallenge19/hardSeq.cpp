#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int lastElement = 0, nextElement = 0;
        int a[128], lastElementIndex;
        a[1] = a[2] = 0;
        for (int i = 3; i <= 128; i++)
        {
            // cout<<"a[i]: "<<a[i] << " ";
            nextElement = 0;
            lastElement = a[i - 1];
            lastElementIndex = i - 1;

            for (int j = lastElementIndex - 1; j >= 0; j--)
            {
                // cout<<"j : "<<j<<endl;
                if (lastElement == a[j])
                {
                    // cout<<"lastElement: "<< lastElement << " and a[j]: " << a[j] << " " << " lastelemnetindex: " << lastElementIndex << " " << endl;
                    nextElement = lastElementIndex - j;
                    break;
                }
            }
            // cout<< "nextElement: " << nextElement<<endl; 
            // cout<<endl;
            if (nextElement != 0){
                a[i] = nextElement;
                // cout<<"a[i]: "<<a[i]<<endl;
            }
            else{
                a[i] = 0;
                // cout<< "a[i]: "<<a[i]<<endl;
            }
        }
        int x = a[n], count=0;
        // cout<<"x: "<<x<<endl;
        for(int i=1;i<=n;i++){
            // cout<<a[i]<< " ";
            if(a[i] == x)
                count++;
        }
        cout<<count<<endl;
    }
    return 0;
}