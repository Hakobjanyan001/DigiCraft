#include <iostream>
#include <include/User.h>

User::User() : id(-1), username("") {}
User::User(int user_id, const std::string& name) : id(user_id), username(name) {}
std::string User::toString() const{
	if(id == -1) {
		return username.empty() ? "name" : username + "no connected";
	} else {
		return "[" + std::to_string(id) +"]" + username;
	}
}

bool User::isValid() const{
	return id >= 1 && !username.empty();
}
