#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char name[100];
    cout << "Enter the sentence: ";
    gets(name);  

    cout << name << endl;   

    int vowels = 0;
    int words = 0;
    int spaces = 0;
    int occurance = 0;

    int span = strlen(name) - 1; 
    int count = 0;

    while (span >= 0 && name[span] == ' ') {
        count++;
        span--;
    }
    
    int index = 0;
    int start = 0;

    while (index < strlen(name) && name[index] == ' ') {
        start++;
        index++;
    }

    int len = strlen(name) - count;
    int i = 0;

    while (len != 0 && i < len) {

        if (name[i] == ' ') {
            spaces++;

            if (i > 0 && name[i - 1] != ' ') {
                words++;
            }
            
        }
        
        if (name[i] == 'a' || name[i] == 'e' || name[i] == 'i' || name[i] == 'o' || name[i] == 'u') vowels++;
        
        i++;
    }

    if (len > 0 && name[len - 1] != ' ') {
        words++;
    }

    cout << "Vowels are: " << vowels << endl;
    cout << "Words are: " << words << endl;
    cout << "Spaces are: " << spaces + count << endl;

    return 0;
}
