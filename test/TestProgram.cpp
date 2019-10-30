
#include <iostream>
#include <fstream>
#include <array>

#include "../include/YggdrasilCore.h"
#include "Parser.h"

using namespace Yggdrasil;

int main(int argc, char ** argv)
{
	Program prog;

	prog.configure_io(1, 1);
	
	debug_callback = [] (std::string message) { std::cout << message; };

	std::string code =
R"(

source: square~ 2000, 0.7
source{0} -> output{0}

)";
	
	//prog.make_graph(std::stringstream(code));
	//for (uint n = 0; n < 100; n++) std::cout << prog.run(n) << '\n';

	Parser parser;
	parser.source_code = code;
	parser.parse_program(prog);

	for (uint n = 0; n < 100; n++) std::cout << prog.run(n) << '\n';
	prog.finish();
}

