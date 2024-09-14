#include <iostream>
#include <string>
#include <map>


int main()
{
    std::map<std::string, std::string> phones;    // Карта для хранения телефонов
    std::map<std::string, std::string> surNames;  // Карта для хранения фамилий
    std::string command;

    std::cout << "Please input a phone number + surname to add, surname to find phone, "
        "phone to find surname or q to finish program: " << std::endl;

    while (std::getline(std::cin, command) && command != "q") {
        size_t spaceR = command.find(' ');

        if (spaceR != std::string::npos) {
            std::string phone = command.substr(0, spaceR);
            std::string surName = command.substr(spaceR + 1);


            phones[phone] = surName;
            surNames[surName] = phone;

            std::cout << "Added: " << phone << " -> " << surName << std::endl;
        }
        else if (phones.find(command) != phones.end()) {
            std::cout << "Surname: " << phones[command] << std::endl;
        }
        else if (surNames.find(command) != surNames.end()) {
            std::cout << "Phone: " << surNames[command] << std::endl;
        }
        else {
            std::cout << "Not found" << std::endl;  // Если ничего не найдено
        }
    }

    return 0;
}
