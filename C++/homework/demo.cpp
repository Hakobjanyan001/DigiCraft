#include <iostream>
#include <string>
#include <vector>


 class Book{
// Member Data
private:
	int m_id;
	std::string m_title;
	std::string m_author;
	std::string m_genre;
	int m_totalCopies;
	int m_availableCopies;
	int copies = 3;

	int m_size;
	int m_capacity;


	//Special functions 
	public:
	Book(int id, std::string& title, std::string& author, std::string& genre) : 
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
		m_totalCopies(copies), 
		m_availableCopies(0) {}
	~Book() {}
	
	// Public API
	 void addBook() {     	// This function takes the new book data from the user and creates a Book object
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
		m_totalCopies = copies;
		m_availableCopies = copies;
		std::cout << "New book added" << std::endl;
	}
	
	void showBook() {	// This function show book details
			std::cout << "ID: " << m_id << "\n"
				<<"Title: " << m_title << "\n"
				<<"Author: " << m_author << "\n"
				<<"Genre: " << m_genre << "\n"
				<<"AvailableCopies:" << m_availableCopies << "\n"
				<<"TotalCopies:" << m_totalCopies << std::endl;
	}
	
	void borrowBook() {   // Fhis function to borrow a book
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
	
	public:
	// Geter
	int getId() {return m_id;}
	
	std::string getTitle() {return m_title;}
	
	int getAvailablesCopies() {return m_availableCopies;}
 };


// Person Struct
struct Person{
	//Member Data
	
	std::string m_name, m_surname;
	int totalUsers;
	
	//Special functions 	
	Person() : 
	       	m_name(""), 
		m_surname("") {}
	
	Person (std::string name, std::string surname) :
	       	m_name(name), 
		m_surname(surname) {}

};





class User {

	// Member Data
	private:
	std::string m_username;
	std::string m_password;
	int borrowedBookIDs[3]; 
	int borrowDates[3];    

	std::vector<Person> users;
	Person per;
	int totalUsers = 0;

	//Special functions 
	public:
	User() : m_username("user"), m_password("user123"){}
	~User() {}

	std::string getName() {return per.m_name;}
	std::string getSurname() {return per.m_surname;}

	// Public API
	void registerUser() {
	    	std::cout << "Write Your Name" << std::endl;
		std::cin >> per.m_name;
	    	std::cout << "Write Your Surname" << std::endl;
		std::cin >> per.m_surname;
		std::string uname = "";
		std::string pass = "";
		std::cout << "Write User name" << std::endl;
		std::cin >> uname;
		std::cout << "Write User passwd" << std::endl;
		std::cin >> pass;
		if(login(uname, pass)){ 
		       	std::cout << "pass" << std::endl;
			users.push_back(per);
			per.totalUsers++;
			}else {
			std::cout << "not pass" << std::endl;
			}
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
				int tmp = books[i].getAvailablesCopies();
				if(tmp > 0) {
				tmp++;
		          	std::cout << "You borrowed: " << books[i].getTitle() << std::endl;
				}else {
					std::cout << "Not found this book" << std::endl;
				}
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
   
   	void viewBorrowedBooks(Book books[], int totalBooks) {
		for(int i = 0; i < totalBooks; i++) {
			std::cout << books[i].getTitle() << std::endl;
		}
	}
};





class Admin {

	// Member Data
	private:
	std::string adminname;
	std::string password;


	// Public API
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
		books[totalBooks] = Book(id, title, author, genre);
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
    
	void viewAllBooks(Book books[], int totalBooks) {
		for(int i = 0; i < totalBooks; i++){
			std::cout << books[i].getTitle() << std::endl;
		}
	}

	void viewUsers(User users[], int totalUsers) {
	for(int i = 0; i < totalUsers; i++) {
		std::cout << users[i].getName() << std::endl;
		std::cout << users[i].getSurname() << std::endl;
	}
    }
};


class Library {

	// Member Data
	private:
	std::vector<Book>myBooks;
	
	protected:
	// Public API
	void addBook() {
		Book newBook;
		newBook.addBook();
		myBooks.push_back(newBook);
	        std::cout << "Book add library" << std::endl;

	}

};

//Utility
void loginMenu();
void adminMenu(Book books[], int &totalBooks, User users[], int totalUsers);
void userMenu(Book books[], int totalBooks);



int main() {
	loginMenu();
	return 0;
}

//Utility
void loginMenu() {
	Book* books;
	int totalBooks = 0;

	User* users;
	int totalUsers = 0;

	std::cout << "___Welcome to Library___\n"
	<< " For Admin enter Admin\n"
	<< " For Users enter User" << std::endl;
	std::string answer = "";
	std::cin >> answer;
	std::string log = "";
	std::string passwd = "";
	if(answer == "Admin" || answer == "admin"){
		for(int i = 0; i < 3; i++){
		std::cout << "Write Admin login " << std::endl;
		std::cin >> log;
		std::cout << "Write Admin passwd" << std::endl; 
		std::cin >> passwd;
			if(log == "admin" && passwd == "admin123") {
					std::cout << "Welcome to Library admin" << std::endl;
					adminMenu(books, totalBooks, users, totalUsers);
					break;		
				}else {
					std::cout << "Unknown login or passwd" << std::endl;
					}
		}
	}else if(answer == "User" || answer == "user") {
	std::cout << "Write User login" << std::endl;
	std::cin >> log;
	std::cout << "Write User passwd" << std::endl;
	std::cin >> passwd;
		if(log == "user" && passwd == "user123") {
		std::cout << "Welcome to Libery User" << std::endl;
		User u;
    		u.registerUser();
		std::string uname, pass;
		std::cout << "Enter User name" << std::endl;
		std::cin >> uname;
		std::cout << "Enter passwd " << std::endl;
		std::cin >> pass;
   		if(u.login(uname, pass)) {
			std::cout << "login successful" << std::endl;
		}else {
			std::cout << "login failed" << std::endl;
		}
		userMenu(books, totalBooks);
			}else {
			std::cout << "Unknown login or passwd" << std::endl;
			}
		}else {
				std::cout << "Unknown answer" << std::endl;
			}
}



//Utility
void adminMenu(Book books[], int &totalBooks, User users[], int totalUsers) {
	Admin* admin = new Admin();
	std::string answer = "";
	
	while(answer != "exit") {
	std::cout << "For add book enther 1:\n" 
		<< "For remove book enther 2:\n"
		<< "For view all book enther 3:\n"
		<< "For view Users  enther 4:\n"
		<< "For exit enther exit" << std::endl;
		std::cin >> answer;
		
		if(answer == "1") {
			admin->addBook(books, totalBooks);
		}else if(answer == "2") {
			admin->removeBook(books, totalBooks);
		}else if(answer == "3") {
			admin->viewAllBooks(books, totalBooks);
		}else if(answer == "4") {
			admin->viewUsers(users, totalUsers);
		}else if(answer == "exit"){
			break;
		}else {
			std::cout << "Unknown answer" << std::endl;
		}
	}
	delete admin;
}




//Utility
void userMenu(Book books[], int totalBooks) {
	User* user = new User();
	std::string answer = "";
	
	while(answer != "exit") {
	std::cout << "For borrow book enther 1:\n"
		<< "For return book enther 2:\n"
		<< "For view borrowed book enther 3:\n"
		<< "For exit enther exit" << std::endl;
		std::cin >> answer;
	
		if(answer == "1") {
			user->borrowBook(books, totalBooks);
		}else if(answer == "2") {
			user->returnBook(books, totalBooks);
		}else if(answer == "3") {
			user->viewBorrowedBooks(books, totalBooks);
		}else if(answer == "exit") {
			break;
		}else {
			std::cout << "Unknown answer" << std::endl;
		}
	}
	delete user;
}
