#pragma once

#include <string>

class Object {
public:
	virtual long long GetID() {
		return 1;
	};
	virtual std::string GetName() {
		return "New Object";
	};
};