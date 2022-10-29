#include "pch.h"
#include "cos.h"

extern "C" __declspec(dllexport) Wrapper_dllfunc * LoadOperation() {
	command_ptr ptr = std::make_shared<Cos>();
	Wrapper_dllfunc* wrp = new Wrapper_dllfunc{ ptr };

	return wrp;
}
