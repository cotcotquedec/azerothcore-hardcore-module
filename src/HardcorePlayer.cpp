/**
    This plugin can be used for common player customizations
 */

#include "ScriptMgr.h"
#include "Player.h"
#include "Configuration/Config.h"

class HardcorePlayer : public PlayerScript {
public:

    HardcorePlayer() : PlayerScript("HardcorePlayer") {}

    void OnLogin(Player *player) override {
        if (player->isDead()) {
            ChatHandler(player->GetSession()).SendSysMessage("You are dead, get over it! LuL");
        }
    }

    void OnPlayerReleasedGhost(Player *player) override {
        ChatHandler(player->GetSession()).SendSysMessage("You're journey is now over!!!");
    }
};

void AddHardcorePlayerScripts() {
    new HardcorePlayer();
}

