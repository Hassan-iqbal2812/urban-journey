#ifndef CMD_H
#define CMD_H
#include <string>
namespace cmd {
	void handleArgs(const std::string,int,char **);
	bool tutorial_navigator(std::string);
}
#endif
