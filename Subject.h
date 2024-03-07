#ifndef SUBJECT_H
#define SUBJECT_H

#include "ISubject.h"
#include <list>

class Subject : public ISubject
{
public:
	virtual ~Subject() {};
	void Attach(IObserver* observer) override;
	void Detach(IObserver* observer) override;
	void Notify() override;
	void CreateMessage(std::string message = "Empty");
	void HowManyObserver();

private:
	std::list<IObserver*> m_listObserver;
	std::string m_message;
};
#endif //SUBJECT_H