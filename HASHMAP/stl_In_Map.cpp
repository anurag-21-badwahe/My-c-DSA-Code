#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    //creation
    unordered_map<string,int> m;

    //insertion
    
    //METHOD 1:
    pair<string,int>p = make_pair("ANURAG",12);
    m.insert(p);

    //METHOD 2:
    pair<string,int>pair2("badwahe",2);
    m.insert(pair2);

    //METHOD 3:
    m["My"] = 1;
    m["NAME"] = 23;

    //UPDATION
    m["is"] = 12;


    //SEARCHING
    cout << m["ANURAG"]<<endl;
    cout << m.at("badwahe") << endl;

    //IF I WANT TO SEARCH A ENTRY WHICH I NEVER INSERT

   // cout << m.at("newKey") << endl;//ERROR
     cout << m["unknownKey"] << endl;//THIS LINE CREATE AN ENTRY IF ELEMENT NOT FOUND;
     cout << m.at("unknownKey") << endl;//ERROR



     //size
     cout << m.size()<<endl;

     //erase
     m.erase("is");
    cout << m.size()<<endl;


    // ITERATOR
     unordered_map<string,int> :: iterator it = m.begin();

     while(it != m.end()){
     cout << it->first << " " << it->second << endl;
     it++;
     }

}