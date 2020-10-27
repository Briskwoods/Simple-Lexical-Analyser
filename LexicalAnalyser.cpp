// LexicalAnalyser.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

using namespace std;

int isKeyword(char buffer[]) {
	char keywords[32][10] = {
	   "auto","break","case","char","const","continue","default",
	   "do","double","else","enum","extern","float","for","goto",
		"if","int","long","register","return","short","signed",
		"sizeof","static","struct","switch","typedef","union",
		"unsigned","void","volatile","while" };

	int i, flag = 0;

	for (i = 0; i < 32; ++i) 
	{
		if (strcmp(keywords[i], buffer) == 0) {
			flag = 1;
			break;
		}
	}
	return flag;
}

int main()
{
	char character, buffer[15], operators[] = "+-/*%=";
	ifstream fin("Text.txt");
	int i, j = 0;

	if (!fin.is_open()) {
		cout << "Error. Unable to open or find file.\n";
		exit(0);
	}

	while (!fin.eof())
	{
		character = fin.get();

		for (i = 0; i < 6; ++i) {
			if (character == operators[i]) {
				cout << character << " is operator. \n";
			}
		}

		if(isalnum(character)){
			buffer[j++] = character;
		}

		else if ((character == ' ' || character == '\n') && (j!=0)) {
			buffer[j] = '\0';
			j = 0;

			if (isKeyword(buffer) == 1) {
				cout << buffer << " is Keyword. \n";
			}
			else {
				cout << buffer << " is an Identifier. \n";
			}

		}
	}

	fin.close();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
