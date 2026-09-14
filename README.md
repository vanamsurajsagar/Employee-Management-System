# Employee-Management-System
A modular, console-based CRUD application written in C that handles employee records and features persistent local storage using standard File I/O operations.

## 🚀 Features
- **Persistent Data Storage:** Saves records locally to a text file (`employees.txt`), ensuring data remains intact even after closing the program.
- **Structured Data Models:** Leverages C structures (`struct`) to efficiently bundle employee parameters (ID, Name, and Salary).
- **Safe Appending:** Opens files in append mode (`"a"`) to safely add new records to the database without overwriting existing data.
- **Clean Parsing Engine:** Utilizes line-by-line file reads coupled with string token parsing (`sscanf`) to cleanly format raw files back into readable console tables.

## 🛠️ System Architecture (Functions)
The program separates application responsibilities into distinct functional layers:
* `main()`: Operates the infinite control menu, routing user selection traffic through a `switch-case` framework.
* `addEmployee()`: Collects new profile definitions from the user buffer and stream-writes them into comma-separated text blocks.
* `displayEmployees()`: Targets the text repository file, evaluates availability, parses active lines, and prints structural records.

## 📋 Prerequisites
To compile and run this code, ensure a standard C compiler is active in your terminal environment:
- **GCC** (Linux/Mac)
- **MinGW / MSVC** (Windows)
- Or any C-compatible IDE (VS Code, Code::Blocks, Dev-C++)

## 💻 How to Run

1. **Clone the repository:**
   ```bash
   git clone https://github.com
   cd YOUR_REPO_NAME
   ```

2. **Compile the program:**
   ```bash
   gcc employee_system.c -o employee_system
   ```

3. **Execute the compiled binary:**
   ```bash
   ./employee_system
   ```

## 📸 Sample Application Run
```text
=== Employee Management System ===
1. Add Employee Records
2. Display All Employees
3. Exit
Enter your choice: 2

ID         Name                 Salary    
--------------------------------------------
101        Alice Smith          75000.00  
102        Bob Jones            62000.50  
```

## 📄 License
This repository is open-source and free to use under the [MIT License](LICENSE).
