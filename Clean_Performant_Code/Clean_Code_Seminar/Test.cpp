#include <string>

class MyTime
{
public:
	int m_hours;
	int m_minutes;
	int m_seconds;
	//int* m_data;
	std::string m_description;

	// user-defined c'tor
	MyTime(int hours, int minutes, int seconds)
		: m_hours(hours), m_minutes(minutes), m_seconds(seconds)
	{ }

	//MyTime() = default;
	//MyTime() {}

	// def c'tor
	MyTime(): m_hours(0), m_minutes(0), m_seconds(0)
	{
	}

	void print();
};


void test_lifecycle()
{
	MyTime t;

	MyTime t2(1, 1, 1);

	MyTime t3(t2);

	t = t2;
}