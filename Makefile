ifeq ($(strip $(DEVKITARM)),)
$(error "Please set DEVKITARM in your environment. export DEVKITARM=<path to>devkitARM")
endif

include $(DEVKITARM)/gba_rules

PROJ = sap

SOURCES		:=	src sprites engine
CFILES		:=	$(foreach dir,$(SOURCES),$(wildcard $(dir)/*.c))
OFILES := $(CFILES:.c=.o)

INCLUDES = -I$(DEVKITPRO)/libtonc/include
LIBS = -L$(DEVKITPRO)/libtonc/lib -ltonc

CFLAGS = -mthumb-interwork -mthumb -O2 -Wall -fno-strict-aliasing $(INCLUDES)
LDFLAGS = -mthumb-interwork -mthumb -specs=gba.specs

$(info $$CFILES is [${CFILES}])
$(info $$OFILES is [${OFILES}])


DEPENDS	:=	$(OFILES:.o=.d)

$(PROJ).gba: $(PROJ).elf
	$(OBJCOPY) -v -O binary $(PROJ).elf $(PROJ).gba
	gbafix $(PROJ).gba

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PROJ).elf: $(OFILES)
	$(CC) $(LDFLAGS) $(OFILES) $(LIBS) -o $(PROJ).elf


.PHONY: clean
clean:
	rm -f $(PROJ).elf
	rm -f $(OBJS)
	rm -f $(PROJ).gba

-include $(DEPENDS)