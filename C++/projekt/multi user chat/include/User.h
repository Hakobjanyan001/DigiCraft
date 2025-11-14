#ifndef USER_H
#define USER_H

#include <string>
class User{
private:
	int id;
	std::string username;

public:
	User();
	User(int user_id, const std::string& name);
	~User();
	std::string toString() const;
	bool isValid() const;
};
#endif //USER_H
