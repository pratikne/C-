#include <bits/stdc++.h>
using namespace std;

int main()
{

    string str;
    int pos;
    static int count = 0;
    for (int i = 1; i < 1000; i++)
    {
        str = to_string(i);
        pos = 0;
        // while (str.find('7', pos++) != string::npos)
        // {
        //     count++;
        // }
        for(int j=0; j < str.length(); j++){
            if(str[j] == '7'){
                count++;
            }
        }
    }
     cout << "7 occurs = " << count << " times" << endl;

    return 0;
}