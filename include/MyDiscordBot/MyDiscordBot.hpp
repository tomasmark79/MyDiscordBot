#ifndef __MYDISCORDBOT_H__
#define __MYDISCORDBOT_H__

#include "dpp/dpp.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <string>

#define OAUTH_TOKEN_FILE   "/home/tomas/.discord_oauth.key"
#define EMOJI_INTERVAL_SEC (int)600
#define URL_EXCHANGE_RATES_CZ                                                  \
    "https://www.cnb.cz/cs/financni-trhy/devizovy-trh/kurzy-devizoveho-trhu/"  \
    "kurzy-devizoveho-trhu/denni_kurz.txt"

# define URL_COIN_GECKO "https://api.coingecko.com/api/v3/simple/price?ids=bitcoin&vs_currencies=usd"

// Library declaration

class MyDiscordBot
{
  public:
    MyDiscordBot();
    ~MyDiscordBot();

  protected:
    std::unique_ptr<dpp::cluster> bot;

  private:
    bool getToken(std::string &token);
    bool initCluster();
    void onReady(std::unique_ptr<dpp::cluster> &bot);
    void slashCommands(std::unique_ptr<dpp::cluster> &bot);
};

#endif // __MYDISCORDBOT_H__