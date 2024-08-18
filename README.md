# Hotel Management System

This project is a simple Hotel Management System implemented in C. It provides a basic authentication system for different roles in a hotel, including customers, chefs, receptionists, and managers. The system imports data from CSV files, authenticates users based on their credentials, and displays their profile details upon successful login.

## Features

- **User Roles**: 
  - Customer
  - Chef
  - Receptionist
  - Manager

- **Authentication**:
  - The system authenticates users based on their unique ID and password.
  - User details are stored in a binary search tree for each role.
  
- **Data Import**:
  - User data is imported from CSV files.
  
- **Profile Page**:
  - After successful authentication, the user’s details are displayed.

## Project Structure

- **Structures**: 
  - `struct customer`: Stores customer details.
  - `struct chef`: Stores chef details.
  - `struct receptionist`: Stores receptionist details.
  - `struct manager`: Stores manager details.

- **Functions**:
  - `findUser()`, `findChef()`, `findReceptionist()`, `findManager()`: Searches for a user in the respective binary search tree.
  - `insert()`, `insertChef()`, `insertReceptionist()`, `insertManager()`: Inserts a user into the respective binary search tree.
  - `importfromcus()`, `importChefDataFromCSV()`, `importReceptionistDataFromCSV()`, `importManagerDataFromCSV()`: Imports data from CSV files into the binary search trees.
  - `authenticate()`, `authenticateChef()`, `authenticateReceptionist()`, `authenticateManager()`: Authenticates a user by verifying their ID and password.
  - `aunthenticate_all()`: Handles the authentication process for all user roles.
  - `Login()`: Manages the login process.

- **Main Function**:
  - The `main()` function starts the program by calling the `Login()` function.

## How to Use

### Compile the Program: 
   Use a C compiler like `gcc` to compile the code:
   ```bash
   gcc -o hotel_management_system hotel_management_system.c 
   ```


### Prepare CSV Files:

Ensure you have the following CSV files in the same directory as the compiled program:

- `customer1.csv`
- `chef.csv`
- `receptionist.csv`
- `manager.csv`

Each CSV file should follow this format:

- **Customer**: `id,password,name,number,bill`
- **Chef**: `UID,Name,password,phno`
- **Receptionist**: `UID,Name,password,phno`
- **Manager**: `UID,Name,password,phno`

### Login:

- Enter your User ID and Password.
- If authentication is successful, your profile details will be displayed.

### Notes:

- The `system("cls");` command is used to clear the console screen, which is specific to Windows. On other platforms, replace it with `system("clear");` or remove it entirely.
- The code assumes that the first digit of the User ID distinguishes the role (1 for customers, 2 for chefs, 3 for receptionists, 4 for managers).
- Make sure that the CSV files contain correctly formatted data to avoid parsing errors.

### Future Improvements:

- Add error handling for file operations and user input.
- Implement features for adding, updating, and deleting user data.
- Enhance security by using encrypted passwords.
- Extend the system to manage hotel rooms, bookings, and services.
