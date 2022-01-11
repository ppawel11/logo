#include <gtest/gtest.h>

#include "../../src/Source/StringStream/StringStreamSource.h"
#include "../../src/Source/SourceInterface.h"
#include "../../src/Lexical/Lexer/Lexer.h"
#include "../../src/Parsing/Parser.h"

class parser_test: public ::testing::Test
{
public:
    std::string to_be_parsed;
protected:
    void SetUp() override {
        to_be_parsed =
                "var num_1 = 4;"
                "repeat(num_1){"
                "   forward(100);"
                "   turn(180);"
                "}";
    }

    void TearDown() override {
        // Kod uruchamiany po wykonaniu kodu testu, przed wykonaniem destruktora
    }
};


TEST_F(parser_test, parser_basic_test )
{
    std::istringstream input(to_be_parsed);
    SourceInterface * scanner = new StringStreamSource(input);
    Lexer lexer = Lexer(scanner);
    Parser parser = Parser(lexer);
    Program program = parser.parseProgram();
}
