#pragma once
#include "domain.h"
#include "dynamic_vector.h"
#include "repository.h"
#include "service.h"

class Tests {
public:
	static void testsDynamicVector();
	static void testTrenchCoats();
	static void testRepository();
	static void testService();
	static void testAll();
};