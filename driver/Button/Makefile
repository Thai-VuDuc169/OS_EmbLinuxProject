obj-m += button_ctl.o

all:
	#make -C /lib/modules/$(shell uname -r)/build M=$(DIR)/driver modules
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	#make -C /lib/modules/$(shell uname -r)/build M=$(DIR)/driver clean
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean 
