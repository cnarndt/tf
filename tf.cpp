#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <string>


using namespace std;

int ch, match, i, wordCount, matchh, occurence, flg;
float tf, tfs, idf, tfidf;
char word[50], line[50];
int nd = 3, iterm;

string bookToRead{ "768.txt" };

void calculateTF()
{
	FILE *file;
	file = fopen(bookToRead.c_str(), "r");	

	// reset
	wordCount = 0;
	match = 0;
	i = 0;
	char c;
	
	// lower case
	while (word[i])
	{
		c = word[i];
		word[i] = tolower(c);
		i++;
	}

	while (!feof(file))
	{
		fscanf(file, "%s", line);		
		
		i = 0;
		while (line[i])
		{
			c = line[i];
			line[i] = tolower(c);
			i++;
		}

		if (strstr(line, word) != 0)
			match++;
		wordCount++;
	}

	fclose(file);	

	cout << "\n----------------Total # of Word-------------------\n";
	cout << "\n Document: " << bookToRead << " = " << wordCount;
	
	cout << "\n\n------------------Term Counts--------------------\n";
	cout << word << " in ";	
	cout << "Doc " << bookToRead << " = " << match;
	
	cout << "\n------------------Term Frequency------------------\n";
	cout << "     " << word << " : ";
	
	tf = (float)match / wordCount;   //Term Frequency
	tfs = tf;
	cout << "      " << tf;
}



void calculateIDF()
{
	FILE *file;
	file = fopen(bookToRead.c_str(), "r");
	
	// reset
	wordCount = 0;
	match = 0;	
	
	while (!feof(file))
	{
		fscanf(file, "%s", line);
		//  if(strcmp(line,word)==0)
		
		if (strstr(line, word) != 0)
		{
			match++;
			matchh++;
			flg = 1;
		}
		
		wordCount++;
	}

	fclose(file);
	

	cout << "\n----------------Total # of Word-------------------\n";

	cout << "\n Document " << bookToRead << " are = " << wordCount;
	

	cout << "\n\n------------------Term Counts--------------------\n";
	cout << "\n Documant " << bookToRead << " = " << matchh;	

	if (matchh > 0)
	{
		matchh = 1;
		flg = flg + matchh;
		occurence = occurence + flg;
	}
	else
		matchh = 0;
	
	tf = (float)1 / occurence;
	idf = log10(tf);	

	cout << "\n\n-----------------Inverse Document Frequency-------------------\n";	
	cout << "\n IDF = " << idf;

	cout << "\n\n---------Term Frequency Inverse Document Frequency------------\n";
	cout << "\n TFIDF in " << bookToRead << ": " << idf*tfs;

	matchh = wordCount = flg = 0;

	cout << "\n";
}


int main(int argc, char **argv) 
{
	if (argc >= 2)
		bookToRead = argv[1];

	do
	{
		cout << "\n************** Menu ****************\n";
		cout << "\n (1) Term Frequency";
		cout << "\n (2) Inverse Document Frequency";
		cout << "\n (3) Exit";
		cout << "\n************************************\n";
		cout << "\n Select from Menu => "; cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "\n Enter The Word  => ";
			cin >> word;
			calculateTF();
			break;
		case 2: cout << "\n Enter The Word  => ";
			cin >> word;
			calculateIDF();
			break;
		case 3: exit(0);
		}
	}

	while (ch != 3);
	_getch();
}