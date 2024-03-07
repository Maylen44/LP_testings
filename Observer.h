#ifndef OBSERVER_H
#define OBSERVER_H

#include "IObserver.h"
#include "Subject.h"

class Observer : public IObserver
{
public:
	Observer(Subject& subject);
	virtual ~Observer();
	void Update(const std::string& message_from_subject) override;
	void RemoveMeFromTheList();
	void PrintInfo();

private:
	Subject& m_subject;
	std::string m_messageFromSubject;
	int m_number;

};

//TODO: question about static variables overall: what is the diference of using
// a static variable inside of the class other then just having a static
// variable outside of the class in the class files? 
static int s_numberOfObservers;

#endif //OBSERVER_H