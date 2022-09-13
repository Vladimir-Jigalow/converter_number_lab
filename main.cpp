#include <iostream>
#include <cmath>
#include <string>


using std::cin;
using std::cout;
using std::endl;
using std::string;


uint64_t binToDec(const string& bin_array);
string decToBin(uint64_t decimal);


int main()
{
    int answer;
    cout << "1) Enter decimal number and convert to binary.\n"
        << "2) Enter binary number and convert to decimal.\n: ";
    cin >> answer;
    if (answer == 1)
    {
        cout << "Enter a decimal number: ";
        uint64_t decimal_number;
        cin >> decimal_number;
        cout << decToBin(decimal_number);
    }
    else if (answer == 2)
    {
        cout << "Enter a decimal number: ";
        string binary_number;
        cin >> binary_number;
        cout << binToDec(binary_number);
    }
    cin.get();
    return 0;
}


uint64_t binToDec(const string& bin_array)
{
    uint64_t answer = 0;
    cout << bin_array << " = " ;
    for (int i = bin_array.size() - 1; i >= 0; --i)
    {
        if (bin_array[i] == '1')
        {
            cout << "1*2^" << i + 1;
            answer += pow(2, bin_array.size() - i - 1);
        }
        else
        {
            cout << "0*2^" << i + 1;
        }
        if (i != 0)
        {
            cout << " + ";
        }
    }
    cout << " = "<< answer << endl;
    return answer;
}


string decToBin(uint64_t decimal)
{
    string binary_array;
    while(decimal != 0)
    {
        cout << decimal << " / 2 = " << decimal / 2 << "\t";
        cout << decimal << " % 2 = " << decimal % 2 << "\n";
        binary_array += std::to_string(decimal % 2);
        decimal /= 2;
    }
    return string(binary_array.rbegin(), binary_array.rend());
}
