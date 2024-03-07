#include "Subject.h"
#include "Logger.h"

void Subject::Attach(IObserver* observer)
{
	m_listObserver.push_back(observer);
}

void Subject::Detach(IObserver* observer)
{
	m_listObserver.remove(observer);
}

//TODO: question about iterators: what are they, syntax and usage instead of 
//other means
void Subject::Notify()
{
	std::list<IObserver*>::iterator iterator = m_listObserver.begin();
	HowManyObserver();
	while (iterator != m_listObserver.end())
	{
		(*iterator)->Update(m_message);
		++iterator;
	}
}

void Subject::CreateMessage(std::string message)
{
	m_message = message;
	LOGGER->Log("Message from Subject: " + message);
	Notify();
}

void Subject::HowManyObserver()
{
	//Logger::GetLogger()->Log(" There are: " + m_listObserver.size());
}