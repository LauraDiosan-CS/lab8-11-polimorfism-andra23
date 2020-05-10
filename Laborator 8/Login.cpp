#include "Login.h"
#include<iostream>
LoginManager::LoginManager() {

	username = "\0";
	password = "\0";
	User u1("Ana", "adrH");
	User u2("SorinaV", "sorV");
	users.push_back(u1);
	users.push_back(u2);
}
bool LoginManager::login(string username, string password) {


	for (User x : users) {

		string ch_username = x.getUsername();
		string ch_password = x.getPassword();

		if (username.compare(ch_username) == 0 && password.compare(ch_password) == 0) {

			cout << "      BINE AI VENIT," << " " << username << "!\n";
			return true;

		}
		else {
			cout << "Invalid login attempt. Please try again.\n" << "\n";
			return false;
		}
	}

	return true;

}

