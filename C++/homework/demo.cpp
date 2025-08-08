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


public:
	Book(int id, std::string title, std::string author, std::string genre, int copies = 3) : 
		 m_id(id), 
		 m_title(title), 
   		 m_author(author), 
         m_genre(genre), 
		 m_totalCopies(copies),
		 m_availableCopies(copies) {}
	Book() : 
		m_id(0),
	   	m_title(""), 
		m_author(""), 
		m_genre(""), 
		m_totalCopies(0), 
		m_availableCopies(0) {}
	~Book() {}
	


	
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
		}else {
			std::cout << "No copies book" << std::endl;
		}
	}
	
	void returnBook() {
		if(m_availableCopies < m_totalCopies) {
		m_availableCopies++;
		} else {
				std::cout << "The book has reached its maximum quantity" << std::endl;
		}
	}
	
	int getId() {return m_id;}
	
	std::string getTitle() {return m_title;}

 };





struct Person{

};



class User {
private:
	std::string m_username;
	std::string m_password;
	int borrowedBookIDs[3]; 
	int borrowDates[3];    

public:
	User() : m_username("user"), m_password("user123"){}
	~User() {}

    void registerUser() {
		std::string uname = "";
		std::string pass = "";
		std::cout << "Write User login" << std::endl;
		std::cin >> uname;
		std::cout << "Write User passwd" << std::endl;
		std::cin >> pass;
		login(uname, pass) == true 
			   	? std::cout << "pass" << std::endl 
				: std::cout << "not pass" << std::endl;
	}
   
   	bool login(std::string uname, std::string pass) {
			return (uname == m_username && pass == m_password);
			
	}
   
   	void borrowBook(Book books[], int totalBooks) {
		int id;
		std::cout << "Enter book ID to borrow" << std::endl;
		std::cin >> id;
		for(int i = 0; i < totalBooks; i++) {
				if(books[i].getId() == id){
					books[i].borrowBook();
		            std::cout << "You borrowed: " << books[i].getTitle() << std::endl;
					break;
				}
		}
		std::cout << "Book not found" << std::endl;

	}
   
   	void returnBook(Book books[], int totalBooks) {
		int id;
		std::cout << "For return enther book id" << std::endl;
		std::cin >> id;
		for(int i = 0; i < totalBooks; i++) {
			if(books[i].getId() == id){
				books[i].returnBook();
 				std::cout << "You returned: " << books[i].getTitle() << std::endl; 
				break;
			}
		}
	   	std::cout << "Book not found!" << std::endl;
	}
   
   	void viewBorrowedBooks(Book books[], int totalBooks) {}
};





class Admin {
private:
	std::string adminname;
	std::string password;
public:
    void addBook(Book books[], int &totalBooks) {
		int id;
		std::string title, author, genre;
		std::cout << "write new book data" << std::endl;
		std::cout << "id" << std::endl;
		std::cin >> (id);
		std::cin.ignore();	
		std::cout << "Title" << std::endl;	
		std::getline(std::cin, title);
		std::cout << "author" << std::endl;
		std::getline(std::cin, author);
		std::cout << "Genre" << std::endl;
		std::getline(std::cin ,genre);
		books[totalBooks] = Book book(id, title, author, genre);
		totalBooks++;
		std::cout << "New book added" << std::endl;
	}

	void removeBook(Book books[], int &totalBooks) {
			int id;
			std::cout << "For remove enther book id"  << std::endl;
			std::cin >> id;
			for(int i = 0; i < totalBooks; i++){
				if(books[i].getId() ==  id) {
					for(int j = i; j < totalBooks - 1; j++){
							books[j] = books[j + 1];
					}
					totalBooks--;
					std::cout << "Book removed" << std::endl;
					break;
				}
			}
	}
    
	void viewAllBooks(Book books[], int totalBooks) {}

    void viewUsers(User users[], int totalUsers) {}
};


class Library {
	private:
	std::vector<Book>myBooks;
	public:
	void addBook() {
       	int id;
		std::string title, author, genre;
		std::cout << "write new book data" << std::endl;
		std::cout << "id" << std::endl;
		std::cin >> (id);	
		std::cin.ignore();
		std::cout << "Title" << std::endl;	
		std::getline(std::cin, title);
		std::cout << "author" << std::endl;
		std::getline(std::cin, author);
		std::cout << "Genre" << std::endl;
		std::getline(std::cin ,genre);
		Book book(id, title, author, genre);
		std::cout << "New book added" << std::endl;
		myBooks.push_back(Book(id, title, author, genre));
	}
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
	<< " For Admin enter Admin\n"
	<< " For Users enter User" << std::endl;
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
 					adminMenu();
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
 		userMenu();
			}else {
			std::cout << "Unknown login or passwd" << std::endl;
			}
		}else {
				std::cout << "Unknown answer" << std::endl;
			}
}



void adminMenu(books[], &totalBooks, Users[]) {
	Admin admin;
	std::string answer = "";
	while(answer != "exit") {
	std::cout << "For add book enther 1:\n" 
		<< "For remove book enther 2:\n"
		<< "For view all book enther 3:\n"
		<< "For view Users  enther 4:\n"
		<< "For exit enther exit" << std::endl;
		if(answer == "1") {
			admin.addBook(books[], totalBooks);
		}else if(answer == "2") {
			admin.removeBook(books[], totalBooks);
		}else if(answer == "3") {
			admin.viewAllBooks(books[], totalBooks);
		}else if(answer == "4") {
			admin.viewUsers(users[], totalUsers);
		}else if(answer == "exit"){
			break;
		}else {
			std::cout << "Unknown answer" << std::endl;
		}
	}
}




void userMenu(books[], totalBooks) {
	User user;
	std::string answer = "";
	while(answer != "exit") {
	std::cout << "For borrow book enther 1:\n"
		<< "For return book enther 2:\n"
		<< "For view borrowed book enther 3:\n"
		<< "For exit enther exit" << std::endl;
		if(answer == "1") {
			user.borrowBook(books[], totalBooks)
		}else if(answer == "2") {
			user.returnBook(books[], totalBooks)
		}else if(answer == "3") {
			user.viewBorrowedBooks(books[], totalBooks)
		}else if(answer == "exit") {
			break;
		}else {
			std::cout << "Unknown answer" << std::endl;
		}
	}
}
