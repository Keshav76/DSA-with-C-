#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    string s1 = "fam", s2 = "ily", s3 = "nincompoop";
    cout<<"S1 : "<<s1<<endl;
    cout<<"S2 : "<<s2<<endl;
    s1.append(s2);
    cout<<"S1 after appending S2 in it. : "<<s1<<endl;
    int emp = s1.empty();
    cout<<"IS S1 empty : "<<emp<<endl;
    cout<<"compare : "<<s1.compare(s2)<<endl;
    cout<<"s1 ka pehla char : "<<s1[0]<<endl;
    cout<<"s3 . find (\"com\") : "<<s3.find("com")<<endl;
    s3.erase(3, 3);
    cout<<"s3 after deleting 3 char from index 3 : "<<s3<<endl;
    s3.clear();
    cout<<"Cleared string : "<<s3<<endl;
    s3  = "nincompoop";
    sort (s3.begin(), s3.end());
    cout<<"Sorted string : "<<s3<<endl;
}
