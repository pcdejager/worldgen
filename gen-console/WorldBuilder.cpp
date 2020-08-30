#include "pch.h"
#include "WorldBuilder.h"
#include "Types.h"
#include "Logger.h"

void WorldBuilder::Run()
{
    LoggerPtr logger = Logger::GetLogger();
    logger->Log(L"Starting world generation:");
}