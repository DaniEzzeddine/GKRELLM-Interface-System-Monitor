#ifndef FT_GKRELLM_HPP
#define FT_GKRELLM_HPP


#include "bytes.hpp"
#include "time_util.hpp"


#include "IMonitorModule.hpp"
#include "CPUModule.hpp"
#include "DateTimeModule.hpp"
#include "HostnameModule.hpp"
#include "NetworkModule.hpp"
#include "OSModule.hpp"
#include "UsernameModule.hpp"
#include "RAMModule.hpp"


#include "FrameClock.hpp"
#include "MonitorModuleList.hpp"


#include "IMonitorDisplay.hpp"
#include "GraphicMonitorDisplay.hpp"
#include "TermMonitorDisplay.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


#include <ncurses.h>
#include <unistd.h>
#include <limits.h>
#include <time.h> 
#include <stdlib.h> 
#include <sys/utsname.h>
#include <string>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/vmmeter.h>
#include <random>

#endif