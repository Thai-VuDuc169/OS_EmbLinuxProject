#include <fcntl.h>
#include <string.h>
#include <iostream>
#include <iosfwd>
#include <unistd.h>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

#include <pthread.h>
////{ buttons

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MY_SIGNAL		40
#define FILENAME		"/dev/buttons"

#define FILENAME_1	"/home/pi/Desktop/Nokia5110LCDriver/user_interface/planet.txt"
#define FILENAME_2	"/home/pi/Desktop/Nokia5110LCDriver/user_interface/rocket.txt"
#define FILENAME_3	"/home/pi/Desktop/Nokia5110LCDriver/user_interface/unicorn.txt"
#define FILENAME_4	"/home/pi/Desktop/Nokia5110LCDriver/user_interface/video.txt"

int button_state = 1;

using namespace std;

void signal_handle(int n, siginfo_t *info, void* data)
{
	printf("jump to sig_handle\n");
	button_state = info->si_int;
	printf("button_state is %d\n", button_state);
}
////}

#define MAX_STREAM_SIZE 510
#define MAX_TEXT_SIZE 84

#define LCD_WIDTH 84
#define LCD_HEIGHT 48

char buffer[MAX_STREAM_SIZE];

void set_data_mode_text(bool is_text){
    int fd;

    fd = open("/sys/gpio_lcd5110/gpio_lcd5110/data_mode" , O_RDWR);
    if (fd == -1){
        fprintf(stderr, "Error opening file (setting mode)\n");
        exit(-1);
    }
    if (is_text)
        write(fd, "t\0" , 2);
    else
        write(fd, "i\0" , 2);

    close(fd);
}

void clear_buffer (char * buffer) {
    memset(buffer, 0, 32);
}

void LCD_CheckInputToBuff()
{
    std::ifstream f_stream;
    if (button_state == 1)
    {
        f_stream.open( FILENAME_1 , std::ifstream::in);
	cout << "\nf_stream1" << endl;
    }
    if (button_state == 2)
    {
        f_stream.open( FILENAME_2 , std::ifstream::in);
	cout << "\nf_stream2" << endl;
    }  
    if (button_state == 3)
    {
        f_stream.open( FILENAME_3 , std::ifstream::in);
	cout << "\nf_stream3" << endl;
    } 
    if (button_state == 4)
    {
        f_stream.open( FILENAME_4 , std::ifstream::in);
	cout << "\nf_stream4" << endl;
    }
	if ( f_stream.is_open() && !f_stream.rdstate() )
    {
	std::string content((std::istreambuf_iterator<char>(f_stream)), (std::istreambuf_iterator<char>()));
        // I M A G E
        set_data_mode_text(false);
        std::istringstream iss(content);
        int i = 0;
        for (std::string line; std::getline(iss, line); )
        {
            if (i >= MAX_STREAM_SIZE)
            {
                return;
            }
            buffer[i] = char(std::stoi(line));
            i++;
        }
    }
}
void LCD_DrawImage()
{
    clear_buffer(buffer);
    int fd;
    fd = open("/dev/gpio_5110" , O_RDWR);
    if (fd == -1)
    {
        fprintf(stderr, "Error opening file\n");
        // exit(-1);
        return;
    }
    write(fd, buffer , sizeof(buffer));
    close(fd);
    clear_buffer(buffer);
    return;
}
////{thread
void *thread_ControlButtons(void* ar)
{
	struct sigaction sig;
	int fd;

	printf("process id is %d\n", getpid());
	sig.sa_sigaction = signal_handle;
	sig.sa_flags = SA_SIGINFO;

	sigaction(MY_SIGNAL, &sig, NULL);

	fd = open(FILENAME, O_RDONLY);
	if (fd < 0) {
		perror("open: Failed\n");
		cout << "open: Failed\n" << endl;
	}
	for(;;)
	{};
	return ar;		
}
////}

/*********\
2D_array: 
\*********/

int main()
{
	pthread_t tid1;
	pthread_create(&tid1, NULL, thread_ControlButtons, NULL);

    for(;;)
    {   
       LCD_CheckInputToBuff();
       LCD_DrawImage();
       usleep(10);
    }
    return 0;
}

