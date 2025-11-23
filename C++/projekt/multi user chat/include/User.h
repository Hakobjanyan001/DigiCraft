#ifndef USER_H
#define USER_H

#include <string>
class User{
private:
	int id = -1;
	std::string username;

public:
	User();
	User(int user_id, const std::string& name);
	~User();

	void setID(int newid);
	int getId() const;
	
	void setUsername(const std::string& newusername);
	const std::string& getUsername() const;
	
	std::string toString() const;
	bool isValid() const;
};
#endif //USER_H
