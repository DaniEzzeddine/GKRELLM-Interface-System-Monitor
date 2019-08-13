#include "ft_gkrellm.hpp"
# define MAINMENU_WIDTH 64
# define MAINMENU_HEIGHT 17
void RunTermMonitor()
{
	initscr();				// Initialize the ncurses
	cbreak();				// Read keypresses immediately, instead of waiting for newline
	noecho();				// Suppress echoing of typed characters
	nodelay(stdscr, true);	// Do not stall while waiting for key presses
	keypad(stdscr, true);	// Allows capturing of arrow keys
	refresh();				// Clear the window
	// TODO xset keyboard delay
	srand(time(0));
	int screenWidth, screenHeight;
	getmaxyx(stdscr, screenHeight, screenWidth);
	int _offsetX = (screenWidth - MAINMENU_WIDTH) / 2;
	if (_offsetX < 0) _offsetX = 0;
	int _offsetY = (screenHeight - MAINMENU_HEIGHT) / 2;
	if (_offsetY < 0) _offsetY = 0;
	FrameClock clock;
	TermMonitorDisplay TerminalDisplay(0);
	TerminalDisplay.addModule(new HostnameModule());
	TerminalDisplay.addModule(new UsernameModule());
	TerminalDisplay.addModule(new OSModule());
	TerminalDisplay.addModule(new DateTimeModule()); 
	TerminalDisplay.addModule(new CPUModule()); 
	TerminalDisplay.addModule(new RAMModule()); 
	TerminalDisplay.addModule(new NetworkModule()); 
    // system("sysctl -n machdep.cpu.brand_string >> text.txt; echo 'Cores: ' & sysctl -n hw.ncpu  >> text.txt");
    // system("sysctl -n machdep.cpu.brand_string >> text.txt; echo 'Cores: '>> text.txt; sysctl -n hw.ncpu >> text.txt");
	for(;;)
	{

	if (clock.tick())
	{

		erase();
		for (int i = 1; i < 101; i++)
		{
			mvaddch(12 + 36 - 1, 4 + i, '-');
		}
		for (int i = 1; i < 36; i++)
		{
			mvaddch(12 + i, 4, '|');
			mvaddch(12 + i,  105, '|');
		}
		TerminalDisplay.displayModules();
		refresh();
		}
	}
}


void RunGraphic()
{
	sf::RenderWindow window(sf::VideoMode(2000, 1200), "Frankenstein");
	FrameClock clock;
	window.clear();
	GraphicMonitorDisplay MonitorDisplay(0);
	MonitorDisplay.addModule(new HostnameModule());
	MonitorDisplay.addModule(new UsernameModule());
	MonitorDisplay.addModule(new OSModule());
	MonitorDisplay.addModule(new DateTimeModule()); 
	MonitorDisplay.addModule(new CPUModule()); 
	MonitorDisplay.addModule(new RAMModule()); 
	MonitorDisplay.addModule(new NetworkModule()); 
	while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();	
        }
		if (clock.tick())
		{
			MonitorDisplay.displayModule(&window);
		}
    }

}

int main(int argc, char **argv)
{
    if (argc == 1)
	{
	    RunTermMonitor();
        endwin();				// Close ncurses
    }
	else if (!strcmp(argv[1], "-g"))
		RunGraphic();
	return 0;
}
