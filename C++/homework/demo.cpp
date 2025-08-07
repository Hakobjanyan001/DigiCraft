#include <iostream>
#include <string>

 class Book{
private:
	int m_id;
	std::string m_title;
	std::string m_author;
	std::string m_genre;
	int m_totalCopies;
	int m_availableCopies;
	
	int m_size;
	int m_capacity;
	Book* m_arr;
	
	void resize(int newcap) {
			Book* newarr = new Book[newcap];
			for(int i = 0; i < m_size; i++) {
					newarr[i] = m_arr[i];
			}
			delete [] m_arr;
			m_arr = newarr;
			m_capacity = newcap;

	}

public:
	Book(int id, std::string title, std::string autor, std::string genre) : m_id(id), m_title(title), m_author(autor), m_genre(genre), m_totalCopies(3)/*, m_availableCopies("???????")*/ {}
	Book() : m_id(0), m_title(""), m_author(""), m_genre(""), m_totalCopies(0), m_availableCopies(0) {}
	~Book() {delete [] m_arr;}
	
	void addBook() {
			int id;
			std::string title, author, genre;
			if(m_size == m_capacity) {
					resize(m_capacity == 0 ? 1 : m_capacity * 2);
			}
			std::cout << "write new book data" << std::endl;
			std::cout << "id" << std::endl;
			std::cin >> id;	
			std::cout << "Title" << std::endl;	
			std::cin >> title;
			std::cout << "Auther" << std::endl;
			std::cin >> author;
			std::cout << "Genre" << std::endl;
			std::cin >> genre;
			Book book(id, title, author, genre);
			m_arr[m_size++] = book;
			std::cout << "New book added" << std::endl;		
	}

	
	void showBook() {
			std::cout << "ID: " << m_id << "\n"
					"Title: " << m_title << "\n"
					"Author: " << m_author << "\n"
					"Genre: " << m_genre << "\n"
					"AvailableCopies:" << m_availableCopies << "\n"
					"TotalCopies:" << m_totalCopies << std::endl;
	}
	
	void borrowBook() {}
	
	void returnBook() {}
	
	int getID() {return m_id;}
	
	std::string getTitle() {return m_title;}

 };




class Person{
protected:
public:
	Person() {}	
	~Person() {}	
};



class User : public Person{
private:
	std::string username;
	std::string password;
	int borrowedBookIDs[3]; 
	int borrowDates[3];    

public:
    void registerUser() {}
   
   //	bool login(std::string uname, std::string pass) {}
   
   	void borrowBook(Book books[], int totalBooks) {}
   
   	void returnBook(Book books[], int totalBooks) {}
   
   	void viewBorrowedBooks(Book books[], int totalBooks) {}
};





class Admin : public Person{
private:
	std::string adminname;
	std::string password;
public:
    void addBook(Book books[], int &totalBooks) {
	}

	void removeBook(Book books[], int &totalBooks) {}
    
	void viewAllBooks(Book books[], int totalBooks) {}

    void viewUsers(User users[], int totalUsers) {}
};


void loginMenu();
void adminMenu();
void userMenu();

int main() {
	loginMenu();
	return 0;
}


void loginMenu() {
	std::cout << "___Welcome to Library___\n"
	 "For Admin enter Admin\n"
	 "For Users enter User" << std::endl;
	std::string answer = "";
	std::cin >> answer;
	std::string login = "";
	std::string passwd = "";
	if(answer == "Admin" || answer == "admin"){
		for(int i = 0; i < 3; i++){
		std::cout << "Write Admin login " << std::endl;
		std::cin >> login;
		std::cout << "Write Admin passwd" << std::endl; 
		std::cin >> passwd;
			if(login == "admin" && passwd == "admin123") {
					std::cout << "Welcome to Library admin" << std::endl;
					//AdminMenu();
					break;		
				}else {
					std::cout << "Unknown login or passwd" << std::endl;
					}
		}
	}else if(answer == "User" || answer == "user") {
	std::cout << "Write User login" << std::endl;
	std::cin >> login;
	std::cout << "Write User passwd" << std::endl;
	std::cin >> passwd;
	std::cout << "Welcome to Libery User" << std::endl;
	//UserMenu();
		}else {
				std::cout << "Unknown answer" << std::endl;
			}
}
