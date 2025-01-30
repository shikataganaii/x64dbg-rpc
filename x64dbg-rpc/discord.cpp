#include "pch.h"
#include "plugin.h"
#include "shlwapi.h"
#include "discord-rpc/discord_rpc.h"
#include <filesystem>
#include <chrono>
#include <format> 
// why?? cuz i felt like it
#ifdef _WIN64
const char* gApplicationId = "1334107855887794269";
#else 
const char* gApplicationId = "1334642088800944168";
#endif
static int64_t gEptime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
DiscordRichPresence* gDiscordRichPresence = new DiscordRichPresence();

void initializeRPC()
{
    DiscordEventHandlers handle;
    memset(&handle, 0, sizeof(handle));
    gDiscordRichPresence->state = "Idling";
    gDiscordRichPresence->largeImageKey = "x64dbg";
    gDiscordRichPresence->startTimestamp = gEptime;
    Discord_Initialize(gApplicationId, &handle, 1, 0);
    Discord_UpdatePresence(gDiscordRichPresence);
}

void updateRPC(PLUG_CB_INITDEBUG* initDbg)
{
    // hacky
    std::string filename = std::filesystem::path(initDbg->szFileName).filename().string();
    static std::string formattedState = std::format("Debugging {}", filename);
    gDiscordRichPresence->state = formattedState.c_str();
    Discord_UpdatePresence(gDiscordRichPresence);
}

void resetRPC()
{
    gDiscordRichPresence->state = "Idling";
    Discord_UpdatePresence(gDiscordRichPresence);
}