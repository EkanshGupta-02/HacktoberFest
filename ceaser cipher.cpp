#include<bits/stdc++.h>

using namespace std;

bool comp(const pair<char,int> &a, const pair<char,int> &b){
    return a.second > b.second;
}

string removeSpaces(string str)
{
    string value = "";
    for (int i = 0; i<str.size(); i++){
        if (str[i] == ' '){
            continue;
        }
        if(str[i] == ','){
            continue;
        }
        value += str[i]; // here count is incremented
    }
    return value;
}

string encrypt(string plainText){
    string encryptedString = "";
    for(int i = 0;i<plainText.size();i++){
        char ch = plainText[i];
        char newChar = 25-(ch -'A')+'A';
        encryptedString += newChar;
    }
    return encryptedString;
}

void countFrequency(string encryptedString, vector<pair<char,int>> &freq){
    for(int i = 0;i<encryptedString.size();i++){
        freq[encryptedString[i]-'A'].first = encryptedString[i];
        freq[encryptedString[i]-'A'].second++;
    }
}


void decrypt(string encryptedString, string frequencyString , string standardString,vector<string> &decrypted){
    for(int i = 0;i<10;i++){
        int shift = 0;
        string decryptedString = "";
        for(int j = 0;j<encryptedString.size();j++){
            if(encryptedString[j] != ' '){
                for(int k = 0;k<frequencyString.size();k++){
                    if(encryptedString[j] == frequencyString[k]){
                        shift = k;
                        break;
                    }
                }
                decryptedString+=standardString[i+shift];
            }
        }
        decrypted.push_back(decryptedString);
    }
}



int main(){
    cout<< "Enter the plain text only in CAPITAL letter: ";
    string plainText = "";
    getline(cin,plainText);
    
    plainText = removeSpaces(plainText);

    string encryptedString = encrypt(plainText);

    string standardString = "ETAOINSHRDLCUMWFGYPBVKJXQZ";

    cout << "Encrypted String is: ";
    cout << encryptedString << endl;

    vector<pair<char,int>> freq(26);
    for(int i = 0;i<26;i++){
        freq[i].first = i+'a';
    }
    countFrequency(encryptedString, freq);
    sort(freq.begin(),freq.end(),comp);

    string frequencyString = "";
    for(int i = 0;i<26;i++){
        if(freq[i].second){
            frequencyString+=freq[i].first;
        }
    }
    vector<string> decrypted;
    decrypt(encryptedString, frequencyString,standardString, decrypted);
    for(auto i:decrypted){
        cout << i << endl;
    }
    cout << endl;
    return 0;
}