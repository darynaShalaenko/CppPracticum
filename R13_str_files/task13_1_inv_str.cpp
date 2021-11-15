

#include <iostream>
#include <fstream>

using namespace std;

string punctuation = " .,?!"; //  Всі символи пунктуації

bool in(char s) {
    for (char sym : punctuation) { // Перебор симвлів зі всіх символів пунктуації
        if (s == sym) {return true;} // Перевірка чи збігається символ з одним із символів пунктуації
    }
    return false; // Якщо символ не співпалв з одним символом пунктуації,йде повернення що не є символом пунктуації 
}

string inversion(const string & s){
   string res ="";
   size_t n = s.size()-1;	
   for(int i=1;i<=n;++i){
	res.push_back(s[n-i]); 
   }
   return res;		
}

int main() {
    string line;
    ifstream infile ("example.txt"); // Відкриваємо файл для зчитування
    ofstream outfile ("example_out.txt"); // Відкриваємо файл для зчитування

    string ans = ""; // Створюємо змінну для запису пунктуації
    string word ="";	
    string text;	
    char sym;	
    if (infile.is_open()) { // Перевірка чи відкрився файл

            while(getline(infile,text,'\n')) { //  Прохід по кожному рядку
                for(int i=0;i<text.size();++i){ // по коному символу рядка
		sym = text[i];
                if (in(sym)) { //  Перевірка чи є символ знаком пунктуації
                    //ans += sym; // У разі якщо є ,запис до відповіді
		   if(word!=""){
                      ans =  inversion(word);
		      outfile<<ans;	
		   }	
		   word = ""; 	
		   outfile<<sym;	 	
                }
		else{
			cout<<sym;
			word.push_back(sym);
		}
		cout<<sym;
            }

        }
        infile.close(); // Закриття файлу зчитування
    }

    //ofstream outfile ("ans.txt"); // Відкриття файлу для записування відповіді
    //outfile << ans << endl; // запис відповіді
    outfile.close(); // Закриття файлу записи

    return 0; // Відповідь, що програма працює нормально
}


