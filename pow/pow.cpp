#include "pch.h"
#include "pow.h"

extern "C" __declspec(dllexport) Wrapper_dllfunc* LoadOperation() {
	command_ptr ptr = std::make_shared<Pow>();
	Wrapper_dllfunc* wrp = new Wrapper_dllfunc{ ptr };
	
	return wrp;
}
