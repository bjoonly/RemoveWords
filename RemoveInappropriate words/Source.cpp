#include"Func.h"


int main() {
	cout << "Original:\n\n";
	ShowDataFromFile("Original.txt");
	RemoveInappropriateWords();
	cout << "\n\nModified text:\n\n";
	ShowDataFromFile("ModifiedText.txt");
	return 0;
}