// Declares input validation and stop-reading helpers.
#ifndef INPUT_HELPERS_H
#define INPUT_HELPERS_H

#include "Stop.h"

#include <string>

int ReadInt(const std::string& prompt);
Stop* ReadStop();

#endif
