// Map is internally implemented using red balck trees
/// well the keys are unique if alwys the exting values of key gets updated
// in all tress the insertion and finding operation are of log(n)
#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<int, string> m;
    m[1] = "abc"; // Olog(n)
    m[2] = "abcd";
    m[3] = "abcde";
    // there is one more way of isnerting value inside the map
    // the keys are stores in order if the keys were string then it would have followes lexographical order
    m.insert({4, "abcdef"});
    m[6]; // its by default value is going to be 0 or empty vector or empty stirng//well mera toh nahi hoa kuch the result is empty

    // now the way to return the map elements
    map<int, string>::iterator it;
    for (it = m.begin(); it != m.end(); ++it)
    {
        cout << (*it).first << " " << (*it).second << endl;
    }
    // now find the value of the
    // auto it=m.find(3);//it return iterator
    it = m.find(3); // it return iterator
    // erase the element log(n)

    /*m.erase(3);
    if(it==m.end()){
        cout<<"Value dont exist";
    }
    else{
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }*/
    if (it != m.end())
    { // If key exists, erase it
        m.erase(it);
        cout << "Element with key 3 erased" << endl;
    }
    else
    {
        cout << "Value does not exist" << endl;
    }

    // Print map elements after deletion
    cout << "\nAfter deletion:\n";
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }
}

//time comlexity of storing the elements could increase if the keys sre long strings because comapring them could take time so the time complexity will be (size of string *log(n)).

//unorder map are exucted usign has tables and it may not compile with complex data types like set,vectors ,pair so only prmituve could work(cimaprison is possible in this);