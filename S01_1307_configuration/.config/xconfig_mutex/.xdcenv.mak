#
_XDCBUILDCOUNT = 0
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/ti/bios_6_34_02_18/packages;C:/ti/ccsv5/ccs_base;J:/WorkHouse2013/SW2013/S01_1307_VTDR_Stellaris/S01_Repository/S01_1307_configuration/.config
override XDCROOT = C:/ti/xdctools_3_24_05_48
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/ti/bios_6_34_02_18/packages;C:/ti/ccsv5/ccs_base;J:/WorkHouse2013/SW2013/S01_1307_VTDR_Stellaris/S01_Repository/S01_1307_configuration/.config;C:/ti/xdctools_3_24_05_48/packages;..
HOSTOS = Windows
endif
