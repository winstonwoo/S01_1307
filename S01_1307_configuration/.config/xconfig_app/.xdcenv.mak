#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/PROGRA~1/TEXASI~1/bios_6_35_01_29/packages;C:/PROGRA~1/TEXASI~1/ccsv5/ccs_base;J:/WorkHouse2013/SW2013/S01_1307_VTDR_Stellaris/S01_1307_configuration/.config
override XDCROOT = C:/PROGRA~1/TEXASI~1/xdctools_3_25_00_48
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/PROGRA~1/TEXASI~1/bios_6_35_01_29/packages;C:/PROGRA~1/TEXASI~1/ccsv5/ccs_base;J:/WorkHouse2013/SW2013/S01_1307_VTDR_Stellaris/S01_1307_configuration/.config;C:/PROGRA~1/TEXASI~1/xdctools_3_25_00_48/packages;..
HOSTOS = Windows
endif
