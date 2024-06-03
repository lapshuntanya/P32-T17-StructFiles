#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

struct Client
{
	char name[100] = "";		//ПІБ кліента
	char number[17] = "";		//Номер картки
	double cash = 0;			//Кошти
	 
	void fillClient() {
		cout << "Input name: "; 
		cin.getline(name, 100);
		sprintf_s(number, 17, "%d%d%d%d",
			rand()%10'000 + 1000, rand() % 10'000 + 1000,
			rand() % 10'000 + 1000, rand() % 10'000 + 1000);
		cash = 50;
	}

	void showClient() {
		cout << "Client: " << name << endl;
		cout << "Card:   " << number << endl;
		cout << "Cash:   " << cash << "UAH\n\n";
	}

	void saveToTextFile(FILE* fp)
	{
		fprintf(fp, "\n%s\n%s\n%0.2lf", name, number, cash);
	}

	void loadFromTextFile(FILE* fp)
	{
		//
		//"Gryshenko Daniil"
		//"1234123412341234"
		// 2500
		fscanf_s(fp, "\n");
		fgets(name, 100, fp); //!
		name[strlen(name)-1] = '\0';

		fscanf_s(fp, "\n%s", number, 17);
		fscanf_s(fp, "\n%lf", &cash);
	}

	void saveToBinFile(FILE* fp)
	{
		int size = strlen(name) + 1;
		fwrite(&size, sizeof(int), 1, fp);
		fwrite(name, sizeof(char), size, fp);

		size = strlen(number) + 1;
		fwrite(&size, sizeof(int), 1, fp);
		fwrite(number, sizeof(char), size, fp);

		fwrite(&cash, sizeof(double), size, fp);
	}

	void loadFromBinFile(FILE* fp)
	{
		int size = 0;
		fread(&size, sizeof(int), 1, fp);
		fread(name, sizeof(char), size, fp);
		
		fread(&size, sizeof(int), 1, fp);
		fread(number, sizeof(char), size, fp);

		fread(&cash, sizeof(double), size, fp);
	}
};