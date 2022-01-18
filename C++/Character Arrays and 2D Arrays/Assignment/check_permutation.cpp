#include<iostream>
#include<cstring>
using namespace std;

// Approach1 : here all characters of str1 are matched with all characters of str2, If found update the value to '0', so that it do not form repetition in matching.
bool CheckPermutation1(char str1[], char str2[]){
    for(int i=0; i<strlen(str1); i++){
        bool found = false;
        for(int j=0; j<strlen(str2); j++){
            if(str1[i] == str2[j]){
                str2[j] = '0';
                found = true;
                break;
            }
        }
        if(!found){
            return false;
        }
    }
    return true;
}

// Approach2 : Since we know that there are 256 unique characters. So we can save the frequency of each character in an array of 256.
bool CheckPermutation2(char str1[], char str2[]){
    int frequency[256] = {0};
    if(strlen(str1) != strlen(str2))
        return false;
    for(int i=0; i<strlen(str1); i++)
        frequency[str1[i]]++;
    for(int i=0; i<strlen(str2); i++)
        frequency[str1[i]]--;
    for(int i=0; i<256; i++){
        if(frequency[i] != 0){
            return false;
        }
    }
    return true;
}

int main() {
    char str1[100], str2[100];
    bool isPermutation;
    cin>>str1>>str2;
    isPermutation = CheckPermutation1(str1, str2);
    if(isPermutation)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
}