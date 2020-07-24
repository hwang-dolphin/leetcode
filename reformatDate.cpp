
#include <iostream>
using namespace std;

#include <vector>
#include <sstream>
#include <map>

string reformatDate(string date)
{
    string dayTemp;
    vector<string> dateVect;
    stringstream ss;
    string temp;
    
    string result;
    
    map<string, string> monthMap;
    
    monthMap.insert(make_pair("Jan", "01"));
    monthMap.insert(make_pair("Feb", "02"));
    monthMap.insert(make_pair("Mar", "03"));
    monthMap.insert(make_pair("Apr", "04"));
    monthMap.insert(make_pair("May", "05"));
    monthMap.insert(make_pair("Jun", "06"));
    monthMap.insert(make_pair("Jul", "07"));
    monthMap.insert(make_pair("Aug", "08"));
    monthMap.insert(make_pair("Sep", "09"));
    monthMap.insert(make_pair("Oct", "10"));
    monthMap.insert(make_pair("Nov", "11"));
    monthMap.insert(make_pair("Dec", "12"));
    
    ss << date;
    
    while (getline(ss, temp, ' '))
    {
        dateVect.push_back(temp);
    }
    
    dayTemp = isdigit(dateVect[0][1]) ? dateVect[0].substr(0, 2) : dateVect[0].substr(0, 1);
    
    if (dayTemp.size() == 1)
    {
        dayTemp.insert(0, "0");
    }
    
    result = dateVect[2] + "-" + monthMap[dateVect[1]] + "-" + dayTemp;
    
    return result;
    
}

int main()
{
    string date = "6th Jun 1933";
    string answer = reformatDate(date);
    
    cout << answer << endl;
    
    return 0;
}



