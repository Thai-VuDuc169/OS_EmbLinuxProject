# OS_EmbLinuxProject
  - snake_game_project
  - include device drivers of nokia 5110 LCD, buttons
  - write application to control device drivers (such as: snake game)
# to build device drivers
  - cd OS_EmbLinuxProject
  - bash ./setup.sh
# to build user program
  - g++ -o int interface_main.cpp -lpthread
