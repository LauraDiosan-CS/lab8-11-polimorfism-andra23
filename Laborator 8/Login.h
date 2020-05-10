#pragma once
#include<string>
#include "User.h"
#include<vector>
using namespace std;
class LoginManager {
public:
	string username;
	string password;
	vector<User> users;
	LoginManager();
	~LoginManager() {};
	bool login(string, string);
};
