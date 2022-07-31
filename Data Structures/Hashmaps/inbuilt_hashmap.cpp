#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> ourmap;

    // Insert
    pair<string, int> p("abc", 1);
    ourmap.insert(p);
    ourmap["def"] = 2;

    // Find or Access
    cout << ourmap["abc"] << endl;
    cout << ourmap.at("abc") << endl;

    // Error as there does not exist key named "ghi"
    // cout << ourmap.at("ghi") << endl;

    cout << "Size: " << ourmap.size() << endl;
    // If key does not exist, it will add a key named "ghi" with default value of 0 
    cout << ourmap["ghi"] << endl;
    cout << "Size: " << ourmap.size() << endl;

    // To check the presence
    if(ourmap.count("ghi") > 0)
        cout << "ghi is present" << endl;
    else
        cout << "ghi is not present" << endl;
    
    // To erase an element
    ourmap.erase("ghi");

    // To check the presence
    cout << "Size: " << ourmap.size() << endl;

    if(ourmap.count("ghi") > 0)
        cout << "ghi is present" << endl;
    else
        cout << "ghi is not present" << endl;    
}