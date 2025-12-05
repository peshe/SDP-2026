#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <charconv>
#include <stdexcept>
#include <filesystem>

class Tree
{
	int value;
	std::vector<Tree*> children;

	static void trimLeft(std::string_view& sv, std::size_t trim_cnt = 0)
	{
		sv.remove_prefix(trim_cnt);
		sv.remove_prefix(std::min(sv.find_first_not_of(' '), sv.size()));
	}
	static void requireCharAndTrim(char expected, std::string_view& sv)
	{
		if(sv.empty() || sv[0] != expected)
			throw std::invalid_argument("bad tree representation: " + std::string{expected} + " expected");
		trimLeft(sv, 1);
	}

	Tree(std::string_view& sv)
	{
		try
		{
			trimLeft(sv);
			requireCharAndTrim('(', sv);
			auto [number_end, ec] = std::from_chars(sv.begin(), sv.end(), value);
			if(ec != std::errc{})
				throw std::invalid_argument("bad tree representation: number expected");
			trimLeft(sv, number_end - sv.data());
			requireCharAndTrim('(', sv);
			bool subtrees_present = !sv.empty() && sv[0] != ')';
			while(subtrees_present)
			{
				children.push_back(new Tree(sv));
				subtrees_present = !sv.empty() && sv[0] == ',';
				if(subtrees_present) requireCharAndTrim(',', sv);
			}
			requireCharAndTrim(')', sv);
			requireCharAndTrim(')', sv);
		}
		catch(...) {
			clear();
			throw;
		}
	}

	Tree(const std::string& s, std::string_view sv) try: Tree(sv)
	{
		if(!sv.empty())
			throw std::invalid_argument("bad tree representation: unexpected chars after end");
	}
	catch(const std::exception& e)
	{
		throw std::invalid_argument(e.what() + std::string{'\n'} + s + '\n' +
			std::string(sv.data() - s.data(), '-') + '^' +
			std::string(sv.size() - 1 + sv.empty(), '-'));
	}
public:
	Tree(const std::string& s): Tree(s, s) {}
	Tree(const Tree&) = delete;
	Tree& operator=(const Tree&) = delete;
	~Tree() { clear(); }

	void clear() noexcept
	{
		for(Tree* child : children)
			delete child;
		children.clear();
	}

	int maxPathSum() const noexcept
	{
		if(children.empty())
			return value;
		int max = children[0]->maxPathSum();
		for(std::size_t i = 1; i < children.size(); i++)
		{
			int sum = children[i]->maxPathSum();
			if(max < sum)
				max = sum;
		}
		return value + max;
	}

	static Tree readFromFile(const char* filename)
	{
		std::ifstream ifs(filename);
		if(!ifs) throw std::runtime_error("could not open the file " + std::string(filename));
		std::string line;
		std::getline(ifs, line);
		return Tree{line};
	}
};

int solve(const char* filename)
{
	Tree t = Tree::readFromFile(filename);
	return t.maxPathSum();
}

int main()
{
	using namespace std::filesystem;
	try {
		for(const std::filesystem::directory_entry& entry : directory_iterator{"test-files"})
			if(entry.is_regular_file()) try
			{
				std::cout << "solving for " << entry.path().c_str() << '\n';
				std::cout << solve(entry.path().c_str()) << '\n';
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}
