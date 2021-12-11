#include <regex>
#include <map>

std::string derivative(std::string polynomial) {
	std::map<int, int> degreeToCoef;
	std::smatch match;
	std::regex polynomial_element(R"((\-?\d*)\*?x\^?(\d*))");
	while (std::regex_search(polynomial, match, polynomial_element)) {
		int coef = (match[1] == "" || match[1] == "-") ? std::stoi(match[1].str() + "1") : std::stoi(match[1]);
		int degree = (match[2] == "") ? 1 : std::stoi(match[2]);
		//std::cout << coef << " " << degree << std::endl;
		if (degreeToCoef.find(degree) == degreeToCoef.end())
			degreeToCoef.insert(std::make_pair(degree, coef));
		else degreeToCoef.at(degree) += coef;


		polynomial = match.suffix().str();
	}

	std::string res = "";
	
	for (auto element = degreeToCoef.rbegin(); element != degreeToCoef.rend(); ++element) {
		int degree = (*element).first;
		int coef = (*element).second;
		std::string plus = (coef >= 0 && !res.empty()) ? "+" : "";
		
		if (coef == 0)
			continue;
		else if (degree == 1)
			res += plus + std::to_string(coef);
		else {
			std::string make_degree = (degree == 2) ? "" : "^" + std::to_string(degree - 1);
			res += plus + std::to_string(degree * coef) + "*x" + make_degree;
		}
	}
	return res;
}

