#include <iostream>
#include <cstdlib>
#include <list>
#include <string>

using namespace std;

bool num_not_guessed = false;

int calculator()
{
	int a;
	char sum;
	int b;
	int answer;


	while (true)
	{
		cout << "Enter your first number: ";
		cin >> a;
		cout << std::endl;

		cout << "Enter operator: ";
		cin >> sum;
		cout << std::endl;

		cout << "Enter second number: ";
		cin >> b;
		cout << std::endl;

		if (sum == '*') {
			answer = a * b;
			break;
		}
		else if (sum == '+') {
			answer = a + b;
			break;
		}
		else if (sum == '-') {
			answer = a - b;
			break;
		}
		else if (sum == '/') {
			answer = a / b;
			break;
		}
		else
		{
			cout << "Enter a valid operator: + - * /";
			cout << endl;
		}
	}

	cout << "The answer is: " << answer << std::endl;
	system("pause");
	return 0;
}

int numguess(int num)
{
	int guess_num;

	cout << "Guess the number: ";
	cin >> guess_num;
	cout << endl;

	if (guess_num == num)
	{
		cout << "Well done!!";
		num_not_guessed = true;
		cout << endl;
		system("pause");
	}
	else if (guess_num <= num)
	{
		cout << "Too low!";
		cout << endl;
	}
	else if (guess_num >= num)
	{
		cout << "Too High!";
		cout << endl;
	}

	cout << num;

	return 0;
}

int todolist() 
{

	string input;
	char addMore;
	list<string> to_do_list = {};

	do {
		cin.clear();
		cout << "Enter your task: ";
		getline(cin, input);
		cout << endl;

		to_do_list.push_back(input);

		cout << "Do you want to add more? (y/n)";
		cin >> addMore;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		system("cls");

	} while (addMore == 'y' || addMore == 'Y');


	cout << "Your To-Do List:" << endl;
	for (const auto& task : to_do_list)
	{
		cout << "- " << task << endl;
	}
	system("pause");
	return 0;
}

double convertToFahrenheit(double celsius) {
	return (celsius * 9.0 / 5.0) + 32.0;  // The formula for conversion
}
double convertToCelsius(double fahrenheit) {
	return (fahrenheit - 32) * 5.0 / 9.0;  // The formula for conversion
}

int tempconverter()
{
	double uni;
	char uni_type;
	double uni_answer;

	cout << "Which unit do you want to covert? [C = Celcuis] [F = Fahrenheit]: ";
	cin >> uni_type;
	cout << endl;
	
	cout << "Enter your unit: ";
	cin >> uni;
	cout << endl;

	if (uni_type == 'C' || uni_type == 'c')
	{
		uni_answer = convertToFahrenheit(uni);
	}
	if (uni_type == 'F' || uni_type == 'f')
	{
		uni_answer = convertToCelsius(uni);
	}

	cout << "Your answer is: " << uni_answer;
	cout << endl;

	return 0;
}

int decide(int choice)
{
	srand(time(0));
	int num = rand() % 101;
	if (choice == '1')
	{
		system("cls");
		calculator();
	}
	else if (choice == '2')
	{
		system("cls");
		while (num_not_guessed == false)
		{
			numguess(num);
		}
	}
	else if (choice == '3')
	{
		todolist();
	}
	else if (choice == '4')
	{
		while (true)
		{
			tempconverter();
		}
	}

	return 0;

}

int main()
{
	char choice;

	cout << "[1] Calculator [2] Number guessing game [3] To-do list [4] Tempature Converter" << endl;
	cin >> choice;
	decide(choice);

	return 0;
}