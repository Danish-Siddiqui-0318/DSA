/*
 ============================================================
   STUDENT RECORD MANAGEMENT SYSTEM
   Data Structure : Binary Search Tree (BST)
   Language       : C++
   Persistence    : File I/O (students.txt)
   Key by         : Roll Number
 ============================================================
   OPERATIONS:
     1. Insert Student
     2. Search Student
     3. Delete Student
     4. Display All (In-order / Sorted)
     5. Display All (Pre-order)
     6. Display All (Post-order)
     7. Find Topper (Max GPA)
     8. Find Min / Max Roll Number
     9. Count Total Students
    10. Update Student Info
     0. Exit  (auto-saves to students.txt)
 ============================================================
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const string FILE_NAME = "students.txt";

// ─────────────────────────────────────────
//  Student data stored at each BST node
// ─────────────────────────────────────────
struct Student {
    int    rollNo;
    string name;
    string department;
    float  gpa;
    int    semester;
};

// ─────────────────────────────────────────
//  BST Node
// ─────────────────────────────────────────
struct Node {
    Student data;
    Node*   left;
    Node*   right;
    Node(Student s) : data(s), left(nullptr), right(nullptr) {}
};

// ─────────────────────────────────────────
//  BST Class
// ─────────────────────────────────────────
class StudentBST {
private:
    Node* root;

    Node* insert(Node* node, Student s) {
        if (!node) return new Node(s);
        if (s.rollNo < node->data.rollNo)
            node->left  = insert(node->left,  s);
        else if (s.rollNo > node->data.rollNo)
            node->right = insert(node->right, s);
        else
            cout << "\n  [!] Roll No " << s.rollNo << " already exists.\n";
        return node;
    }

    Node* search(Node* node, int rollNo) {
        if (!node || node->data.rollNo == rollNo) return node;
        if (rollNo < node->data.rollNo)
            return search(node->left,  rollNo);
        return search(node->right, rollNo);
    }

    Node* minNode(Node* node) {
        while (node->left) node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int rollNo) {
        if (!node) { cout << "\n  [!] Roll No not found.\n"; return node; }
        if (rollNo < node->data.rollNo)
            node->left  = deleteNode(node->left,  rollNo);
        else if (rollNo > node->data.rollNo)
            node->right = deleteNode(node->right, rollNo);
        else {
            if (!node->left)  { Node* t = node->right; delete node; return t; }
            if (!node->right) { Node* t = node->left;  delete node; return t; }
            Node* successor = minNode(node->right);
            node->data      = successor->data;
            node->right     = deleteNode(node->right, successor->data.rollNo);
        }
        return node;
    }

    void inOrder(Node* node) {
        if (!node) return;
        inOrder(node->left);
        printStudent(node->data);
        inOrder(node->right);
    }

    void preOrder(Node* node) {
        if (!node) return;
        printStudent(node->data);
        preOrder(node->left);
        preOrder(node->right);
    }

    void postOrder(Node* node) {
        if (!node) return;
        postOrder(node->left);
        postOrder(node->right);
        printStudent(node->data);
    }

    void findTopper(Node* node, Node*& best) {
        if (!node) return;
        if (!best || node->data.gpa > best->data.gpa) best = node;
        findTopper(node->left,  best);
        findTopper(node->right, best);
    }

    int count(Node* node) {
        if (!node) return 0;
        return 1 + count(node->left) + count(node->right);
    }

    void destroy(Node* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

    // ── Save in-order to file ──────────────
    void saveToFile(Node* node, ofstream& out) {
        if (!node) return;
        saveToFile(node->left, out);
        // Each student on one line, fields separated by '|'
        out << node->data.rollNo    << "|"
            << node->data.name      << "|"
            << node->data.department<< "|"
            << fixed << setprecision(2) << node->data.gpa << "|"
            << node->data.semester  << "\n";
        saveToFile(node->right, out);
    }

    void printStudent(const Student& s) {
        cout << "  +---------------------------------+\n";
        cout << "  | Roll No   : " << left << setw(20) << s.rollNo      << "|\n";
        cout << "  | Name      : " << left << setw(20) << s.name        << "|\n";
        cout << "  | Dept      : " << left << setw(20) << s.department  << "|\n";
        cout << "  | GPA       : " << left << setw(20) << fixed << setprecision(2) << s.gpa << "|\n";
        cout << "  | Semester  : " << left << setw(20) << s.semester    << "|\n";
        cout << "  +---------------------------------+\n";
    }

public:
    StudentBST() : root(nullptr) {}
    ~StudentBST() { destroy(root); }

    // ── Insert ─────────────────────────────
    void insertStudent(Student s, bool silent = false) {
        root = insert(root, s);
        if (!silent)
            cout << "\n  [OK] Student inserted successfully.\n";
    }

    // ── Search ─────────────────────────────
    void searchStudent(int rollNo) {
        Node* result = search(root, rollNo);
        if (result) {
            cout << "\n  [OK] Student found:\n";
            printStudent(result->data);
        } else {
            cout << "\n  [!] Roll No " << rollNo << " not found.\n";
        }
    }

    // ── Delete ─────────────────────────────
    void deleteStudent(int rollNo) {
        root = deleteNode(root, rollNo);
        cout << "\n  [OK] Done.\n";
    }

    // ── Traversals ─────────────────────────
    void displayInOrder() {
        if (!root) { cout << "\n  [!] No records found.\n"; return; }
        cout << "\n  === All Students (Sorted by Roll No) ===\n";
        inOrder(root);
    }

    void displayPreOrder() {
        if (!root) { cout << "\n  [!] No records found.\n"; return; }
        cout << "\n  === Pre-order Traversal ===\n";
        preOrder(root);
    }

    void displayPostOrder() {
        if (!root) { cout << "\n  [!] No records found.\n"; return; }
        cout << "\n  === Post-order Traversal ===\n";
        postOrder(root);
    }

    // ── Topper ─────────────────────────────
    void showTopper() {
        if (!root) { cout << "\n  [!] No records found.\n"; return; }
        Node* best = nullptr;
        findTopper(root, best);
        cout << "\n  === Topper (Highest GPA) ===\n";
        printStudent(best->data);
    }

    // ── Min / Max ──────────────────────────
    void showMinMax() {
        if (!root) { cout << "\n  [!] No records found.\n"; return; }
        Node* mn = root; while (mn->left)  mn = mn->left;
        Node* mx = root; while (mx->right) mx = mx->right;
        cout << "\n  Minimum Roll No:\n"; printStudent(mn->data);
        cout << "\n  Maximum Roll No:\n"; printStudent(mx->data);
    }

    // ── Count ──────────────────────────────
    void countStudents() {
        cout << "\n  Total Students: " << count(root) << "\n";
    }

    // ── Update ─────────────────────────────
    void updateStudent(int rollNo) {
        Node* node = search(root, rollNo);
        if (!node) { cout << "\n  [!] Roll No not found.\n"; return; }
        Student& s = node->data;
        cout << "\n  Updating record for Roll No: " << rollNo << "\n";
        cout << "  New Name       [" << s.name       << "]: "; cin.ignore(); getline(cin, s.name);
        cout << "  New Department [" << s.department << "]: "; getline(cin, s.department);
        cout << "  New GPA        [" << s.gpa        << "]: "; cin >> s.gpa;
        cout << "  New Semester   [" << s.semester   << "]: "; cin >> s.semester;
        cout << "\n  [OK] Record updated.\n";
    }

    // ── Save all records to file ───────────
    void saveToFile() {
        ofstream out(FILE_NAME);
        if (!out) { cout << "\n  [!] Could not open file for saving.\n"; return; }
        saveToFile(root, out);
        out.close();
        cout << "\n  [OK] Records saved to " << FILE_NAME << "\n";
    }

    // ── Load records from file ─────────────
    int loadFromFile() {
        ifstream in(FILE_NAME);
        if (!in) return 0;   // no file yet, that's fine

        int loaded = 0;
        string line;
        while (getline(in, line)) {
            if (line.empty()) continue;

            // Parse: rollNo|name|department|gpa|semester
            Student s;
            size_t p1 = line.find('|');
            size_t p2 = line.find('|', p1 + 1);
            size_t p3 = line.find('|', p2 + 1);
            size_t p4 = line.find('|', p3 + 1);

            if (p1 == string::npos || p2 == string::npos ||
                p3 == string::npos || p4 == string::npos) continue;

            s.rollNo     = stoi(line.substr(0, p1));
            s.name       = line.substr(p1 + 1, p2 - p1 - 1);
            s.department = line.substr(p2 + 1, p3 - p2 - 1);
            s.gpa        = stof(line.substr(p3 + 1, p4 - p3 - 1));
            s.semester   = stoi(line.substr(p4 + 1));

            insertStudent(s, true);   // silent = no success message per record
            loaded++;
        }
        in.close();
        return loaded;
    }
};

// ─────────────────────────────────────────
//  Input helper
// ─────────────────────────────────────────
Student getStudentInput() {
    Student s;
    cout << "\n  Enter Roll No   : "; cin >> s.rollNo;
    cin.ignore();
    cout << "  Enter Name      : "; getline(cin, s.name);
    cout << "  Enter Department: "; getline(cin, s.department);
    cout << "  Enter GPA (0-4) : "; cin >> s.gpa;
    cout << "  Enter Semester  : "; cin >> s.semester;
    return s;
}

void printMenu() {
    cout << "\n";
    cout << "  +======================================+\n";
    cout << "  |   STUDENT RECORD MANAGEMENT (BST)    |\n";
    cout << "  +======================================+\n";
    cout << "  |  1.  Insert Student                  |\n";
    cout << "  |  2.  Search Student                  |\n";
    cout << "  |  3.  Delete Student                  |\n";
    cout << "  |  4.  Display All (In-order / Sorted) |\n";
    cout << "  |  5.  Display All (Pre-order)         |\n";
    cout << "  |  6.  Display All (Post-order)        |\n";
    cout << "  |  7.  Find Topper (Max GPA)           |\n";
    cout << "  |  8.  Min / Max Roll Number           |\n";
    cout << "  |  9.  Count Total Students            |\n";
    cout << "  |  10. Update Student Info             |\n";
    cout << "  |  0.  Exit (auto-saves)               |\n";
    cout << "  +======================================+\n";
    cout << "  Choice: ";
}

// ─────────────────────────────────────────
//  Main
// ─────────────────────────────────────────
int main() {
    StudentBST bst;

    // Load saved records from file
    int loaded = bst.loadFromFile();
    if (loaded > 0)
        cout << "\n  [OK] " << loaded << " record(s) loaded from " << FILE_NAME << "\n";
    else {
        // First run: insert sample data
        cout << "\n  [i] No save file found. Loading sample data...\n";
        bst.insertStudent({101, "Ali Hassan",  "Computer Science", 3.85f, 5}, true);
        bst.insertStudent({203, "Sara Khan",   "Electrical Eng",   3.50f, 3}, true);
        bst.insertStudent({155, "Usman Tariq", "Mechanical Eng",   2.90f, 4}, true);
        bst.insertStudent({312, "Fatima Noor", "Computer Science", 3.95f, 6}, true);
        bst.insertStudent({89,  "Hamza Malik", "Software Eng",     3.10f, 2}, true);
        bst.insertStudent({250, "Zara Ahmed",  "Civil Eng",        2.75f, 5}, true);
        cout << "  [i] 6 sample records loaded.\n";
    }

    int choice;
    do {
        printMenu();
        cin >> choice;

        switch (choice) {
            case 1: bst.insertStudent(getStudentInput()); break;
            case 2: {
                int r; cout << "\n  Enter Roll No to search: "; cin >> r;
                bst.searchStudent(r); break;
            }
            case 3: {
                int r; cout << "\n  Enter Roll No to delete: "; cin >> r;
                bst.deleteStudent(r); break;
            }
            case 4:  bst.displayInOrder();   break;
            case 5:  bst.displayPreOrder();  break;
            case 6:  bst.displayPostOrder(); break;
            case 7:  bst.showTopper();       break;
            case 8:  bst.showMinMax();       break;
            case 9:  bst.countStudents();    break;
            case 10: {
                int r; cout << "\n  Enter Roll No to update: "; cin >> r;
                bst.updateStudent(r); break;
            }
            case 0:
                bst.saveToFile();
                cout << "  Goodbye!\n\n";
                break;
            default: cout << "\n  [!] Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
