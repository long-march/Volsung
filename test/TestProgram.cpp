
#include <iostream>
#include <fstream>
#include <array>

#include "Volsung.hh"

using namespace Volsung;

int main(int argc, char ** argv)
{
	Program prog;

	prog.configure_io(1, 1);

	debug_callback = [] (std::string message) { std::cout << message; };

	uint time = 10;
	bool print = false;
	Program::add_directive("config", [&time, &print] (std::vector<TypedValue> arguments, Program*) {
		time = arguments[0].get_value<float>();
		if (arguments.size() > 1) print = (bool) arguments[1].get_value<float>();
	});

	std::string code =
R"(

osc~ 440 -> output

&config 4, 1

)";

	Parser parser;
	parser.source_code = code;
	parser.parse_program(prog);
	log("Finished parsing");

	if (print) for (uint n = 0; n < time; n++) std::cout << prog.run(0.f) << '\n';
	else for (uint n = 0; n < time; n++) prog.run(0.f);
	prog.finish();
}

