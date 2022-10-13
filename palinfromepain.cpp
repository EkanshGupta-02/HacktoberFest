#include<bits/stdc++.h>
using namespace std;


void solve(){

    long long int  a, b;
    cin >> a >> b;
    if (a % 2 == 1 && b % 2 == 1)
    {
        cout << -1 << endl;
        return;
    }
    else if (a % 2 == 0 && b % 2 == 1)
    {
        if (b == 1)
        {
            cout << -1 << endl;
            return;
        }
        for (long long int  i = 0; i < a / 2; i++)
        {
            cout << 'a';
        }
        for (long long int  i = 0; i < b; i++)
        {
            cout << 'b';
        }
        for (long long int  i = 0; i < a / 2; i++)
        {
            cout << 'a';
        }
        cout << endl;
        cout << 'b';
        for (long long int  i = 0; i < (a / 2); i++)
        {
            cout << 'a';
        }

        for (long long int  i = 0; i < b-2; i++)
        {
            cout << 'b';
        }
        for (long long int  i = 0; i < a / 2; i++)
        {
            cout << 'a';
        }
        cout << 'b';
        cout << endl;
    }
    else if (a % 2 == 1 && b % 2 == 0)
    {
        if (a == 1)
        {
            cout << -1 << endl;
            return;
        }
        for (long long int  i = 0; i < b / 2; i++)
        {
            cout << 'b';
        }
        for (long long int  i = 0; i < a; i++)
        {
            cout << 'a';
        }
        for (long long int  i = 0; i < b / 2; i++)
        {
            cout << 'b';
        }
        cout << endl;
        cout << 'a';
        for (long long int  i = 0; i < (b / 2); i++)
        {
            cout << 'b';
        }

        for (long long int  i = 0; i < a-2; i++)
        {
            cout << 'a';
        }
        for (long long int  i = 0; i < b / 2; i++)
        {
            cout << 'b';
        }
        cout << 'a';
        cout << endl;
    }
    else
    {
        for (long long int  i = 0; i < a / 2; i++)
        {
            cout << 'a';
        }
        for (long long int  i = 0; i < b; i++)
        {
            cout << 'b';
        }
        for (long long int  i = 0; i < a / 2; i++)
        {
            cout << 'a';
        }
        cout << endl;

        for (long long int  i = 0; i < b / 2; i++)
        {
            cout << 'b';
        }
        for (long long int  i = 0; i <a; i++)
        {
            cout << 'a';
        }
        for (long long int  i = 0; i < b / 2; i++)
        {
            cout << 'b';
        }
        cout << endl;
    }

}

int main(){
    int  t;
    cin>>t;

    while(t--){

        solve();
    }
    return 0;
}