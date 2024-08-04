#include <string>
#include <cpr/cpr.h>

struct mCMD{
std::string mUrl;
std::string mAuthorization;
std::string mClient_id;
};

namespace mFunctions{
void twitch_reproduce(const std::string& name);
void twitch_followed();
void twitch_comment(const std::string& comment);

void dock_toggle();
};

namespace mHelper{
void failedRequest(const cpr::Response& response);
};

