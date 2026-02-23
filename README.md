# Online Complaint Management System (C++)

A console-based Online Complaint Management System developed in C++ that allows users to register, edit, process, and analyze complaints efficiently. The system manages pending complaints using a dynamic queue and stores resolved complaints using a dynamic stack.

---

## 📌 Project Overview

This application simulates a real-world complaint handling system where complaints are:

* Added and stored as pending
* Processed in FIFO order
* Marked as resolved
* Stored in a history log

The system also provides simple analytics based on complaint priority levels.

---

## 🚀 Features

* Add new complaints with unique ID validation
* Edit existing complaint details
* Process complaints in First-In-First-Out (FIFO) order
* Store resolved complaints in history (Last-In-First-Out view)
* Dynamic memory resizing when capacity is exceeded
* Priority-based analytics (High / Medium / Low)
* Menu-driven interactive console interface

---

## 🏗️ Core Concepts Used

* Structures (`struct Complaint`)
* Classes and Objects
* Encapsulation
* Dynamic memory allocation using `new` and `delete`
* Dynamic Queue implementation
* Dynamic Stack implementation
* Array resizing logic

---

## 📊 Complaint Workflow

1. A complaint is added with:

   * Unique ID
   * Name
   * Category
   * Priority (1 = High, 2 = Medium, 3 = Low)
2. Newly added complaints are marked as **Pending**.
3. Complaints are processed in FIFO order.
4. Once processed, status changes to **Resolved**.
5. Resolved complaints are stored in history for review.

---

## 📈 Analytics

The system provides a summary of:

* High priority complaints
* Medium priority complaints
* Low priority complaints
* Total complaints registered

---

## 🛠️ How to Run

```bash
# Compile the program
g++ main.cpp -o complaint

# Run the program
./complaint        # Linux / Mac
complaint.exe      # Windows
```

---

## 📂 Project Structure

* `main.cpp` – Contains:

  * Complaint structure
  * Dynamic Queue class
  * Dynamic Stack class
  * ComplaintSystem class
  * Complete menu-driven application logic

---

## 🎯 Learning Outcome

This project demonstrates practical implementation of dynamic data structures, memory management, and structured system design in C++. It simulates a real-world complaint handling workflow using efficient data management techniques.

---

## 📄 License

This project is created for educational and practice purposes.

---

## 👨‍💻 Author

Malik Shoaib.
