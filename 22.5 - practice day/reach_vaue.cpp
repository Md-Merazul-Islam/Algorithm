#include<bits/stdc++.h>
using namespace std;

bool check(long long val, long long tar)
{

    if(val== tar)
    {

        return true;
    }
    if(val> tar)
    {

        return false;
    }
    else
    {

        return check(val*10,tar) || check(val*20 , tar);
    }

}

int main()
{
    long long t;
    cin>>t;
    while(t--)
    {

        long long n;
        cin>>n;
        if(check(1,n))
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }


    return 0;
}
