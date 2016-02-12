// easyMakefile: Makes Makefiles Easy - v01
// easyMakefile.v01.cpp
// SUMNER, BR.
// UCD SPRING 2016

#include <iostream>
#include <fstream>
#include <string>

using std::endl;
using std::cout;
using std::cin;


int main()
{
    std::string fileName;

    cout
        << endl << endl
        << "[easyMakefile: Makes Makefiles Easy]" << endl << endl << endl
        << "[NOTE: ALL SOURCE FILES SHOULD END WITH .cpp]" << endl
        << "[ENTER FILENAME FOR THE TARGET EXECUTABLE>  ";

    cin >> fileName;

    std::ofstream Makefile;
    Makefile.open("Makefile");

    if (!Makefile.fail())
    {
        Makefile
            << "# TAKEN FROM http://www.puxan.com/web/blog/HowTo-Write-Generic-Makefiles" << endl << endl

            << "# Declaration of variables" << endl
            << "CC = g++" << endl
            << "CC_FLAGS = -w" << endl << endl

            << "# File names" << endl
            << "EXEC = " << fileName << endl
            << "SOURCES = $(wildcard *.cpp)" << endl
            << "OBJECTS = $(SOURCES:.cpp=.o)" << endl << endl

            << "# Main target" << endl
            << "$(EXEC): $(OBJECTS)" << endl
            << "\t$(CC) $(OBJECTS) -o $(EXEC)" << endl << endl

            << "# To obtain object files" << endl
            << "%.o: %.cpp" << endl
            << "\t$(CC) -c $(CC_FLAGS) $< -o $@" << endl << endl

            << "# To remove generated files" << endl
            << "clean:" << endl
            << "\trm -f $(EXEC) $(OBJECTS)" << endl;

            cout << endl << endl << "[MAKEFILE BUILT SUCCESSFULLY]" << endl << endl << endl;
    }

    cout
        << "[NOTE: IF YOU MODIFY HEADERS, YOU SHOULD \"make clean\" BEFORE YOU \"make\"]" << endl
        << "[SEE: http://www.puxan.com/web/blog/HowTo-Write-Generic-Makefiles]" << endl << endl;

    Makefile.close();
    return 0;

}



