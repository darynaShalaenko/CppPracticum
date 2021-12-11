#include <iostream>
#include <sstream>
#include <string>

using namespace std;


int num_of_repeat(const string& s, string word1) { //функція для підрахунку кількості повторів слова word1 в рядку s
    int count=0;
    stringstream ss;
    ss<<s;
    while (ss.good()) {   //цикл, який проходиться по кожному слову word речення s і додає до count одиницю, якщо це слово дорівнює заданому word1 
        string word;
        ss>>word;           
        if (ss.fail())
            break;
        if (word==word1) {
            count++;
        }
    }
    return count;
}

string find_and_delete_word(string& s, string word1) { //функція для видалення всіх слів рядка s, які дорівнюють слову word1
    int index=-1;
    stringstream ss;
    ss<<s;
    while (ss.good()) {  //цикл, який проходиться по кожному слову word речення s і видаляє його, якщо це слово дорівнює заданому word1  
        string word;
        ss>>word;           
        if (ss.fail())
            break;
        if (word==word1) {
            index=s.find(word);
            if(index>-1) {
                s.erase(index,word.size()+1);
                index=-1;
            }
        }
    }
    return s;
}


//Функція, яка змінює задане речення
void delete_words(string& s, int num) { //функція для видалення всіх слів рядка s, к-ть повторів яких дорівнює заданому num
    int index=-1;
    stringstream ss;
    ss<<s;
    while (ss.good()) {   //цикл, який проходиться по кожному слову word речення s і видаляє всі слова, які дорівнюють слову word, якщо к-ть повторів цього слова дорівнює заданому num  
        string word;
        ss>>word;           
        if (ss.fail())
            break;
        if (num_of_repeat(s, word)==num) {
            s=find_and_delete_word(s,word);
        }
    }
}

string find_and_delete_word02(const string& s, string word1) { //функція для видалення всіх слів рядка s, які дорівнюють слову word1
    string s2=s;
    int index=-1;
    stringstream ss;
    ss<<s2;
    while (ss.good()) {  //цикл, який проходиться по кожному слову word речення s і видаляє його, якщо це слово дорівнює заданому word1  
        string word;
        ss>>word;           
        if (ss.fail())
            break;
        if (word==word1) {
            index=s2.find(word);
            if(index>-1) {
                s2.erase(index,word.size()+1);
                index=-1;
            }
        }
    }
    return s2;
}

//Функція, яка не змінює задане речення
string delete_words02(const string& s, int num) { //функція для видалення всіх слів рядка s, к-ть повторів яких дорівнює заданому num
    string s2=s;
    int index=-1;
    stringstream ss;
    ss<<s2;
    while (ss.good()) {   //цикл, який проходиться по кожному слову word речення s і видаляє всі слова, які дорівнюють слову word, якщо к-ть повторів цього слова дорівнює заданому num  
        string word;
        ss>>word;           
        if (ss.fail())
            break;
        if (num_of_repeat(s2, word)==num) {
            s2=find_and_delete_word02(s2,word);
        }
    }
    return s2;
}





int main() {
    string sentence="I live in a city with many people who love their city with its many streets";
    
    //Функція, яка не змінює задане речення
    string s1=delete_words02(sentence,2); //видаляє з речення sentence всі слова, що повторюються 2 рази
    cout<<s1<<endl;
    
    //Функція, яка змінює задане речення
    delete_words(sentence,2); //видаляє з речення sentence всі слова, що повторюються 2 рази
    cout<<sentence<<endl;
    
    return 0;
}
