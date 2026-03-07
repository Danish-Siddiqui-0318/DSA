// Linear Search

// #include <iostream>
// using namespace std;

// int main()
// {
//     int input[10] = {77, 98, 32, 65, 27, 99, 12, 15, 72, 57};
//     int toSearch;
//     cin >> toSearch;

//     bool found = false;

//     for (int i = 0; i < 10; i++)
//     {
//         if (input[i] == toSearch)
//         {
//             cout << "Number is Found";
//             found = true;
//             break;
//         }
//     }

//     if (!found)
//     {
//         cout << "Number is Not found";
//     }

//     return 0;
// }

// Binary Search

// #include <iostream>
// using namespace std;

// int main() {
//     int l = 0;
//     int r = 9;
//     int mid;
//     int input[10] = {12, 37, 77, 88, 112, 168, 200, 211, 300, 315};
//     int toSearch;
//     bool isfind=false;

//     cin >> toSearch;

//     while ((l < r) || (l == r)) {
//         mid = (l + r) / 2;

//         if (toSearch == input[mid]) {
//             cout << "Value is Found";
//             isfind=true;
//             break;
//         }

//         if (toSearch > input[mid]) {
//             l = mid + 1;
//         } else {
//             r = mid - 1;
//         }
//     }
//     if(!isfind){
//         cout<<"Not found";
//     }
//     return 0;
// }


// Linear Search (Duplicate in Array)
// #include <iostream>
// using namespace std;

// int main()
// {
//     int input[12] = {77, 98, 32, 65, 27, 99,32, 12, 15, 72, 32,57};
//     int toSearch;
//     cin >> toSearch;

//     int noOfFinds = 0;
//     bool found = false;

//     for (int i = 0; i < 10; i++)
//     {
//         if (input[i] == toSearch)
//         {
//             found = true;
//             noOfFinds++;
//         }
//     }

//     if (!found)
//     {
//         cout << "Number is Not found";
//     }
//     else
//     {
//         cout << toSearch << " is found and there are " << noOfFinds << " in this array";
//     }

//     return 0;
// }


// Binary Search (Duplication)
// #include <iostream>
// using namespace std;

// int main() {
//     int input[14] = {12,12, 37, 77, 88, 112, 168, 168,168,168,200, 211, 300, 315};
//     int n = 14;
//     int toSearch;
//     cin >> toSearch;

//     int l = 0, r = n - 1;
//     int first = -1, last = -1;

//     while (l <= r) {
//         int mid = (l + r) / 2;
//         if (input[mid] == toSearch) {
//             first = mid;
//             r = mid - 1;   
//         } else if (toSearch > input[mid]) {
//             l = mid + 1;
//         } else {
//             r = mid - 1;
//         }
//     }

//     l = 0;
//     r = n - 1;

    
//     while (l <= r) {
//         int mid = (l + r) / 2;
//         if (input[mid] == toSearch) {
//             last = mid;
//             l = mid + 1;   
//         } else if (toSearch > input[mid]) {
//             l = mid + 1;
//         } else {
//             r = mid - 1;
//         }
//     }

//     if (first == -1) {
//         cout << "Not found";
//     } else {
//         cout << "Total duplicates: " << (last - first + 1);
//     }

//     return 0;
// }
