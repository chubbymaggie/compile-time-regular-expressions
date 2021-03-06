#include <ctre.hpp>
#include <cstdio>
#include <string_view>
#include <iostream>


void match(std::string_view subject) {
	using namespace ctre::literals;
	
	if (auto [matched, inner] = "^([0-9]+?[a-z]++)+"_ctre.match(subject); matched) {
		std::cout << "matched = " << matched.to_view() << "\n";
		if (inner) {
			std::cout << "  inner = " << inner.to_view() << "\n";
		}
	}
}

int main() {
	using namespace std::string_view_literals;
	match("123abc456def"sv);
	
	auto input = "123,456,768"sv;
	
	using namespace ctre::literals;
	for (auto match: ctre::range(input,"[0-9]++"_ctre)) {
		std::cout << std::string_view{match} << "\n";
	}
	
}