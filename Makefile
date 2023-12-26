ifeq (,$(TARGET))
$(error TARGET is not set)
endif

ifeq (,$(TOOLCHAIN_PREFIX))
$(error TOOLCHAIN_PREFIX is not set)
endif

ifeq (,$(CFLAGS))
$(error CFLAGS is not set)
endif

ifeq (,$(LDFLAGS))
$(error LDFLAGS is not set)
endif

CC = $(TOOLCHAIN_PREFIX)gcc

CFLAGS += -I$(SYSROOT)/usr/include

LDFLAGS += -L$(SYSROOT)/lib
LDFLAGS += -L$(SYSROOT)/usr/lib
LDFLAGS += -lwiringx

SOURCE = $(wildcard *.c)
OBJS = $(patsubst %.c,build/%.o,$(SOURCE))

BUILD_DIR = build

.SILENT: $(BUILD_DIR)/$(TARGET) $(OBJS) clean run clean-device

# scp $(BUILD_DIR)/$(TARGET) root@192.168.42.1:/root/

run: $(BUILD_DIR)/$(TARGET)
	echo Copying '$(TARGET)' to device
	sshpass -p 'milkv' scp $(BUILD_DIR)/$(TARGET) root@192.168.42.1:/root/
	echo Running '$(TARGET)' on device
	sshpass -p 'milkv' ssh root@192.168.42.1 '/root/$(TARGET)'

$(BUILD_DIR)/$(TARGET): $(OBJS)
	echo Linking '$(TARGET)'
	mkdir -p $(BUILD_DIR)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

build/%.o: %.c
	echo Compiling '$<'
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean clean-device
clean:
	echo Cleaning
	rm -rf $(BUILD_DIR)

clean-device:
	echo Cleaning device
	sshpass -p 'milkv' ssh root@192.168.42.1 'cd /root/ && rm -rf *'
