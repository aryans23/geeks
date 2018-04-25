#include <utility>      // std::pair, std::make_pair
#include <string>       // std::string
#include <iostream>     // std::cout
#include <vector>
#include <map>

using namespace std;

/*
class Foo {
    public:
        Foo(): a(0) {}
        Foo& get();
        Foo& set(int);
        Foo& show();
    private:
        int a;
};

Foo& Foo::get() {
    cout << "Enter value " << endl;
    cin >> a;
    return *this;
}

Foo& Foo::show() {
    cout << a << endl;
    return *this;
}

int main() {
    Foo ob;
    ob.get().show();
    ob.show();
}

*/

//int main() {

    //typedef map<string, int> Words;
    //string word;
    //Words word_count;

    //while(cin >> word) {
    //    ++word_count[word];
    //}

    //while(cin >> word) {
    //    pair< Words::iterator, bool > ret = word_count.insert(make_pair(word, 1));
    //    if(!ret.second) {
    //        ++ret.first->second;
    //    }
    //    cout << word_count["foo"] << endl;
    //}

    //int occurs = 0;

    //if(word_count.count("foo")) {
    //    
    //    occurs = word_count["foo"];
    //}

    //cout << occurs << endl;
    
    //vector< pair<string, int> > cvec;
    //typedef pair<string, int> ele;
    //string name;
    //int age;

    //while (cin >> name >> age) {
    //    ele stu(name, age);
    //    cvec.push_back(stu);
    //}

    //for(vector<ele>::iterator it = cvec.begin(); it != cvec.end(); it++) {
    //    cout << "Name = " << (*it).first << endl;
    //    cout << "Age = " << (*it).second << endl;
    //}

    //for(vector<ele>::iterator it = cvec.begin(); it != cvec.end(); it++) {
    //    it->first = "Aryan";
    //    it->second = 22;
    //}

    //for(vector<ele>::iterator it = cvec.begin(); it != cvec.end(); it++) {
    //    cout << "Name = " << (*it).first << endl;
    //    cout << "Age = " << (*it).second << endl;
    //}

    //vector<ele>::value_type example = ele("ff", 2);
    //cout << example.first << endl;
    //cout << example.second << endl;
//}
