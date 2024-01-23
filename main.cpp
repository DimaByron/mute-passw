#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void    create_name(string str, ofstream &f_name)
{
    int     i = 0;
    while (str[i] != ':')
    {
        f_name << str[i];
        i++;
    }
    f_name << endl;
}

void    create_pass(string str, ofstream &f_pass)
{
    int i = 0;
    while (str[i] != ':')
        i++;
    i++;
    while (str[i])
    {
        f_pass << str[i];
        i++;
    }
    f_pass << endl;
}

void    create_mute(string str, ofstream &f_mute)
{
    int i = 0;
    while (str[i] != ':')
        i++;
    i++;
    f_mute << str[i];
    while (i < (str.length() - 2))
    {
        str[i] = '*';
        f_mute << str[i];
        i++;
    }
    str[i] = str[(str.length() - 1)];
    f_mute << str[i];
    f_mute << endl;
}

int main(int ac, char** av)
{
    string  str;
    ifstream    f_in(av[1]);
    ofstream    f_name("name.txt");
    ofstream    f_pass("pass.txt");
    ofstream    f_mute("mute.txt");
    if (!f_in)
    {
        cout << "Error file name" << endl;
        return 0;
    }
    if (!f_name || !f_pass || !f_mute)
    {
        cout << "Error file create" << endl;
        return 0;
    }
    while (getline(f_in, str))
    {
        create_name(str, f_name);
        create_pass(str, f_pass);
        create_mute(str, f_mute);
        str.clear();
    }
    f_in.close();
    f_name.close();
    f_pass.close();
    f_mute.close();
    return 0;
}