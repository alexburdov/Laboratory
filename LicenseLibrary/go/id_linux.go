package main

import (
	"os"
	"strings"
)

const (
	dbusPath    = "/var/lib/dbus/machine-id"
	dbusPathEtc = "/etc/machine-id"
)

func GUID() string {
	computerGuid, err := os.ReadFile(dbusPath)
	if err != nil {
		computerGuid, err = os.ReadFile(dbusPathEtc)
	}
	if err != nil {
		return ""
	}
	// Computer GUID is 'd17a926da4fe4197aac024c503e0c492'
	return strings.TrimSpace(string(computerGuid))
}
