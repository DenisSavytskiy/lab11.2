#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include "../AP_Lab№11.2/AP_Lab№11.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace WordCounterUnitTest
{
    TEST_CLASS(WordCounterTest)
    {
    public:
        TEST_METHOD(TestEmptyFile)
        {
            // Create an empty test file
            ofstream emptyFile("empty_test.txt");
            emptyFile.close();

            int result = CountWordsInFile("empty_test.txt");
            Assert::AreEqual(0, result);
        }

        TEST_METHOD(TestSingleLineFile)
        {
            // Create a file with a single line
            ofstream testFile("single_line_test.txt");
            testFile << "Hello world how are you" << endl;
            testFile.close();

            int result = CountWordsInFile("single_line_test.txt");
            Assert::AreEqual(5, result);
        }

        TEST_METHOD(TestMultiLineFile)
        {
            // Create a multi-line test file
            ofstream testFile("multi_line_test.txt");
            testFile << "Hello world" << endl;
            testFile << "How are you today" << endl;
            testFile.close();

            int result = CountWordsInFile("multi_line_test.txt");
            Assert::AreEqual(6, result);
        }

        TEST_METHOD(TestFileWithExtraSpaces)
        {
            // Create a file with extra spaces
            ofstream testFile("extra_spaces_test.txt");
            testFile << "  Hello   world   how   are   you  " << endl;
            testFile.close();

            int result = CountWordsInFile("extra_spaces_test.txt");
            Assert::AreEqual(5, result);
        }
	};
}