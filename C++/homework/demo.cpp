#include <iostream>
#include <string>
#include <vector>

// Declaration

class Book; 
class User; 
class Admin;
class Library;
struct Person;


void openLoginMenu();
void openUserMenu();
void openAdminMenu();

 class Book{
// Member Data
private:
	int m_id;
	std::string m_title;
	std::string m_author;
	std::string m_genre;
	int copies = 3;
	int m_totalCopies;
	int m_availableCopies;


	//Special functions 
	public:
	Book(	int id, 
		std::string& title, 
		std::string& author,
	       	std::string& genre) : 
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
		std::cin >> id;
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
	
	void borrowBook() {   // This function to borrow a book
		if(m_availableCopies > 0 ) {
		m_availableCopies--;
		return ;
		}
		std::cout << "No copies book" << std::endl;
		
	}
	
	void returnBook() {
		if(m_availableCopies < m_totalCopies) {
		m_availableCopies++;
		return ;
		}
		std::cout << "The book has reached its maximum quantity" << std::endl;
	}
	
	public:
	// Geter
	int getId() {return m_id;}
	
	std::string getTitle() {return m_title;}
	
	int& getAvailablesCopies() {return m_availableCopies;}
 };


// Person Struct
struct Person{
	protected:
	//Member Data
	
	std::string m_name, m_surname, m_city;
	int m_age;
	
	public:
	int totalUsers;
	//Special functions 	
	Person(	) :
		m_name(""),
		m_surname(""),
		m_age(0),
		m_city("") {}

	
	Person(	std::string& name,
		std::string& surname,
		int age,
		std::string& city) :
		m_name(name),
		m_surname(surname),
		m_age(age),
		m_city(city){}

	
	~Person() {}
	
	

	std::string getName () {return m_name;}
	std::string getSurname () {return m_surname;}
	
	std::vector<User> myUser;

};





class User : public Person{

	// Member Data
	private:
	std::string m_username;
	std::string m_passwd;
	int borrowedBookIDs[3]; 
	int borrowDates[3];    
	std::vector<Book> borrowedBooks;
	
	//Special functions 
	public:
	
	User() : 
		Person(), 
		m_username(""), 
		m_passwd("") {}

	
	User(	std::string name,
		std::string surname,
		int age,
		std::string city,
		std::string username,
		std::string passwd) : 
		Person(name, surname, age, city), 
		m_username(username), 
		m_passwd(passwd) {}

	
	~User() {}

	
	std::string getUsername() {return m_username;}
	std::string getPasswd() {return m_passwd;}
	
	std::string getName () {return m_name;}
	std::string getSurname () {return m_surname;}
	

	// Public API
	void registerUser() {   
			std::string name, surname, city, username, passwd;
			int age;

			std::cout << "Write Your Name" << std::endl;
			std::cin >> name;
			std::cout << "Write Your Surname" << std::endl;
			std::cin >> surname;
			std::cout << "Write Your Age" << std::endl;
			std::cin >> age;
			std::cout << "Write Your City" << std::endl;
			std::cin >> city;
			std::cout << "Write User Username (login)" << std::endl;
			std::cin >> username;
			std::cout << "Write User Password (passwd)" << std::endl;
			std::cin >> passwd;

			User newUser(name, surname, age, city, username, passwd);

			if(login(username, passwd)){ 
					std::cout << "pass" << std::endl;
					myUser.push_back(newUser);
					Person newPerson;
					newPerson.totalUsers++;
					openUserMenu();
					return ;
			} 
			std::cout << "User not found " << std::endl;
	}
  
   	bool login(std::string& uname, std::string& pass) {  
			return (uname == getUsername() && pass == getPasswd());
			
	}
   
   	void borrowBook(Book books[], int totalBooks) {  
		int id;
		std::cout << "Enter book ID to borrow" << std::endl;
		std::cin >> id;
		for(int i = 0; i < totalBooks; i++) {
			if(books[i].getId() == id){
				int tmp = books[i].getAvailablesCopies();
				if(tmp > 0) {
				tmp--;
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
		std::cout << "Write day borrow Book " <<  std::endl;
		int dayBorrowBook;
		std::cin >> dayBorrowBook;	
		int id;
		int allDay = 7;
		int fine = 500; 
		std::cout << "For return enther book id" << std::endl;
		std::cin >> id;
		for(int i = 0; i < totalBooks; i++) {
			if(books[i].getId() == id){
				books[i].returnBook();
				if(dayBorrowBook > allDay){
					int debt = dayBorrowBook - allDay;
					int ollFine = fine * debt;
					std::cout << "User fine " << ollFine << " dram" << std::endl;
 					std::cout << "You returned: " << books[i].getTitle() << std::endl; 
				}
 				std::cout << "You returned: " << books[i].getTitle() << std::endl; 
				books[i].getAvailablesCopies()++;
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





class Admin : public Person{

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
	public:
	std::vector<User> users;
	std::vector<Book> myBooks;
	int totalBooks;
	int totalUsers;

	Library() : totalBooks(0), totalUsers(0){}
	~Library() {}

	// Public API
	void addBook() {
		Book newBook;
		newBook.addBook();
		myBooks.push_back(newBook);
		totalBooks++;
	        std::cout << "Book add library" << std::endl;

	}

};



int main() {
	openLoginMenu();
	return 0;
}

//Utility
void openLoginMenu() {
	Book* books = new Book();
	int totalBooks = 0;

	User* users = new User();
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
					openAdminMenu();
					delete books;
					delete users;
					break;		
				}else {
					std::cout << "Unknown login or passwd" << std::endl;
					}
		}
	}else if(answer == "User" || answer == "user") {
		User newUser;
    		newUser.registerUser();
		std::string uname = "user";
		std::string pass = "user123";
		if(newUser.login(uname, pass)){
			openUserMenu();
			return ;
		}
	}else {
			std::cout << "Unknown answer" << std::endl;
		}
}



//Utility
void openAdminMenu() { 
	Library myLibrary;
	Book* books = new Book[100];
	User* users = new User[100];
	Admin admin;
	int answer;
	
	while(true) {
	std::cout << "For add book enther 1:\n" 
		<< "For remove book enther 2:\n"
		<< "For view all book enther 3:\n"
		<< "For view Users  enther 4:\n"
		<< "For exit enther exit 0" << std::endl;
		std::cin >> answer;
		
		switch(answer){
		case 1:	
			admin.addBook(books, myLibrary.totalBooks);
			delete [] books;
			break;
		case 2:
			admin.removeBook(books, myLibrary.totalBooks);
			delete [] books;
			break;
		case 3:
			admin.viewAllBooks(books, myLibrary.totalBooks);
			delete [] books;
			break;
		case 4:
			admin.viewUsers(users, myLibrary.totalUsers);
			delete [] users;
			delete [] books;
		case 0:
			delete [] books;
			break;
		default:
			std::cout << "Unknown answer" << std::endl;
			delete [] books;
			break;
		}
	}
}




//Utility
void openUserMenu() { 
	Library myLibrary;
	Book* books = new Book[100];
	User user;
	
	int answer;
	
	while(true) {
	std::cout << "For borrow book enther 1:\n"
		<< "For return book enther 2:\n"
		<< "For view borrowed book enther 3:\n"
		<< "For exit enther 0" << std::endl;
		std::cin >> answer;
	
		switch(answer){
		case 1:
			user.borrowBook(books, myLibrary.totalBooks);
			delete [] books;
			break;
		case 2:
			user.returnBook(books, myLibrary.totalBooks);
			delete [] books;
			break;
		case 3:
			user.viewBorrowedBooks(books, myLibrary.totalBooks);
			delete [] books;
			break;
		case 0:
			delete [] books;
			return;
		default:
			delete [] books;
			std::cout << "Unknown answer" << std::endl;
			break;
		}
	}
}
