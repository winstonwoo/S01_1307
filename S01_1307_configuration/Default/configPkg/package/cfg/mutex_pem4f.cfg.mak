# invoke SourceDir generated makefile for mutex.pem4f
mutex.pem4f: .libraries,mutex.pem4f
.libraries,mutex.pem4f: package/cfg/mutex_pem4f.xdl
	$(MAKE) -f J:\WorkHouse2013\SW2013\S01_1307_VTDR_Stellaris\S01_Repository\S01_1307_configuration/src/makefile.libs

clean::
	$(MAKE) -f J:\WorkHouse2013\SW2013\S01_1307_VTDR_Stellaris\S01_Repository\S01_1307_configuration/src/makefile.libs clean

