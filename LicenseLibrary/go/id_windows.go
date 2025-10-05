package main

import (
	"golang.org/x/sys/windows/registry"
)

const (
	REGISTRY_GUID_PATH = "SOFTWARE\\Microsoft\\Cryptography"
	REGISTRY_GUID_KEY  = "MachineGuid"
)

func GUID() string {
	reg, err := registry.OpenKey(registry.LOCAL_MACHINE, REGISTRY_GUID_PATH, registry.QUERY_VALUE|registry.WOW64_64KEY)
	if err != nil {
		return ""
	}
	defer func(key registry.Key) {
		err := key.Close()
		if err != nil {
			return
		}
	}(reg)
	computerGuid, _, err := reg.GetStringValue(REGISTRY_GUID_KEY)
	if err != nil {
		return ""
	}
	return computerGuid
}
