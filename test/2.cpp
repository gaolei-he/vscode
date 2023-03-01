#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    if(s.find("Association_for_Computing_Machinery") != string::npos && \
    s.find("Air_Combat_Maneuvering") != string::npos)
        cout << "N0" << endl;
    else if(s.find("Association_for_Computing_Machinery") != string::npos)
        cout << "YES" << endl;
    else if(s.find("Air_Combat_Maneuvering") != string::npos)
        cout << "YES" << endl;
    else
        cout << "N0" << endl;
    return 0;
}