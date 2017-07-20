# This is a generated file. Please do not edit.

.PHONY: all

COMMANDS := 	\
	    scd_cmd_1

all: $(COMMANDS)

scd_cmd_1:
	@echo begin generating scanner info for $@
	gcc -D 'USE_CUNIT_DEF=1' -D 'USE_CUNIT_TEST_DEF=1' -O0 -E -P -v -dD specs.c
	@echo end generating scanner info for $@


