#include "Subject.h"
#include "Observer.h"
#include "Logger.h"


void ClientCode()
{
    Subject* subject = new Subject;
    Observer* observer1 = new Observer(*subject);
    Observer* observer2 = new Observer(*subject);

    subject->Attach(observer1);
    subject->Attach(observer2);

    subject->CreateMessage("The weather is hot today! :p");
    subject->CreateMessage("My new car is great! ;)");

    observer1->RemoveMeFromTheList();
    observer2->RemoveMeFromTheList();

    delete observer2;
    delete observer1;
    delete subject;
}

void runLogger()
{
    std::string message1 = "logg message 1 ...";
    std::string message2 = "logg message 2 ...";
    int nNum = 10;
    Logger::GetLogger()->Log("message to be logged");
    Logger::GetLogger()->Log(message1);

    //TODO: this arguments flow is somewhat confusing.
    LOGGER->Log(" Message is:%s Number is:%d", message2.c_str(), nNum);
}

int main(int argc, char* argv[])
{
    ClientCode();
    runLogger();
    return 0;
}






/*
#include <iostream>
#include "tinyxml2.h"

using namespace tinyxml2;

int main() {
    XMLDocument doc; // Create a TinyXML document object

    if (doc.LoadFile("config.xml")) { // Load the XML file
        XMLElement* root = doc.FirstChildElement("config"); // Get the root element

        if (root) {
            int age;
            if (root->QueryIntAttribute("age", &age) == XML_SUCCESS) { // Read the age attribute
                std::cout << "Age: " << age << std::endl; // Print the age
            }
            else {
                std::cerr << "Failed to read age attribute." << std::endl;
            }
        }
        else {
            std::cerr << "No 'config' element found." << std::endl;
        }
    }
    else {
        std::cerr << "Failed to load XML file." << std::endl;
    }

    return 0;
}
*/
