#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

enum monthName {January, February, March, April, May, June, July, August, September, October, November, December};
struct Date{
    monthName month;
    unsigned short day; //1..31
    unsigned short year;
};

template <class T>
void heapSort(vector<T> &mass);

template <class T>
void outMass(vector<T> &mass);

istream& operator>> (istream& is, Date &in);
ostream& operator<< (ostream& os, Date &out);
bool operator> (Date a, Date b);
bool operator< (Date a, Date b);

int main() {

    cout << "Choice data type 1 - int, 2 - date: ";
    short choice;
    cin >> choice;
    cout << "Enter full file name: ";
    string fileName;
    cin >> fileName;

    ifstream iFile(fileName);
    int num; //number of digits
    iFile >> num;
    if (choice == 1)
    {
        vector<int> mass;
        for (int i = 0; i < num; i++){
            int temp;
            iFile >> temp;
            mass.push_back(temp);
        }

        cout << "Unsorted mass:\n";
        outMass(mass);

        heapSort(mass);

        cout << "Sorted mass:\n";
        outMass(mass);

        ofstream ofile ("sorted.txt");
        for (int i = 0; i < mass.size(); i++)
        {
            ofile << mass[i] << endl;
        }
    }
    else if (choice == 2)
    {
        vector<Date> mass;
        for (int i = 0; i < num; i++){
            Date temp;
            iFile >> temp;
            mass.push_back(temp);
        }

        cout << "Unsorted mass:\n";
        outMass(mass);

        heapSort(mass);

        cout << "Sorted mass:\n";
        outMass(mass);

        ofstream ofile ("sorted.txt");
        for (int i = 0; i < mass.size(); i++)
        {
            ofile << mass[i] << endl;
        }
    }
    return 0;
}

template <class T>
void outMass(vector<T> &mass){
    for (T i : mass)
        cout << i << endl;
    cout << endl;
}

template <class T>
void buildTree(vector<T> &mass,int root, int size);

template <class T>
void heapSort(vector<T> &mass){
    unsigned long long int m = mass.size() / 2;//number of root
    unsigned long long int r = mass.size();

    while (m > 0) {
        buildTree(mass, m - 1, r);
        swap(mass[0], mass[r - 1]);
        r--;
        m = r / 2;
    }
}

template <class T>
void recBuildTree(vector<T> &mass,int root, int size);

template <class T>
void buildTree(vector<T> &mass,int root, int size){
    for (int i = root; i >= 0; i--){
        int left = 2 * i + 1;
        int right = 2 * i + 2;


        if (left >= size)
            return;

        if ( (right >= size && mass[i] < mass[left]) || (right < size && mass[left] > mass[right] && mass[i] < mass[left]) ){
            swap(mass[left], mass[i]);
            recBuildTree(mass, left, size);
        }
        else if (right < size && mass[right] > mass[left] && mass[i] < mass[right]){
            swap(mass[right], mass[i]);
            recBuildTree(mass, right, size);
        }
    }
}

template <class T>
void outDebug(vector<T> &mass,int root, int left, int right){
    cout << "Mass:" << endl;
    outMass(mass);
    cout << endl << "root: " << mass[root] << endl;
    cout << endl << "left: " << mass[left] << endl;
    cout << endl << "right: " << mass[right] << endl;
}

template <class T>
void recBuildTree(vector<T> &mass,int root, int size){
    int left = 2 * root + 1;
    int right = 2 * root + 2;


    if (left >= size)
        return;

    if ( (right >= size && mass[root] < mass[left]) || (right < size && mass[left] > mass[right] && mass[root] < mass[left]) ){
        swap(mass[left], mass[root]);
        recBuildTree(mass, left, size);
    }
    else if (right < size && mass[right] > mass[left] && mass[root] < mass[right]){
        swap(mass[right], mass[root]);
        recBuildTree(mass, right, size);
    }
}

istream& operator>> (istream& is, Date &in) {
    string month;
    unsigned short day;
    unsigned short year;

    is >> month >> day >> year;

    in.day = day;
    in.year = year;

    if ( month == "January")
        in.month = January;
    else if ( month == "February")
        in.month = February;
    else if ( month == "March")
        in.month = March;
    else if ( month == "April")
        in.month = April;
    else if ( month == "May")
        in.month = May;
    else if ( month == "June")
        in.month = June;
    else if ( month == "July")
        in.month = July;
    else if ( month == "August")
        in.month = August;
    else if ( month == "September")
        in.month = September;
    else if ( month == "October")
        in.month = October;
    else if ( month == "November")
        in.month = November;
    else if ( month == "December")
        in.month = December;

    return is;
}

ostream& operator<< (ostream& os, Date &out){
    if (out.month == January)
        os << "January ";
    else if (out.month == February)
        os << "February ";
    else if (out.month == March)
        os << "March ";
    else if (out.month == April)
        os << "April ";
    else if (out.month == May)
        os << "May ";
    else if (out.month == June)
        os << "June ";
    else if (out.month == July)
        os << "July ";
    else if (out.month == August)
        os << "August ";
    else if (out.month == September)
        os << "September ";
    else if (out.month == October)
        os << "October ";
    else if (out.month == November)
        os << "November ";
    else if (out.month == December)
        os << "December ";

    os << out.day << " " << out.year;

    return os;
}

bool operator> (Date a, Date b)
{
    if (a.year != b.year)
        return a.year > b.year;
    else if (a.month != b.month)
        return a.month > b.month;
    else if (a.day != b.day)
        return a.day > b.day;

    return false;
}

bool operator< (Date a, Date b)
{
    if (a.year != b.year)
        return a.year < b.year;
    else if (a.month != b.month)
        return a.month < b.month;
    else if (a.day != b.day)
        return a.day < b.day;

    return false;
}
