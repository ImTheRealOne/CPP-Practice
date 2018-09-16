#include "stdafx.h"
#include "Context.h"


Context::Context()
{
	map = new std::map<char *, int>();
}


Context::~Context()
{
	delete map;
}

int Context::Lookup( char* value) const {
	return map->at(value);
}

void Context::Assign(VariableExp * exp, int value) {
	
	map->insert(std::pair<char *, int>(exp->getName(),value));

}


