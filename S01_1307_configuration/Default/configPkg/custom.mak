## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,em4f linker.cmd \
  package/cfg/mutex_pem4f.oem4f \

linker.cmd: package/cfg/mutex_pem4f.xdl
	$(SED) 's"^\"\(package/cfg/mutex_pem4fcfg.cmd\)\"$""\"J:/WorkHouse2013/Temp/temp08121/S01_Repository/S01_1307_configuration/Default/configPkg/\1\""' package/cfg/mutex_pem4f.xdl > $@
