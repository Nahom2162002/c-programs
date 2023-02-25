#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void login(string username, string password) {
	ifstream myfile;
	string line;
	myfile.open("logininfo.txt", ios::binary);

	size_t user;
	size_t pass;

	while (myfile.good()) {
		getline(myfile, line);
		user = line.find(username);
		pass = line.find(password);

		if (user != string::npos && password == "") {
			break;
		}
	}

	if ((user != string::npos && password == "") || (user == string::npos && password != "")) {
		cout << "Incorrect username or password";
	}

	else {
		cout << "Logged in successfully!";
	}
}

void create_account(string username, string password) {
	fstream file;
	string securityquestion;
	string securityanswer;
	string questions[5];
	int x;
	int questionsLength = 0;

	file.open("logininfo.txt", ios::out | ios::in);
	file << username << password << endl;
    file.open("questions.txt");

	while (file.is_open()) {
		getline(file, securityquestion);
		questions[questionsLength] = securityquestion;
		questionsLength++;
	}

	x = rand() % 5;

	securityquestion = questions[x];

	cout << "Your security question is:" << securityquestion;
	cout << "Answer:";
	cin >> securityanswer;

	file << securityquestion << securityanswer << endl;
}

string forgotusername(string securityquestion, string securityanswer) {
	string answer;
	string foundusername;
	cout << securityquestion;
	cin >> answer;
	int x = securityanswer.compare(answer);

	if (x != 0) {
		cout << "Incorrect answer";
	}

	else {
		cout << "Correct, your username is:" << foundusername;
	}

	return foundusername;
}

string forgotpassword() {
	string newpassword;
	string confirmpassword;

	cout << "Input new password:";
	cin >> newpassword;
	cout << "Confirm new password:";
	cin >> confirmpassword;

	if (newpassword != confirmpassword) {
		cout << "Passwords don't match";
		forgotpassword();
	}

	else {
		cout << "New password made!";
	}

	return newpassword;
}

int main() {
	string username;
	string password;
	string choice;
	string confirmpassword;

	cout << "Logging back in or creating an account? ('Login' for logging in, 'Creating' for creating an account')";
	cin >> choice;

    if (choice.compare("Login")) {
		cout << "Username:";
		cin >> username;
		cout << "Password:";
		cin >> password;

		login(username, password);
	}

	else if (choice.compare("Creating")) {
		cout << "Username";
		cin >> username;
		cout << "Password:";
		cin >> password;
		cout << "Confirm password:";
		cin >> confirmpassword;

		if (password != confirmpassword) {
			cout << "Passwords do not match";
		}

		else {
			create_account(username, password);
		}
	}

	return 0;
}