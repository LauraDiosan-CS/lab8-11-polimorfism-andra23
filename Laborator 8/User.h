#pragma once
#include <string>
#include<ostream>
using namespace std;
class User {
private:

	char* username;
	char* password;

public:
	User();
	User(const char*, const char* p);
	~User();
	friend ostream& operator<<(ostream& os, const User& u);
	char* getUsername();
	char* getPassword();
};
