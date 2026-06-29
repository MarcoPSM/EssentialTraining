/*
Logic IPuzzle
*/

#include <unordered_set>
#include <iostream>
class LogicIPpuzzle {
  public:
    int rowOfPosition(int pos, int numColumns) {
        return pos / numColumns + 1;
    }

    int columnOfPosition(int pos, int numColumns) {
        return pos % numColumns + 1;
    }

    bool isIntFactor(int number, int factor) {
        return number % factor == 0;
    }

    int getIntFactor(int number, int factor) {
        return number / factor;
    }

    int sumDigits(std::string s) {
        int sum = 0;
        for (char c : s) {
            if (isdigit(c)) {
                sum += c - '0';
            }
        }
        sum = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                sum += s[i] - '0';
            }
        }
        return sum;
    }

    int countCharOccurrence(std::string s, char c) {
        int sum = 0;
        for(int i = 0; i < s.size(); i++) {
	        if(s[i] == c) {
		        sum++;
	        }
	    }
        return sum;
    }

    int countDigitOccurrence(std::string s, int d) {
        int sum = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= '0' && s[i] <= '9' && s[i] == static_cast<char>('0' + d)) {
                sum++;
            }
        }
        return sum;
    }

    bool hasDigit(std::string s) {
        for( char c : s) {
            if(c >= '0' && c <= '9') {
                return true;
            }
        }
        return false;
    }            

    bool isFillingChar(char c) {
        return c == 'P' || (c>='1' && c<='9');
    }

    bool isValidPuzzleInConstruction(const std::string& spc) {
        if (spc.empty()) {
            return false;
        }
        for( char c : spc) {
            if (c != '.' && !isFillingChar(c)) {
                return false;
            }
        }
        return true;
    }

    bool isFilled(const std::string& spc) {
        return spc.find('.') != std::string::npos;
    }

    bool isPuzzle(const int& rows, const int& cols, const std::string& spc) {
        if(spc.size() != rows * cols) {
            return false;
        }
        std::unordered_set<char> clues;

        for(char c : spc) {
            if(c >= '1' && c <= '9') {
                auto [it, inserted] = clues.insert(c);
                if(!inserted) {
                    return false;
                }
            }
        }

        return true;
    }

};

int main() {
    int pos = 4;
    int numColumns = 4;
    LogicIPpuzzle puzzle;
    std::cout << "Position " << pos << " in a grid with " << numColumns
              << " columns is at row " << puzzle.rowOfPosition(pos, numColumns)
              << " and column " << puzzle.columnOfPosition(pos, numColumns)
              << std::endl;

    std::string s = "a1b2c3c";
    std::cout << "Sum of digits in string \"" << s << "\" is "
              << puzzle.sumDigits(s) << std::endl;
    std::cout << "Char c appears " << puzzle.countCharOccurrence(s, 'c') << " times!" << std::endl;
    
    std::cout << puzzle.countDigitOccurrence("a103330b", 3) << "\n";
    std::cout << (puzzle.hasDigit("asd1qwe") ? "True" : "False") << std::endl;
    std::cout << "P is a fill char " << (puzzle.isFillingChar('P') ? "True" : "False") << std::endl;
    std::string spc;
    std::cout << "Espero False: " << (puzzle.isValidPuzzleInConstruction(spc) ? "True" : "False") << std::endl;
    spc = ". P";
    std::cout << "Espero False: " << (puzzle.isValidPuzzleInConstruction(spc) ? "True" : "False") << std::endl;
    spc = ".1P";
    std::cout << "Espero True: " << (puzzle.isValidPuzzleInConstruction(spc) ? "True" : "False") << std::endl;

    return 0;
    
}
