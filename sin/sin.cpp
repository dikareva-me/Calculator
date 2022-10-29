#include "pch.h"
#include "sin.h"

extern "C" __declspec(dllexport) Wrapper_dllfunc * LoadOperation() {
	command_ptr ptr = std::make_shared<Sin>();
	Wrapper_dllfunc* wrp = new Wrapper_dllfunc{ ptr };

	return wrp;
}
