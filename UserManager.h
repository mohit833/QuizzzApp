#pragma once
#ifndef USERMANAGER_H
#define USERMANAGER_H
#include<string>
class UserManager {
public:
	void registerUser(const std::string& username, const std::string& password);
	bool authenticateUser(const std::string& username, const std::string& password);
};
#endif