#include <iostream>
#include <string>
#include <vector>

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

	std::vector<Book>books;

public:
	Book(int id, std::string title, std::string author, std::string genre, int copies = 3) : 
		 m_id(id), 
		 m_title(title), 
   		 m_author(author), 
         m_genre(genre), 
		 m_totalCopies(copies),
		 m_availableCopies(copies) {}
	Book() : m_id(0), m_title(""), m_author(""), m_genre(""), m_totalCopies(0), m_availableCopies(0) {}
	~Book() {}
	

	void addBook() {
       		int id;
		std::string title, author, genre;
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
		std::cout << "New book added" << std::endl;
		books.push_back(Book(id, title, author, genre));
	}

	
	void showBook() {
			std::cout << "ID: " << m_id << "\n"
				<<"Title: " << m_title << "\n"
				<<"Author: " << m_author << "\n"
				<<"Genre: " << m_genre << "\n"
				<<"AvailableCopies:" << m_availableCopies << "\n"
				<<"TotalCopies:" << m_totalCopies << std::endl;
	}
	
	void borrowBook() { 
		if(m_availableCopies > 0 ) {
		m_availableCopies--;
		return true;
		}
		return false;
	}
	
	void returnBook() {
		if(m_availableCopies < m_totalCopies) {
		m_availableCopies++;
		} else {
				std::cout << "The book has reached its maximum quantity" << std::endl;
		}
	}
	
	int getID() {return m_id;}
	
	std::string getTitle() {return m_title;}

 };





struct Person{

};



class User : public Person{
private:
	std::string m_username;
	std::string m_password;
	int borrowedBookIDs[3]; 
	int borrowDates[3];    

public:
	User() : m_username("user"), m_password("user123"){}
	~User() {}

    void registerUser() {}
   
   	bool login(std::string uname, std::string pass) {
			return (uname == m_username && pass == m_password);
			
	}
   
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
	Book b;
	b.addBook();
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
		if(login == "user" && passwd == "user123") {
		std::cout << "Welcome to Libery User" << std::endl;
		//UserMenu();
			}else {
			std::cout << "Unknown login or passwd" << std::endl;
			}
		}else {
				std::cout << "Unknown answer" << std::endl;
			}
}
