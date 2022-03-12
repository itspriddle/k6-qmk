## Custom

# Set Windows keys
_K6_WINDOWS = no

ifeq ($(strip $(_K6_WINDOWS)), yes)
	OPT_DEFS += -D_K6_WINDOWS
endif

# Enable console for debugging
# CONSOLE_ENABLE = yes
