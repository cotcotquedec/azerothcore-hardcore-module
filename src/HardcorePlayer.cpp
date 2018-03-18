/**
    This plugin can be used for common player customizations
 */

#include "ScriptMgr.h"
#include "Player.h"
#include "Configuration/Config.h"

class HardcorePlayer : public PlayerScript{
public:

    HardcorePlayer() : PlayerScript("HardcorePlayer") { }

    void OnPlayerReleasedGhost(Player* player) override {
        player->KillPlayer();
    }
};

void AddHardcorePlayerScripts() {
    new HardcorePlayer();
}

