#include <iostream>
#include <fstream>

int main( int argc, char **argv )
{
	if (argc <=1 )
	{
		std::cerr << "Usage: " << argv[0] << " [infile]" << std::endl;
		return -1;
	}	
	
	// Reading the file
	std::ifstream input(argv[1]);

	if( !input.good() )
	{
		std::cerr << "Some error with open the '" << argv[1] << "'file." << std::endl;
		return -1;
	}

	std::string line, name, content;
	while( std::getline( input, line ).good() )
	{
		if ( line.empty() || line[0] == '>' )
		{
			if ( !name.empty() )
			{
				std::cout << ">" << name << std::endl;
				std::cout << content << std::endl;
				name.clear();
				content.clear();
			}
			if ( !line.empty() )
			{
				if ( line.find(' ') == std::string::npos )
				{
					name = line.substr(1);
				}
				if ( line.find(' ') != std::string::npos )
				{
					name = line.substr(2);
				}
			}
		}
		else if ( !line.empty() and !name.empty() )
		{
				content += line;
		}
	}

	if ( !name.empty() )
	{
		std::cout << ">" << name << std::endl;
		std::cout << content << std::endl;
	}
	return 0;
}
