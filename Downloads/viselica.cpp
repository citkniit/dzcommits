#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;
int main() {
setlocale(LC_ALL, "rus");
vector<char> alphabet;//вектор содержащий алфавит
for (char i = 'A'; i <= 'Z'; i++) {//заполнение алфавита
alphabet.push_back(i);
	}
const int max_wrong = 5;//сколько ошибок можно сделать
vector<string> words{ "FOOTBALL", "PROGRAM", "COMPUTER", "MAIN", "SPORT","VISELICA"};//слова которые могут попасться
srand(static_cast<unsigned int>(time(0)));
random_shuffle(words.begin(), words.end());//рандомно выбираем одно из слов
const string word = words[0];// присваиваем это слово в word
const int word_length = word.length();//длина слова
int wrong = 0;//счётчик ощибок
string sofar(word_length, '_');//как выглядит слово на данном этапе угадывания
string used = "";//строка использованных букв
int n;
string s;//строка для ввода слова полностью
cout << "Максимальное количество ошибок = " << max_wrong;
cout << "Доступные буквы ";
	for (vector<char>::iterator iter = alphabet.begin(); iter != alphabet.end(); iter++)
 cout << *iter;
 cout << endl;
 cout << "Загаданное слово: " << sofar;
 cout << endl;
	while ((wrong != max_wrong) && (sofar != word)) {//пока количество ошибок не равно максимальному и слов не отгадано
		cout << "Введите 1 если хотите написать слово целиком и 0 если хотите угадывать букву ";
		cin >> n;
		if (n == 1) {//условие ввода слова
			cout << "Введите слово: ";
			cin >> s;
			for (int i = 0; i < s.length(); i++)
				s[i] = toupper(s[i]);//перевод всех букв в верхний регистр так как слова загаданы в верхнем регистре
			if (s == word) {
				cout << "Вы выиграли!";//выигрыш если слово отгадано
			}
			else cout << "Вы проиграли";//проигрыш если вы ввели всё слово и не отгадали(в интеренете так прописаны правила)
			break;
		}
	cout << "ВВедите букву ";
	char bukva;
		cin >> bukva;//ввод буквы
		bukva = toupper(bukva);//перевод буквы в верхний регистр
		while (used.find(bukva) != string::npos) {//пока буква есть в списке использованных
			cout << "Вы уже вводили эту букву, введите другую";
			cin >> bukva;
			bukva = toupper(bukva);
		}
		used += bukva;//добавление буквы в список использованных
   if(word.find(bukva) != string::npos){//если буква есть в слове
  cout << "буква\t" << bukva << '\t' << "встречается в слове" << '\n';
			for (int i = 0; i < word_length; i++) {
				if (word[i] == bukva) {//вставляем букву в нужное место
					sofar[i] = bukva;//вставляем букву вместо _
				}
			}
	    }
		else {
			cout << "буквы\t" << bukva << '\t' << "в слове нет" << '\n';//если буквы нет
		wrong++;//счётчик ошибок увеличивается
		if (wrong == max_wrong) {//если лимит ошибок исчерпан вы проиграли
			cout << "Вы проиграли";
			break;
		}
         }
		if ((sofar == word) && (wrong < max_wrong)) {//если слово отгадано и лимит ошибок не исчерпан вы выиграли
		    cout << sofar << '\t' << "Вы выиграли!";
			break;
		}
        cout << endl;
		cout << "количество ошибок = " << wrong;
		cout << "Доступные буквы ";
		bool t;
		for (vector<char>::iterator iter = alphabet.begin(); iter != alphabet.end(); iter++) {//вывод доступных букв
			t = true;
			for (int i = 0; i < used.length(); i++) {
				if (*iter == used[i]) {
					t = false;
					break;
				}
			}
			if (t == true) cout << *iter;
			else continue;
		}
		cout << endl;
        cout << "Загаданное слово: " << sofar;
	}
	return 0;
}