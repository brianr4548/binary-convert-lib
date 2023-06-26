// Name: Brian Rhodes.
// Date Submission: 6/25/2023.
// Description: This program takes in user input of a binary number 4-12 bits long and utilizes the NumConvert class to
// convert the binary number to decimal, hexidecimal, octal, signed magnitude, ones-complement, and twos-complement.



#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class NumConvert {
private:
	string binaryNum;
	int decimal;
	int octal;
	string hexadecimal;
	string SM;
	string ones;
	string twos;


public:
	NumConvert();
	void toDecimal();
	void toOctal();
	void toHexadecimal();
	void toSM();
	void negativeOnes();
	void negativeTwos();
	void userInput();


	string getBinary();
	int getDecimal();
	int getOctal();
	string getHexadecimal();
	string getSM();
	string getOnes();
	string getTwos();


};

NumConvert::NumConvert() {
	this->binaryNum = "000001000";
	this->decimal = 0;
	this->octal = 0;
	this->hexadecimal = "none";
	this->SM = "none";
	this->ones = "none";
	this->twos = "none";
}

void NumConvert::userInput() {
	string *input = new string;
	bool *switcher = new bool;

	
	*switcher = true;
	while (1 == 1) {
		cout << "please enter a binary number that is 4 digits or greater and 14 digits or less: ";
		getline(cin,*input);

		if (input->size() < 4 || input->size() > 14) {
			system("cls");
			cout << "ERROR: Enter a binary number between 4 and 12 bits!" <<  endl;
			continue;
		}

		for (auto num : *input) {
			if (num != '1' && num != '0') {
				system("cls");
				cout << "ERROR: Enter only binary digit (0 or 1)!" << endl;
				*switcher = false;
				break;
			}
			else {
				*switcher = true;
			}
		}

		if (*switcher == false) {
			continue;
		}

		break;

	}
	system("cls");
	input->insert(0, "0");
	this->binaryNum = *input;

	delete input;
	delete switcher;
}

void NumConvert::toDecimal() {
	int* total = new int;
	int* power = new int;
	vector<int> binaryVect;



	for (char digit : this->binaryNum) {
		if (digit == '0') {
			binaryVect.push_back(0);
		}
		else {
			binaryVect.push_back(1);
		}
	}

	*total = 0;
	for (int i = 0, j = binaryVect.size() - 1; i < binaryVect.size(); i++, j--) {
		*power = pow(2, j);
		*total += binaryVect[i] * *power;
	}

	this->decimal = *total;
	delete total;
	delete power;
}

void NumConvert::toOctal() {
	int* copiedDecimal = new int;
	string *concatedOctal = new string;
	vector<string> octalVect;

	*copiedDecimal = this->decimal;
	while (1 == 1) {
		if (*copiedDecimal > 8) {
			octalVect.push_back(to_string(*copiedDecimal % 8));
			*copiedDecimal /= 8;
			continue;
		}

		octalVect.push_back(to_string(*copiedDecimal));
		break;


	}

	for (int i = octalVect.size() - 1; i >= 0; i--) {
		*concatedOctal += octalVect[i];
	}

	this->octal = stoi(*concatedOctal);
	delete copiedDecimal;
	delete concatedOctal;
}

void NumConvert::toHexadecimal() {
	int* copiedDecimal = new int;
	string* concatedHex = new string;
	vector<string> hexVect;

	*copiedDecimal = this->decimal;
	while (1 == 1) {
		if (*copiedDecimal > 16) {
			if ((*copiedDecimal % 16) >= 10) {
				switch (*copiedDecimal % 16) {
				case 10:
					hexVect.push_back("A");
					*copiedDecimal /= 16;
					break;
				case 11:
					hexVect.push_back("B");
					*copiedDecimal /= 16;
					break;
				case 12:
					hexVect.push_back("C");
					*copiedDecimal /= 16;
					break;
				case 13:
					hexVect.push_back("D");
					*copiedDecimal /= 16;
					break;
				case 14:
					hexVect.push_back("E");
					*copiedDecimal /= 16;
					break;
				case 15:
					hexVect.push_back("F");
					*copiedDecimal /= 16;
					break;
				}
				continue;
			}
			else {
				hexVect.push_back(to_string(*copiedDecimal % 16));
				*copiedDecimal /= 16;
				continue;
			}
		}

		if (*copiedDecimal >= 10) {
			switch (*copiedDecimal) {
			case 10:
				hexVect.push_back("A");
				break;
			case 11:
				hexVect.push_back("B");
				break;
			case 12:
				hexVect.push_back("C");
				break;
			case 13:
				hexVect.push_back("D");
				break;
			case 14:
				hexVect.push_back("E");
				break;
			case 15:
				hexVect.push_back("F");
				break;
			}
			break;
		}
		else {
			hexVect.push_back(to_string(*copiedDecimal));
			break;
		}

		



	}

	for (int i = hexVect.size() - 1; i >= 0; i--) {
		*concatedHex += hexVect[i];
	}

	this->hexadecimal = *concatedHex;
	delete copiedDecimal;
	delete concatedHex;

}

void NumConvert::toSM() {
	string* copiedBinary = new string;
	*copiedBinary = this->binaryNum;
	if (copiedBinary->at(0) == '0') {
		copiedBinary->at(0) = '1';
	}
	else {
		copiedBinary->at(0) = '0';
	}
	this->SM = *copiedBinary;

	delete copiedBinary;
}

void NumConvert::negativeOnes() {
	string* copiedBinary = new string;
	*copiedBinary = this->binaryNum;

	for (int i = 0; i < copiedBinary->size(); i++) {
		if (copiedBinary->at(i) == '1') {
			copiedBinary->at(i) = '0';
		}
		else {
			copiedBinary->at(i) = '1';
		}
	}

	this->ones = *copiedBinary;
	delete copiedBinary;
}

void NumConvert::negativeTwos() {
	string* copiedBinary = new string;
	int* count = new int;
	*copiedBinary = this->binaryNum;

	for (int i = 0; i < copiedBinary->size(); i++) {
		if (copiedBinary->at(i) == '1') {
			copiedBinary->at(i) = '0';
		}
		else {
			copiedBinary->at(i) = '1';
		}
	}

	*count = copiedBinary->size() - 1;
	while (1 == 1) {
		if (copiedBinary->at(*count) == '0') {
			copiedBinary->at(*count) = '1';
			break;
		}
		else {
			copiedBinary->at(*count) = '0';
			*count-= 1;
			continue;
		}


	}
	
	this->twos = *copiedBinary;
	delete copiedBinary;
}

int NumConvert::getDecimal() {
	return this->decimal;
}

string NumConvert::getBinary() {
	return this->binaryNum;
}

string NumConvert::getHexadecimal() {
	return this->hexadecimal;
}

int NumConvert::getOctal() {
	return this->octal;
}

string NumConvert::getSM() {
	return this->SM;
}

string NumConvert::getOnes() {
	return this->ones;
}

string NumConvert::getTwos() {
	return this->twos;
}

int main() {
	NumConvert *test = new NumConvert;
	test->userInput();
	test->toDecimal();
	test->toOctal();
	test->toHexadecimal();
	test->toSM();
	test->negativeOnes();
	test->negativeTwos();

	cout << "The bits entered: " << test->getBinary() << endl;
	cout << "The Decimal equivalent: " << test->getDecimal() << endl;
	cout << "The Octal equivalent: " << test->getOctal() << endl;
	cout << "The Hexadecimal equivalent: " << test->getHexadecimal() << endl;
	cout << "The negative no " << "(-" << test->getDecimal() << ") " << "using Signed Magnitude " << test->getSM() << endl;
	cout << "The negative no " << "(-" << test->getDecimal() << ") " << "using 1's Complement " << test->getOnes() << endl;
	cout << "The negative no " << "(-" << test->getDecimal() << ") " << "using 2's Complement " << test->getTwos() << endl;

	delete test;
}