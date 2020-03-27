#include "Func.h"

void RemoveInappropriateWords() {
	string data, word,space=" ";
	int pos ,pos_space;
	ifstream finOriginal, finWords;
	ofstream fout;

	fout.open("ModifiedText.txt");
	finOriginal.open("Original.txt");
	finWords.open("InappropriateWords.txt");

	bool isOpenOriginal = finOriginal.is_open();
	bool isOpenWords = finWords.is_open();
	bool isOpenModified = fout.is_open();

	if (isOpenOriginal == false || isOpenWords == false || isOpenModified == false) {
		cout << "The file couldn't be opened.\n";
		return;
	}
	while (getline(finOriginal, data)) {

		while (getline(finWords, word)) {
			pos = data.find(word);
			pos_space = data.find(space, pos);
			while (pos != string::npos) {
				data = data.erase(pos, pos_space-pos);
				pos = data.find(word);
				pos_space = data.find(space, pos);
			}	
		}
		fout << data << endl;
		finWords.clear();
		finWords.seekg(0, ios::beg);
	}
	
	finOriginal.close();
	finWords.close();
	fout.close();
}
void ShowDataFromFile(string FileName) {
	ifstream fin;
	string data;
	fin.open(FileName);
	bool isOpen = fin.is_open();
	if (isOpen==false) {
		cout << "The file couldn't be opened.\n";
		return;
	}
	while (getline(fin, data))
		cout << data << endl;
}