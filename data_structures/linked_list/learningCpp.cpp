#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
using namespace std;

//class StrPerm {
//   public :
//    string name;
//};

//void foo(string name) {
//    int i;
//    for(i = 0; i<=name.length(); i++){
//        cout << name[i] << endl;
//    }
//}

//string &shorterStr(string &a, string &b) {
//    return a.size() < b.size() ? a:b; // returning the lvaue as reference
//}

//void foo(const int &a) { cout << "From const int a = " << a << endl; }

int main() {

    string s = "abc" + 'd'; // compiles but doesn't work
    cout << s << endl;

    int i;
    list<int> ilist;
    
    for(i = 0; i <  5; i++) {
        int input;
        cin >> input;
        ilist.push_back(input);
    }

    //deque<int> ideque1, ideque2;
    //deque<int>::iterator it1, it2;
    ////it1 = ideque1.begin();
    ////it2 = ideque2.begin();

    //for(list<int>::iterator iter = ilist.begin(); iter != ilist.end(); iter++) {
    //    if(*iter % 2 == 0){
    //        ideque1.push_back(*iter);
    //    }
    //    else {
    //        ideque2.push_back(*iter);
    //    }
    //}  

    // No iterator arithmetic on containers other than vectors or deque
    // list<int> l;
    // list<int>::iterator it = l.begin(), it2 = l.end();
    // while(it < it2) {it++;}
        
    //string a,b;
    //a ="aryan";
    //b = "dan";
    //
    //shorterStr(a,b) = "is not the shorter name";  // returned the reference as lvalue
    //cout << a << " " << b << endl;

    //int a = 5;
    //int *b = new int;
    //b = &a;
    //cout << *b << endl;
    //b = 0;  // have to initialize it to 0 before deleting (avoid dangling pointer)
    //delete b;

    
    //string s = "Hello";
    //string s1 = s + "abc" + "dd";
    //string s2 = "abc" + "dd" + s;
    //cout << s1 << " " << s2 << endl;

    //int a;
    //cout << "Enter" << endl;
    //cout << (cin >> a) << endl;
    //cout << "End" << endl; 

    // StrPerm ob;
    // int i = 1;
    // cout << "Enter name : ";
    // cin >> ob.name;
    // cout << ob.name << endl;
    // foo(ob.name);
    
    //int a = 1;
    //int b = 2;
    //const int &c = a + b;
    //cout << c << endl;
    //a++; b++;
    //cout << c << endl;
    //cout << a << endl;
    //cout << b << endl;

    //int &x = a;

    //double d = 4.2;
    //int t = d;
    //int &e = t;
    //cout << e << endl;

    //int f = 5;
    //const int &g = f;
    //cout << g << endl;
    //f++; f++;
    //cout << f << endl;
    //cout << g << endl;

    //g = e;
    //cout << g << endl;

    //enum Week {
    //    Mon = 1, Tue, Wed, Thr, Fri, Sat, Sun
    //};

    //bool a = Tue;
    //Week b = Sun;
    //cout << b << endl;

    //cout << a << endl;

    return 0;
}
 
