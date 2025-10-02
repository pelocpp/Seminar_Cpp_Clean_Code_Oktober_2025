// Pointer / References

#include <print>

void test_pointer_references_01()
{
	// ===========================================
	// Pointer

	int n = 123;

	// C / C++
	int* ip;

	ip = &n;   // Adresse-von

	// Weise der Variablen n den Wert 456 zu
	*ip = 456;  // indirekten Zugriff // Wert-von

	// ACHTUNG: !!!!!!!!!!!!!!!!!!!!!!!!!!
	ip++;

	// =============================================
	// Referenz

	int m = 123;

	int& ri = m;     // Referenz-Variable

	// Weise der Variablen m den Wert 456 zu
	ri = 456;

	// ACHTUNG: !!!!!!!!!!!!!!!!!!!!!!!!!!
	ri++;
}

// WHY ?????????????????????????????????

struct Time
{
	int m_hours;
	int m_minutes;
	int m_seconds;
};

// Variante: KOPIE: Bad
//static void printTime(Time t)
//{
//	std::println("{:02}:{:02}:{:02}", t.m_hours, t.m_minutes, t.m_seconds);
//}

// Variante: Pointer : Ginge
static void printTimePointer (Time* t)
{
	std::println("{:02}:{:02}:{:02}", 
		(*t).m_hours, t->m_minutes, t->m_seconds);
}

// // Variante: Referenz: Ist Optimal // C++ Stylish
static void printTimeReferenz(const Time& t)
{
	// t.m_hours++;  // Falsch // Nicht übersetzungsfähig

	std::println("{:02}:{:02}:{:02}",
		t.m_hours, t.m_minutes, t.m_seconds);
}


void test_pointer_references()
{
	Time now{ 9, 46, 0 };
	printTimeReferenz(now);
}


void test_stack_versus_heap()
{
	Time nowStack{ 9, 46, 0 };   // LIEGt AM STACK
	printTimeReferenz(nowStack);

	Time* nowHeap = new Time { 9, 46, 0 };   // LIEGt AM STACK
	printTimePointer(nowHeap);

	// ...
	delete nowHeap;
}

//
//void test_pointer_a_la_java()
//{
//	Time now;    // Name // Bezeichner // Referenz (4 Bytes)
//
//	now = new Time();
//}