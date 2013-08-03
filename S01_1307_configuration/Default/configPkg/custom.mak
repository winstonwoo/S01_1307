## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,em4f linker.cmd \
  package/cfg/mutex_pem4f.oem4f \

linker.cmd: package/cfg/mutex_pem4f.xdl
	$(SED) 's"^\"\(package/cfg/mutex_pem4fcfg.cmd\)\"$""\"J:/WorkHouse2013/SW2013/S01_1307_VTDR_Stellaris/S01_Repository/S01_1307_configuration/Default/configPkg/\1\""' package/cfg/mutex_pem4f.xdl > $@
