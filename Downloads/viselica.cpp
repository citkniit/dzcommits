#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;
int main() {
setlocale(LC_ALL, "rus");
vector<char> alphabet;//������ ���������� �������
for (char i = 'A'; i <= 'Z'; i++) {//���������� ��������
alphabet.push_back(i);
	}
const int max_wrong = 5;//������� ������ ����� �������
vector<string> words{ "FOOTBALL", "PROGRAM", "COMPUTER", "MAIN", "SPORT","VISELICA"};//����� ������� ����� ���������
srand(static_cast<unsigned int>(time(0)));
random_shuffle(words.begin(), words.end());//�������� �������� ���� �� ����
const string word = words[0];// ����������� ��� ����� � word
const int word_length = word.length();//����� �����
int wrong = 0;//������� ������
string sofar(word_length, '_');//��� �������� ����� �� ������ ����� ����������
string used = "";//������ �������������� ����
int n;
string s;//������ ��� ����� ����� ���������
cout << "������������ ���������� ������ = " << max_wrong;
cout << "��������� ����� ";
	for (vector<char>::iterator iter = alphabet.begin(); iter != alphabet.end(); iter++)
 cout << *iter;
 cout << endl;
 cout << "���������� �����: " << sofar;
 cout << endl;
	while ((wrong != max_wrong) && (sofar != word)) {//���� ���������� ������ �� ����� ������������� � ���� �� ��������
		cout << "������� 1 ���� ������ �������� ����� ������� � 0 ���� ������ ��������� ����� ";
		cin >> n;
		if (n == 1) {//������� ����� �����
			cout << "������� �����: ";
			cin >> s;
			for (int i = 0; i < s.length(); i++)
				s[i] = toupper(s[i]);//������� ���� ���� � ������� ������� ��� ��� ����� �������� � ������� ��������
			if (s == word) {
				cout << "�� ��������!";//������� ���� ����� ��������
			}
			else cout << "�� ���������";//�������� ���� �� ����� �� ����� � �� ��������(� ���������� ��� ��������� �������)
			break;
		}
	cout << "������� ����� ";
	char bukva;
		cin >> bukva;//���� �����
		bukva = toupper(bukva);//������� ����� � ������� �������
		while (used.find(bukva) != string::npos) {//���� ����� ���� � ������ ��������������
			cout << "�� ��� ������� ��� �����, ������� ������";
			cin >> bukva;
			bukva = toupper(bukva);
		}
		used += bukva;//���������� ����� � ������ ��������������
   if(word.find(bukva) != string::npos){//���� ����� ���� � �����
  cout << "�����\t" << bukva << '\t' << "����������� � �����" << '\n';
			for (int i = 0; i < word_length; i++) {
				if (word[i] == bukva) {//��������� ����� � ������ �����
					sofar[i] = bukva;//��������� ����� ������ _
				}
			}
	    }
		else {
			cout << "�����\t" << bukva << '\t' << "� ����� ���" << '\n';//���� ����� ���
		wrong++;//������� ������ �������������
		if (wrong == max_wrong) {//���� ����� ������ �������� �� ���������
			cout << "�� ���������";
			break;
		}
         }
		if ((sofar == word) && (wrong < max_wrong)) {//���� ����� �������� � ����� ������ �� �������� �� ��������
		    cout << sofar << '\t' << "�� ��������!";
			break;
		}
        cout << endl;
		cout << "���������� ������ = " << wrong;
		cout << "��������� ����� ";
		bool t;
		for (vector<char>::iterator iter = alphabet.begin(); iter != alphabet.end(); iter++) {//����� ��������� ����
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
        cout << "���������� �����: " << sofar;
	}
	return 0;
}