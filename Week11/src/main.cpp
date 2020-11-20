/**
* @file main.cpp
* @brief  Week 11, External Libraries
*
* @author Zachary Schwab
* @assignment 11.1
* @date 11/19/2020
* @credits https://theboostcpplibraries.com/boost.tokenizer
* @credits https://theboostcpplibraries.com/boost.program_options
* 
*/

#include <boost/tokenizer.hpp>
#include <boost/program_options.hpp>
#include <iostream>
#include <fstream>

using namespace boost::program_options;

int main(int argc, const char *argv[])
{
    typedef boost::tokenizer<boost::char_separator<char>> tokenizer;


    std::string fileName = "";
    try
    {
        options_description desc{"Options"};
        desc.add_options()
        ("help,h", "Help screen")
        ("file", value<std::string>()->default_value("outFile"), "File");

        variables_map vm;
        store(parse_command_line(argc, argv, desc), vm);
        notify(vm);
        if(vm.count("file"))
        {
            fileName = vm["file"].as<std::string>();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    fileName += ".xml";
    std::ofstream outFile;
    outFile.open(fileName);

    std::string input;
    getline(std::cin, input);
    if(outFile)
    {
        outFile << "<sentence> \n";
        tokenizer tok{input};
        //iterate through the tokenizer to grab the individual words
        for (tokenizer::iterator it = tok.begin(); it != tok.end(); ++it)
            outFile << "\t<word>" << *it << "</word>" << '\n';
        outFile << "</sentence>";
    }
    outFile.close();
    return 0;
}