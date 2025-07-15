obj-m := main.o

KERNEL_DIR ?= ~/rpi/linux-8b914fd9e718e40aebaca7bc0c0a292eca77e5aa

CROSS_COMPILE ?= aarch64-linux-gnu-

OUTPUT_DIR ?= ~/rpi/output

all:
	make -C $(KERNEL_DIR) M=$(PWD) ARCH=arm64 CROSS_COMPILE=$(CROSS_COMPILE) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean
	make -C $(KERNEL_DIR) M=$(PWD) ARCH=arm64 CROSS_COMPILE=$(CROSS_COMPILE) clean

host:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules