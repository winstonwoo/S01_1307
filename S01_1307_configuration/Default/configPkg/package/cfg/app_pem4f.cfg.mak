# invoke SourceDir generated makefile for app.pem4f
app.pem4f: .libraries,app.pem4f
.libraries,app.pem4f: package/cfg/app_pem4f.xdl
	$(MAKE) -f J:\WorkHouse2013\SW2013\S01_1307_VTDR_Stellaris\S01_1307_configuration/src/makefile.libs

clean::
	$(MAKE) -f J:\WorkHouse2013\SW2013\S01_1307_VTDR_Stellaris\S01_1307_configuration/src/makefile.libs clean

