# OS_EmbLinuxProject
  - snake_game_project
  - include device drivers of nokia 5110 LCD, buttons
  - write application to control device drivers (such as: snake game)
# to build device drivers
  - cd OS_EmbLinuxProject
  - bash ./setup.sh
# plug in the wire for the Nokia5110
  - RES -> GPIO17
  - SCE -> GPIO18
  - DC -> GPIO27
  - SDIN -> GPIO22
  - SCLK -> GPIO23
# plug in the wire for the buttons
  - GPIO 12,16,20,21 connect to Vcc
# to build user program
  - g++ -o int interface_main.cpp -lpthread
