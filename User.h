#pragma once
#ifndef USER_H
#define USER_H
#include<string>
class User {
public:
	std::string username;
	std::string password;

	User(std::string uname, std::string pwd);

};
#endif
