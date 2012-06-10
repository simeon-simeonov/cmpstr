/*
 * =====================================================================================
 *
 *       Filename:  cmpstr.cc
 *
 *    Description:  A program for comparing strings
 *
 *        Version:  1.0
 *        Created:  28/05/12 23:03:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Simeon Simeonov 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstdlib>
#include <map>
#include <string>

using namespace std;

const char program_name[] = "cmpstr";

void usage ()
{
  cout << "\n"
       << "    This program compares 2 or more strings given to it on the command line.\n"
       << "    Usage is:\n\n"
       << "        " << program_name << " <string1> <string2> ... <stringN>\n\n"
       << "    Output is in the following format:\n\n"
       << "        ==============================\n"
       << "        \"string i\"\n"
       << "        (number of occurences)\n" 
       << "        ==============================\n"
       << "        \"string i+1\"\n"
       << "        (number of occurences)\n" 
       << endl;

  exit (EXIT_FAILURE);
}

int main(int argc, const char *argv[])
{
    if(argc < 3)
        usage();
    else if(argc == 3)
    {
        string str1 = argv[1];
        string str2 = argv[2];

        if(str1 == str2)
            cout << "\nStrings are the same\n" << endl;
        else
            cout << "\nStrings are different\n" << endl;
    }
    else
    {
        map<string, int> strings;
        map<string, int>::iterator it;

        for(int i = 1; i < argc; i++)
        {
            it = strings.find(argv[i]);

            if(it == strings.end())
                strings.insert(pair<string, int>(argv[i], 1));
            else
                it->second++;
        }

        for(it = strings.begin(); it != strings.end(); it++)
        {
            cout << "==============================\n" 
                << "\"" << it->first << "\"" << "\n" 
                << "(" << it->second << ")" << endl;
        }
    }
    return 0;
}
