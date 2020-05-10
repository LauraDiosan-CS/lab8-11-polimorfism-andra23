#include "User.h"
User::User() {
	this->username = NULL;
	this->password = NULL;
}
User::User(const char* username, const char* password) {

	this->username = new char[strlen(username) + 1];
	strcpy_s(this->username, strlen(username) + 1, username);
	this->password = new char[strlen(password) + 1];
	strcpy_s(this->password, strlen(password) + 1, password);

}
User::~User() {

}
ostream& operator<<(ostream& os, const User& u) {

	os << "Username: " << u.username << "\n";
	os << "Password: " << u.password;
	return os;
}
char* User::getUsername() {

	return this->username;
}
char* User::getPassword() {

	return this->password;
}


