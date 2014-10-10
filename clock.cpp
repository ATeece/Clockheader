#include "clock.h"

Clock::Clock()
{
	time_t timer;
    struct tm * temp;
    time(&timer);
    temp = localtime(&timer);
    hour = temp->tm_hour;
    min = temp->tm_min;
    sec = temp->tm_sec;
}
Clock::Clock(Clock & c)
{
	hour = c.hour;
	min = c.min;
	sec = c.sec;
}
Clock::Clock(int h, int m, int s)
{
	hour = h;
	min = m;
	sec = s;
}
Clock::Clock(std::string input)
{
    std::stringstream temp;
    int count = 0, tempInt;
    switch (input.length())
    {
        case 8:
            temp.str(input.substr(0,2));
            temp >> tempInt;
            setHour(tempInt);
            temp.clear();
            temp.str(input.substr(3,2));
            temp >> tempInt;
            setMin(tempInt);
            temp.clear();
            temp.str(input.substr(6,2));
            temp >> tempInt;
            setSec(tempInt);
            temp.clear();
            break;
        case 5:
            temp.str(input.substr(0,2));
            temp >> tempInt;
            setHour(tempInt);
            temp.clear();
            temp.str(input.substr(3,2));
            temp >> tempInt;
            setMin(tempInt);
            temp.clear();
            break;
    }
}

Clock::~Clock()
{

}

void Clock::gmt()
{
    time_t timer;
    struct tm * temp;
    time(&timer);
    temp = gmtime(&timer);
    hour = temp->tm_hour;
    min = temp->tm_min;
    sec = temp->tm_sec;
}
void Clock::local()
{
    time_t timer;
    struct tm * temp;
    time(&timer);
    temp = localtime(&timer);
    hour = temp->tm_hour;
    min = temp->tm_min;
    sec = temp->tm_sec;
    }
bool operator==(const Clock a, const Clock b)
{
    if (a.getHour() == b.getHour() && a.getMin() == b.getMin() && a.getSec() == b.getSec())
    {
        return true;
    }
    else {return false;}
}
bool operator!=(const Clock a, const Clock b)
{
    if (a.getHour() == b.getHour() && a.getMin() == b.getMin() && a.getSec() == b.getSec())
    {
        return false;
    }
    else {return true;}
}
Clock operator+(Clock a, const Clock b)
{
    a.setHour(a.getHour() + b.getHour());
    a.setMin(a.getMin() + b.getMin());
    a.setSec(a.getSec() + b.getSec());
    	while(a.getSec() >= 60)
	{
		a.setMin(a.getMin()+1);
		a.setSec(a.getSec()-60);
	}
		while(a.getMin() >= 60)
	{
		a.setHour(a.getHour()+1);
		a.setMin(a.getMin()-60);
	}
	while(a.getHour() >= 24) { a.setHour(a.getHour()-24); }
    return a;
}
Clock operator-(Clock a, const Clock b)
{
    a.setHour(a.getHour() - b.getHour());
    a.setMin(a.getMin() - b.getMin());
    a.setSec(a.getSec() - b.getSec());
    	while(a.getSec() < 0)
	{
		a.setMin(a.getMin()-1);
		a.setSec(a.getSec()+60);
	}
		while(a.getMin() < 0)
	{
		a.setHour(a.getHour()-1);
		a.setMin(a.getMin()+60);
	}
	while(a.getHour() < 0 ) { a.setHour(a.getHour()+24); }
    return a;
}
void Clock::setHour(int hour) {
    this->hour = hour;
}
void Clock::setMin(int minute) {
    this->min = minute;
}
void Clock::setSec(int second) {
    this->sec = second;
}
//Sets calling clock
void Clock::setClock(int hour, int minute, int second) {
    this->hour = hour;
    this->min = minute;
    this->sec = second;
}
void Clock::setClock(std::string input) {
    std::stringstream temp;
    int count = 0, tempInt;
    switch (input.length())
    {
        case 8:
            temp.str(input.substr(0,2));
            temp >> tempInt;
            setHour(tempInt);
            temp.clear();
            temp.str(input.substr(3,2));
            temp >> tempInt;
            setMin(tempInt);
            temp.clear();
            temp.str(input.substr(6,2));
            temp >> tempInt;
            setSec(tempInt);
            temp.clear();
            break;
        case 5:
            temp.str(input.substr(0,2));
            temp >> tempInt;
            setHour(tempInt);
            temp.clear();
            temp.str(input.substr(3,2));
            temp >> tempInt;
            setMin(tempInt);
            temp.clear();
            break;
    }
}
//Sets a named clock
void Clock::setClock(Clock a, int hour, int minute, int second) {
    a.hour = hour;
    a.min = minute;
    a.sec = second;
}
std::ostream& operator<<(std::ostream& out, const Clock& a)
{
   return out << std::setfill('0') <<std::setw(2) << a.getHour() << ':' << std::setw(2) << a.getMin() << ':' << std::setw(2) << a.getSec();
}
