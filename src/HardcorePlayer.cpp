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
        ChatHandler(player->GetSession()).SendSysMessage("You are dead, get over it!");
        if (player->isDead()) {
            player->GetSession()->PlayerLogout();
        }
    }


    void OnPlayerReleasedGhost(Player *player) override {
        player->KillPlayer();
        player->GetSession()->PlayerLogout();
    }
};

void AddHardcorePlayerScripts() {
    new HardcorePlayer();
}

