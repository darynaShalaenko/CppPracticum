#include <iostream>
#include <string>
#include <sstream>
#define N 100
using namespace std;


void find_longest_word(string words[N], string longest_words[N], int& words_number, int& longest_words_number){

    string longest_word = words[0];

    for (int i=1;i<words_number;i++){
        if (words[i].length()>longest_word.length()){
            longest_word = words[i];
        }
    }
    //cout<<longest_word;
    for (int i=0;i<words_number;i++)
        if (words[i].length()==longest_word.length()){
            longest_words[longest_words_number] = words[i];
            longest_words_number+=1;
        }

}

int main(){

    string s;
    getline(cin,s);

    stringstream ss;

    ss << s;

    int words_number=0;
    int longest_words_number = 0;

    string* words = new string[N];
    string* longest_words = new string[N];

    while (ss.good()) {
        ss >> words[words_number];
        words_number+=1;
        if (ss.fail())
            break;
    }

    find_longest_word(words,longest_words,words_number,longest_words_number);

    for (int i=0;i<longest_words_number;i++){
        cout<<longest_words[i]<<endl;
    }


    delete[] words;
    delete[] longest_words;

    return 0;
}
