/* STL : Vectors*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;     // vector is a container. the syntax: container_name<data type> variable_name
                       // this will create an empty container
    v.push_back(1);    // this means that we want to push a number into the array or the container.
    v.emplace_back(2); // emplace also means to add or push a number into the container
    cout << v[0];

    vector<pair<int, int>> vec;
    vec.push_back({1, 2});  // for push_back we have to specify the curly braces to push that value pair into the container
    vec.emplace_back(3, 4); // in emplace_back, we dont have to specify the curly brackets. it will assume it as pair and take it as
                            // input to the container

    vector<int>::iterator it = v.begin(); // iterator is used to access the elements of the container. begin function will start
                                          // from the first number
    it++;
    cout << *(it);

    vector<int>::iterator it = v.end(); // this pointer will at the position right after the last element of the container. if we want to access the last element of the container, we will first have to do it--.
    // vector<int>::iterator it = v.rend();    // never used
    // vector<int>::iterator it = v.rbegin();  // never used

    // to access the elements of the conatiner one by one
    for (vector<int>::iterator it = v.end(); it != v.end(); it++)
    {
        cout << *(it);
    }
    for (auto it = v.begin(); it != v.end(); it++) // auto will understand the datatype based on the value we assign to a variable
    {
        cout << *(it);
    }

    // (10,20,30,40)
    v.erase(v.begin() + 1); // erase function will erase or delete the value the particular location   (10,30,40)

    // (10,10)
    v.insert(v.begin(), 300);       // we want to insert 300 at the beginning  (300,10,10)
    v.insert(v.begin() + 1, 2, 50); // syntax: v.insert(v.begin()+where/ position where you want to add, how many numbers you want to add, which number is to be added)      (300,50,50,10,10)

    // (10,20,30,40)
    cout<<v.size();    // gives the size of the vector    output--> 4

    vector<pair<int, int>> v1,v2;
    v1.emplace_back(10,20);
    v2.emplace_back(30,40);
    v1.swap(v2);    // swapping the vectors.  v1-->(30,40)  v2-->(10,20)

    v.clear(); // erase the entire vector

    v.empty(); 
    cout<<v.empty();     // returns a boolean value whether the string is empty or not

    // for vectors, singly linked list is maintained since we can perform operations only from one end.
}