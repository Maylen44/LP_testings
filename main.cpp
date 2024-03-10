/*


3 Base class with children classes from other branches

class A and class DD
class X and class AA

ok. this one doesnt really work


*/

#include "A.h"
#include "AA.h"
#include "AAA.h"
#include "D.h"
#include "E.h"
#include "DD.h"
#include "X.h"
#include "Z.h"
#include "Y.h"

int main()
{
    A a1(Type_A);
    //A a2;
    AA aa1(Type_AA);
    //AA aa2;
    AAA aaa1;
    //AAA aaa2;

    for (auto& object : a1.m_vector)
    {
        std::cout << "Object in A Vector has enum index: " << object.first << std::endl;
    }
    std::cout << a1.m_vector.size() << std::endl;

    for (auto& object : aa1.m_vector)
    {
        std::cout << "Object in AA Vector has enum index: " << object.first << std::endl;
    }
    std::cout << aa1.m_vector.size() << std::endl;

    for (auto& object : aaa1.m_vector)
    {
        std::cout << "Object in AAA Vector has enum index: " << object.first << std::endl;
    }
    std::cout << aaa1.m_vector.size() << std::endl;

/*
    D d1;
    //D d2;
    E e1;
    //E e2;
    DD dd1;
    //DD dd2;
    X x1;
    //X x2;
    Z z1;
    //Z z2;
    Y y1;
    //Y y2;


*/
    return 0;
}
















































/*
#include "Subject.h"
#include "Observer.h"
#include "Logger.h"

#include <cstdio>


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
    LOG << "Hello World";

    printf();
    return 0;
}

*/



/*
#include "pugixml.hpp"
#include <iostream>
#include <vector>

int main()
{
    pugi::xml_document doc;

    //write to xml file
    pugi::xml_node config = doc.append_child("config");
    config.append_child("setting1").append_child(pugi::node_pcdata).set_value("value1");
    config.append_child("setting2").append_child(pugi::node_pcdata).set_value("value2");

    if (doc.save_file("config.xml")) {
        std::cout << "XML file saved successfully." << std::endl;
    }
    else {
        std::cerr << "Error saving XML file." << std::endl;
    }

    //read to xml file
    if (doc.load_file("config.xml")) {
        std::cout << "XML file loaded successfully." << std::endl;

        pugi::xml_node config = doc.child("config");
        for (pugi::xml_node setting = config.first_child(); setting; setting = setting.next_sibling()) {
            std::cout << setting.name() << ": " << setting.child_value() << std::endl;
        }
    }
    else {
        std::cerr << "Error loading XML file." << std::endl;
    }

    return 0;
}
*/









    //Method to write variables to xml
/*
#include "pugixml.hpp"
#include <SFML/System.hpp>
#include <iostream>

int main()
{
    // Define your variables
    sf::Vector2f WINDOW_RESOLUTION{ 800.f, 600.f };
    sf::Time TIME_RATE_001S{ sf::seconds(0.01f) };
    sf::Time TIME_RATE_05S{ sf::seconds(0.5f) };
    sf::Time TIME_RATE_075S{ sf::seconds(0.75f) };
    sf::Time TIME_RATE_1S{ sf::seconds(1.0f) };
    sf::Time TIME_RATE_3S{ sf::seconds(3.0f) };
    sf::Time TIME_RATE_7S{ sf::seconds(7.0f) };
    float VOLUME_SFX{ 100.0f };
    float VOLUME_MUSIC{ 100.0f };

    // Create XML document
    pugi::xml_document doc;
    pugi::xml_node root = doc.append_child("settings");

    // Add variables to the XML document
    root.append_child("window_resolution")
        .append_attribute("x") = WINDOW_RESOLUTION.x;
    root.child("window_resolution")
        .append_attribute("y") = WINDOW_RESOLUTION.y;

    root.append_child("time_rates")
        .append_child("rate")
        .append_attribute("value") = TIME_RATE_001S.asSeconds();
    root.child("time_rates")
        .append_child("rate")
        .append_attribute("value") = TIME_RATE_05S.asSeconds();
    root.child("time_rates")
        .append_child("rate")
        .append_attribute("value") = TIME_RATE_075S.asSeconds();
    root.child("time_rates")
        .append_child("rate")
        .append_attribute("value") = TIME_RATE_1S.asSeconds();
    root.child("time_rates")
        .append_child("rate")
        .append_attribute("value") = TIME_RATE_3S.asSeconds();
    root.child("time_rates")
        .append_child("rate")
        .append_attribute("value") = TIME_RATE_7S.asSeconds();

    root.append_child("volume")
        .append_child("sfx")
        .append_attribute("value") = VOLUME_SFX;
    root.child("volume")
        .append_child("music")
        .append_attribute("value") = VOLUME_MUSIC;

    // Save the XML document
    if (doc.save_file("config.xml")) {
        std::cout << "XML file saved successfully." << std::endl;
    }
    else {
        std::cerr << "Error saving XML file." << std::endl;
    }

    return 0;

}
*/

    /*
    //method to read from document with variables
    #include "pugixml.hpp"
#include <SFML/System.hpp>
#include <iostream>

int main() {
    pugi::xml_document doc;
    if (doc.load_file("config.xml")) {
        std::cout << "XML file loaded successfully." << std::endl;

        pugi::xml_node settings = doc.child("settings");

        // Read variables from XML
        sf::Vector2f WINDOW_RESOLUTION{
            settings.child("window_resolution").attribute("x").as_float(),
            settings.child("window_resolution").attribute("y").as_float()};

        float VOLUME_SFX = settings.child("volume").child("sfx").attribute("value").as_float();
        float VOLUME_MUSIC = settings.child("volume").child("music").attribute("value").as_float();

        // Output read variables
        std::cout << "Window Resolution: " << WINDOW_RESOLUTION.x << ", " << WINDOW_RESOLUTION.y << std::endl;
        std::cout << "SFX Volume: " << VOLUME_SFX << std::endl;
        std::cout << "Music Volume: " << VOLUME_MUSIC << std::endl;
    } else {
        std::cerr << "Error loading XML file." << std::endl;
    }

    return 0;
}
    */
    


//reading values from xml and writing them in to new variables. important is the syntax of extracting the values from xml 
//and converting into the type that is needed
/*
#include "pugixml.hpp"
#include <SFML/System.hpp>
#include <iostream>

int main() {
    pugi::xml_document doc;
    if (doc.load_file("config.xml")) {
        std::cout << "XML file loaded successfully." << std::endl;

        pugi::xml_node settings = doc.child("settings");

        // Read variables from XML
        int x = settings.child("window_resolution").attribute("x").as_int();
        int y = settings.child("window_resolution").attribute("y").as_int();

        // Output read variables
        std::cout << "Window Resolution: " << x << ", " << y << std::endl;
    } else {
        std::cerr << "Error loading XML file." << std::endl;
    }

    return 0;
}
*/


//this is the method to add variables to the xml file
/*

#include "pugixml.hpp"
#include <SFML/System.hpp>
#include <iostream>

int main() {
    // Define your variables
    int x = 800;
    int y = 600;

    // Create XML document
    pugi::xml_document doc;
    pugi::xml_node root = doc.append_child("settings");

    // Add variables to the XML document
    root.append_child("window_resolution")
        .append_attribute("x") = x;
    root.child("window_resolution")
        .append_attribute("y") = y;

    // Save the XML document
    if (doc.save_file("config.xml")) {
        std::cout << "XML file saved successfully." << std::endl;
    } else {
        std::cerr << "Error saving XML file." << std::endl;
    }

    return 0;
}
*/

//this method overrides specific value inside of the xml file, without overriding the whole xml file anew.
/*
#include "pugixml.hpp"
#include <iostream>

int main() {
    pugi::xml_document doc;
    if (doc.load_file("config.xml")) {
        std::cout << "XML file loaded successfully." << std::endl;

        // Find and update the value of WindowResolution.x
        pugi::xml_node windowResolutionNode = doc.select_node("/settings/window_resolution").node();
        if (windowResolutionNode) {
            int newValue = 2000; // New value for WindowResolution.x
            windowResolutionNode.attribute("x").set_value(newValue);
            std::cout << "Value of WindowResolution.x updated to: " << newValue << std::endl;

            // Save the modified XML file
            if (doc.save_file("config.xml")) {
                std::cout << "XML file saved successfully." << std::endl;
            } else {
                std::cerr << "Error saving XML file." << std::endl;
            }
        } else {
            std::cerr << "Node 'window_resolution' not found in XML file." << std::endl;
        }
    } else {
        std::cerr << "Error loading XML file." << std::endl;
    }

    return 0;
}
*/