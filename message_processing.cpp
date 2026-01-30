#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    string message = "Welcome to the world of C++ programming!";
    cout << "Original message: " << message << endl;
    // Extract the first word using substr()
    size_t first_space = message.find(' ');
    if (first_space != string::npos){ // If the .find() get the space
        string first_word = message.substr(0, first_space);
        cout <<  "First word: " << first_word << endl;
    }
    // Find and extract the last word using rfind() and substr()
    size_t last_space = message.rfind(' ');
    if (last_space != string::npos){
        string last_word = message.substr(last_space + 1);
        cout << "Last word: " << last_word << endl;
    }
    // Count how many times the letter 'o' appears in the message
    int count_o = 0;
    for (char c: message){
        if (c == 'o') {
            count_o++;
        }
    }
    cout << "Number of 'o': " << count_o << endl;

    //Replace World
    cout << "-------------- Replace World ------------------" << endl;
    string text = "Hello world! The world is beautiful.";
    cout << "Original: " << text << endl;
    // Replace "world" with "universe"
    size_t pos = text.find("world");
    if (pos != string::npos){
        text.replace(pos, 5, "universe");
        cout << "After first replacement: " << text << endl;
    }
    // Replace the second occurrence of "world" with "universe"
    pos = text.find("world", pos + 1);
    if (pos != string::npos) {
        text.replace(pos, 5, "universe");
        cout << "After second replacement: " << text << endl;
    }
    // Remove all exclamation marks
    size_t excl;
    while ((excl = text.find('!')) != string::npos){
        text.erase(excl, 1);
    }
    cout << "After removing '!': " << text << endl;
    // Convert text to uppercase
    for (char &c : text){
        c = toupper(static_cast < unsigned char >(c));
    }
    cout << "Uppercase: " << text << endl;

    // Safety comparison with C-style Strings
    cout << "----------------- Safety comparison -------------------" << endl;
    // C-style string operations
    const char* c_str = "Hello";
    char c_buffer[20];
    strcpy(c_buffer, c_str);
    strcat(c_buffer, " World");
    cout << "C-style result: " << c_buffer << endl;
    cout << "C-style length: " << strlen(c_buffer) << endl;
    // std::string operations
    string cpp_str = "Hello";
    cpp_str += "World";
    cout << "std::string result: " << cpp_str << endl;
    cout << "std::string length: " << cpp_str.length() << endl;

    // Demonstrate safe bounds checking
    cout << "\n--- Bounds checking ---" << endl;
    // C-style string (UNSAFE)
    if (strlen(c_buffer) > 15 ){
        cout << "C-style char at index 15: " << c_buffer[15] << endl;
    } else {
        cout << "C-style: index 15 out of bounds!" << endl;
    }
    // std::string (SAFE)
    try {
        cout << "std::string char at index 15: " << cpp_str.at(15) << endl;
    } catch (const out_of_range& e){
        cout << "std::string: index 15 out of bounds!" << endl;
    }

    // std::string (SAFE)
    try {
        std::cout << "std::string char at index 15: "
                  << cpp_str.at(15) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "std::string: index 15 out of bounds!" << std::endl;
    }

    // Show what happens when concatenating a very long string
    // This would cause buffer overflow — DO NOT RUN
    // strcat(c_buffer, " This is a very long string that will cause overflow");

    //Text analysis function that showcases std::string capabilities
    cout << "--------------- std::string capabilities --------------------" << endl;
    string texts = "The Quick Brown Fox Jumps Over the Laze Dog";
    cout << "Analyzing: " << text << endl;
    // Count words (spaces + 1)
    int word_count = count(texts.begin(), texts.end(), ' ') + 1;
    cout << "World coutn: " << word_count << endl;
    // Count vowels (a, e, i, o, u)
    int vowel_count = 0;
    for (char c: text){
        char lower = tolower(static_cast<unsigned char>(c));
        if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u'){
            vowel_count ++;
        }
    }
    cout << "Vowel count: " << vowel_count << endl;

    // Find the longest word
    size_t start = 0;
    size_t end;
    string longest_word;
    while ((end = texts.find(' ', start)) != string::npos){
        string word = texts.substr(start, end - start);
        if (word.length() > longest_word.length()){
            longest_word = word;
        }
        start = end + 1;
    }
    // Last word
    string last_word = texts.substr(start);
    if (last_word.length() > longest_word.length()){
        longest_word = last_word;
    }
    cout << "Longest word: " << longest_word << endl;

    // Check if text contains all letters of the alphabet (pangram)
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    bool is_pangram = true;
    for (char letter : alphabet){
        bool found = false;
        for (char c: text){
            if (tolower(static_cast<unsigned char>(c)) == letter){
                found = true;
                break;
            }
        }
        if (!found){
            is_pangram = false;
            break;
        }
    }
    cout << "Is pangram: " << (is_pangram ? "Yes" : "No") << endl;

}