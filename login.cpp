#include <iostream>
#include <fstream>
#include <string>

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

		if (user != string::npos && password != string::npos) {
			break;
		}
	}

	if ((user != string::npos && password == string::npos) || (user == string::npos && password != string::npos)) {
		cout << "Incorrect username or password";
	}

	else {
		cout << "Logged in successfully!";
	}
}

void create_account(string username, string password) {
	fstream file;
	file.open("logininfo.txt", ios::out | ios::in);
	file << username << password << endl;
}

void forgotusername(string securityquestion) {

}

void forgotpassword(string email) {

}

int main() {
	string username;
	string password;
	cout << "Username:";
	cin >> username;
	cout << "Password:";
	cin >> password;
	return 0;
}
